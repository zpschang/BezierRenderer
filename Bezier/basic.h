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

typedef Eigen::Matrix<float, 3, 1> Point3d;
class Ray
{
public:
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
