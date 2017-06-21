//
//  CubeObject.cpp
//  Bezier
//
//  Created by 张蒲石 on 2017/6/21.
//  Copyright © 2017年 张蒲石. All rights reserved.
//

#include "CubeObject.hpp"

void CubeObject::find_intersection(Ray ray, double& k, Point3d& direction_norm, Point2d& pos)
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
    if(mini > maxi || maxi <= 0)
    {
        k = 1e100;
        return;
    }
    if(mini > 0)
    {
        k = mini;
        Point3d tmp = ray.start + k*ray.direction - p1;
        if(kmin == 0)
        {
            direction_norm = Point3d(1, 0, 0) * flmin;
            pos = Point2d(tmp[1], tmp[2]);
        }
        else if(kmin == 1)
        {
            direction_norm = Point3d(0, 1, 0) * flmin;
            pos = Point2d(tmp[0], tmp[2]);
        }
        else if(kmin == 2)
        {
            direction_norm = Point3d(0, 0, 1) * flmin;
            pos = Point2d(tmp[0], tmp[1]);
        }
    }
    else
    {
        k = maxi;
        Point3d tmp = ray.start + k*ray.direction - p1;
        if(kmax == 0)
        {
            direction_norm = -Point3d(1, 0, 0) * flmax;
            pos = Point2d(tmp[1], tmp[2]);
        }
        else if(kmax == 1)
        {
            direction_norm = -Point3d(0, 1, 0) * flmax;
            pos = Point2d(tmp[0], tmp[2]);
        }
        else if(kmax == 2)
        {
            direction_norm = -Point3d(0, 0, 1) * flmax;
            pos = Point2d(tmp[0], tmp[1]);
        }
    }
}

void CubeObject::find_reflection(Ray ray, Ray &ray_reflection)
{
    
}

void CubeObject::find_refraction(Ray ray, Ray& ray_refraction)
{
    
}

void CubeObject::set_distribute(std::string info)
{
    
}
