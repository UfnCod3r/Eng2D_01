#pragma once

#include "XBasic.h"

#include <math.h>

namespace X
{
	const float PI = 3.1415926535;
	const float HALFPI = PI * 0.5;
	const float RAD2DEG = 180.0 / PI;
	const float DEG2RAD = PI / 180.0;
	
	typedef int Deg4;



	inline float Sqr(float x)			{ return x*x;				}
	inline float Sqrt(float x)			{ return ::sqrt(x);			}
	inline float Sin(float x)			{ return ::sin(x);			}
	inline float Cos(float x)			{ return ::cos(x);			}

	inline float Abs(float s)							{ return ::abs(s); }
	inline float Lerp(float a, float b, float alpha)	{ return (b - a) * alpha + a; }

	//////////////////////////////////////////////////////////////////////////Vec2
	struct Vec2
	{
		union
		{
			float xy[2];
			struct { float x, y; };
		};

		inline Vec2(){}
		inline Vec2(float xy);
		inline Vec2(float x, float y);
		inline Vec2(const float xy[2]);


		inline Vec2 operator + (const Vec2&) const;
		inline Vec2 operator - (const Vec2&) const;
		inline Vec2 operator * (const Vec2&) const;
		inline Vec2 operator / (const Vec2&) const;

		inline Vec2& operator += (const Vec2&);
		inline Vec2& operator -= (const Vec2&);
		inline Vec2& operator *= (const Vec2&);
		inline Vec2& operator /= (const Vec2&);


		inline Vec2 operator + (float) const;
		inline Vec2 operator - (float) const;
		inline Vec2 operator * (float) const;
		inline Vec2 operator / (float) const;

		inline Vec2& operator += (float);
		inline Vec2& operator -= (float);
		inline Vec2& operator *= (float);
		inline Vec2& operator /= (float);


		inline Vec2 operator - () const;		//negate
		inline Vec2 operator ~ () const;		//normalize
		inline float operator | (const Vec2&) const;	//dot product
	};
	

	//////////////////////////////////////////////////////////////////////////Vec3
	struct Vec3
	{
		float x, y, z;

		inline Vec3 operator +(const Vec3& v) const;
		inline Vec3 operator -(const Vec3& v) const;
		inline Vec3 operator *(const Vec3& v) const;
		inline Vec3 operator /(const Vec3& v) const;

		inline Vec3 operator +(float s) const;
		inline Vec3 operator -(float s) const;
		inline Vec3 operator *(float s) const;
		inline Vec3 operator /(float s) const;
	};

	//2x2 Column Major Matrix
	struct Mat2x2
	{
		Vec2 column1, column2;

		Mat2x2(){}
		Mat2x2(float e0, float e1, float e2, float e3) : column1(e0, e1), column2(e2, e3) {}
		Mat2x2(const Vec2& c1, const Vec2& c2) : column1(c1), column2(c2) {}

		Mat2x2 operator * (const Mat2x2& m) const
		{
			return Mat2x2(column1 * m.column1.x + column2 * m.column1.y,
						  column1 * m.column2.x + column2 * m.column2.y);
		}
		Vec2 operator * (const Vec2& v) const
		{
			return column1 * v.x + column2 * v.y;
		}

		static Mat2x2 CreateScale(const Vec2& scale)
		{
			return Mat2x2(scale.x, 0, 0, scale.y);
		}
		static Mat2x2 CreateRotationRadian(float angle)
		{
			float s = ::sin(angle);
			float c = ::cos(angle);
			return Mat2x2(c, -s, s, c);
		}

		static const Mat2x2 IDENTITY;
	};


	//3x3 Column Major Matrix
	struct Mat3x3
	{
		Vec3 column1, column2, column3;

		Mat3x3(const Vec3& c1, const Vec3& c2, const Vec3& c3)
			: column1(c1), column2(c2), column3(c3) {}

		Mat3x3 operator * (const Mat3x3& m) const
		{
			return Mat3x3(
				column1*m.column1.x  +  column2*m.column1.y  + column3*m.column1.z ,
				column1*m.column2.x  +  column2*m.column2.y  + column3*m.column2.z ,
				column1*m.column3.x  +  column2*m.column3.y  + column3*m.column3.z  
				);
		}
		Vec3 operator * (const Vec3& v)
		{
			return (column1 * v.x) + (column2 * v.y) + (column3 * v.z);
		}
	};


	struct Transform
	{
		Vec2 column1;	//right direction
		Vec2 column2;	//up direction
		Vec2 column3;	//position

		Transform(float e0, float e1, float e2, float e3, float e4, float e5)
			: column1(e0, e1), column2(e2, e3), column3(e4,  e5) {}
		Transform(const Vec2& c1, const Vec2& c2, const Vec2& c3)
			: column1(c1), column2(c2), column3(c3) {}
		
		static Transform CreatePosition(const Vec2& position)
		{
			/*
			1	0	x
			0	1	y
			*/
			return Transform(1,0, 0,1, position.x, position.y);
		}
		static Transform CreateScale(const Vec2& scale)
		{
			/*
			x	0	0
			0	y	0
			*/
			return Transform(scale.x,0, 0,scale.y, 0,0);
		}
		static Transform CreateRotationRadian(float angle)
		{
			/*
				cos		sin		0
				-sin	cos		0
			*/
			float s = ::sin(angle);
			float c = ::cos(angle);
			return Transform(c,-s, s,c, 0,0);
		}

		Vec2 getPosition() const {  return column3; }

		float getScaleX() const  { return ::sqrt(column1 | column1); }
		float getScaleY() const  { return ::sqrt(column2 | column2); }

		Transform operator * (const Transform& t) const
		{
			return Transform(
				(column1 * t.column1.x) + (column2 * t.column1.y),
				(column1 * t.column2.x) + (column2 * t.column2.y),
				(column1 * t.column3.x) + (column2 * t.column3.y) + column3);
		}
		inline Vec2 operator * (const Vec2& v)
		{
			return (column1 * v.x) + (column2 * v.y) + column3;
		}
	};

	inline Vec2 Abs(const Vec2& v)								{ return Vec2(::abs(v.x),::abs(v.y));	}
	inline Vec2 Lerp(const Vec2& a, const Vec2& b, float alpha) { return (b - a) * alpha + a;			}


	struct Color4B
	{
		union 
		{
			uint rgba;
			struct { byte r, g, b, a; };
		};
	};



	struct Color4F
	{
		union
		{
			float rgba[4];
			struct { float r, g, b, a; };
		};
	};








	//////////////////////////////////////////////////////////////////////////Vec2
	Vec2::Vec2( float xy ) { x = y = xy; }
	Vec2::Vec2( float _x, float _y ) { x = _x;	y = _y;	}
	Vec2::Vec2( const float _xy[2] ) { x = _xy[0];	y = _xy[1]; }

	Vec2 Vec2::operator+( const Vec2& v) const { return Vec2(x + v.x, y + v.y); }
	Vec2 Vec2::operator-( const Vec2& v) const { return Vec2(x - v.x, y - v.y); }
	Vec2 Vec2::operator*( const Vec2& v) const { return Vec2(x * v.x, y * v.y); }
	Vec2 Vec2::operator/( const Vec2& v) const { return Vec2(x / v.x, y / v.y); }

	Vec2& Vec2::operator+=( const Vec2& v) { x += v.x;	y += v.y;	}
	Vec2& Vec2::operator-=( const Vec2& v) { x -= v.x;	y -= v.y;	}
	Vec2& Vec2::operator*=( const Vec2& v) { x *= v.x;	y *= v.y;	}
	Vec2& Vec2::operator/=( const Vec2& v) { x /= v.x;	y /= v.y;	}

	Vec2 Vec2::operator+( float s) const { return Vec2(x + s, y + s); }
	Vec2 Vec2::operator-( float s) const { return Vec2(x - s, y - s); }
	Vec2 Vec2::operator*( float s) const { return Vec2(x * s, y * s); }
	Vec2 Vec2::operator/( float s) const { return Vec2(x / s, y / s); }

	Vec2& Vec2::operator+=( float s) { x += s;	y += s;		}
	Vec2& Vec2::operator-=( float s) { x -= s;	y -= s;		}
	Vec2& Vec2::operator*=( float s) { x *= s;	y *= s;		}
	Vec2& Vec2::operator/=( float s) { x /= s;	y /= s;		}

	float Vec2::operator|(const Vec2& v) const { return x*v.x + y*v.y; }

	Vec2 Vec2::operator - () const { return Vec2(-x, -y); }
	Vec2 Vec2::operator ~ () const
	{
		float f = x*x + y*y;
		if(f > 0.000001f) 
		{
			f = 1.0 / ::sqrt(f);
			return Vec2(x * f, y * f);
		}
		return Vec2(0,0);
	}
};