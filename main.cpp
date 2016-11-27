#include <iostream>
#include <cvaux.h>
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

/*
 *  Bismillahir Rohmanir Rohiym
 */

int main(){
    Mat img1 = imread("/home/o2b3k/Documents/tutorial/image1.jpg");
    Mat img2 = imread("/home/o2b3k/Documents/tutorial/image1.jpg");
    Mat img3 = imread("/home/o2b3k/Documents/tutorial/image1.jpg");

    cvtColor(img1,img1, CV_RGB2GRAY);
    cvtColor(img2,img2, CV_RGB2GRAY);
    cvtColor(img3,img3, CV_RGB2GRAY);
    cvNamedWindow("1",1);
    imshow("1",img1);
    imshow("2",img2);
    imshow("3",img3);
    cvNamedWindow("2",1);
    cvNamedWindow("3",1);
    Mat res = img2.clone();

    for ( int i=0; i<img1.rows; i++ ) {
        for (int k = 0; k < img1.cols; k++) {
            res.at<uchar>(i,k) = (img1.at<uchar>(i,k)+img2.at<uchar>(i,k)+img3.at<uchar>(i,k))/3;
        }
    }
    cout<<img1<<endl;
    cout<<res<<endl;
    cvNamedWindow("res",1);
    imshow("res",res);
    waitKey(0);
    return 0;
};