#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

int main() {
  cv::String namedWindow = "image_window";

  // Read image
  cv::Mat boltImage = cv::imread("images/bolt.png");
  boltImage.convertTo(boltImage, CV_32F, 1/255.0);

  // calculate gradients gx, gy
  cv::Mat gx, gy;
  cv::Sobel(boltImage, gx, CV_32F, 1, 0, 1);
  cv::Sobel(boltImage, gy, CV_32F, 0, 1, 1);

  // calculate gradient magnitude and direction(in degrees)
  cv::Mat magnitude, angle;
  cv::cartToPolar(gx, gy, magnitude, angle, 1);

  cv::namedWindow(namedWindow, CV_WINDOW_AUTOSIZE);

  // show image in window
  cv::imshow(namedWindow, gx);
  cv::waitKey(0);
  return 0;
}
