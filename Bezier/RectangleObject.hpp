//
//  RectangleObject.hpp
//  Bezier
//
//  Created by 张蒲石 on 2017/6/21.
//  Copyright © 2017年 张蒲石. All rights reserved.
//

#ifndef RectangleObject_hpp
#define RectangleObject_hpp

#include <stdio.h>
#include "object.hpp"

class RectangleObject: public Object
{
    Info find_intersection(Ray ray);
    void find_reflection(Ray ray, Ray& ray_reflection);
    void find_refraction(Ray ray, Ray& ray_refraction);
    void set_distribute(std::string info);
};

#endif /* RectangleObject_hpp */
