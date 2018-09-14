
#ifndef POINT2_H_
#define POINT2_H_

#include <iostream>
#include <fstream>
#include <string>
#include <math.h> //FOR SQRT()
#include <string>

class Point2{
    public:
        Point2();
        Point2(float TempX, float TempY);

        float DistanceBetween(Point2 NewPtr);


    private:
        float x, y, distance;
};

#endif
