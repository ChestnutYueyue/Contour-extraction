#ifndef CONTOUR_H
#define CONTOUR_H
#include <opencv2/opencv.hpp>
#include <iostream>
#ifdef _WIN32
#define OBJECT_API __declspec(dllexport)
#else
#define OBJECT_API
#endif

class OBJECT_API Contour
{
private:
    cv::Mat _img;
    cv::Mat drawing;
    cv::ImreadModes _modes;
    std::string _filename;
    std::string _window_name;

public:
    Contour(const std::string &filename, const cv::ImreadModes &modes = cv::IMREAD_COLOR, const std::string &window_name = "contour");
    // 获取所有轮廓
    void findContours(const int &mode = cv::RETR_EXTERNAL, const int &method = cv::CHAIN_APPROX_SIMPLE);
    // 显示图像
    void show();
    // 保存图像
    void save(const std::string &filename = "");
    // 销毁窗口
    ~Contour();
};
#endif // !CONTOUR_H
