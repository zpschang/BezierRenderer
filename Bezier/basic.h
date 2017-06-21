//
//  basic.h
//  Bezier
//
//  Created by 张蒲石 on 2017/6/14.
//  Copyright © 2017年 张蒲石. All rights reserved.
//

#ifndef basic_h
#define basic_h

#include <vector>
#include <Eigen/Dense>

typedef Eigen::Matrix<double, 3, 1> Point3d;
typedef Eigen::Matrix<double, 2, 1> Point2d;

Point3d projection(Point3d x, Point3d y);

class Ray
{
public:
    Ray(){}
    Ray(Point3d _start, Point3d _direction)
    {
        start = _start;
        direction = _direction;
    }
    Point3d start, direction;
};

class Color
{
public:
    double r, g, b;
    Color(){r = g = b = 0;}
    Color(double _r, double _g, double _b): r(_r), g(_g), b(_b){}
    Color operator * (double t)
    {
        return Color(r*t, g*t, b*t);
    }
    Color operator + (Color c)
    {
        return Color(r+c.r, g+c.g, b+c.b);
    }
};

#endif /* basic_h */
