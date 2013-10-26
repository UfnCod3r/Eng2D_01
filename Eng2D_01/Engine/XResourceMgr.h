#pragma once

#include "XArray.h"

namespace X
{
	//////////////////////////////////////////////////////////////////////////fwd decl
	class Shader;
	class Texture;

	class ResourceMgr
	{

		Vector<Shader*>		m_Shaders;
		Vector<Texture*>	m_Textures;

	public:

		void Init();
		void Release();

		Shader*		LoadShader(const char* filename);
		Texture*	LoadTexture(const char* filename);
		
		Shader*		GetShader(const char* filename);
		Texture*	GetTexture(const char* filename);
	};
	extern ResourceMgr GResourceMgr;
};

