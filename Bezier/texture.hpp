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
#include <functional>

class Texture
{
public:
    Texture(): color(1, 1, 1)
    {
        n = 1.1;
        type = 0;
    }
    int type;
    Color get_color(Point2d p)
    {
        if(type == 0)
            return one_color(p);
        else if(type == 1)
            return white_black(p);
        else
            return Color(0, 0, 0);
    }
    Color one_color(Point2d)
    {
        return color;
    }
    
    Color white_black(Point2d p)
    {
        int x = int(p[0]*100) / 4, y = int(p[1]*100) / 4;
        if((x + y) % 2 == 0)
            return Color(1, 1, 1);
        else
            return Color(0, 0, 0);
    }
    
    double reflect_rate, refract_rate, diffuse_rate, n;
    cv::Mat image;
    Color color;
    
    void get_image(char *filename);
    enum State{diffuse=0, reflect=1, refract=2};
    int state;
};

#endif /* texture_hpp */
