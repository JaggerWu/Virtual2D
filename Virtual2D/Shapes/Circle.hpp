//
//  Circle.hpp
//  Virtual2D
//
//  Created by Jian Wu on 11/07/2019.
//  Copyright © 2019 Jian Wu. All rights reserved.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>

#include "BaseShape.hpp"
#include "/Users/jwu/jwu/Virtual2D/Virtual2D/Common/Math.hpp"

using namespace Vir2D::Common::Math;

namespace Vir2D {
    namespace Shapes {
        class Circle: BaseShape
        {
        public:
            Circle() {}
            float32 radius;
        };
    }
}

#endif /* Circle_hpp */
