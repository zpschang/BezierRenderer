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
    void set_attribute(std::string info);
};

#endif /* RectangleObject_hpp */
