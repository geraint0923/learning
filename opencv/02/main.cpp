#include <opencv2/opencv.hpp>

using namespace std;

int main() {
    const char *pstrImageName = "/Users/yy/Pictures/avatar.jpg";
    const char *pstrScaledImageName = "avatar.jpg";
    const char *pstrWindowsTitle = "OpenCV-Demo";
    const char *pstrScaledWindowsTitle = "OpenCV-Demo-Scaled";

    double fScale = 0.314;
    CvSize czSize;

    IplImage *pImage = cvLoadImage(pstrImageName, CV_LOAD_IMAGE_UNCHANGED);
    IplImage *pScaledImage = NULL;

    czSize.width = pImage->width * fScale;
    czSize.height = pImage->height * fScale;

    pScaledImage = cvCreateImage(czSize, pImage->depth, pImage->nChannels);
    cvResize(pImage, pScaledImage, CV_INTER_AREA);

    cvNamedWindow(pstrWindowsTitle, CV_WINDOW_AUTOSIZE);
    cvNamedWindow(pstrScaledWindowsTitle, CV_WINDOW_AUTOSIZE);

    cvShowImage(pstrWindowsTitle, pImage);
    cvShowImage(pstrScaledWindowsTitle, pScaledImage);

    cvWaitKey();

    cvSaveImage(pstrScaledImageName, pScaledImage);

    cvDestroyWindow(pstrWindowsTitle);
    cvDestroyWindow(pstrScaledWindowsTitle);
    cvReleaseImage(&pImage);
    cvReleaseImage(&pScaledImage);
    return 0;
}
