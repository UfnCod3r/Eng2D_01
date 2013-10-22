#pragma once

#include "XBasic.h"

#include <math.h>

namespace X
{
	const float PI = 3.1415926535;
	const float HALFPI = PI * 0.5;
	const float RAD2DEG = 180.0 / PI;
	const float DEG2RAD = PI / 180.0;
	
	//////////////////////////////////////////////////////////////////////////fwd decl
	struct Vec2;
	struct Color4B;
	struct Color4F;

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
		inline float operator | (const Vec2&);	//dot product
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

	float Vec2::operator|(const Vec2& v) { return x*v.x + y*v.y; }

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