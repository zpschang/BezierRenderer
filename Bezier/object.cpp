//
//  object.cpp
//  Bezier
//
//  Created by 张蒲石 on 2017/6/20.
//  Copyright © 2017年 张蒲石. All rights reserved.
//

#include "object.hpp"

bool Object::is_cross(Point3d p1, Point3d p2, Ray ray)
{
    double tmin[3], tmax[3], mini = -1e100, maxi = 1e100, kmin, flmin, kmax, flmax;
    for(int i = 0; i < 3; i++)
    {
        double t1 = (p1 - ray.start)[i] / ray.direction[i];
        double t2 = (p2 - ray.start)[i] / ray.direction[i];
        tmin[i] = min(t1, t2);
        tmax[i] = max(t1, t2);
        if(tmin[i] > mini)
        {
            mini = tmin[i];
            kmin = i;
            flmin = (t1 < t2) ? -1 : 1;
        }
        if(tmax[i] < maxi)
        {
            maxi = tmax[i];
            kmax = i;
            flmax = (t1 < t2) ? 1 : -1;
        }
    }
    if(mini > maxi || maxi <= 1e-6)
        return false;
    return true;
}
