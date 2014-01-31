#include <opencv2/opencv.hpp>

using namespace std;

IplImage *pImage, *pDstImage;

const char *pDstWindowTitle = "Edge Detection";

void on_trackbar(int threshold) {
    cvCanny(pImage, pDstImage, threshold, threshold * 3, 3);
    cvShowImage(pDstWindowTitle, pDstImage);
}

int main() {
    const char *pImageName = "/Users/yy/Pictures/mama.JPG";
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
