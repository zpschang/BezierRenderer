//
//  Camera.hpp
//  Bezier
//
//  Created by 张蒲石 on 2017/6/21.
//  Copyright © 2017年 张蒲石. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <stdio.h>
#include "basic.h"

class Camera
{
public:
    Camera(Point3d _pos_camera, Point3d _direction_ray, Point3d _direction_vertical, int _w = 640, int _h = 480)
    {
        pos_camera = _pos_camera;
        direction_ray = _direction_ray;
        direction_vertical = _direction_vertical;
        w = _w;
        h = _h;
    }
    Point3d pos_camera, direction_ray, direction_vertical;
    int w, h;
    Ray ray_cast(int u, int v);
};

#endif /* Camera_hpp */
