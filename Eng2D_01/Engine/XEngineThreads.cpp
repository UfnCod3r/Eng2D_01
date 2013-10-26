#include "XEngineThreads.h"
#include "XMemory.h"
#include "XFileMgr.h"
#include "XName.h"
#include "XInput.h"
#include "XGameWindow.h"
#include "XConsole.h"
#include "XResourceMgr.h"
#include "XGLCommandQueue.h"

#include <GL/glew.h>
#include <GL/wglew.h>
#include "XGLMisc.h"

namespace X
{
	ThreadGameUpdate	GThreadGameUpdate;
	ThreadGameRender	GThreadGameRender;
	EngineConfig		GEngineConfig;

	volatile Atomic		GAppRuning	= true;
	volatile Atomic		GErrorOccurred = false;
	DWORD				GMainThreadSleepTime = 32;


	void ThreadGameUpdate::onExec()
	{
		GGameWindow.createWindow(GEngineConfig.windowWidth, GEngineConfig.windowHeight, GEngineConfig.windowTitle);
		GGameWindow.show();

		GResourceMgr.LoadShader("shader.glsl");

		while (GAppRuning)
		{
			MSG lMSG;
			while (::PeekMessageA(&lMSG,  nullptr, 0, 0, PM_REMOVE))
			{
				::TranslateMessage(&lMSG);
				::DispatchMessage(&lMSG);
			}

			ThisThread_Sleep(8);
		}
	}

	void ThreadGameUpdate::init()
	{

	}

	void ThreadGameUpdate::release()
	{

	}



	void ThreadGameRender::onExec()
	{
		ThisThread_Sleep(100);
		GGameWindow.createGLContext(GEngineConfig.glMajorVersion, GEngineConfig.glMinorVersion);

		while (GAppRuning)
		{
			GGLCommandQueue.PassCommands();

			::glClearColor(1,1,1,1);
			::glClear(GL_COLOR_BUFFER_BIT);

// 			::glBegin(GL_LINES);
// 			::glColor3f(1,0,0);
// 			::glVertex2f(0,0);
// 			::glVertex2f(1,1);
// 			::glEnd();

			//::glDrawArrays(GL_LINES, 0, 2);


// 			::glDrawArrays(GL_LINES, 0, 2);


			GGLCommandQueue.PassCommands();

			::SwapBuffers(GGameWindow.getDC());

			GGLCommandQueue.PassCommands();

			ThisThread_Sleep(8);
		}
	}

	void ThreadGameRender::init()
	{

	}

	void ThreadGameRender::release()
	{

	}

	void Engine_Init()
	{
		GGenericAllocator.init();
		GTempAllocator.init();
		GConsole.init();
		GFileManager.init();
		GNameManager.init();
		GInput.init();
		GThreadGameUpdate.init();
		GThreadGameRender.init();
		GResourceMgr.Init();
		GGLCommandQueue.Init();
	}
	void Engine_Release()
	{
		GGLCommandQueue.Release();
		GResourceMgr.Release();
		GThreadGameUpdate.release();
		GThreadGameRender.release();
		GFileManager.release();
		GNameManager.release();
		GInput.release();
		GConsole.release();
		GTempAllocator.release();
		GGenericAllocator.release();
	}

	void Engine_Run( const EngineConfig& config )
	{
		GEngineConfig = config;

		Engine_Init();

		GThreadGameUpdate.run();
		GThreadGameRender.run();

		while (GAppRuning)
		{
			if(GErrorOccurred)
			{

			}
			::Sleep(GMainThreadSleepTime);
		}

		Engine_Release();
	}

};