//
//  scene.hpp
//  Bezier
//
//  Created by 张蒲石 on 2017/6/20.
//  Copyright © 2017年 张蒲石. All rights reserved.
//

#ifndef scene_hpp
#define scene_hpp

#include <stdio.h>
#include "object.hpp"
#include "renderer.hpp"
#include "light.hpp"
#include "basic.h"
#include "Camera.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <vector>
using namespace std;

class Renderer;

class Scene
{
    Camera *camera;
    Renderer *renderer;
public:
    typedef cv::Point3_<uint8_t> Pixel;
    cv::Mat *image;
    Color color_background;
    vector<Object*> objects;
    vector<Light*> lights;
    
    Scene(char *filename);
    void set_camera(Camera* _camera)
    {
        camera = _camera;
    }
    void set_renderer(Renderer* _renderer)
    {
        renderer = _renderer;
    }
    void render();
    void show_image();
    void export_image(char *filename);
};

#endif /* scene_hpp */
