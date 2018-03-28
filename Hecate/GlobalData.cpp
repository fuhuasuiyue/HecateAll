#include "GlobalData.h"
#include <windows.h>
#include <Winnls.h>



GlobalData::GlobalData()
{
	// 获得系统文本文件编码格式 936位GBK
	unCodePage = GetACP();
}

GlobalData::~GlobalData()
{
}
