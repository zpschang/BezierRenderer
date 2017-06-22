//
//  texture.cpp
//  Bezier
//
//  Created by 张蒲石 on 2017/6/20.
//  Copyright © 2017年 张蒲石. All rights reserved.
//

#include "texture.hpp"

#include <sstream>

void Texture::set_attribute(std::string info)
{
    
    
}

std::string Texture::to_string()
{
    std::stringstream stream;
    stream << "texture\n";
    stream << type << ' ' << state << ' ';
    stream << color.r << ' ' << color.g << ' ' << color.b << ' ';
    stream << diffuse_rate << ' ' << reflect_rate << ' ' << refract_rate;
    return stream.str();
}
