//
//  object.hpp
//  Bezier
//
//  Created by 张蒲石 on 2017/6/20.
//  Copyright © 2017年 张蒲石. All rights reserved.
//

#ifndef object_hpp
#define object_hpp

#include <stdio.h>
#include <string>
#include "basic.h"
#include "texture.hpp"

class Object
{
public:
    Texture texture;
    struct Info
    {
        double k;
        Point3d direction_norm;
        Point2d pos;
        int is_in;
    };
    virtual Info find_intersection(Ray ray) = 0;
    virtual void set_attribute(std::string info) = 0;
    virtual std::string to_string() = 0;
};

#endif /* object_hpp */
