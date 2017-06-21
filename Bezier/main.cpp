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

#include <Eigen/Dense>
using Eigen::MatrixXd;

#include <cstdlib>
#include "scene.hpp"

using namespace cv;

Scene *scene = new Scene("");

int main(int argc, const char * argv[]) {
    // insert code here...
    
    typedef Eigen::Matrix<float, 3, 1> Point3d;
    Point3d p(1, 2, 3), p2(1, 1, 1);
    Mat image(600, 600, CV_8UC3);
    for(int i = 0; i < 200; i++)
        for(int j = 0; j < 100; j++)
        {
            Vec3b vec(00, 100, 200); // bgr
            image.at<Vec3b>(i, j) = vec;
        }
    imshow("image", image);
    waitKey(0);
    
    return 0;
}
