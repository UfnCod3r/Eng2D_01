#pragma once

#include "XBasic.h"
#include "XShader.h"

namespace X
{
	//////////////////////////////////////////////////////////////////////////fwd decl
	struct Vec2;
	struct Vec3;
	struct Mat2x2;
	struct Mat3x3;
	struct Transform;


	enum class EPrimitiveType
	{
		POINTS = 0x0000,		//GL_POINTS
		LINES =  0x0001,		//GL_LINES
		LINE_LOOP = 0x0002,		//GL_LINE_LOOP
		LINE_STRIP = 0x0003,	//GL_LINE_STRIP
		TRIANGLES = 0x0004		//GL_TRIANGLES
	};

	enum class EShaderInputType : uint
	{
		FLOAT, VEC2, VEC3, VEC4
	};




	class VertexBuffer
	{
		uint	m_handle;
		uint	m_size;

	public:
		VertexBuffer() : m_handle(0), m_size(0) {}

		void Bind();
		void Create(uint size, void* data, bln isDynamic);
		void Release();
	};










	struct ShaderInputData
	{
		VertexBuffer*		m_VertexBuffer;
		EPrimitiveType		m_PrimitiveType;
		uint				m_VertexCount;
		uint				m_InputSize;
		uint				m_InputCount;
		const char*			m_InputsName[8];
		EShaderInputType		m_InputsType[8];
	};




	class Renderer
	{
		Shader*				m_CurShader;
		ShaderInputData*	m_CurInput;

	public:
		void SetRenderData(Shader* pShader, ShaderInputData* pShaderInput);

		void UpdateUniform(const char* name, float f);
		void UpdateUniform(const char* name, const Vec2& vec2);
		void UpdateUniform(const char* name, const Mat2x2& mat);
		void UpdateUniform(const char* name, const Transform& mat3x32);

		void Draw();
	};
	extern Renderer GRenderer;
};