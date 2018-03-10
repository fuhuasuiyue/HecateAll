#pragma once
#include <HCLogManager.h>

class HCMotionCommon
{
public:
	static HCMotionCommon* getInstance() { static HCMotionCommon sMCommon; return &sMCommon; };
	~HCMotionCommon();

	void initHCLogFile();

private:
	HCMotionCommon();
};

