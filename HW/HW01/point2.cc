// Copyright 2018 CSCI3081W


#include <math.h>  //  FOR SQRT()
#include <iostream>
#include "/point2.h"

Point2::Point2() {
    x = 0.0;
    y = 0.0;
}

Point2::Point2(float TempX, float TempY) {
    x = TempX;
    y = TempY;
}


float Point2::DistanceBetween(Point2 NewPtr) {
    distance = sqrt(pow((x-NewPtr.x), 2) + pow((y-NewPtr.y), 2));
    return distance;
}
