/*
 * eyes.cpp
 *
 *  Created on: 24-Dec-2014
 *      Author: Jewel James
 */
#include<iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main(int argc,char** argv)

{
if (argc !=2)
 {cout<< "usage : ./eyes <your image>"<< endl;
return -1;}


else{
Mat mob_input ,hsv, channels[3] ;
mob_input = imread(argv[1], 1);

cvtColor(mob_input,hsv,CV_BGR2HSV);
namedWindow("hsv format", WINDOW_NORMAL);
imshow("hsv format",hsv);

split(mob_input,channels);

namedWindow("source", WINDOW_NORMAL);
imshow("source",mob_input);
namedWindow("channels_b", WINDOW_NORMAL);
imshow("channels_b",channels[0]);
namedWindow("channels_g", WINDOW_NORMAL);
imshow("channels_g",channels[1]);
namedWindow("channels_r", WINDOW_NORMAL);
imshow("channels_r",channels[2]);
waitKey(0);

Mat color1(2,2, CV_8UC3, Scalar(0,0,255));
Mat color2(2,2, CV_8UC3, Scalar(0,255,0));
Mat color3(2,2, CV_8UC3, Scalar(255,0,0));

Mat hsv1,hsv2,hsv3;

cvtColor(color1,hsv1,CV_BGR2HSV);
cvtColor(color2,hsv2,CV_BGR2HSV);
cvtColor(color3,hsv3,CV_BGR2HSV);
cout<<hsv1<<"\n"<<hsv2<<"\n"<<hsv3<<"\n";
}
return 0;
}
