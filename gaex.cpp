#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv )
{
    Mat image;
    image = imread("template.png", CV_LOAD_IMAGE_UNCHANGED );

    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    //Defines the gird parameters
    int stepSize = 85;
    int topBound = stepSize*7;
    int leftBound = stepSize*5;
    int bottomBound = stepSize*38;
    int rightBound = stepSize*27;
    int width = image.size().width;
    int height = image.size().height;

    //Draws the gird lines on the answer sheet
    for (int i = topBound; i<bottomBound+(stepSize*1); i += stepSize)
        line(image, Point(leftBound, i), Point(rightBound, i), Scalar(255, 0, 0));

    for (int i = leftBound; i<rightBound+(stepSize*1); i += stepSize)
        line(image, Point(i, topBound), Point(i, bottomBound), Scalar(255, 0, 0));

    //Creates the window to see the answer sheet
    namedWindow("GAEX", WINDOW_NORMAL );
    resizeWindow("GAEX", 464, 600);
    imshow("GAEX", image);

    waitKey(0);

    return 0;
}
