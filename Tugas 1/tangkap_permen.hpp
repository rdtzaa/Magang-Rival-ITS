#ifndef tangkap_hpp
#define tangkap_hpp
#include <opencv4/opencv2/opencv.hpp>
using namespace cv;


class Permen {
    public:
    Permen(Point posisi, int diameter);
    void gambarPermen(Point posisi, Mat tampilan, const Scalar warna);
    void tampilSkor(Mat tampilan, int score, const Scalar warna);

    private;
    int diameter;
};

#endif
