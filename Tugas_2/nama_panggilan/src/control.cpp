#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include "turtlesim/TeleportAbsolute.h"
#include "turtlesim/SetPen.h"
#include <string>
#include <iostream>
using namespace std;

void poseCallback(const turtlesim::Pose msg) {
    // ROS_INFO("Posisi x = %f | Posisi y = %f", msg.x, msg.y);
}

void pindahTempat(ros::ServiceClient &client, float x, float y, float theta) {
    turtlesim::TeleportAbsolute srvc;
    srvc.request.x = x;
    srvc.request.y = y;
    srvc.request.theta = theta;
    client.call(srvc);
}

void hapusCoret(ros::ServiceClient &client, bool off) {
    turtlesim::SetPen srvc;
    srvc.request.off = off;
    client.call(srvc);
}

void munculCoret(ros::ServiceClient &client, int r, int g, int b, int width, bool off) {
    turtlesim::SetPen srvc;
    srvc.request.r = r;
    srvc.request.g = g;
    srvc.request.b = b;
    srvc.request.width = width;
    srvc.request.off = off;
    client.call(srvc);
}

void gantiWarna(ros::ServiceClient &client, int r, int g, int b, int width) {
    turtlesim::SetPen srvc;
    srvc.request.r = r;
    srvc.request.g = g;
    srvc.request.b = b;
    srvc.request.width = width;
    client.call(srvc);
}

void gambarR(ros::Publisher &pub) {
    geometry_msgs::Twist cmd;
    ros::Rate rate(1);

    cmd.linear.y = 2.0;
    pub.publish(cmd);
    rate.sleep();
    
    cmd.linear.x = 1.5;
    cmd.linear.y = 0.0;
    cmd.angular.z = -2.7;
    pub.publish(cmd);
    rate.sleep();

    cmd.linear.x = -0.1;
    cmd.linear.y = 1.0;
    cmd.angular.z = 0.0;
    pub.publish(cmd);
    rate.sleep();

}

void gambarA(ros::Publisher &pub) {
    geometry_msgs::Twist cmd;
    ros::Rate rate(1);

    cmd.linear.x = 1.0;
    cmd.linear.y = 1.75;
    pub.publish(cmd);
    rate.sleep();
    
    cmd.linear.x = 1.0;
    cmd.linear.y = -1.8;
    pub.publish(cmd);
    rate.sleep();

    cmd.linear.x = -0.5;
    cmd.linear.y = 0.9;
    pub.publish(cmd);
    rate.sleep();

    cmd.linear.x = -1.0;
    cmd.linear.y = 0.0;
    pub.publish(cmd);
    rate.sleep();

}

void gambarD(ros::Publisher &pub) {
    geometry_msgs::Twist cmd;
    ros::Rate rate(1);

    cmd.linear.y = 2.0;
    pub.publish(cmd);
    rate.sleep();
    
    cmd.linear.x = 3.0;
    cmd.linear.y = 0.0;
    cmd.angular.z = -2.9;
    pub.publish(cmd);
    rate.sleep();
}

void gambarI(ros::Publisher &pub) {
    geometry_msgs::Twist cmd;
    ros::Rate rate(1);

    cmd.linear.y = 2.0;
    pub.publish(cmd);
    rate.sleep();
}

void gambarT(ros::Publisher &pub) {
    geometry_msgs::Twist cmd;
    ros::Rate rate(1);

    cmd.linear.y = 2.0;
    pub.publish(cmd);
    rate.sleep();

    cmd.linear.x = -0.5;
    cmd.linear.y = 0.0;
    pub.publish(cmd);
    rate.sleep();

    cmd.linear.x = 1.0;
    pub.publish(cmd);
    rate.sleep();
}

void gambarManual(ros::Publisher &pub, float x, float y, float z) {
    geometry_msgs::Twist cmd;
    ros::Rate rate(1);

    cmd.linear.x = x;
    cmd.linear.y = y;
    cmd.angular.z = z;
    pub.publish(cmd);
    rate.sleep();
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "tulis_nama");
    ros::NodeHandle n;
    ros::ServiceClient service_pindahTempat = n.serviceClient<turtlesim::TeleportAbsolute>("/turtle1/teleport_absolute");
    ros::ServiceClient service_setpen = n.serviceClient<turtlesim::SetPen>("/turtle1/set_pen");
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
    ros::Subscriber sub = n.subscribe("/turtle1/pose", 1000, poseCallback);
    ros::Rate loop_rate(1);
    ros::Duration delay_func(2.0);

    int r, g, b, width;

    cout << "List CMD" << endl << "1. berhenti" << endl << "2. pindah [x y sudut]" << endl << "3. gerak [x y z]" << endl << "4. bantuan" << endl << "5. radit (Tulis Otomatis)" << endl << "6. warna\n"; 

    while (ros::ok()) {
        string status;
        float dx, dy, dz, radian;

        cout << "Perintah : ";
        cin >> status;

        if (status == "berhenti") {
            break;
        } else if (status == "pindah") {
            cin >> dx >> dy >> radian;

            hapusCoret(service_setpen, true);
            pindahTempat(service_pindahTempat, dx, dy, radian);
            munculCoret(service_setpen, r, g, b, 3, false);
            delay_func.sleep();
        } else if (status == "gerak") {
            cin >> dx >> dy >> dz;

            munculCoret(service_setpen, r, g, b, 3, false);
            gambarManual(pub, dx, dy, dz);

        } else if (status == "radit") {
            hapusCoret(service_setpen, true);
            pindahTempat(service_pindahTempat, 1.0, 8.5, 0.0);
            munculCoret(service_setpen, r, g, b, 3, false);
            delay_func.sleep();

            gambarR(pub);

            delay_func.sleep();
            hapusCoret(service_setpen, true);
            pindahTempat(service_pindahTempat, 2.5, 8.5, 0.0);
            munculCoret(service_setpen, r, g, b, 3, false);

            gambarA(pub);

            delay_func.sleep();
            hapusCoret(service_setpen, true);
            pindahTempat(service_pindahTempat, 5.3, 8.5, 0.0);
            munculCoret(service_setpen, r, g, b, 3, false);

            gambarD(pub);

            delay_func.sleep();
            hapusCoret(service_setpen, true);
            pindahTempat(service_pindahTempat, 6.9, 8.5, 0.0);
            munculCoret(service_setpen, r, g, b, 3, false);

            gambarI(pub);

            delay_func.sleep();
            hapusCoret(service_setpen, true);
            pindahTempat(service_pindahTempat, 8.0, 8.5, 0.0);
            munculCoret(service_setpen, r, g, b, 3, false);

            gambarT(pub);

            delay_func.sleep();
            hapusCoret(service_setpen, true);
            pindahTempat(service_pindahTempat, 5.5, 5.5, 0.0);
        } else if (status == "bantuan") {
            cout << "Huruf R (1 8.5 0)\n1. 0 2 0\n2. 1.5 0 -2.7\n3. -0.1 1 0" << endl;
            cout << "Huruf A (2.5 8.5 0)\n1. 1 1.75 0\n2. 1 -1.8 0\n3. -0.5 0.9 0\n4. -1.0 0 0" << endl;
            cout << "Huruf D (5.3 8.5 0)\n1. 0 2 0\n2. 3 0 2.9" << endl;
            cout << "Huruf I (6.9 8.5 0)\n1. 0 2 0" << endl;
            cout << "Huruf T (8 8.5 0)\n1. 0 2 0\n2. 1 0 0" << endl;
        } else if (status == "warna") {
            cout << "[R G B Width]" << endl;
            cin >> r >> g >> b >> width;

            gantiWarna(service_setpen, r, g, b, width);
        }

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}