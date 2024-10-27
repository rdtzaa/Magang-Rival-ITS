#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

void kaliMatrix(double m1[4][4], double m2[4][4], double result[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

int main() {
    double alpha[3] = {M_PI_2, 0, 0};
    double a[3] = {0, 3, 2};
    double theta1, theta2, theta3;

    string robot;
    cin >> robot;
    if (robot == "L") {
        double d1 = 5;
        double d[3] = {d1, 0, 0};
        cin >> theta1 >> theta2 >> theta3;
        theta1 = theta1 * M_PI/180;
        theta2 = theta2 * M_PI/180;
        theta3 = theta3 * M_PI/180;

        double mtx01[4][4] = {
            {cos(theta1), sin(theta1)*sin(M_PI_2 - alpha[0]) * -1, sin(theta1)*sin(alpha[0]), a[0]*cos(theta1)},
            {sin(theta1), cos(theta1)*sin(M_PI_2 - alpha[0]), cos(theta1)*sin(alpha[0])*-1, a[0]*sin(theta1)},
            {0, sin(alpha[0]), sin(M_PI_2 - alpha[0]), d[0]},
            {0, 0, 0, 1}
        };

        double mtx02[4][4] = {
            {cos(theta2), sin(theta2)*sin(M_PI_2 - alpha[1]) * -1, sin(theta2)*sin(alpha[1]), a[1]*cos(theta2)},
            {sin(theta2), cos(theta2)*sin(M_PI_2 - alpha[1]), cos(theta2)*sin(alpha[1])*-1, a[1]*sin(theta2)},
            {0, sin(alpha[1]), sin(M_PI_2 - alpha[1]), d[1]},
            {0, 0, 0, 1}
        };

        double mtx03[4][4] = {
            {cos(theta3), sin(theta3)*sin(M_PI_2 - alpha[2]) * -1, sin(theta3)*sin(alpha[2]), a[2]*cos(theta3)},
            {sin(theta3), cos(theta3)*sin(M_PI_2 - alpha[2]), cos(theta3)*sin(alpha[2])*-1, a[2]*sin(theta3)},
            {0, sin(alpha[2]), sin(M_PI_2 - alpha[2]), d[2]},
            {0, 0, 0, 1}
        };

        double result1[4][4];
        double result2[4][4];

        kaliMatrix(mtx01, mtx02, result1);
        kaliMatrix(result1, mtx03, result2);

        cout << fixed << setprecision(2);
        cout << result2[0][3] << endl << result2[1][3] << endl << result2[2][3];

    } else if (robot == "D") {
        double d1 = 6;
        double d[3] = {d1, 0, 0};
        cin >> theta1 >> theta2 >> theta3;
        theta1 = theta1 * M_PI/180;
        theta2 = theta2 * M_PI/180;
        theta3 = theta3 * M_PI/180;

        double mtx01[4][4] = {
            {cos(theta1), sin(theta1)*sin(M_PI_2 - alpha[0]) * -1, sin(theta1)*sin(alpha[0]), a[0]*cos(theta1)},
            {sin(theta1), cos(theta1)*sin(M_PI_2 - alpha[0]), cos(theta1)*sin(alpha[0])*-1, a[0]*sin(theta1)},
            {0, sin(alpha[0]), sin(M_PI_2 - alpha[0]), d[0]},
            {0, 0, 0, 1}
        };

        double mtx02[4][4] = {
            {cos(theta2), sin(theta2)*sin(M_PI_2 - alpha[1]) * -1, sin(theta2)*sin(alpha[1]), a[1]*cos(theta2)},
            {sin(theta2), cos(theta2)*sin(M_PI_2 - alpha[1]), cos(theta2)*sin(alpha[1])*-1, a[1]*sin(theta2)},
            {0, sin(alpha[1]), sin(M_PI_2 - alpha[1]), d[1]},
            {0, 0, 0, 1}
        };

        double mtx03[4][4] = {
            {cos(theta3), sin(theta3)*sin(M_PI_2 - alpha[2]) * -1, sin(theta3)*sin(alpha[2]), a[2]*cos(theta3)},
            {sin(theta3), cos(theta3)*sin(M_PI_2 - alpha[2]), cos(theta3)*sin(alpha[2])*-1, a[2]*sin(theta3)},
            {0, sin(alpha[2]), sin(M_PI_2 - alpha[2]), d[2]},
            {0, 0, 0, 1}
        };

        double result1[4][4];
        double result2[4][4];

        kaliMatrix(mtx01, mtx02, result1);
        kaliMatrix(result1, mtx03, result2);

        cout << fixed << setprecision(2);
        cout << result2[0][3] << endl << result2[1][3] << endl << result2[2][3];
    }
}
