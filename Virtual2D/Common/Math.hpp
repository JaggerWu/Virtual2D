//
//  Math.hpp
//  Virtual2D
//
//  Created by Jian Wu on 09/07/2019.
//  Copyright © 2019 Jian Wu. All rights reserved.
//

#ifndef Math_hpp
#define Math_hpp

#include <stdio.h>
#include <math.h>
#include <settings.hpp>

using namespace Vir2D::Common::Settings;

namespace Vir2D {
    namespace Common {
        namespace Math {
            
            inline bool FloatIsValid(float32 x)
            {
                return isfinite(x);
            }
            
            struct vec2
            {
                float32 x, y;
                
                /// Constructor with nothing
                vec2() {}
                
                /// Constructor with init x, y value. Equivalent to
                /// vec2(float32 xInit, float32 yInit)
                /// {
                ///    x = xInit; y = yInit;
                /// }
                vec2(float32 xInit, float32 yInit): x(xInit), y(yInit) {}
                
                void SetZero()
                {
                    x = 0.0f; y = 0.0f;
                }
                
                void Set(float32 x_, float32 y_)
                {
                    x = x_; y = y_;
                }
                
                vec2 operator -() const
                {
                    vec2 v;
                    v.Set(-x, -y);
                    return v;
                }
                
                void operator += (const vec2& v)
                {
                    x += v.x; y += v.y;
                }
                
                void operator -= (const vec2& v)
                {
                    x -= v.x; y -= v.y;
                }
                
                void operator *= (const float32 i)
                {
                    x *= i; y *= i;
                }
                
                void operator /= (const float32 i)
                {
                    x /= i; y /= i;
                }
                
                bool IsValid()
                {
                    return FloatIsValid(x) && FloatIsValid(y);
                }
                
                float32 Length() const
                {
                    return sqrt(x * x + y * y);
                }
                
                float32 Normalize()
                {
                    float32 length = Length();
                    if (length < FLT_EPSILON)
                    {
                        return 0.0f;
                    }
                    x /= length;
                    y /= length;
                    
                    return  length;
                }
                
                vec2 Skew() const
                {
                    return vec2(-y, x);
                }
            };
            
            struct vec3 {
                float32 x, y, z;
                
                vec3() {}
                
                vec3(float32 xInit, float32 yInit, float32 zInit): x(xInit), y(yInit), z(zInit) {}
                
                void SetZero()
                {
                    x = 0.0f; y = 0.0f; z = 0.0f;
                }
                
                void Set(float32 x_, float32 y_, float32 z_)
                {
                    x = x_; y = y_; z = z_;
                }
                
                vec3 operator -() const
                {
                    vec3 v;
                    v.Set(-x, -y, -z);
                    return v;
                }
                
                void operator += (const vec3& v)
                {
                    x += v.x; y += v.y; z += v.z;
                }
                
                void operator -= (const vec3& v)
                {
                    x -= v.x; y -= v.y; z -= v.z;
                }
                
                void operator *= (const float32 i)
                {
                    x *= i; y *= i; z *= 1;
                }
                
                void operator /= (const float32 i)
                {
                    x /= i; y /= i; z /= i;
                }
                
                bool IsValid()
                {
                    return FloatIsValid(x) && FloatIsValid(y) && FloatIsValid(z);
                }
                
                float32 Length() const
                {
                    return sqrt(x * x + y * y + z * z);
                }
                
                float32 Normalize()
                {
                    float32 length = Length();
                    if (length < FLT_EPSILON)
                    {
                        return 0.0f;
                    }
                    x /= length;
                    y /= length;
                    z /= length;
                    
                    return  length;
                }
            };
            
            struct mat2
            {
                vec2 ex, ey;
                
                mat2() {}
                
                mat2(const float32& a11,
                     const float32& a12,
                     const float32& a21,
                     const float32& a22)
                {
                    ex = vec2(a11, a12);
                    ey = vec2(a21, a22);
                }
                
                mat2(const vec2& r1, const vec2& r2)
                {
                    ex = r1; ey = r2;
                }
                
                void Set(const vec2& r1, const vec2& r2)
                {
                    ex = r1;ey = r2;
                }
                
                void SetIdentity()
                {
                    ex = vec2(1.0f, 0.0f);
                    ey = vec2(0.0f, 1.0f);
                }
                
                void SetZero()
                {
                    ex = vec2(0.0f, 0.0f);
                    ey = vec2(0.0f, 0.0f);
                }
                
                mat2 T()
                {
                    return mat2(ex.x, ey.x, ex.y, ey.y);
                }
                
                mat2 GetInverse() const;
                
                vec2 Solve(const vec2& b) const;
            };
            
            struct mat3
            {
                vec3 ex, ey, ez;
                
                mat3() {}
                
                mat3(const float32& a11,
                     const float32& a12,
                     const float32& a13,
                     const float32& a21,
                     const float32& a22,
                     const float32& a23,
                     const float32& a31,
                     const float32& a32,
                     const float32& a33)
                {
                    ex = vec3(a11, a12, a13);
                    ey = vec3(a21, a22, a23);
                    ez = vec3(a31, a32, a33);
                }
                
                mat3(const vec3& r1, const vec3& r2, const vec3& r3)
                {
                    ex = r1; ey = r2; ez = r3;
                }
                
                void Set(const vec3& r1, const vec3& r2, const vec3& r3)
                {
                    ex = r1; ey = r2; ez = r3;
                }
                
                void SetIdentity()
                {
                    ex = vec3(1.0f, 0.0f, 0.0f);
                    ey = vec3(0.0f, 1.0f, 0.0f);
                    ez = vec3(0.0f, 0.0f, 1.0f);
                }
                
                void SetZero()
                {
                    ex = vec3(0.0f, 0.0f, 0.0f);
                    ey = vec3(0.0f, 0.0f, 0.0f);
                    ez = vec3(0.0f, 0.0f, 0.0f);
                }
                
                mat3 T()
                {
                    return mat3(ex.x, ey.x, ez.x, ex.y, ey.y, ez.y, ex.z, ey.z, ez.z);
                }
            };
            
            struct Rot
            {
                /// sin and cos
                float32 s, c;
                
                Rot() {}
                
                /// Usage of explicit, you can visit
                /// https://www.cnblogs.com/this-543273659/archive/2011/08/02/2124596.html
                explicit Rot(float32 angle)
                {
                    s = sinf(angle);
                    c = sinf(angle);
                }
                
                void Set(float32 angle)
                {
                    s = sinf(angle);
                    c = sinf(angle);
                }
                
                void SetIdentity()
                {
                    s = 0.0f;
                    c = 1.0f;
                }
                
                float32 GetAngle() const
                {
                    return atan2f(c, s);
                }
                
            };
            
            inline vec2 operator + (const vec2& a, const vec2& b)
            {
                return vec2(a.x + b.x, a.y + b.y);
            }
            
            inline vec2 operator - (const vec2& a, const vec2& b)
            {
                return vec2(a.x - b.x, a.y - b.y);
            }
            
            inline bool operator == (const vec2& a, const vec2& b)
            {
                return (a.x == b.x && a.y == b.y);
            }
            
            inline float32 vecDot(const vec2& a, const vec2& b)
            {
                return a.x * b.x + a.y * b.y;
            }
            
            inline float32 vecDot(const vec3& a, const vec3& b)
            {
                return a.x * b.x + a.y * b.y + a.z * b.z;
            }
            
            template <typename T>
            inline T v2Abs(T& a)
            {
                return a > T(0) ? a : -a;
            }
            
            inline vec2 v2Abs(const vec2& a)
            {
                return vec2(v2Abs(a.x), v2Abs(a.y));
            }
            
            inline mat2 v2Abs(const mat2& A)
            {
                return mat2(v2Abs(A.ex), v2Abs(A.ey));
            }
            
            template <typename T>
            inline T v2Min(const T& a, const T& b)
            {
                return a < b ? a : b;
            }
            
            inline vec2 v2Min(const vec2& a, const vec2& b)
            {
                return vec2(v2Min(a.x, b.x), v2Min(a.y, b.y));
            }
            
            template <typename T>
            inline T v2Max(const T& a, const T& b)
            {
                return a > b ? a : b;
            }
            
            inline vec2 v2Max(const vec2& a, const vec2& b)
            {
                return vec2(v2Max(a.x, b.x), v2Max(a.y, b.y));
            }
            
            template <typename T>
            inline T Swap(T& a, T& b)
            {
                T tmp = a;
                a = b;
                b = tmp;
            }
        }
    }
}

#endif /* Math_hpp */
