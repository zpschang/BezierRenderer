//
//  collider.cpp
//  Bezier
//
//  Created by 张蒲石 on 2017/6/20.
//  Copyright © 2017年 张蒲石. All rights reserved.
//

#include "collider.hpp"

Color Collider::get_color(Point3d intersection, Point3d direction_norm, Point3d direction_out, Texture& texture, Point2d pos)
{
    // get color from texture
    
    Color color(200, 200, 200);
    
    double rho_d = 0.5, rho_s = 0.5, s = 2;
    Color sum_diff(0, 0, 0), sum_mirr(0, 0, 0);
    double sum_L = 0;
    
    for(Light* light: scene->lights)
        sum_L += light->L;
    
    for(Light* light: scene->lights)
    {
        Point3d direction_light = intersection - light->pos;
        if(direction_light.dot(direction_norm) < 0)
            continue;
        
        Point3d N = direction_norm / length(direction_norm);
        Point3d L = direction_light / length(direction_light);
        Point3d R = direction_out / length(direction_out);
        Point3d V = 2 * N * N.dot(L) - L;
        
        sum_diff += light->L / sum_L * L.dot(N) * light->color;
        sum_mirr += light->L / sum_L * pow(R.dot(V), s) * light->color;
    }
    
    return color*(rho_d * sum_diff + rho_s * sum_mirr);
}
