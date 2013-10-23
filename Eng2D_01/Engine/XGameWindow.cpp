#include "XGameWindow.h"
#include "XEngineThreads.h"

#include <GL\glew.h>
#include <GL\wglew.h>

namespace X
{
	GameWindow GGameWindow;

	LRESULT WINAPI MainWNDProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
	{
		switch(msg)
		{

		case WM_CREATE:
			break;

		case WM_SIZE:
			// 			gGame_WinHeight = HIWORD(lparam);
			// 			gGame_WinWidth = LOWORD(lparam);
			// 			glViewport(0, 0, gGame_WinWidth, gGame_WinHeight);
			break;

		case WM_KEYDOWN:
			// 			gGame_CurKeyStates[wparam] = true;
			break;

		case WM_KEYUP:
			// 			gGame_CurKeyStates[wparam] = false;
			break;

		case WM_LBUTTONDOWN:
			// 			gGame_CurMouseStates[0] = true;
			break;

		case WM_LBUTTONUP:
			// 			gGame_CurMouseStates[0] = false;
			break;

		case WM_RBUTTONDOWN:
			// 			gGame_CurMouseStates[1] = true;
			break;

		case WM_RBUTTONUP:
			// 			gGame_CurMouseStates[1] = false;
			break;

		case WM_MBUTTONDOWN:
			// 			gGame_CurMouseStates[2] = true;
			break;

		case WM_MBUTTONUP:
			// 			gGame_CurMouseStates[2] = false;
			break;

		case WM_MOUSEMOVE:
			{
				// 				XVec2i newPos(HIWORD(lparam), HIWORD(lparam));
				// 				gGame_MouseVelocity = newPos - gGame_MousePos;
				// 				gGame_MousePos = newPos;
			}
			break;

		case WM_CLOSE:
		case WM_QUIT:
		case WM_DESTROY:
			//GAppRuning = false;
			break;
		}

		return DefWindowProc(hwnd, msg, wparam, lparam);
	}



	void GameWindow::createWindow(uint w, uint h, const char* title)
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
		wndc.lpszClassName			= title;
		wndc.lpszMenuName			= NULL;
		wndc.style					= CS_HREDRAW | CS_VREDRAW;

		if(!RegisterClassEx(&wndc))
		{
			::MessageBox(NULL, "RegisterClassEx Failed", "Error", MB_OK);
		}

		m_HWND = ::CreateWindowEx(NULL, title, title,  WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS
			, 0, 0, w, h, NULL, NULL, NULL, NULL);

		if(!m_HWND)
		{
			::MessageBox(NULL, "CreateWindowEx Failed", "Error", MB_OK);
		}

		m_HDC = ::GetDC(m_HWND);
		if(!m_HDC)
		{	
			::MessageBox(NULL, "GetDC Failed", "Error", MB_OK);
		}
	}
	
	void GameWindow::createGLContext( int glMajorVersion, int glMinorVersion )
	{
		XASSERT(GetCurrentThreadId() == GThreadGameRender.getId());

		PIXELFORMATDESCRIPTOR pfd = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		pfd.nSize		= sizeof(PIXELFORMATDESCRIPTOR);
		pfd.nVersion	= 1;
		pfd.dwFlags		= PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
		pfd.iPixelType	= PFD_TYPE_RGBA;
		pfd.cColorBits	= 32;
		pfd.cDepthBits	= 32;
		pfd.iLayerType	= PFD_MAIN_PLANE;

		int nPixelFormat = ChoosePixelFormat(m_HDC, &pfd);

		BOOL bResult = SetPixelFormat(m_HDC, nPixelFormat, &pfd);

		HGLRC tempContext = wglCreateContext(m_HDC);
		if(wglMakeCurrent(m_HDC, tempContext) == FALSE)
		{

		}

		GLenum lGlewInitResult = glewInit();
		XASSERT(lGlewInitResult == GLEW_NO_ERROR);

		int attribs[] =
		{
			WGL_CONTEXT_MAJOR_VERSION_ARB, glMajorVersion,
			WGL_CONTEXT_MINOR_VERSION_ARB, glMinorVersion,
			0
		};

		m_HGLRC = wglCreateContextAttribsARB(m_HDC, 0, attribs);
		wglMakeCurrent(NULL,NULL);
		wglDeleteContext(tempContext);
		wglMakeCurrent(m_HDC, m_HGLRC);
		wglSwapIntervalEXT(0);
	}

	void GameWindow::show()
	{
		XASSERT(::GetCurrentThreadId() == GThreadGameUpdate.getId());

		::ShowWindow(m_HWND, SW_SHOW);
		::SetForegroundWindow(m_HWND);
		::SetFocus(m_HWND);
	}

	void GameWindow::destroy()
	{

	}

};
