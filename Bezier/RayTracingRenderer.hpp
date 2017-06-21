//
//  RayTracingRenderer.hpp
//  Bezier
//
//  Created by 张蒲石 on 2017/6/20.
//  Copyright © 2017年 张蒲石. All rights reserved.
//

#ifndef RayTracingRenderer_hpp
#define RayTracingRenderer_hpp

#include <stdio.h>
#include "renderer.hpp"

class RayTracingRenderer: public Renderer
{
public:
    RayTracingRenderer();
    Color render(Ray ray);
};

#endif /* RayTracingRenderer_hpp */
