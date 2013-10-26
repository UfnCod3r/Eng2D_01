#pragma once

#include "XThreading.h"

namespace X
{
	//////////////////////////////////////////////////////////////////////////fwd decl
	class Shader;

	typedef void (*Proc_CompileShaderResult)(Shader* pShader, bln success);


	//////////////////////////////////////////////////////////////////////////GLCommandQueue
	class GLCommandQueue
	{
		struct ICommand
		{
			ICommand* m_next;
			virtual void onExec() = 0;
		};

		struct CMDCompileShader : ICommand
		{
			Shader*			m_Shader;
			const char*		m_VShaderSrc;
			const char*		m_FShaderSrc;


			CMDCompileShader(Shader* pShader, const char* vShaderSrc, const char* fShaderSrc)
				: m_Shader(pShader), m_VShaderSrc(vShaderSrc), m_FShaderSrc(fShaderSrc) {}

			void onExec();
		};


		struct CMDCreateTexture : ICommand
		{

		};


		static const uint BUFFER_SIZE = 512*512;
		
		ICommand*	m_FirstCommand;
		ICommand*	m_LastCommand;
		char*		m_bufferSeek;
		WaitEvent	m_PassingCommand;
		char		m_buffer[BUFFER_SIZE];



		void		PushCommand(ICommand* cmd);


	public:

		void Init();
		void Release();


		void CompileShader(Shader* inout_Shader, const char* vShaderSrc, const char* fShaderSrc, Proc_CompileShaderResult opt_Proc);
		

		void PassCommands();

	};

	extern GLCommandQueue GGLCommandQueue;

};