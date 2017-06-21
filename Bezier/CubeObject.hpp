//
//  CubeObject.hpp
//  Bezier
//
//  Created by 张蒲石 on 2017/6/21.
//  Copyright © 2017年 张蒲石. All rights reserved.
//

#ifndef CubeObject_hpp
#define CubeObject_hpp

#include <stdio.h>
#include "object.hpp"

class CubeObject: public Object
{
public:
    Point3d p1, p2;
    Object::Info find_intersection(Ray ray);
    void find_reflection(Ray ray, Ray& ray_reflection);
    void find_refraction(Ray ray, Ray& ray_refraction);
    void set_attribute(std::string info);
};

#endif /* CubeObject_hpp */
