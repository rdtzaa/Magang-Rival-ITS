#include "tangkap_permen.hpp"
using namespace cv;

Permen::Permen(Point posisi, int diameter)
    : posisi(posisi), diameter(diameter) {}

void Permen::gambarPermen(Point posisi, Mat tampilan, const Scalar warna) {
    circle(tampilan, posisi, diamater, warna, -1);
}

void Permen::tampilSkor(Mat tampilan, int score, const Scalar warna) {
    putText(tampilan, "SCORE: " + to_string(score), Point(10, 50), FONT_HERSHEY_SIMPLEX, 1, warna, 2);
}
