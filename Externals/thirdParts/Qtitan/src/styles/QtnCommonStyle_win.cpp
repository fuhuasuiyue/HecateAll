/****************************************************************************
**
** Qtitan Library by Developer Machines (Microsoft-Ribbon implementation for Qt.C++)
** 
** Copyright (c) 2009-2015 Developer Machines (http://www.devmachines.com)
**           ALL RIGHTS RESERVED
** 
**  The entire contents of this file is protected by copyright law and
**  international treaties. Unauthorized reproduction, reverse-engineering
**  and distribution of all or any portion of the code contained in this
**  file is strictly prohibited and may result in severe civil and 
**  criminal penalties and will be prosecuted to the maximum extent 
**  possible under the law.
**
**  RESTRICTIONS
**
**  THE SOURCE CODE CONTAINED WITHIN THIS FILE AND ALL RELATED
**  FILES OR ANY PORTION OF ITS CONTENTS SHALL AT NO TIME BE
**  COPIED, TRANSFERRED, SOLD, DISTRIBUTED, OR OTHERWISE MADE
**  AVAILABLE TO OTHER INDIVIDUALS WITHOUT WRITTEN CONSENT
**  AND PERMISSION FROM DEVELOPER MACHINES
**
**  CONSULT THE END USER LICENSE AGREEMENT FOR INFORMATION ON
**  ADDITIONAL RESTRICTIONS.
**
****************************************************************************/
#include <QPainter>
#include "QtnCommonStylePrivate.h"
#include "QtnRibbonStylePrivate.h"
#include "QtnRibbonMainWindow.h"
#include "QtnStyleHelpers.h"
#include <qt_windows.h>

QTITAN_USE_NAMESPACE


#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
QT_BEGIN_NAMESPACE
    Q_GUI_EXPORT QPixmap qt_pixmapFromWinHBITMAP(HBITMAP, int hbitmapFormat = 0);
    Q_GUI_EXPORT HBITMAP qt_pixmapToWinHBITMAP(const QPixmap& p, int hbitmapFormat = 0);
    Q_GUI_EXPORT HICON qt_pixmapToWinHICON(const QPixmap& p);
    Q_GUI_EXPORT QPixmap qt_pixmapFromWinHICON(HICON icon);
QT_END_NAMESPACE

enum HBitmapFormat 
{
    HBitmapNoAlpha,
    HBitmapPremultipliedAlpha,
    HBitmapAlpha
};
#endif

static QImage qtn_fromWinHBITMAP(HDC hdc, HBITMAP bitmap, int w, int h)
{
    BITMAPINFO bmi;
    memset(&bmi, 0, sizeof(bmi));
    bmi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth       = w;
    bmi.bmiHeader.biHeight      = -h;
    bmi.bmiHeader.biPlanes      = 1;
    bmi.bmiHeader.biBitCount    = 32;
    bmi.bmiHeader.biCompression = BI_RGB;
    bmi.bmiHeader.biSizeImage   = w * h * 4;

    QImage image(w, h, QImage::Format_ARGB32_Premultiplied);
    image.fill(0);
    if (image.isNull())
        return image;

    // Get bitmap bits
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    uchar* data = (uchar*)::malloc(bmi.bmiHeader.biSizeImage);
#else
    uchar* data = (uchar*)qMalloc(bmi.bmiHeader.biSizeImage);
#endif

    if (GetDIBits(hdc, bitmap, 0, h, data, &bmi, DIB_RGB_COLORS)) 
    {

        // Create image and copy data into image.
        for (int y = 0; y < h; ++y) 
        {
            void* dest = (void*) image.scanLine(y);
            void* src = data + y * image.bytesPerLine();
            memcpy(dest, src, image.bytesPerLine());
        }
    } 
    else 
    {
        qWarning("qtn_fromWinHBITMAP(), failed to get bitmap bits");
    }
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    Q_ASSERT(false); //TODO
#else
    qFree(data);
#endif

    return image;
}

QPixmap StyleHelper::alphaBlend(const QPixmap& src)
{
//    HBITMAP winBitmap1 = src.toWinHBITMAP(QPixmap::Alpha);
//    return QPixmap::fromWinHBITMAP(winBitmap1, QPixmap::PremultipliedAlpha);

    bool foundAlpha = false;
    HDC screenDevice = GetDC(0);
    HDC hdc = CreateCompatibleDC(screenDevice);
    ReleaseDC(0, screenDevice);

    int w = src.width();
    int h = src.height();

#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    HBITMAP winBitmap = qt_pixmapToWinHBITMAP(src, HBitmapAlpha);
#else
    HBITMAP winBitmap = src.toWinHBITMAP(QPixmap::Alpha);
#endif

    HGDIOBJ oldhdc = (HBITMAP)SelectObject(hdc, winBitmap);

    QImage image = qtn_fromWinHBITMAP(hdc, winBitmap, w, h);

    for (int y = 0 ; y < h && !foundAlpha ; y++) 
    {
        QRgb* scanLine = reinterpret_cast<QRgb*>(image.scanLine(y));
        for (int x = 0; x < w ; x++) 
        {
            if (qAlpha(scanLine[x]) != 0) 
            {
                foundAlpha = true;
                break;
            }
        }
    }

    if (!foundAlpha) 
    {
        //If no alpha was found, we use the mask to set alpha values
        QImage mask = qtn_fromWinHBITMAP(hdc, winBitmap, w, h);

        for (int y = 0 ; y < h ; y++)
        {
            QRgb* scanlineImage = reinterpret_cast<QRgb*>(image.scanLine(y));
            QRgb* scanlineMask = mask.isNull() ? 0 : reinterpret_cast<QRgb*>(mask.scanLine(y));
            for (int x = 0; x < w ; x++)
            {
                if (scanlineMask && qRed(scanlineMask[x]) != 0)
                    scanlineImage[x] = 0; //mask out this pixel
                else
                    scanlineImage[x] |= 0xff000000; // set the alpha channel to 255
            }
        }
    }

    SelectObject(hdc, oldhdc); //restore state
    DeleteObject(winBitmap);
    DeleteDC(hdc);

    return QPixmap::fromImage(image);
}

static inline COLORREF rgbcolorref(const QColor& col)
{
    return RGB(col.red(), col.green(), col.blue());
}

void FillSolidRect(HDC hdc, int x, int y, int cx, int cy, COLORREF clr)
{
    ::SetBkColor(hdc, clr);

    RECT rect;
    rect.left    = x;
    rect.top     = y;
    rect.right   = x + cx;
    rect.bottom  = y + cy;

    //::ExtTextOut(hdc, 0, 0, ETO_OPAQUE, &rect, NULL, 0, NULL); //!< ribbon原先写法

    //! 修改原因
    //  Resize窗口的时候花屏，显示的模型时隐时现, 经调试，发现时绘制边框导致的
    //  在使用OpenGL的情况下，如果连续调用两次以上就会导致花屏，解决方法是换成以下方式绘制边框：

    HBRUSH hbr = ::CreateSolidBrush(clr);
    HBRUSH hbrBk = (HBRUSH)::SelectObject(hdc, hbr);
    ::FillRect(hdc, &rect, hbr);
    ::SelectObject(hdc, hbrBk);
    ::DeleteObject(hbr);

}

void Draw3dRect(HDC hdc, int x, int y, int cx, int cy, COLORREF clrTopLeft, COLORREF clrBottomRight)
{
    FillSolidRect(hdc, x, y, cx - 1, 1, clrTopLeft);
    FillSolidRect(hdc, x, y, 1, cy - 1, clrTopLeft);
    FillSolidRect(hdc, x + cx, y, -1, cy, clrBottomRight);
    FillSolidRect(hdc, x, y + cy, cx, -1, clrBottomRight);
}

void Draw3dRect(HDC hdc, LPCRECT lpRect, COLORREF clrTopLeft, COLORREF clrBottomRight)
{
    Draw3dRect(hdc, lpRect->left, lpRect->top, lpRect->right - lpRect->left,
        lpRect->bottom - lpRect->top, clrTopLeft, clrBottomRight);
}

// for QForm
/*! \internal */
bool RibbonPaintManager2013::drawFrame(const QStyleOption* opt, QPainter* p, const QWidget* w) const
{
#ifdef Q_OS_WIN
    Q_UNUSED(p);
    QTN_D_STYLE(RibbonStyle)
    if (qobject_cast<const RibbonMainWindow*>(w))
    {
        if (const StyleOptionFrame* optFrame = qstyleoption_cast<const StyleOptionFrame*>(opt))
        {
            HDC hdc = (HDC)optFrame->hdc;

            QRect rc = optFrame->rect;
            rc.adjust(0, 0, -1, -1);

            QRect rcBorders = optFrame->clientRect;
            int nRightBorder = rcBorders.left() - rc.left(), nLeftBorder = rcBorders.left() - rc.left(), nTopBorder = rcBorders.top() - rc.top();
            int nBottomBorder = rc.bottom() - rcBorders.bottom() + 1/*/2*/;
            int statusHeight = optFrame->statusHeight;

            HBRUSH hBrush = ::CreateSolidBrush(rgbcolorref(d.m_clrRibbonFace)/*RGB(255, 0,0)*/);
            Q_ASSERT(hBrush != Q_NULL);
            // draw top
            RECT rectTop = {0, 0, rc.width(), nTopBorder};
            ::FillRect(hdc, &rectTop, hBrush);
            // draw left
            RECT rectLeft = {0, 0, nLeftBorder, rc.height()};
            ::FillRect(hdc, &rectLeft, hBrush);
            // draw right
            RECT rectRight = {rc.width() - nRightBorder, 0, rc.width() + nRightBorder, rc.height()};
            ::FillRect(hdc, &rectRight, hBrush);
            // draw bottom
            RECT rectBottom = {0, rc.height() - nBottomBorder, rc.width(), rc.height() + nBottomBorder};
            ::FillRect(hdc, &rectBottom, hBrush);

            COLORREF clrBorder = optFrame->active ? rgbcolorref(d.m_clrFrameBorderActive0) : rgbcolorref(d.m_clrFrameBorderInactive0);

            RECT rectFrame = {0, 0, rc.width(), rc.height()};
            ::Draw3dRect(hdc, &rectFrame, clrBorder, clrBorder);

            ::DeleteObject(hBrush);

            if (optFrame->hasStatusBar && !optFrame->isBackstageVisible)
            {
                HBRUSH hBrushStatusBar = ::CreateSolidBrush(rgbcolorref(d.m_clrStatusBarShadow)/*RGB(255, 0,0)*/);
                Q_ASSERT(hBrushStatusBar != Q_NULL);

                RECT rectBottom = {0, rc.height() - nBottomBorder, rc.width(), rc.height() + nBottomBorder};
                ::FillRect(hdc, &rectBottom, hBrushStatusBar);

                RECT rectLeft = {0, rc.height() - (statusHeight + nTopBorder), nLeftBorder, rc.height() - nBottomBorder};
                ::FillRect(hdc, &rectLeft, hBrushStatusBar);

                RECT rectRight = {rc.width() - nRightBorder, rc.height() - (statusHeight + nTopBorder), rc.width(), rc.height() - nBottomBorder};
                ::FillRect(hdc, &rectRight, hBrushStatusBar);

                ::DeleteObject(hBrushStatusBar);
            }
        }
        return true;
    }
#endif // Q_OS_WIN
    return false;
}
