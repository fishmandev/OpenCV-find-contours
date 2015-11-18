#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char **argv) {
    IplImage *src, *gray, *dst;
    CvMemStorage *storage = cvCreateMemStorage(0);
    CvSeq *contours = 0;

    src = cvLoadImage("img/src.png", 1);
    gray = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
    dst = cvCreateImage(cvGetSize(src), IPL_DEPTH_32F, 3);

    cvSet(dst, cvScalar(255, 255, 255));
    cvCvtColor(src, gray, CV_RGB2GRAY);

    cvFindContours(gray, storage, &contours, sizeof(CvContour), CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);

    for (CvSeq *seq0 = contours; seq0 != 0; seq0 = seq0->h_next) {
        cvDrawContours(dst, seq0, CV_RGB(255, 0, 0), CV_RGB(0, 0, 255), 0, 1, 8);
    }

    cvSaveImage("img/dst.png", dst);

    cvReleaseImage(&src);
    cvReleaseImage(&dst);
    cvReleaseImage(&gray);

    return 0;
}