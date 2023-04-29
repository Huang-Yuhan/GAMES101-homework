#include<cmath>
#include<eigen3/Eigen/Core>
#include<eigen3/Eigen/Dense>
#include<eigen3/Eigen/Geometry>
#include<iostream>

/*
给定一个点 P=(2,1), 将该点绕原点先逆时针旋转45◦，再平移(1,2), 计算出
变换后点的坐标（要求用齐次坐标进行计算）。
*/

int main(){

    Eigen::Vector3<double> P(2,1,0);   
    const float pidiv4 = atan(1);
    Eigen::MatrixXd rotate{
        {cos(pidiv4),-sin(pidiv4),0},
        {sin(pidiv4),cos(pidiv4),0},
        {0,0,1}
    };
    Eigen::MatrixXd trans{
        {1,0,1},
        {0,1,2},
        {0,0,1}
    };
    Eigen::Vector3d ans=trans*rotate*P;
    std::cout<<ans;
    return 0;
}