#include "ImportOCAF.h"
#include <TDataStd_Name.hxx>
#include "Standard_Handle.hxx"
#include <TDF_Label.hxx>
#include <TDF_LabelSequence.hxx>
#include <TDF_Label.hxx>
# include <TDocStd_Document.hxx>
# include <XCAFApp_Application.hxx>
# include <XCAFDoc_DocumentTool.hxx>
# include <XCAFDoc_ShapeTool.hxx>
# include <XCAFDoc_ColorTool.hxx>
# include <XCAFDoc_Location.hxx>
# include <TDF_Label.hxx>
# include <TDF_LabelSequence.hxx>
# include <TDF_ChildIterator.hxx>
# include <TDataStd_Name.hxx>
# include <Quantity_Color.hxx>
# include <STEPCAFControl_Reader.hxx>
# include <STEPCAFControl_Writer.hxx>
# include <STEPControl_Writer.hxx>
# include <IGESCAFControl_Reader.hxx>
# include <IGESCAFControl_Writer.hxx>
# include <IGESControl_Controller.hxx>
# include <Interface_Static.hxx>
# include <Transfer_TransientProcess.hxx>
# include <XSControl_WorkSession.hxx>
# include <TopTools_IndexedMapOfShape.hxx>
# include <TopTools_MapOfShape.hxx>
# include <TopExp_Explorer.hxx>
# include <TopoDS_Iterator.hxx>
# include <APIHeaderSection_MakeHeader.hxx>
#include <Resource_Unicode.hxx>
#include "PartModel.h"
#include <QDebug>
#include <QTextCodec> 
#include "TextCodeConvert.h"



ImportOCAF::ImportOCAF(Handle_TDocStd_Document h, DocumentCommon* d, const std::string& name)
	: pDoc(h), doc(d), default_name(name)
{
	aShapeTool = XCAFDoc_DocumentTool::ShapeTool(pDoc->Main());
	aColorTool = XCAFDoc_DocumentTool::ColorTool(pDoc->Main());
}

ImportOCAF::~ImportOCAF()
{
}

void ImportOCAF::loadShapes()
{
	myRefShapes.clear();
	loadShapes(pDoc->Main(), TopLoc_Location(), default_name, "", false);
}

void ImportOCAF::loadShapes(const TDF_Label& label, const TopLoc_Location& loc, const std::string& defaultname, const std::string& assembly, bool isRef)
{
	int hash = 0;
	TopoDS_Shape aShape;
	if (aShapeTool->GetShape(label, aShape)) {
		hash = aShape.HashCode(HashUpper);
	}

	Handle(TDataStd_Name) name;
	std::string part_name = defaultname;
	if (label.FindAttribute(TDataStd_Name::GetID(), name)) {
		TCollection_ExtendedString extstr = name->Get();
		char* str = new char[extstr.LengthOfCString() + 1];
		//Standard_Utf8Char* utf8str = new Standard_Utf8Char[extstr.LengthOfCString() + 1];
		// test
		//bool isASCStr = extstr.IsAscii();
		//if (!isASCStr)
		//{
		//	const Standard_WideChar* wChar = extstr.ToWideString();
		//	//extstr.ToUTF8CString(str);
		//	str = TextCodeConvert::UnicodeToUTF8(wChar);
		//	part_name = str;
		//	//part_name = TextCodeConvert::GBKToUTF8(part_name);
		//	//int nExtCharSize = extstr.Length();
		//	//int nCharSize = extstr.LengthOfCString();
		//	//for (int nCurExtPos = 1; nCurExtPos <= nExtCharSize; ++nCurExtPos)
		//	//{
		//	//	Standard_ExtCharacter extChar = extstr.Value(nCurExtPos);
		//	//	Standard_Character stdChar = ToCharacter(extChar);
		//	//	nCharSize++;
		//	//}
		//}
		//else
		//{
			//extstr.ToUTF8CString(str);
			//part_name = str;
		//}
			extstr.ToUTF8CString(str);
			part_name = str;
		delete[] str;
		if (part_name.empty()) {
			part_name = defaultname;
		}
		else {
			bool ws = true;
			for (std::string::iterator it = part_name.begin(); it != part_name.end(); ++it) {
				if (*it != ' ') {
					ws = false;
					break;
				}
			}
			if (ws)
				part_name = defaultname;
		}
	}

	TopLoc_Location part_loc = loc;
	Handle(XCAFDoc_Location) hLoc;
	if (label.FindAttribute(XCAFDoc_Location::GetID(), hLoc)) {
		if (isRef)
			part_loc = part_loc * hLoc->Get();
		else
			part_loc = hLoc->Get();
	}

	std::string asm_name = part_name;

	TDF_Label ref;
	if (aShapeTool->IsReference(label) && aShapeTool->GetReferredShape(label, ref)) {
		loadShapes(ref, part_loc, part_name, asm_name, true);
	}

	if (isRef || myRefShapes.find(hash) == myRefShapes.end()) {
		TopoDS_Shape aShape;
		if (isRef && aShapeTool->GetShape(label, aShape))
			myRefShapes.insert(aShape.HashCode(HashUpper));

		if (aShapeTool->IsSimpleShape(label) && (isRef || aShapeTool->IsFree(label))) {
			if (!asm_name.empty())
				part_name = asm_name;
			if (isRef)
				createShape(label, loc, part_name);
			else
				createShape(label, part_loc, part_name);
		}
		else {
			for (TDF_ChildIterator it(label); it.More(); it.Next()) {
				loadShapes(it.Value(), part_loc, part_name, asm_name, isRef);
			}
		}
	}

}

void ImportOCAF::createShape(const TDF_Label& label, const TopLoc_Location& loc, const std::string& name)
{
	const TopoDS_Shape& aShape = aShapeTool->GetShape(label);
	if (!aShape.IsNull() && aShape.ShapeType() == TopAbs_COMPOUND) {
		TopExp_Explorer xp;
		int ctSolids = 0, ctShells = 0;
		for (xp.Init(aShape, TopAbs_SOLID); xp.More(); xp.Next(), ctSolids++)
			createShape(xp.Current(), loc, name);
		for (xp.Init(aShape, TopAbs_SHELL, TopAbs_SOLID); xp.More(); xp.Next(), ctShells++)
			createShape(xp.Current(), loc, name);
		if (ctSolids > 0 || ctShells > 0)
			return;
	}

	createShape(aShape, loc, name);

}

void ImportOCAF::createShape(const TopoDS_Shape& aShape, const TopLoc_Location& loc, const std::string& name)
{
	TopoDS_Shape pAshape = aShape;
	//PartModel* part = doc->addPartModel();
	PartModel* part = doc->getProject()->addPartModel();
	if (!loc.IsIdentity())
		part->setPartShape(pAshape.Moved(loc));
	else
		part->setPartShape(pAshape);
	part->setPartName(QString().fromStdString(name));

	Quantity_Color aColor;
	//App::Color color(0.8f, 0.8f, 0.8f);
	if (aColorTool->GetColor(aShape, XCAFDoc_ColorGen, aColor) ||
		aColorTool->GetColor(aShape, XCAFDoc_ColorSurf, aColor) ||
		aColorTool->GetColor(aShape, XCAFDoc_ColorCurv, aColor)) {
	//	color.r = (float)aColor.Red();
	//	color.g = (float)aColor.Green();
	//	color.b = (float)aColor.Blue();
	//	std::vector<App::Color> colors;
	//	colors.push_back(color);
	//	applyColors(part, colors);
		part->setQuantityColor(aColor);
	}

	TopTools_IndexedMapOfShape faces;
	TopExp_Explorer xp(aShape, TopAbs_FACE);
	while (xp.More()) {
		faces.Add(xp.Current());
		xp.Next();
	}
	bool found_face_color = false;
	//std::vector<App::Color> faceColors;
	//faceColors.resize(faces.Extent(), color);
	xp.Init(aShape, TopAbs_FACE);
	while (xp.More()) {
		if (aColorTool->GetColor(xp.Current(), XCAFDoc_ColorGen, aColor) ||
			aColorTool->GetColor(xp.Current(), XCAFDoc_ColorSurf, aColor) ||
			aColorTool->GetColor(xp.Current(), XCAFDoc_ColorCurv, aColor)) {
			int index = faces.FindIndex(xp.Current());
			//color.r = (float)aColor.Red();
			//color.g = (float)aColor.Green();
			//color.b = (float)aColor.Blue();
			//faceColors[index - 1] = color;
			found_face_color = true;
		}
		xp.Next();
	}

	if (found_face_color) {
		//applyColors(part, faceColors);
		part->setQuantityColor(aColor);
	}
}
