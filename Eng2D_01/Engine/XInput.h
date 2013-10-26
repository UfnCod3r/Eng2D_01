#pragma once

#include "XMemory.h"

namespace X
{
	//////////////////////////////////////////////////////////////////////////fwd decl
	class GameWindow;


	//////////////////////////////////////////////////////////////////////////Input
	class Input
	{
		friend class GameWindow;

		XMSALIGN(16) struct Data
		{
			bln keys[256];
			bln mouseButtons[3];
			int mouseX,  mouseY;
		};

		Data m_curState;
		Data m_preState;

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