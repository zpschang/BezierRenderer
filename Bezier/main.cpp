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

using namespace cv;


int main(int argc, const char * argv[]) {
    // insert code here...
    
    typedef Eigen::Matrix<float, 3, 1> Point3d;
    Point3d p(1, 2, 3), p2(1, 1, 1);
    
    return 0;
}
