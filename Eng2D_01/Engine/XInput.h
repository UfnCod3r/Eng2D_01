#pragma once

#include "XMemory.h"

namespace X
{
	class Input
	{
		bln	m_curKeyState[256];
		bln	m_preKeyState[256];
		int m_mouseX, m_mouseY;

	public:

		class Listener : UseGenericAllocator<GGenericAllocator>
		{
			virtual void onKeyDown(int key);
			virtual void onKeyUp(int key);
			virtual void onMouseMove(int x, int y);
			virtual void onMouseDown(int button, int x, int y);
			virtual void onMouseUp(int button, int x, int y);
		};


		void init();
		void release();

		void addListener(Listener* listener);
		void removeListener(Listener* listener);
		uint listenerCount() const;

		bln keyDown(int key);
		bln keyPress(int key);
		bln keyRelease(int key);
	};

	extern Input GInput;
};