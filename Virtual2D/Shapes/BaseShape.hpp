//
//  BaseShape.h
//  Virtual2D
//
//  Created by Jian Wu on 11/07/2019.
//  Copyright © 2019 Jian Wu. All rights reserved.
//

#ifndef BaseShape_h
#define BaseShape_h

#include "/Users/jwu/jwu/Virtual2D/Virtual2D/Common/Math.hpp"

using namespace Vir2D::Common::Math;

namespace Vir2D {
    namespace Shapes {
        enum Type
        {
            circle = 0,
        };
        
        class BaseShape
        {
        public:
            Type GetType() const;
        
            Type type;
        
            float32 mass;
            
            vec2 position;
            
            vec2 GetPosition();
            
            void move(vec2& d);
        };
        
        inline Type BaseShape::GetType() const
        {
            return type;
        }
        
        inline vec2 BaseShape::GetPosition()
        {
            return position;
        }
        
        inline void BaseShape::move(vec2& d)
        {
            position += d;
        }
    }
}

#endif /* BaseShape_h */
