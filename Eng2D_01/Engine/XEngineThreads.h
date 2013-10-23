#pragma once

#include "XThreading.h"

namespace X
{
	//////////////////////////////////////////////////////////////////////////ThreadGameUpdate 
	class ThreadGameUpdate : public IThread
	{
		void  onExec();

	public:
		void init();
		void release();
	};
	extern ThreadGameUpdate GThreadGameUpdate;



	//////////////////////////////////////////////////////////////////////////ThreadGameRender
	class ThreadGameRender : public IThread
	{
		void onExec();

	public:
		void init();
		void release();

	};
	extern ThreadGameRender GThreadGameRender;


	struct  EngineConfig
	{
		uint	windowWidth;
		uint	windowHeight;
		uint	windowBPP;
		char*	windowTitle;
		bln		fullScreen;
		uint	glMajorVersion;
		uint	glMinorVersion;
	};

	void Engine_Run(const EngineConfig& config);
};