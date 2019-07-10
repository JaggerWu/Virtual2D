//
//  Shapes.hpp
//  Virtual2D
//
//  Created by Jian Wu on 10/07/2019.
//  Copyright © 2019 Jian Wu. All rights reserved.
//

#ifndef Shapes_hpp
#define Shapes_hpp

#include <stdio.h>

#include "settings.hpp"
#include "Math.hpp"

using namespace Vir2D::Common::Settings;
using namespace Vir2D::Common::Math;

namespace Vir2D {
    namespace Common {
        namespace Shapes {
            
            struct Circle
            {
                float32 radius;
                vec2 position;
                
                Circle() {}
                
                Circle(const float32& r, const vec2& p)
                {
                    radius = r; position = p;
                }
                
                void Move(const float32& dx, const float32& dy)
                {
                    position += vec2(dx, dy);
                }
            };
        }
    }
}

#endif /* Shapes_hpp */
