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
    void set_attribute(std::string info);
    std::string to_string();
};

#endif /* CubeObject_hpp */
