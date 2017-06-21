//
//  RayTracingRenderer.cpp
//  Bezier
//
//  Created by 张蒲石 on 2017/6/20.
//  Copyright © 2017年 张蒲石. All rights reserved.
//

#include "RayTracingRenderer.hpp"
#include "collider.hpp"

RayTracingRenderer::RayTracingRenderer()
{
    
    
}

Color RayTracingRenderer::render(Ray ray)
{
    // calculate all the intersections, find nearest
    double mini_length = 1e100;
    Object *object = nullptr;
    Point3d intersection, direction_norm;
    Point2d pos;
    for(Object* tmp_object : scene->objects)
    {
        double tmp;
        Point3d tmp_point;
        Point2d tmp_pos;
        tmp_object->find_intersection(ray, tmp, tmp_point, tmp_pos);
        if(tmp < mini_length)
        {
            mini_length = tmp;
            direction_norm = tmp_point;
            pos = tmp_pos;
            intersection = ray.start + tmp*ray.direction;
            object = tmp_object;
        }
    }
    if(object == nullptr || mini_length > 1e10)
        return scene->color_background;
    
    // get colors
    
    Texture& texture = object->texture;
    Color color_diffuse, color_reflect, color_refract, color;
    
    if(texture.state & (1<<Texture::diffuse))
    {
        color_diffuse = Collider().get_color(intersection, direction_norm, -ray.direction, texture, pos);
        color = color + color_diffuse * texture.diffuse_rate;
    }
    if(texture.state & (1<<Texture::reflect))
    {
        Ray ray_next;
        object->find_reflection(ray, ray_next);
        color_reflect = render(ray_next);
        color = color + color_reflect * texture.reflect_rate;
    }
    
    if(texture.state & (1<<Texture::refract))
    {
        Ray ray_next;
        object->find_refraction(ray, ray_next);
        color_refract = render(ray_next);
        color = color + color_refract * texture.refract_rate;
    }
    
    return color;
}
