//
//  light.cpp
//  Bezier
//
//  Created by 张蒲石 on 2017/6/20.
//  Copyright © 2017年 张蒲石. All rights reserved.
//

#include "light.hpp"

#include <sstream>

std::string Light::to_string()
{
    std::stringstream stream;
    stream << pos << std::endl;
    stream << color.r << ' ' << color.g << ' ' << color.b << ' ';
    stream << L;
    return stream.str();
}
