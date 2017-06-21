//
//  main.cpp
//  Bezier
//
//  Created by 张蒲石 on 2017/6/14.
//  Copyright © 2017年 张蒲石. All rights reserved.
//

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <Eigen/Dense>
using Eigen::MatrixXd;

#include <cstdlib>
#include "scene.hpp"
#include "RayTracingRenderer.hpp"
#include "CubeObject.hpp"

Scene *scene = new Scene("");

int main(int argc, const char * argv[]) {
    // insert code here...
    scene->set_renderer(new RayTracingRenderer);
    scene->set_camera(new Camera(Point3d(-4, -5, 2), Point3d(1, 1, -0.6), Point3d(0, 0, 1)));
    
    scene->lights.push_back(new Light(Point3d(5, 5, 5)));
    scene->lights.push_back(new Light(Point3d(0, 5, 5), Color(0, 0, 1), 0));
    
    CubeObject *cube = new CubeObject;
    cube->p1 = Point3d(0, -1, -2);
    cube->p2 = Point3d(2, 1, 0);
    cube->texture.state = 1<<Texture::diffuse;
    cube->texture.diffuse_rate = 1;
    cube->texture.color = Color(1, 0, 0);
    scene->objects.push_back(cube);
    
    cube = new CubeObject;
    cube->p1 = Point3d(5, 4, -2);
    cube->p2 = Point3d(7, 6, 0);
    cube->texture.state = 1<<Texture::diffuse;
    cube->texture.diffuse_rate = 1;
    cube->texture.color = Color(0, 0, 1);
    scene->objects.push_back(cube);
    
    CubeObject *ground = new CubeObject;
    ground->p1 = Point3d(-100, -100, -5);
    ground->p2 = Point3d(100, 100, -2);
    ground->texture.state = 1<<Texture::diffuse;
    ground->texture.diffuse_rate = 1;
    scene->objects.push_back(ground);
    scene->render();
    
    scene->show_image();
    
    return 0;
}
