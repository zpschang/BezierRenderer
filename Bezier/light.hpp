//
//  light.hpp
//  Bezier
//
//  Created by 张蒲石 on 2017/6/20.
//  Copyright © 2017年 张蒲石. All rights reserved.
//

#ifndef light_hpp
#define light_hpp

#include <stdio.h>
#include <string>
#include "basic.h"

class Light
{
public:
    double L;
    Point3d pos;
    void set_attribute(std::string info);
};

#endif /* light_hpp */
