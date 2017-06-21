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

Color RayTracingRenderer::render(Ray ray, double rate)
{
    // calculate all the intersections, find nearest
    double mini_length = 1e100;
    Object *object = nullptr;
    Point3d intersection;
    Object::Info info;
    
    int flag_reflect = 0;
    
    if(rate < 1e-3)
        return scene->color_background;
    
    for(Object* tmp_object : scene->objects)
    {
        Object::Info _info;
        _info = tmp_object->find_intersection(ray);
        if(_info.k < mini_length)
        {
            mini_length = _info.k;
            info = _info;
            intersection = ray.start + info.k*ray.direction;
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
        color_diffuse = Collider().get_color(intersection, info.direction_norm, -ray.direction, texture, info.pos);
        color = color + color_diffuse * texture.diffuse_rate;
    }
    if(texture.state & (1<<Texture::reflect))
    {
        Ray ray_next;
        
        Point3d N = info.direction_norm / length(info.direction_norm);
        Point3d L = -ray.direction / length(ray.direction);
        
        if(info.is_in && sqrt(1 - pow(N.dot(L), 2)) * texture.n > 1)
            flag_reflect = 1;
        
        ray_next.start = intersection;
        ray_next.direction = 2 * N * N.dot(L) - L;
       
        
            color_reflect = render(ray_next, rate * texture.reflect_rate);
            color = color + color_reflect * texture.reflect_rate;
        
    }
    
    if(texture.state & (1<<Texture::refract))
    {
        Ray ray_next;
        
        Point3d N = info.direction_norm / length(info.direction_norm);
        Point3d L = -ray.direction / length(ray.direction);
        double sine;
        if(!info.is_in)
            sine = sqrt(1 - pow(N.dot(L), 2)) / texture.n;
        else
            sine = sqrt(1 - pow(N.dot(L), 2)) * texture.n;
        double tang = sine / sqrt(1 - pow(sine, 2));
        Point3d H = N.cross(N.cross(L));
        H = H / length(H);
        
        //std::cout<< "aaa\n" << ray.start << "\n" << ray.direction << "\n";
        
        ray_next.start = intersection;
        ray_next.direction = -N + H*tang;
        
        //std::cout<< ray_next.start << "\n" << ray_next.direction << "\n";
        //if(!flag_reflect)
        {
            color_refract = render(ray_next, rate * texture.refract_rate);
            color = color + color_refract * texture.refract_rate;
        }
    }
    
    return color;
}
