//
//  collider.hpp
//  Bezier
//
//  Created by 张蒲石 on 2017/6/20.
//  Copyright © 2017年 张蒲石. All rights reserved.
//

#ifndef collider_hpp
#define collider_hpp

#include <stdio.h>
#include "scene.hpp"
#include "basic.h"

extern Scene* scene;

class Collider
{
public:
    Collider(){}
    Color get_color(Point3d intersection, Point3d direction_norm, Point3d direction_out, Texture& texture);
};

#endif /* collider_hpp */
