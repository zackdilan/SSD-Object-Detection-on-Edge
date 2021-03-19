#include <memory>
#include <iostream>
#include <stdio.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <vitis/ai/nnpp/tfssd.hpp>
#include <vitis/ai/tfssd.hpp>

using namespace std;
using namespace cv;

int main(int argc, char *argv[]){

    Mat frame;
    VideoCapture cap;
    // open the default camera
    cap.open(0);
    if (!cap.isOpened()){
        cerr << "ERROR! Unable to open camera\n";
        return 1;
    }
    // --- Grab the frames
    cout << "Start grabbing" << endl
        << "Press any key to terminate";
    for (;;){
        //wait for a new frame from camera and store it into frame
        cap.read(frame);
        //check if succeded
        if (frame.empty()){
            cerr << "ERROR! blank frame grabbed";
            break;
        }
        //show live and wait for a key with timeout long enough to show images
        imshow("Live",frame);
        if (waitKey(5) >= 0)
            break;
    }
    return 0;
}

