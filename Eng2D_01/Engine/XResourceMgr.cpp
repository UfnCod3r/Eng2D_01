#include "XResourceMgr.h"
#include "XFileMgr.h"
#include "XString.h"
#include "XConsole.h"
#include "XShader.h"
#include "XGLCommandQueue.h"

namespace X
{
	ResourceMgr GResourceMgr;


	static const char VERTEX_SHADER_TAG[]		= "[vertexshader]";
	static const char FRAGMENT_SHADER_TAG[]		= "[fragmentshader]";



	Shader* ResourceMgr::LoadShader( const char* filename )
	{
		XASSERT(filename);

		uint lFileSize = 0;
		uint lByteRead = 0;

		//currently exist -------
		Shader* lShader = GetShader(filename);
		if(lShader) return lShader;

		//get file size -------
		if(!GFileManager.fileGetSize(filename, lFileSize)) return nullptr;

		//read file -----------
		char* lFileContent = (char*)GTempAllocator.alloc(lFileSize+1);
		GFileManager.fileOpenReadFull(filename, lFileContent, lByteRead);
		if(lFileSize != lByteRead) return nullptr;
		lFileContent[lFileSize] = '\0';

		//find shader tags ---------
		char* lVShaderTag = StrFindFirstStrI(lFileContent, VERTEX_SHADER_TAG);
		char* lFShaderTag = StrFindFirstStrI(lFileContent, FRAGMENT_SHADER_TAG);
		if(lFShaderTag == nullptr || lVShaderTag == nullptr)
			return nullptr;

		//Separating the Shaders ------
		if(lVShaderTag < lFShaderTag) 
			lFShaderTag[0] = '\0';
		else 
			lVShaderTag[0] = '\0';

		lVShaderTag += XARRAY_LENGTH(VERTEX_SHADER_TAG);
		lFShaderTag += XARRAY_LENGTH(FRAGMENT_SHADER_TAG);

		
		lShader = new Shader(filename);

		//Is Render Thread, Compile Now -----------
		if(IsRenderThread())
		{
			if(lShader->CompileNow(lVShaderTag, lFShaderTag) == false)
			{
				delete lShader;
				return nullptr;
			}

			m_Shaders.push(lShader);
			return lShader;
		}

		//push to GLCommandQueue, will be compiled as soon as possible ---------
		m_Shaders.push(lShader);
		GGLCommandQueue.CompileShader(lShader, lVShaderTag, lFShaderTag, nullptr);
		return lShader;
	}

	Texture* ResourceMgr::LoadTexture( const char* filename )
	{

	}

	void ResourceMgr::Init()
	{

	}

	void ResourceMgr::Release()
	{
		m_Shaders.clear();
		m_Textures.clear();
	}

	Shader* ResourceMgr::GetShader( const char* filename )
	{
		XASSERT(filename);

		auto lHash = StrHash(filename);
		for (uint i = 0; i < m_Shaders.length(); i++)
		{
			if(m_Shaders[i]->GetName().hash() == lHash)
				return m_Shaders[i];
		}
		return nullptr;
	}

	Texture* ResourceMgr::GetTexture( const char* filename )
	{
		return nullptr;
	}


}