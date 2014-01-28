#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

IplImage *pImage, *pDstImage;

const char *pDstWindowTitle = "Threshold";

void on_trackbar(int threshold) {
    cvThreshold(pImage, pDstImage, threshold, 255, CV_THRESH_BINARY);
    cvShowImage(pDstWindowTitle, pDstImage);
    cout << "Threshold: " << threshold << endl;
}

int main() {
    const char *pImageName = "/Users/yy/Pictures/aaa.png";
    const char *pWindowTitle = "Origin Image";
    const char *pWindowToolBar = "Threshold";

    pImage = cvLoadImage(pImageName, CV_LOAD_IMAGE_GRAYSCALE);
    pDstImage = cvCreateImage(cvGetSize(pImage), IPL_DEPTH_8U, 1);

    cvNamedWindow(pWindowTitle, CV_WINDOW_AUTOSIZE);
    cvNamedWindow(pDstWindowTitle, CV_WINDOW_AUTOSIZE);

    int nThresholdEdge = 1;
    cvCreateTrackbar(pWindowToolBar, pDstWindowTitle, &nThresholdEdge, 100, on_trackbar);

    cvShowImage(pWindowTitle, pImage);
    on_trackbar(1);

    cvWaitKey();

    cvDestroyWindow(pWindowTitle);
    cvDestroyWindow(pDstWindowTitle);

    cvReleaseImage(&pImage);
    cvReleaseImage(&pDstImage);

    return 0;
}
