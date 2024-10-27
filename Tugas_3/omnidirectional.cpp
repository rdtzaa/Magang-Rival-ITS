#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

struct RobotL {
    double jarak = 0.15;
    double sudut[3] = {0, -3 * M_PI_4, 3 * M_PI_4};
    double posisi[3][2] = {
        {0, jarak},
        {jarak * cos(M_PI_4), - jarak * sin(M_PI_4)},
        {- jarak * cos(M_PI_4), - jarak * sin(M_PI_4)}
    };
    double mtx_perhitungan[3][3] = {
        {-(posisi[0][0] * sin(sudut[0]) - posisi[0][1] * cos(sudut[0])), -cos(sudut[0]), sin(sudut[0])},
        {-(posisi[1][0] * sin(sudut[1]) - posisi[1][1] * cos(sudut[1])), -cos(sudut[1]), sin(sudut[1])},
        {-(posisi[2][0] * sin(sudut[2]) - posisi[2][1] * cos(sudut[2])), -cos(sudut[2]), sin(sudut[2])}
    };
};

struct RobotD {
    double jarak = 0.15;
    double sudut[3] = {0, (-2 * M_PI) / 3, (2 * M_PI) / 3};
    double posisi[3][2] = {
        {0, jarak},
        {jarak * cos(M_PI_2 / 3), - jarak * sin(M_PI_2 / 3)},
        {- jarak * cos(M_PI_2 / 3), - jarak * sin(M_PI_2 / 3)}
    };
    double mtx_perhitungan[3][3] = {
        {(posisi[0][0] * sin(sudut[0]) - posisi[0][1] * cos(sudut[0])), cos(sudut[0]), sin(sudut[0])},
        {(posisi[1][0] * sin(sudut[1]) - posisi[1][1] * cos(sudut[1])), cos(sudut[1]), sin(sudut[1])},
        {(posisi[2][0] * sin(sudut[2]) - posisi[2][1] * cos(sudut[2])), cos(sudut[2]), sin(sudut[2])}
    };
};

int main() {
    string nama_robot;
    cin >> nama_robot;
    cout << fixed << setprecision(2);
    if (nama_robot == "LILDAN") {
        RobotL dan;
        int i = 0;
        vector<vector<double>> dataw;
        int forward = 0;
        string cmd;
        string arah;
        while (true){
            int vz, vy, vx;
            cin >> vx >> vy >> vz;
            forward += vy;
            double w1 = vz * dan.mtx_perhitungan[0][0] + vy * dan.mtx_perhitungan[0][1] + vx * dan.mtx_perhitungan[0][2];
            double w2 = vz * dan.mtx_perhitungan[1][0] + vy * dan.mtx_perhitungan[1][1] + vx * dan.mtx_perhitungan[1][2];
            double w3 = vz * dan.mtx_perhitungan[2][0] + vy * dan.mtx_perhitungan[2][1] + vx * dan.mtx_perhitungan[2][2];
            dataw.push_back({w2, w1, w3});
            cout << "Lanjut isi / GAS? ";
            cin >> cmd;
            if (cmd == "GAS") {
                break;
            } else {
                i++;
            }
        }
        if (forward < 0) {
            cout << "Δ" << endl;
        } else {
            cout << "∇" << endl;
        }
        for (int j = 0; j <= i; j++) {
            cout << dataw[j][0] / 0.0635 << " " << dataw[j][1] / 0.0635 << " " << dataw[j][2] / 0.0635 << endl;
        }
    } else if (nama_robot == "DHARMI") {
        RobotD dar;
        int i = 0;
        vector<vector<double>> dataw;
        int forward = 0;
        string cmd;
        while (true){
            int vz, vy, vx;
            cin >> vx >> vy >> vz;
            forward += vy;
            double w1 = vz * dar.mtx_perhitungan[0][0] + vy * dar.mtx_perhitungan[0][1] + vx * dar.mtx_perhitungan[0][2];
            double w2 = vz * dar.mtx_perhitungan[1][0] + vy * dar.mtx_perhitungan[1][1] + vx * dar.mtx_perhitungan[1][2];
            double w3 = vz * dar.mtx_perhitungan[2][0] + vy * dar.mtx_perhitungan[2][1] + vx * dar.mtx_perhitungan[2][2];
            dataw.push_back({w2, w3, w1});
            cout << "Lanjut isi / GAS? ";
            cin >> cmd;
            if (cmd == "GAS") {
                break;
            } else {
                i++;
            }
        }

        if (forward < 0) {
            cout << "Δ" << endl;
        } else {
            cout << "∇" << endl;
        }
        
        for (int j = 0; j <= i; j++) {
            cout << dataw[j][0] / 0.024 << " " << dataw[j][1] / 0.024 << " " << dataw[j][2] / 0.024 << endl;
        }
    }
}
