//
//  texture.hpp
//  Bezier
//
//  Created by 张蒲石 on 2017/6/20.
//  Copyright © 2017年 张蒲石. All rights reserved.
//

#ifndef texture_hpp
#define texture_hpp

#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "basic.h"

class Texture
{
public:
    Texture(): color(1, 1, 1)
    {
    }
    double reflect_rate, refract_rate, diffuse_rate;
    cv::Mat image;
    Color color;
    
    void get_image(char *filename);
    enum State{diffuse=0, reflect=1, refract=2};
    int state;
};

#endif /* texture_hpp */
