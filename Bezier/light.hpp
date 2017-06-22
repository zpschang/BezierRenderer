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
    Light(Point3d _pos, Color _color = Color(1, 1, 1), double _L = 1): color(_color), pos(_pos)
    {
        L = _L;
    }
    double L;
    Color color;
    Point3d pos;
    void set_attribute(std::string info);
    std::string to_string();
};

#endif /* light_hpp */
