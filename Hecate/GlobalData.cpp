#include "GlobalData.h"
#include <windows.h>
#include <Winnls.h>



GlobalData::GlobalData()
{
	// ���ϵͳ�ı��ļ������ʽ 936λGBK
	unCodePage = GetACP();
}

GlobalData::~GlobalData()
{
}
