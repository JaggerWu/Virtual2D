//
//  Math.cpp
//  Virtual2D
//
//  Created by Jian Wu on 09/07/2019.
//  Copyright © 2019 Jian Wu. All rights reserved.
//

#include "Math.hpp"

namespace Vir2D {
    namespace Common {
        namespace Math {
            
            mat2 mat2::GetInverse() const
            {
                float32 a = ex.x, b = ex.y, c = ey.x, d = ey.y;
                float32 det = a * d - b * c;
                
                if (det != 0.0f)
                {
                    det = 1.0f / det;
                }
                
                mat2 InverseMat;
                InverseMat.Set(vec2(d * det, -b * det), vec2(-c * det, a * det));
                
                return InverseMat;
            }
            
            /// Solve A * x = B
            vec2 mat2::Solve(const vec2& B) const
            {
                float32 a = ex.x, b = ex.y, c = ey.x, d = ey.y;
                float32 det = a * d - b * c;
                
                if (det != 0.0f)
                {
                    det = 1.0f / det;
                }
                
                float32 x_1 = (d * B.x - b * B.y) * det;
                float32 x_2 = (a * B.y - c * B.x) * det;
                
                return vec2(x_1, x_2);
            }
        }
    }
}
