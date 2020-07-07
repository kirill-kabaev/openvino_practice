#include "opencv_coins.hpp"
#include <string>

using namespace cv;
Mat img = imread("C:\\Users\\k_kab\\Picture\\coins.jpg");

unsigned countCoins(const Mat& img) {
    Mat gray, thresh;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    threshold(gray, thresh, 0, 255, THRESH_BINARY_INV + THRESH_OTSU);
    // Remove unfilled black holes by morphological closing
    morphologyEx(thresh, thresh, MORPH_CLOSE, Mat::ones(3, 3, CV_8U), Point(-1, -1), 2);
    // TODO: implement an algorithm from https://docs.opencv.org/master/d3/db4/tutorial_py_watershed.html
    //namedWindow("Display window", WINDOW_AUTOSIZE);
    imshow("grayscale", thresh);
    waitKey();
    //imwrite("C:\\Users\\k_kab\\Picture\\result.jpg", thresh);
    // noise removal
    // sure background area
    dilate(thresh, thresh, Mat::ones(3, 3, CV_8U), Point(-1, -1), 3);


 

}

