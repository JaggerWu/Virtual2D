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

struct vec2 {
    vec2() {}
    
    float32 x, y;
    
    void SetZero()
    {
        x = 0.0f;
        y = 0.0f;
    }
    
    void Set(float32 x_, float32 y_)
    {
        x = x_;
        y = y_;
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
    
    
};

struct vec3 {
    vec3() {}
    
    float32 x, y, z;
    
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
};

#endif /* Math_hpp */
