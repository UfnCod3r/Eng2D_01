#include "XShader.h"
#include "XConsole.h"

#include <GL/glew.h>

namespace X
{
	uint Shader::CurShaderHandle = ~0;

	bln Shader::CompileNow( const char* vShaderSrc, const char* fShaderScr)
	{
		XASSERT(IsRenderThread());
		XASSERT(vShaderSrc && fShaderScr);

		const uint BUFF_SIZE = 8000;
		char lErros[BUFF_SIZE];
		GLint lIsOk = 0;
		GLsizei lLen = 0;
		GLuint lVShader, lFShader;
		
		GConsole.printMessage("#Compiling Shader...  \t%s\n", m_name.cstr());

		m_handle = 0;
		m_compiled = false;

		lVShader = ::glCreateShader(GL_VERTEX_SHADER);
		::glShaderSource(lVShader, 1, (const GLchar**)&vShaderSrc, 0);
		::glCompileShader(lVShader);
		::glGetShaderiv(lVShader, GL_COMPILE_STATUS, &lIsOk);
		if(lIsOk == GL_FALSE)
		{
			::glGetShaderInfoLog(lVShader, BUFF_SIZE,  &lLen, lErros);
			::glDeleteShader(lVShader);
			GConsole.printError("Failed :(\n%s----------------------\n", lErros);
			return false;
		}

		lFShader = ::glCreateShader(GL_FRAGMENT_SHADER);
		::glShaderSource(lFShader, 1, (const GLchar**)&fShaderScr, 0);
		::glCompileShader(lFShader);
		::glGetShaderiv(lFShader, GL_COMPILE_STATUS, &lIsOk);
		if(lIsOk == GL_FALSE)
		{
			::glGetShaderInfoLog(lFShader, BUFF_SIZE,  &lLen, lErros);
			::glDeleteShader(lVShader);
			::glDeleteShader(lFShader);
			GConsole.printError("Failed :(\n%s----------------------\n", lErros);
			return false;
		}

		m_handle = ::glCreateProgram();
		::glAttachShader(m_handle, lVShader);
		::glAttachShader(m_handle, lFShader);
		::glLinkProgram(m_handle);

		::glGetProgramiv(m_handle, GL_LINK_STATUS, &lIsOk);
		if(lIsOk == GL_FALSE)
		{
			::glGetProgramInfoLog(m_handle, BUFF_SIZE, &lLen, lErros);
			::glDeleteProgram(m_handle);
			::glDeleteShader(lVShader);
			::glDeleteShader(lFShader);
			m_handle = 0;
			GConsole.printError("Failed :(\n%s----------------------\n", lErros);
			return false;
		}

		m_compiled = true;
		GConsole.printSuccess("Success.\n");
		return true;
	}

	uint Shader::GetUniformLocation( const char* name )
	{
		XASSERT(name && m_compiled && IsRenderThread());
		return ::glGetUniformLocation(m_handle, name);
	}

	uint Shader::GetAttribLocation( const char* name )
	{
		XASSERT(name && m_compiled && IsRenderThread());
		return ::glGetAttribLocation(m_handle, name);
	}


	void Shader::Release()
	{
		XASSERT(IsRenderThread() && m_handle != CurShaderHandle);
		if(m_handle) ::glDeleteProgram(m_handle);
		m_handle = 0;
		m_compiled = false;
	}

	void Shader::Bind()
	{
		XASSERT(m_compiled && IsRenderThread());

		if(m_handle != CurShaderHandle)
		{
			CurShaderHandle = m_handle;
			::glUseProgram(m_handle);
		}
	}



}