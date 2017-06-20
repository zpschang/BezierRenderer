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
#include "basic.h"
#include "texture.hpp"

class Object
{
public:
    Texture texture;
    virtual void find_intersection(Ray ray, double& k, Point3d& direction_norm) = 0;
    virtual void find_reflection(Ray ray, Ray& ray_reflection) = 0;
    virtual void find_refraction(Ray ray, Ray& ray_refraction) = 0;
    virtual void set_distribute(char *info) = 0;
};

#endif /* object_hpp */
