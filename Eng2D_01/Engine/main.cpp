#include "XMath.h"
#include "XArray.h"
#include <iostream>
#include "XList.h"
#include "XName.h"
#include "XFileMgr.h"
#include "XEngineThreads.h"
#include "XResourceMgr.h"


__declspec(dllexport) uintptr QWE123(X::ForwardListTS<int>& a, int n)
{
	return a.nodeCount();
}

int main(int argc, char** argv)
{

	using namespace X;
// 	Vec2 lVertex(1,0);
// 	Transform lTransform = Transform::CreateRotationRadian(90*DEG2RAD);
// 	Vec2 lV = lTransform * lVertex;
// 	printf("%f %f\n", lV.x, lV.y);

	
	EngineConfig conf;
	conf.fullScreen = false;
	conf.glMajorVersion = 2;
	conf.glMinorVersion = 1;
	conf.windowBPP = 24;
	conf.windowHeight = 600;
	conf.windowTitle = "Eng";
	conf.windowWidth = 800;
	Engine_Run(conf);
}
