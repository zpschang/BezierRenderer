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
    color_background = Color(1, 1, 1);
}

void Scene::render()
{
    if(image != nullptr)
        delete image;
    
    image = new cv::Mat(2 * camera->h, 2 * camera->w, CV_8UC3);
    
    printf("%d %d\n", camera->h, camera->w);
    
    
    image->forEach<Pixel>([this](Pixel& p, const int * position) -> void {
        int v = position[0], u = position[1];
        Ray ray = camera->ray_cast(u, v);
        Color color = renderer->render(ray);
        double maxi = std::max(std::max(color.r, color.g), color.b);
        if(maxi > 1)
        {
            color.b /= maxi;
            color.g /= maxi;
            color.r /= maxi;
        }
        
        p.x = color.b * 255;
        p.y = color.g * 255;
        p.z = color.r * 255;
        
        printf("%d %d end\n", v, u);
    });
    
    
    //Ray ray = camera->ray_cast(0, 162);
    //Color color = renderer->render(ray) * 255;
    /*
    for(int v = 0; v < 2 * camera->h; v++)
    {
        printf("%d\n", v);
        for(int u = 0; u < 2 * camera->w; u++)
        {
            if(v == 162)
                printf("%d\n", u);
            Ray ray = camera->ray_cast(u, v);
            Color color = renderer->render(ray) * 255;
            cv::Vec3b vec(color.b, color.g, color.r);
            //printf("[%f, %f, %f]\n", color.r, color.g, color.b);
            image->at<cv::Vec3b>(v, u) = vec;
        }
    }
    */
    
    printf("render finished\n");
    
    
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

void Scene::export_scene(char *filename)
{
    ofstream out(filename);
    out << "camera" << endl << camera->to_string() << endl;
    out << "light" << ' ' << lights.size() << endl;
    for(int i = 0; i < lights.size(); i++)
        out << lights[i]->to_string() << endl;
    out << "object " << objects.size() << endl;
    for(int i = 0; i < objects.size(); i++)
    {
        out << objects[i]->to_string() << endl;
        out << objects[i]->texture.to_string() << endl;
    }
    out.close();
}
