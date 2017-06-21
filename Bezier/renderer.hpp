//
//  renderer.hpp
//  Bezier
//
//  Created by 张蒲石 on 2017/6/20.
//  Copyright © 2017年 张蒲石. All rights reserved.
//

#ifndef renderer_hpp
#define renderer_hpp

#include <stdio.h>
#include "scene.hpp"
#include "basic.h"

class Scene;

extern Scene *scene;

class Renderer
{
public:
    virtual Color render(Ray ray) = 0;
    
};

#endif /* renderer_hpp */
