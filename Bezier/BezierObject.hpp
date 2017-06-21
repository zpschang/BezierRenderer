//
//  BezierObject.hpp
//  Bezier
//
//  Created by 张蒲石 on 2017/6/21.
//  Copyright © 2017年 张蒲石. All rights reserved.
//

#ifndef BezierObject_hpp
#define BezierObject_hpp

#include <stdio.h>
#include "object.hpp"

class CubeObject;

class BezierObject: public Object
{
public:
    int n, m;
    Eigen::MatrixX3d point[3];
    Point3d p1, p2;
    
    Object::Info find_intersection(Ray ray);
    void set_attribute(std::string info);
    
    void calc_round();
    Point3d calc_point(double u, double v);
    std::pair<Point3d, Point3d> calc_derivative(double u, double v);
    Point3d calc_norm(double u, double v);
};

#endif /* BezierObject_hpp */
