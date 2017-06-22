//
//  SphereObject.hpp
//  Bezier
//
//  Created by 张蒲石 on 2017/6/21.
//  Copyright © 2017年 张蒲石. All rights reserved.
//

#ifndef SphereObject_hpp
#define SphereObject_hpp

#include <stdio.h>
#include "object.hpp"

class SphereObject
{
public:
    Point3d center;
    double radius;
    Object::Info find_intersection(Ray ray);
    void set_attribute(std::string info);
    std::string to_string();
};


#endif /* SphereObject_hpp */
