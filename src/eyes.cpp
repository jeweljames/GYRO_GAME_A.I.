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


Mat hsv1,hsv2,hsv3;

Mat color1_lower(mob_input.rows,mob_input.cols, CV_8UC3, Scalar(200,140,0));
Mat color2_lower(1,1, CV_8UC3, Scalar(222,174,49));
Mat color3_lower(1,1, CV_8UC3, Scalar(255,0,0));
Mat color1_upper(mob_input.rows,mob_input.cols, CV_8UC3, Scalar(220,150,0));
Mat color2_upper(1,1, CV_8UC3, Scalar(222,174,49));
Mat color3_upper(1,1, CV_8UC3, Scalar(255,0,0));


inRange(mob_input, color1_lower, color1_upper, hsv1);

namedWindow("source", WINDOW_NORMAL);
imshow("source",mob_input);
waitKey(1000);
namedWindow("channels_b", WINDOW_NORMAL);
imshow("channels_b",channels[0]);
waitKey(1000);
namedWindow("channels_g", WINDOW_NORMAL);
imshow("channels_g",channels[1]);
waitKey(1000);
namedWindow("channels_r", WINDOW_NORMAL);
imshow("channels_r",channels[2]);
waitKey(1000);
/*
hsv1 = {129, 229, 198}
hsv2= [98, 199, 222]
hsv3= [120, 255, 255] 


cvtColor(color1,hsv1,CV_BGR2HSV);
cvtColor(color2,hsv2,CV_BGR2HSV);
cvtColor(color3,hsv3,CV_BGR2HSV);
cout<<hsv1<<"\n"<<hsv2<<"\n"<<hsv3<<"\n"; */


namedWindow("color1_lower",WINDOW_NORMAL);
imshow("color1_lower",color1_lower);
waitKey(1000);
namedWindow("color1_upper",WINDOW_NORMAL);
imshow("color1_upper",color1_upper);
waitKey(1000);
namedWindow("one",WINDOW_NORMAL);
imshow("one",hsv1);
waitKey(0) ;
}
return 0;
}
