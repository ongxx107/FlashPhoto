
// Copyright 2018 CSCI3081W


#ifndef HW01_POINT2_H_
#define HW01_POINT2_H_

#include <math.h>  //  FOR SQRT()
#include <iostream>
#include <fstream>
#include <string>

class Point2 {
 public:
        Point2();
        Point2(float TempX, float TempY);
        float DistanceBetween(Point2 NewPtr);

 private:
        float x, y, distance;
}

#endif  // HW01_POINT2_H_
