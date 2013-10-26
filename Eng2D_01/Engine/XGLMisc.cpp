#include "XGLMisc.h"
#include "XEngineThreads.h"
#include <gl\glew.h>

namespace X
{
	/*
	GLShader GLCompileVertexShaderNow( const char* shaderSrc, char* outError )
	{
		XASSERT(ThisThread_ID() == GThreadGameRender.getId());
		XASSERT(shaderSrc);

		GLuint lShader = ::glCreateShader(GL_VERTEX_SHADER);
		::glShaderSource(lShader, 1, (const GLchar**)&shaderSrc, 0);
		::glCompileShader(lShader);
		GLint lIsOk = 0;
		::glGetShaderiv(lShader, GL_COMPILE_STATUS, &lIsOk);
		if(lIsOk == GL_FALSE)
		{
			if(outError)
			{
				const uint BUFF_SIZE = 4096;
				GLsizei lLen  =0;
				::glGetShaderInfoLog(lShader, BUFF_SIZE,  &lLen, outError);
			}
			return 0;
		}
		return lShader;
	}

	GLShader GLCompileFragmentShaderNow( const char* shaderSrc, char* outError )
	{
		XASSERT(ThisThread_ID() == GThreadGameRender.getId());
		XASSERT(shaderSrc);

		GLuint lShader = ::glCreateShader(GL_FRAGMENT_SHADER);
		::glShaderSource(lShader, 1, (const GLchar**)&shaderSrc, 0);
		::glCompileShader(lShader);
		GLint lIsOk = 0;
		::glGetShaderiv(lShader, GL_COMPILE_STATUS, &lIsOk);
		if(lIsOk == GL_FALSE)
		{
			if(outError)
			{
				const uint BUFF_SIZE = 4096;
				GLsizei lLen = 0;
				::glGetShaderInfoLog(lShader, BUFF_SIZE,  &lLen, outError);
			}
			return 0;
		}
		return lShader;
	}
	GLProgram GLCreateProgramNow( GLShader vertexShader, GLShader fragmentShader, char* outError )
	{
		XASSERT(ThisThread_ID() == GThreadGameRender.getId());
		XASSERT(outError);

		GLuint lProg = ::glCreateProgram();
		::glAttachShader(lProg, vertexShader);
		::glAttachShader(lProg, fragmentShader);
		::glLinkProgram(lProg);
		
		GLint lIsOk;
		::glGetProgramiv(lProg, GL_LINK_STATUS, &lIsOk);
		if(lIsOk == GL_FALSE)
		{
			if(outError)
			{
				const uint BUFF_SIZE = 40960;
				GLsizei lLen = 0;
				::glGetProgramInfoLog(lProg, BUFF_SIZE, &lLen, outError);
			}
			return 0;
		}
		return lProg;
	}

	GLProgram GLCreateProgramNow( const char* vertexShader, const char* fragmentsShader, char* outError )
	{
		XASSERT(ThisThread_ID() == GThreadGameRender.getId());
		return GLCreateProgramNow(GLCompileVertexShaderNow(vertexShader, 0), GLCompileFragmentShaderNow(fragmentsShader, 0), outError);
	}
	*/


	
}
	 