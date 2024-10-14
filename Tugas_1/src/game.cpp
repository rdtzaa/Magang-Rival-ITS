#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
#include "tangkap_permen.hpp"
using namespace std;
using namespace cv;

int main() {
    VideoCapture kamera(0);
    if(kamera.isOpened()){
        cerr << "Bismillah" << endl;
    }

    Mat frame;

    Mat frame_check;
    kamera >> frame_check;

    Size ukuranKamera = frame_check.size();
    int panjang = ukuranKamera.width;
    int lebar = ukuranKamera.height;

    int score = 0;
    Scalar warnaSkor(255, 255, 255);
    
    Scalar warnaPermen(255, 0, 0), warnaJaring(255, 255, 255);
    Point posisiPermen(rand() % panjang, rand() % lebar);
    int diameterPermen = 10;

    Permen permen(diameterPermen);
    float speedX = 4.0f;
    float speedY = 5.0f;

    while (true) {
        kamera >> frame;

        Mat hsv, lim_color;
        Mat frame_clone =  frame.clone();

        cvtColor(frame, hsv, COLOR_BGR2HSV);
        inRange(hsv, Scalar(0,159,116), Scalar(179,255,168), lim_color); //Warna Single-Dot (Merah)

        vector<vector<Point>> kontur;
        findContours(lim_color, kontur, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        permen.gambarPermen(posisiPermen, frame_clone, warnaPermen, diameterPermen);
        posisiPermen.x += (int) speedX;
        posisiPermen.y += (int) speedY;

        if (posisiPermen.x - diameterPermen < 0 || posisiPermen.x + diameterPermen > panjang) {
            speedX = -speedX;
        }

        if (posisiPermen.y - diameterPermen < 0 || posisiPermen.y + diameterPermen > lebar) {
            speedY = -speedY;
        }

        for (size_t i = 0; i < kontur.size(); i++) {
            Rect box = cv::boundingRect(kontur[i]);
            // rectangle(frame_clone, box, warnaJaring, 2);

            Point tpusatnet(box.x + box.width / 2, box.y + box.height / 2);
            int radiusJaring = min(box.width, box.height) / 2;

            circle(frame_clone, tpusatnet, radiusJaring, warnaJaring, 2);

            if (norm(tpusatnet - posisiPermen) <= radiusJaring) {
                score++;
                posisiPermen = Point(rand() % panjang, rand() % lebar);
            }
        }

        permen.tampilSkor(frame_clone, score, warnaSkor);
        // putText(frame_clone, "SCORE: " + to_string(score), Point(10, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 2);

        imshow("Tangkap Permen",frame_clone);
        if(waitKey(30) == 32){
            break;
        }
    }
}
