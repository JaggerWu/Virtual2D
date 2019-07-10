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
        }
    }
}

#endif /* Math_hpp */
