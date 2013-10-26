#pragma once

#include "XName.h"

namespace X
{
	//////////////////////////////////////////////////////////////////////////Shader
	class IShader
	{
		IShader(){}
		~IShader(){}
	public:
		virtual void Release(){}
		virtual void Reload(){}
		virtual uint GetAttribLocation(const char*){ return 0; }
		virtual uint GetUniformLocation(const char*){ return 0; }
		virtual const Name& GetName(){ return Name(); }
	};


	//////////////////////////////////////////////////////////////////////////Shader
	class Shader
	{
		static uint CurShaderHandle;

		uint			m_handle;
		Name			m_name;
		volatile bln	m_compiled;

	public:
		Shader(const char* sFileName) : m_handle(0), m_name(sFileName), m_compiled(false) {}

		bln CompileNow(const char* vShaderSrc, const char* fShaderScr);

		void Release();
		void Bind();

		uint GetHandle() const		{ return m_handle;		}
		const Name&	GetName() const { return m_name;		}
		uint isCompiled() const		{ return m_compiled;	}

		uint GetUniformLocation(const char* name);
		uint GetAttribLocation(const char* name);
	};

};