//
//  BlockAllocator.cpp
//  Virtual2D
//
//  Created by Jian Wu on 20/07/2019.
//  Copyright © 2019 Jian Wu. All rights reserved.
//

#include "BlockAllocator.hpp"

using namespace Vir2D::Common;

int32 BlockAllocator::s_blockSizes[blockSizes] = {
    16, 32, 64, 128, 256,
};
