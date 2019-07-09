//
//  Virtual2D.cpp
//  Virtual2D
//
//  Created by Jian Wu on 09/07/2019.
//  Copyright © 2019 Jian Wu. All rights reserved.
//

#include <iostream>
#include "Virtual2D.hpp"
#include "Virtual2DPriv.hpp"

void Virtual2D::HelloWorld(const char * s)
{
    Virtual2DPriv *theObj = new Virtual2DPriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void Virtual2DPriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

