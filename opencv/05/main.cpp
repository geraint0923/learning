#include <opencv2/opencv.hpp>

using namespace std;

int main(int argc, char **argv) {
    const char *pstrWindowSrcTitle = "Origin Image";
    const char *pstrWindowOutTitle = "Out Image";

    const int IMAGE_WIDTH = 400;
    const int IMAGE_HEIGHT = 200;

    IplImage *pSrcImage = cvCreateImage(cvSize(IMAGE_WIDTH, IMAGE_HEIGHT), IPL_DEPTH_8U, 3);

    cvRectangle(pSrcImage, cvPoint(0, 0), cvPoint(pSrcImage->width, pSrcImage->height), CV_RGB(255, 255, 255), CV_FILLED);
    CvPoint ptCircleCenter = cvPoint(IMAGE_WIDTH / 4, IMAGE_HEIGHT / 2);
    int nRadius = 80;
    cvCircle(pSrcImage, ptCircleCenter, nRadius, CV_RGB(255, 255, 0), CV_FILLED);
    ptCircleCenter = cvPoint(IMAGE_WIDTH / 4, IMAGE_HEIGHT / 2);
    nRadius = 30;
    cvCircle(pSrcImage, ptCircleCenter, nRadius, CV_RGB(255, 255, 255), CV_FILLED);

    CvPoint ptLeftTop = cvPoint(IMAGE_WIDTH / 2 + 20, 20);
    CvPoint ptRightBottom = cvPoint(IMAGE_WIDTH - 20, IMAGE_HEIGHT - 20);
    cvRectangle(pSrcImage, ptLeftTop, ptRightBottom, CV_RGB(0, 255, 255), CV_FILLED);
    ptLeftTop = cvPoint(IMAGE_WIDTH / 2 + 60, 40);
    ptRightBottom = cvPoint(IMAGE_WIDTH - 60, IMAGE_HEIGHT - 40);
    cvRectangle(pSrcImage, ptLeftTop, ptRightBottom, CV_RGB(255, 255, 255), CV_FILLED);

    cvNamedWindow(pstrWindowSrcTitle, CV_WINDOW_AUTOSIZE);
    cvShowImage(pstrWindowSrcTitle, pSrcImage);

    IplImage *pGrayImage = cvCreateImage(cvGetSize(pSrcImage), IPL_DEPTH_8U, 1);
    cvCvtColor(pSrcImage, pGrayImage, CV_BGR2GRAY);

    IplImage *pBinaryImage = cvCreateImage(cvGetSize(pGrayImage), IPL_DEPTH_8U, 1);
    cvThreshold(pGrayImage, pBinaryImage, 250, 255, CV_THRESH_BINARY);


    CvMemStorage *pcvMStorage = cvCreateMemStorage();
    CvSeq *pcvSeq = NULL;
    cvFindContours(pBinaryImage, pcvMStorage, &pcvSeq, sizeof(CvContour), CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cvPoint(0, 0));

    IplImage *pOutImage = cvCreateImage(cvGetSize(pSrcImage), IPL_DEPTH_8U, 3);
    int nLevels = 5;

    cvRectangle(pOutImage, cvPoint(0, 0), cvPoint(pOutImage->width, pOutImage->height), CV_RGB(255, 255, 255), CV_FILLED);
    cvDrawContours(pOutImage, pcvSeq, CV_RGB(255, 0, 0), CV_RGB(0, 255, 0), nLevels, 2);

    cvNamedWindow(pstrWindowOutTitle, CV_WINDOW_AUTOSIZE);
    cvShowImage(pstrWindowOutTitle, pOutImage);

    cvWaitKey(0);
    
    cvReleaseMemStorage(&pcvMStorage);
    cvDestroyWindow(pstrWindowSrcTitle);
    cvDestroyWindow(pstrWindowOutTitle);
    cvReleaseImage(&pSrcImage);
    cvReleaseImage(&pGrayImage);
    cvReleaseImage(&pBinaryImage);
    cvReleaseImage(&pOutImage);
    
    return 0;
}
