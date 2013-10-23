#pragma once

#include "XBasic.h"

namespace X
{
	//////////////////////////////////////////////////////////////////////////GameWindow
	class GameWindow
	{
		HWND	m_HWND;
		HDC		m_HDC;
		HGLRC	m_HGLRC;

	public:
		GameWindow() : m_HWND(nullptr), m_HDC(nullptr), m_HGLRC(nullptr) {}

		HWND getWND() const { return m_HWND; }
		HDC  getDC() const  { return m_HDC; }

		void createWindow(uint w, uint h, const char* title);
		void createGLContext(int glMajorVersion, int glMinorVersion);
		void show();
		void destroy();
	};
	extern GameWindow GGameWindow;
};