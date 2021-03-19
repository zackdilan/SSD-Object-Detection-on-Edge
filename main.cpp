#pragma once
#include <memory>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <vitis/ai/nnpp/tfssd.hpp>
#include <vitis/ai/tfssd.hpp>

using namespace std;
using namespace cv;

int main(){
    string image_path = "ronaldo.jpg";
    Mat img = imread(image_path);

    if (img.empty()){
        cout <<"Could not read the image " << image_path << endl;
        return 1;
    }

    // create the tfssd object
    // need to understand : create is a factory function in TFSSD class, we use scope 
    // resolution operator to call it.
    // tfssd is a pointer to class TFSSD
    auto tfssd = vitis::ai::TFSSD::create("ssd_mobilenet_v2_coco_tf", true);
    // results is a  vector
    auto results = tfssd -> run(img);
    for(const auto &r : results.bboxes){
        auto label = r.label;
        auto x = r.x * img.cols;
        auto y = r.y * img.rows;
        auto width = r.width * img.cols;
        auto height = r.height * img.rows;
        auto score = r.score;
        cv::Point pt1(x,y);
        cv::Point pt2(x + width, y + height);
        cv:: rectangle(img, pt1 , pt2, cv::Scalar(0,255,0));
        cout << "RESULT :" << label << "\t" << x << "\t" << y << "\t" << width << "\t"
                <<height << "\t" << score << endl;
    }
    //  save the image
    cv::imwrite("main_result.jpg",img);

}