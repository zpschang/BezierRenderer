//
//  BezierObject.cpp
//  Bezier
//
//  Created by 张蒲石 on 2017/6/21.
//  Copyright © 2017年 张蒲石. All rights reserved.
//

#include "BezierObject.hpp"

#include <sstream>

void BezierObject::set_attribute(std::string info)
{
    std::stringstream stream(info);
    stream >> n >> m;
    point.assign(m+1, std::vector<Point3d>(n+1));
    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= n; j++)
            for(int k = 0; k < 3; k++)
                stream >> point[i][j][k];
}

Object::Info BezierObject::find_intersection(Ray ray)
{
    Object::Info info;
    calc_round();
    bool is_cross = Object::is_cross(p1, p2, ray);
    if(!is_cross)
    {
        info.k = 1e100;
        return info;
    }
    double t = 0, u0 = 0.5, v0 = 0.5;
    Point3d vec(t, u0, v0);
    int flag = 1;
    while(flag)
    {
        Point3d p_surface = calc_point(u0, v0, m, n, point);
        Point3d p_line = ray.start + t * ray.direction;
        Point3d delta = p_surface - p_line;
        auto pair = calc_derivative(u0, v0);
        Eigen::Matrix<double, 3, 3> mat;
        for(int i = 0; i < 3; i++)
        {
            mat(i, 0) = ray.direction[i];
            mat(i, 1) = -pair.first[i];
            mat(i, 2) = -pair.second[i];
        }
        
        vec -= mat.inverse() * delta;
        
        if(std::abs(u0 - vec[1]) < 0.001 && std::abs(v0 - vec[2]) < 0.001)
            flag = 0;
        t = vec[0], u0 = vec[1], v0 = vec[2];
    }
    info.k = t;
    info.direction_norm = calc_norm(u0, v0);
    if(ray.direction.dot(info.direction_norm) > 0)
        info.is_in = 1;
    else
        info.is_in = -1;
    info.pos = Point2d(u0*100, v0*100);
    
    return info;
}

void BezierObject::calc_round()
{
    p1 = Point3d(1e100, 1e100, 1e100);
    p2 = Point3d(-1e100, -1e100, -1e100);
    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= n; j++)
            for(int k = 0; k < 3; k++)
            {
                p1[k] = min(p1[k], point[i][j][k]);
                p2[k] = max(p2[k], point[i][j][k]);
            }
}

Point3d BezierObject::calc_point(double u, double v, int m, int n,
                                 std::vector<std::vector<Point3d>> point)
{
    std::vector<std::vector<Point3d>> f;
    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= n; j++)
            f[i][j] = point[i][j];
    for(int k = 1; k <= m; k++)
        for(int i = 0; i <= m-k; i++)
            for(int j = 0; j <= n; j++)
                f[i][j] = (1-u) * f[i][j] + u * f[i+1][j];
    for(int l = 1; l <= n; l++)
        for(int j = 0; j <= n-l; j++)
            f[0][j] = (1-v) * f[0][j] + v * f[0][j+1];
    return f[0][0];
}

std::pair<Point3d, Point3d> BezierObject::calc_derivative(double u, double v)
{
    std::vector<std::vector<Point3d>> tmp_point;
    for(int i = 0; i <= m-1; i++)
        for(int j = 0; j <= n; j++)
            for(int k = 0; k < 3; k++)
                tmp_point[i][j][k] = point[i+1][j][k] - point[i][j][k];
    Point3d p1 = calc_point(u, v, m-1, n, tmp_point);
    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= n-1; j++)
            for(int k = 0; k < 3; k++)
                tmp_point[i][j][k] = point[i][j+1][k] - point[i][j][k];
    Point3d p2 = calc_point(u, v, m, n-1, tmp_point);
    return std::make_pair(p1, p2);
}

Point3d BezierObject::calc_norm(double u, double v)
{
    auto pair = calc_derivative(u, v);
    return pair.first.cross(pair.second);
}
