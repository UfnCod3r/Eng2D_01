#pragma once

#include "XBasic.h"

namespace X
{

	uint	GLCompileVertexShaderNow(const char* shaderSrc, char* outError);
	uint	GLCompileFragmentShaderNow(const char* shaderSrc, char* outError);
	uint	GLCreateProgramNow(const char* vertexShader, const char* fragmentsShader, char* outError);
	uint	GLCreateProgramNow(uint vertexShader, uint fragmentShader, char* outError);

	class Shader
	{
		static uint CurProgHandle;
		uint m_prog;

	public:
		Shader() : m_prog(0) {}

		bln create(const char* vertexShaderSrc, const char* fragmentShaderSrc, char* outError);
		bln create(uint vertexShader, uint fragmentShader, char* outError);

		void release();

		void bind();

		uint getHandle() const { return m_prog; }

		uint getUniformLocation(const char* name);
		uint getAttribLocation(const char* name);

		void setUniform1f(uint location , float value);
		void setUniform2f(uint location , const float* values);
		void setUniform3f(uint location , const float* values);
		void setUniform4f(uint location , const float* values);

		void setUniform1f(const char* name , float value);
		void setUniform2f(const char* name , const float* values);
		void setUniform3f(const char* name , const float* values);
		void setUniform4f(const char* name , const float* values);

		void setUniformMatrix2x2(uint location, const float* values);
		void setUniformMatrix3x3(uint location, const float* values);
		void setUniformMatrix4x4(uint location, const float* values);

		void setUniformMatrix2x2(const char* name, const float* values);
		void setUniformMatrix3x3(const char* name, const float* values);
		void setUniformMatrix4x4(const char* name, const float* values);
	};

	class GLVertexLBuffer
	{
		uint m_handle;

	public:
		GLVertexLBuffer() : m_handle(0) {}

		bln crate(size_t size, void* data, bln dynamic);

		void release();
		
		void bind();

		uint getHandle() const { return m_handle; }
	};
};
