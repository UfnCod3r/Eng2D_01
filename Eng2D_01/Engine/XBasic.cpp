#include "XBasic.h"
#include "XEngineThreads.h"

namespace X
{
	bln IsRenderThread()
	{
		return ThisThread_ID() == GThreadGameRender.getId();
	}

	bln IsUpdateThread()
	{
		return ThisThread_ID() == GThreadGameUpdate.getId();
	}

};