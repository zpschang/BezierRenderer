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
    scene->set_camera(new Camera(Point3d(-1, 0, 0), Point3d(1, 0, 0), Point3d(0, 0, 1)));
    
    scene->lights.push_back(new Light(Point3d(-2, 0, 2)));
    CubeObject *cube = new CubeObject;
    cube->p1 = Point3d(0, -1, -2);
    cube->p2 = Point3d(2, 1, 0);
    cube->texture.state = Texture::diffuse;
    cube->texture.diffuse_rate = 1;
    scene->objects.push_back(cube);
    
    scene->render();
    
    scene->show_image();
    
    return 0;
}
