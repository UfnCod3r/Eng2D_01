#include "XMath.h"
#include "XArray.h"
#include <iostream>
#include "XList.h"
#include "XName.h"
#include "XFileMgr.h"
#include "XEngineThreads.h"

__declspec(dllexport) uintptr QWE123(X::ForwardListTS<int>& a, int n)
{
	return a.nodeCount();
}



int main(int argc, char** argv)
{
	using namespace X;
	EngineConfig conf;
	conf.fullScreen = false;
	conf.glMajorVersion = 3;
	conf.glMinorVersion = 3;
	conf.windowBPP = 24;
	conf.windowHeight = 600;
	conf.windowTitle = "Eng";
	conf.windowWidth = 800;
	Engine_Run(conf);
}
