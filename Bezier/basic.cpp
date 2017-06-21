//
//  basic.cpp
//  Bezier
//
//  Created by 张蒲石 on 2017/6/21.
//  Copyright © 2017年 张蒲石. All rights reserved.
//

#include <stdio.h>
#include "basic.h"

Point3d projection(Point3d x, Point3d y)
{
    return x.dot(y) / y.dot(y) * y;
}
