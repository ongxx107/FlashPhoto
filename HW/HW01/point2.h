
#ifndef POINT2_H_
#define POINT2_H_

#include <iostream>
#include <fstream>
#include <string>
#include <math.h> //FOR SQRT()
#include <string>

class Point2{
    public:
        Point2 p00();
        Point2 p11(float, float);
        Point2 p21(float, float);
        Point2 p12(float, float);
        Point2 pPI45(float, float);
        Point2 p_a(float, float);
        Point2 p_b(float, float);

        Point2 DistanceBetween(Point2);

    
    private:
        float x, y, distance;
};

#endif
