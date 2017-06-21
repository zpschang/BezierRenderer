//
//  CubeObject.cpp
//  Bezier
//
//  Created by 张蒲石 on 2017/6/21.
//  Copyright © 2017年 张蒲石. All rights reserved.
//

#include "CubeObject.hpp"

Object::Info CubeObject::find_intersection(Ray ray)
{
    Object::Info info;
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
    {
        info.k = 1e100;
        return info;
    }
    if(mini > 1e-6)
    {
        info.k = mini;
        Point3d tmp = ray.start + info.k*ray.direction - p1;
        if(kmin == 0)
        {
            info.direction_norm = Point3d(1, 0, 0) * flmin;
            info.pos = Point2d(tmp[1], tmp[2]);
        }
        else if(kmin == 1)
        {
            info.direction_norm = Point3d(0, 1, 0) * flmin;
            info.pos = Point2d(tmp[0], tmp[2]);
        }
        else if(kmin == 2)
        {
            info.direction_norm = Point3d(0, 0, 1) * flmin;
            info.pos = Point2d(tmp[0], tmp[1]);
        }
        info.is_in = 0;
    }
    else
    {
        info.k = maxi;
        Point3d tmp = ray.start + info.k*ray.direction - p1;
        if(kmax == 0)
        {
            info.direction_norm = -Point3d(1, 0, 0) * flmax;
            info.pos = Point2d(tmp[1], tmp[2]);
        }
        else if(kmax == 1)
        {
            info.direction_norm = -Point3d(0, 1, 0) * flmax;
            info.pos = Point2d(tmp[0], tmp[2]);
        }
        else if(kmax == 2)
        {
            info.direction_norm = -Point3d(0, 0, 1) * flmax;
            info.pos = Point2d(tmp[0], tmp[1]);
        }
        info.is_in = 1;
    }
    return info;
}

void CubeObject::find_reflection(Ray ray, Ray &ray_reflection)
{
    
}

void CubeObject::find_refraction(Ray ray, Ray& ray_refraction)
{
    
}

void CubeObject::set_attribute(std::string info)
{
    
}
