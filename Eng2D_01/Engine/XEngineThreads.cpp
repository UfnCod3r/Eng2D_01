#include "XEngineThreads.h"
#include "XMemory.h"
#include "XFileMgr.h"
#include "XName.h"
#include "XInput.h"
#include "XGameWindow.h"

#include <GL/glew.h>
#include <GL/wglew.h>

namespace X
{
	ThreadGameUpdate	GThreadGameUpdate;
	ThreadGameRender	GThreadGameRender;
	EngineConfig		GEngineConfig;

	volatile Atomic		GAppRuning	= true;
	volatile Atomic		GErrorOccurred		= false;
	DWORD				GMainThreadSleepTime = 32;
	HWND				GHWND = nullptr;
	HDC					GHDC = nullptr;
	HGLRC				GHGLRC = nullptr;


	/*
	int CreateWND()
	{
		XASSERT(::GetCurrentThreadId() == GThreadGameUpdate.getId());

		WNDCLASSEX wndc;
		wndc.cbSize					= sizeof(WNDCLASSEX);
		wndc.cbClsExtra				= 0;
		wndc.cbWndExtra				= 0;
		wndc.hbrBackground			= 0;
		wndc.hCursor				= LoadCursor(NULL, IDC_ARROW);
		wndc.hIcon					= LoadIcon(NULL, IDI_APPLICATION);
		wndc.hIconSm				= LoadIcon(NULL, IDI_APPLICATION);
		wndc.hInstance				= GetModuleHandle(NULL);
		wndc.lpfnWndProc			= MainWNDProc;
		wndc.lpszClassName			= GEngineConfig.windowTitle;
		wndc.lpszMenuName			= NULL;
		wndc.style					= CS_HREDRAW | CS_VREDRAW;

		if(!RegisterClassEx(&wndc))
		{
			MessageBox(NULL, "RegisterClassEx Failed", "Error", MB_OK);
			return -1;
		}

		GHWND = CreateWindowEx(NULL, GEngineConfig.windowTitle, GEngineConfig.windowTitle,  WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS
			, 0, 0, GEngineConfig.windowWidth, GEngineConfig.windowHeight, NULL, NULL, NULL, NULL);

		if(!GHWND)
		{
			MessageBox(NULL, "CreateWindowEx Failed", "Error", MB_OK);
			return -2;
		}

		GHDC = GetDC(GHWND);
		if(!GHDC)
		{	
			MessageBox(NULL, "GetDC Failed", "Error", MB_OK);
			return -3;
		}
	}

	int CreateGLContext()
	{
		XASSERT(GetCurrentThreadId() == GThreadGameRender.getId());

		PIXELFORMATDESCRIPTOR pfd;
		memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
		pfd.nSize		= sizeof(PIXELFORMATDESCRIPTOR);
		pfd.nVersion	= 1;
		pfd.dwFlags		= PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
		pfd.iPixelType	= PFD_TYPE_RGBA;
		pfd.cColorBits	= 32;
		pfd.cDepthBits	= 32;
		pfd.iLayerType	= PFD_MAIN_PLANE;

		int nPixelFormat = ChoosePixelFormat(GHDC, &pfd);

		if (nPixelFormat == 0) 
			return -4;

		BOOL bResult = SetPixelFormat(GHDC, nPixelFormat, &pfd);
		if (!bResult) 
			return -5;

		HGLRC tempContext = wglCreateContext(GHDC);
		if(wglMakeCurrent(GHDC, tempContext) == FALSE)
			return -6;

		GLenum lGlewInitResult = glewInit();
		XASSERT(lGlewInitResult == GLEW_NO_ERROR);

		int attribs[] =
		{
			WGL_CONTEXT_MAJOR_VERSION_ARB, GEngineConfig.glMajorVersion,
			WGL_CONTEXT_MINOR_VERSION_ARB, GEngineConfig.glMinorVersion,
			0
		};


		GHGLRC = wglCreateContextAttribsARB(GHDC, 0, attribs);
		wglMakeCurrent(NULL,NULL);
		wglDeleteContext(tempContext);
		wglMakeCurrent(GHDC, GHGLRC);
		wglSwapIntervalEXT(0);

// 		gConsole.printMessage("GL Version %s\n", ::glGetString(GL_VERSION));
// 		gConsole.printMessage("GLSL Version %s\n", ::glGetString(GL_SHADING_LANGUAGE_VERSION));
// 		if(!GLEW_ARB_draw_instanced)
// 			gConsole.printError("GL_ARB_draw_instanced  Not Supported :(\n");
// 		if(!GLEW_ARB_multitexture)
// 			gConsole.printError("GL_ARB_multitexture  Not Supported :(\n");
// 		if(!GLEW_ARB_uniform_buffer_object)
// 			gConsole.printError("GL_ARB_uniform_buffer_object  Not Supported :(\n");
// 		if(!GLEW_ARB_texture_non_power_of_two)
// 			gConsole.printError("GL_ARB_texture_non_power_of_two  Not Supported :(\n");
	}
	*/

	void ThreadGameUpdate::onExec()
	{
		GGameWindow.createWindow(GEngineConfig.windowWidth, GEngineConfig.windowHeight, GEngineConfig.windowTitle);
		GGameWindow.show();

		while (GAppRuning)
		{
			MSG lMSG;
			while (::PeekMessageA(&lMSG,  GHWND, 0, 0, PM_REMOVE))
			{
				::TranslateMessage(&lMSG);
				::DispatchMessage(&lMSG);
			}
			::Sleep(8);
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
		::Sleep(100);
		GGameWindow.createGLContext(GEngineConfig.glMajorVersion, GEngineConfig.glMinorVersion);

		while (GAppRuning)
		{
			::glClear(GL_COLOR_BUFFER_BIT);
			::SwapBuffers(GGameWindow.getDC());
			::Sleep(8);
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
		GFileManager.init();
		GNameManager.init();
		GInput.init();
		GThreadGameUpdate.init();
		GThreadGameRender.init();
	}
	void Engine_Release()
	{
		GThreadGameUpdate.release();
		GThreadGameRender.release();
		GFileManager.release();
		GNameManager.release();
		GInput.release();
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