#include <opencv2/opencv.hpp>

using namespace std;

int main() {
	const char *pstrImageName = "/Users/yy/Pictures/avatar.jpg";
	const char *pstrWindowsTitle = "OpenCV-Demo";

	IplImage *pImage = cvLoadImage(pstrImageName, CV_LOAD_IMAGE_UNCHANGED);
	
	cvNamedWindow(pstrWindowsTitle, CV_WINDOW_AUTOSIZE);

	cvShowImage(pstrWindowsTitle, pImage);

	cvWaitKey();

	cvDestroyWindow(pstrWindowsTitle);
	cvReleaseImage(&pImage);
	return 0;
}
