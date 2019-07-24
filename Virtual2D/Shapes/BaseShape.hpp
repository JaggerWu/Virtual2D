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
        
        /// Shape Types
        enum Type
        {
            circle = 0,
        };
        
        /// Mass Data Struct
        struct MassData
        {
            /// The mass of the shape, usually in kilograms.
            float32 mass;
            
            /// The position of the shape's centroid relative to the shape's origin.
            vec2 center;
            
            /// The rotational inertia of the shape about the local origin.
            float32 I;
        };
        
        class BaseShape
        {
        public:
            BaseShape() {}

            /// Efficient Cpp
            virtual ~BaseShape() {}
            
            Type GetType() const;
        
            Type type;
        
            MassData mass;
            
            vec2 position;
            
            vec2 GetPosition();
            
            void Move(vec2& d);
            
            virtual int32 GetChildCount() const = 0;
            
            virtual void ComputeMass(MassData* massData, float32 density) const = 0;
        };
        
        inline Type BaseShape::GetType() const
        {
            return type;
        }
        
        inline vec2 BaseShape::GetPosition()
        {
            return position;
        }
        
        inline void BaseShape::Move(vec2& d)
        {
            position += d;
        }
    }
}

#endif /* BaseShape_h */
