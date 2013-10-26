#include "XRenderer.h"

#include <gl\glew.h>

namespace X
{



// 	void Renderer::SetInputData( ShaderInputData* data )
// 	{
// 
// //@WhiteBoard
// // 		enum class EShaderDataType : uint
// // 		{
// // 			Float = 0, Vec2, Vec3, Vec4
// // 		};
// 		const uint	LUTShaderDataTypeSize[] = {sizeof(float), sizeof(float[2]), sizeof(float[3]), sizeof(float[4])};
// 		const uint	LUTShaderDataTypeCount[] = {1,2,3,4};
// 		const uint	LUTToGLType[] = {GL_FLOAT, GL_FLOAT, GL_FLOAT, GL_FLOAT};
// 
// 		GLuint lOffset = 0;
// 		GLuint lAttribLocation = 0;
// 		GLuint lSize = 0;
// 		GLuint lType = 0;
// 		GLuint lStride = m_CurInput->m_InputSize;
// 
// 		m_CurInput = data;
// 		m_CurInput->m_VertexBuffer->Bind();
// 		
// 		//0, 2, GL_FLOAT, false, sizeof(Vertex), 0
// 		//0, 2, GL_FLOAT, false, sizeof(Vertex), sizeof(float2)
// 
// 		for (uint i = 0; i < m_CurInput->m_InputCount; i++)
// 		{
// 			const char* lInputName = m_CurInput->m_InputsName[i];
// 			uint lInputType = (uint)m_CurInput->m_InputsType[i];
// 
// 			lAttribLocation = m_CurShader->GetAttribLocation(lInputName);
// 			lSize = LUTShaderDataTypeCount[lInputType];
// 			lType = LUTToGLType[lInputType];
// 
// 			::glEnableVertexAttribArray(lAttribLocation);
// 			::glVertexAttribPointer(lAttribLocation, lSize, lType, false, lStride, (GLvoid*)lOffset);
// 			lOffset += LUTShaderDataTypeSize[lInputType];
// 		}
// 	}


	Renderer GRenderer;

	/*
	void Renderer::SetRenderData( Shader* pShader, ShaderInputData* pShaderInput )
	{
		XASSERT(pShader && pShaderInput);
		XASSERT(IsRenderThread());

		const uint	LUTShaderDataTypeSize[] = {sizeof(float), sizeof(float[2]), sizeof(float[3]), sizeof(float[4])};
		const uint	LUTShaderDataTypeCount[] = {1, 2, 3, 4};
		const uint	LUTToGLType[] = {GL_FLOAT, GL_FLOAT, GL_FLOAT, GL_FLOAT};

		m_CurShader = pShader;
		m_CurShader->Bind();	//bind shader
		m_CurInput = pShaderInput;
		m_CurInput->m_VertexBuffer->Bind();	//bind vertex buffer

		GLuint lOffset = 0;
		GLuint lAttribLocation = 0;
		GLuint lSize = 0;
		GLuint lType = 0;
		GLuint lStride = m_CurInput->m_InputSize;

		//generate input layout
		for (uint i = 0; i < m_CurInput->m_InputCount; i++)
		{
			const char* lInputName = m_CurInput->m_InputsName[i];
			uint lInputType = (uint)m_CurInput->m_InputsType[i];

			lAttribLocation = m_CurShader->GetAttribLocation(lInputName);
			lSize = LUTShaderDataTypeCount[lInputType];
			lType = LUTToGLType[lInputType];

			::glEnableVertexAttribArray(lAttribLocation);
			::glVertexAttribPointer(lAttribLocation, lSize, lType, false, lStride, (void*)lOffset);
			lOffset += LUTShaderDataTypeSize[lInputType];
		}
	}

	void Renderer::Draw()
	{
		XASSERT(IsRenderThread());

		if(m_CurShader)
			::glDrawArrays((GLenum)m_CurInput->m_PrimitiveType, 0, m_CurInput->m_VertexCount);
	}
	*/

	void VertexBuffer::Bind()
	{
		::glBindBuffer(GL_ARRAY_BUFFER, m_handle);
	}

	void VertexBuffer::Create( uint size, void* data, bln isDynamic )
	{
		::glGenBuffers(1, &m_handle);
		::glBindBuffer(GL_ARRAY_BUFFER, m_handle);
		::glBufferData(GL_ARRAY_BUFFER, size, data, isDynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
		::glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void VertexBuffer::Release()
	{
		if(m_handle) ::glDeleteBuffers(1, &m_handle);
		m_handle = 0;
	}

}