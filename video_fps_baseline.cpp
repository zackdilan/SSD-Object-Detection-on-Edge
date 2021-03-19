#include <iostream>
#include <time.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
using namespace std;
using namespace cv;

int main(){

    Mat frame;
    VideoCapture cap;
    // open the default camera
    cap.open(0);
    if (!cap.isOpened()){
        cerr << "ERROR! Unable to open camera\n";
        return 1;
    }
    int no_of_frames = 120;
    int frame_counter = 0;
    time_t start, end;
    //start time
    time(&start);
    
    for(;;){
        cap.read(frame);
        //check if succeded
        if (frame.empty()){
            cerr << "ERROR! blank frame grabbed";
            break;
        }
        frame_counter ++;
        if (frame_counter == no_of_frames){
            // get the time
            time(&end);
            break;
        }
    }
    // time elapsed
    double seconds = difftime (end, start);

    double fps =  no_of_frames/seconds;
    cout << "estimated frames per second :" << fps << endl;

    cap.release();
    return 0; 


    
}

