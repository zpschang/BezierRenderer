//
//  Camera.cpp
//  Bezier
//
//  Created by 张蒲石 on 2017/6/21.
//  Copyright © 2017年 张蒲石. All rights reserved.
//

#include "Camera.hpp"

Ray Camera::ray_cast(int u, int v)
{
    Point3d t1 = projection(direction_vertical, direction_ray);
    Point3d iv = direction_vertical - t1; // image vertical
    Point3d ih = direction_ray.cross(iv) / length(direction_ray); // image horizonal
    
    Point3d direction = direction_ray + ih * (u-w) / w + iv * (h-v) / h;
    
    return Ray(pos_camera, direction);
}

void Camera::set_attribute(std::string info)
{
    
    
}

std::string Camera::to_string()
{
    std::stringstream stream;
    stream << pos_camera << std::endl << direction_ray << std::endl << direction_vertical << std::endl;
    stream << w << ' ' << h << ' ';
    return stream.str();
}
