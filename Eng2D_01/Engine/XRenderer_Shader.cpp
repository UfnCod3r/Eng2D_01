#include "XRenderer.h"
#include <GL/glew.h>

namespace X
{
	/*
	uint Shader::CurShaderHandle;


	void Shader::bind()
	{
		XASSERT(ThisThread_ID() == GThreadGameRender.getId());

		if(CurShaderHandle != m_handle)
		{
			CurShaderHandle = m_prog;
			::glUseProgram(m_prog);
		}
	}

	bln Shader::create( uint vertexShader, uint fragmentShader, char* outError )
	{
		XASSERT(ThisThread_ID() == GThreadGameRender.getId());
		XASSERT(outError);

		const uint BUFF_SIZE = 4096;
		GLsizei lLen = 0;
		GLint lIsOk;

		m_prog = ::glCreateProgram();
		::glAttachShader(m_prog, vertexShader);
		::glAttachShader(m_prog, fragmentShader);
		::glLinkProgram(m_prog);

		::glGetProgramiv(m_prog, GL_LINK_STATUS, &lIsOk);
		if(lIsOk == GL_FALSE)
		{
			if(outError) ::glGetProgramInfoLog(m_prog, BUFF_SIZE, &lLen, outError);
			m_prog = 0;
			return false;
		}
		return true;
	}

	bln Shader::create( const char* vertexShaderSrc, const char* fragmentShaderSrc, char* outError )
	{
		XASSERT(ThisThread_ID() == GThreadGameRender.getId());
		XASSERT(vertexShaderSrc && fragmentShaderSrc);

		const uint BUFF_SIZE = 4096;
		GLint lIsOk = 0;
		GLsizei lLen = 0;
		GLuint lVShader, lFShader;

		lVShader = ::glCreateShader(GL_VERTEX_SHADER);
		::glShaderSource(lVShader, 1, (const GLchar**)&vertexShaderSrc, 0);
		::glCompileShader(lVShader);
		::glGetShaderiv(lVShader, GL_COMPILE_STATUS, &lIsOk);
		if(lIsOk == GL_FALSE)
		{
			if(outError) ::glGetShaderInfoLog(lVShader, BUFF_SIZE,  &lLen, outError);
			return false;
		}

		lFShader = ::glCreateShader(GL_FRAGMENT_SHADER);
		::glShaderSource(lFShader, 1, (const GLchar**)&fragmentShaderSrc, 0);
		::glCompileShader(lFShader);
		::glGetShaderiv(lFShader, GL_COMPILE_STATUS, &lIsOk);
		if(lIsOk == GL_FALSE)
		{
			if(outError) ::glGetShaderInfoLog(lFShader, BUFF_SIZE,  &lLen, outError);
			return false;
		}

		return this->create(lVShader, lFShader, outError);
	}

	void Shader::Release()
	{
		XASSERT(ThisThread_ID() == GThreadGameRender.getId());
		if(m_handle) ::glDeleteProgram(m_handle);
	}

	uint Shader::GetUniformLocation( const char* name )
	{
		XASSERT(ThisThread_ID() == GThreadGameRender.getId());
		return ::glGetUniformLocation(m_handle, name);
	}

	uint Shader::GetAttribLocation( const char* name )
	{
		XASSERT(ThisThread_ID() == GThreadGameRender.getId());
		return ::glGetAttribLocation(m_handle, name);
	}
	*/

// 	void Shader::setUniform1f( uint location , float value )
// 	{
// 		::glUniform1f(location, value);
// 	}
// 	void Shader::setUniform1f( const char* name , float value )
// 	{
// 		setUniform1f(getUniformLocation(name), value);
// 	}
// 	void Shader::setUniform2f( uint location , const float* values )
// 	{
// 		::glUniform2fv(location, 1, values);
// 	}
// 	void Shader::setUniform2f( const char* name , const float* values )
// 	{
// 		setUniform2f(getUniformLocation(name), values);
// 	}
// 	void Shader::setUniform3f( uint location , const float* values )
// 	{
// 		::glUniform3fv(location, 1, values);
// 	}
// 	void Shader::setUniform3f( const char* name , const float* values )
// 	{
// 		setUniform3f(getUniformLocation(name), values);
// 	}
// 	void Shader::setUniform4f( uint location , const float* values )
// 	{
// 		::glUniform4fv(location, 1, values);
// 	}
// 	void Shader::setUniform4f( const char* name , const float* values )
// 	{
// 		setUniform4f(getUniformLocation(name), values);
// 	}




// 	bln GLVertexLBuffer::crate( size_t size, void* data, bln dynamic )
// 	{
// 		XASSERT(ThisThread_ID() == GThreadGameRender.getId());
// 		::glGenBuffers(1, &m_handle);
// 		::glBindBuffer(GL_ARRAY_BUFFER, m_handle);
// 		::glBufferData(GL_ARRAY_BUFFER, size, data, dynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
// 		::glBindBuffer(GL_ARRAY_BUFFER, 0);
// 		return true;
// 	}
// 
// 	void GLVertexLBuffer::release()
// 	{
// 		XASSERT(ThisThread_ID() == GThreadGameRender.getId());
// 		if(m_handle) ::glDeleteBuffers(1, &m_handle);
// 	}
// 
// 	void GLVertexLBuffer::bind()
// 	{
// 		XASSERT(ThisThread_ID() == GThreadGameRender.getId());
// 		::glBindBuffer(GL_ARRAY_BUFFER, m_handle);
// 	}

}