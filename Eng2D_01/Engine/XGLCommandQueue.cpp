#include "XGLCommandQueue.h"
#include "XShader.h"

namespace X
{
	GLCommandQueue GGLCommandQueue;


	void GLCommandQueue::Init()
	{
		m_FirstCommand = nullptr;
		m_LastCommand = nullptr;
		m_bufferSeek = m_buffer;
		m_PassingCommand.init();
	}

	void GLCommandQueue::Release()
	{
		m_PassingCommand.release();
	}

	void GLCommandQueue::PassCommands()
	{
		XASSERT(IsRenderThread());

		ICommand* cmd = m_FirstCommand;
		if(cmd == nullptr) return;

		m_PassingCommand.setWaitable();

		do
		{
			cmd->onExec();
			cmd = cmd->m_next;
		}
		while(cmd);

		m_FirstCommand = nullptr;
		m_LastCommand = nullptr;
		m_bufferSeek = m_buffer;
		
		m_PassingCommand.breakWaits(); 
	}

	void GLCommandQueue::CompileShader( Shader* inout_Shader, const char* vShaderSrc, const char* fShaderSrc, Proc_CompileShaderResult opt_Proc )
	{
		m_PassingCommand.waiting();
		PushCommand(new (m_bufferSeek) CMDCompileShader(inout_Shader, vShaderSrc, fShaderSrc));
		m_bufferSeek += sizeof(CMDCompileShader);
		XASSERT(m_bufferSeek < (m_buffer + BUFFER_SIZE));
	}

	void GLCommandQueue::PushCommand( ICommand* cmd )
	{
		if(m_LastCommand)
		{
			m_LastCommand->m_next = cmd;
			m_LastCommand = cmd;
			return;
		}

		m_FirstCommand = m_LastCommand = cmd;
	}


	void GLCommandQueue::CMDCompileShader::onExec()
	{
		m_Shader->CompileNow(m_VShaderSrc, m_FShaderSrc);
	}

}