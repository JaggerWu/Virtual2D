//
//  BaseShape.h
//  Virtual2D
//
//  Created by Jian Wu on 11/07/2019.
//  Copyright © 2019 Jian Wu. All rights reserved.
//

#ifndef BaseShape_h
#define BaseShape_h

#inlude "../Common/Math.hpp"

using namespace Vir2D::Common::Math

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
            
                float32
        };
        
        inline Type BaseShape::GetType() const
        {
            return type;
        }
    }
}

#endif /* BaseShape_h */
