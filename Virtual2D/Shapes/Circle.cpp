//
//  Circle.cpp
//  Virtual2D
//
//  Created by Jian Wu on 11/07/2019.
//  Copyright © 2019 Jian Wu. All rights reserved.
//

#include "Circle.hpp"
#include "BaseShape.hpp"

using namespace Vir2D::Shapes;
using namespace Vir2D::Common::Settings;

void Circle::ComputeMass(MassData *massData, float32 density) const
{
    massData->mass = density * pi * radius * radius;
    massData->center = position;
    
    /// TODO: Add inertia about the local origin
}
