#include <Contour.h>

Contour::Contour(const std::string &filename, const cv::ImreadModes &modes, const std::string &window_name)
{
    this->_modes = modes;
    this->_filename = filename;
    this->_window_name = window_name;
}

void Contour::findContours(const int &mode, const int &method)
{
    this->_img = cv::imread(this->_filename, this->_modes);
    if (this->_img.empty())
    {
        std::cout << "Error: can not read image" << std::endl;
        return;
    }
    if (this->_modes != cv::IMREAD_GRAYSCALE)
    {
        cv::cvtColor(this->_img, this->_img, cv::COLOR_BGR2GRAY);
    }
    cv::GaussianBlur(this->_img, this->_img, cv::Size(1, 1), 0, 0);
    cv::Canny(this->_img, this->_img, 0, 200);
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(this->_img, contours, mode, method);
    this->drawing = cv::Mat::zeros(this->_img.size(), CV_8UC3);
    for (size_t i = 0; i < contours.size(); i++)
    {
        cv::drawContours(drawing, contours, i, cv::Scalar(255, 255, 255), 2);
    }
}
void Contour::show()
{
    cv::namedWindow(this->_window_name, cv::WINDOW_KEEPRATIO);
    cv::imshow(this->_window_name, this->drawing);
    cv::waitKey(0);
}
void Contour::save(const std::string &filename)
{
    if (filename.empty())
    {
        this->_filename.replace(this->_filename.find(".jpg"), 4, "_1.jpg");
    }
    else
    {
        this->_filename = filename;
    }

    if (cv::imwrite(this->_filename, this->drawing, {cv::IMWRITE_JPEG_QUALITY, 100}))
    {
        std::cout << "Success: save image" << std::endl;
    }
    else
    {
        std::cout << "Error: can not save image" << std::endl;
    }
}
Contour::~Contour()
{
    cv::destroyAllWindows();
}
