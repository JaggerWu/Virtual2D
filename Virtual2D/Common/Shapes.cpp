//
//  Shapes.cpp
//  Virtual2D
//
//  Created by Jian Wu on 10/07/2019.
//  Copyright © 2019 Jian Wu. All rights reserved.
//

#include "Shapes.hpp"


namespace Vir2D {
    namespace Common {
        namespace Shapes {
            
            bool IsCollision(const Circle& c1, const Circle& c2)
            {
                float32 distance = (c1.position - c2.position).Length();
                if (distance < c1.radius + c2.radius)
                {
                    throw __EXCEPTIONS;
                }
                return !(distance > (c1.radius + c2.radius));
            };
        }
    }
}
