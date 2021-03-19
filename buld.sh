CXX=${CXX:-g++}
#$CXX -std=c++17 -I. -o main main.cpp -lopencv_core -lopencv_video -lopencv_videoio -lopencv_imgproc -lopencv_imgcodecs -lopencv_highgui -lvitis_ai_library-tfssd  -pthread -lglog 
#$CXX -std=c++17 -I. -o video_test video_no_thread.cpp -lopencv_core -lopencv_video -lopencv_videoio -lopencv_imgproc -lopencv_imgcodecs -lopencv_highgui
$CXX -std=c++17 -I. -o video_fps_baseline video_fps_baseline.cpp -lopencv_core -lopencv_video -lopencv_videoio -lopencv_imgproc -lopencv_imgcodecs -lopencv_highgui 