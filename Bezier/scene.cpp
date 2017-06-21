//
//  scene.cpp
//  Bezier
//
//  Created by 张蒲石 on 2017/6/20.
//  Copyright © 2017年 张蒲石. All rights reserved.
//

#include "scene.hpp"

Scene::Scene(char *filename)
{
    image = nullptr;
    
}

void Scene::render()
{
    if(image != nullptr)
        delete image;
    
    image = new cv::Mat(2 * camera->h, 2 * camera->w, CV_8UC3);
    
    printf("%d %d\n", camera->h, camera->w);
    
    image->forEach<Pixel>([this](Pixel& p, const int * position) -> void {
        int v = position[0], u = position[1];
        Ray ray = camera->ray_cast(u - camera->w, v - camera->h);
        Color color = renderer->render(ray);
        p.x = color.b;
        p.y = color.g;
        p.z = color.r;
    });
    
    printf("render finished\n");
    
    /*
    for(int v = 0; v < 2 * camera->h; v++)
    {
        printf("%d\n", v);
        for(int u = 0; u < 2 * camera->w; u++)
        {
            Ray ray = camera->ray_cast(u - camera->w, v - camera->h);
            Color color = renderer->render(ray);
            cv::Vec3b vec(color.b, color.g, color.r);
            image->at<cv::Vec3b>(v, u) = vec;
        }
    }
     */
}

void Scene::show_image()
{
    cv::imshow("render", *image);
    cv::waitKey(0);
}

void Scene::export_image(char *filename)
{
    cv::imwrite(filename, *image);
    
}
