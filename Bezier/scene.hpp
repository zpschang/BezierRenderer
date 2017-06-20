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

#include <vector>
using namespace std;

class Renderer;

class Scene
{
    Point3d me, my_direction;
    Renderer *renderer;
public:
    vector<Object*> objects;
    vector<Light*> lights;
    Scene(char *filename);
    void write_info(char *filename);
    void set_pos(Point3d, Point3d);
    void set_renderer(Renderer*);
    void render();
    void export_img(char *filename);
};

#endif /* scene_hpp */
