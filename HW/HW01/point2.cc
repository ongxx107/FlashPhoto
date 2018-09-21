
#include <iostream>
#include "point2.h"
#include <math.h> //FOR SQRT()

Point2::Point2(){

    x = 0.0;
    y = 0.0;
    
}

Point2::Point2(float TempX, float TempY){

    x = TempX;
    y = TempY;

}


float Point2::DistanceBetween(Point2 NewPtr){

    distance = sqrt( pow( (x-NewPtr.x), 2) + pow( (y-NewPtr.y), 2) );
    return distance;

}
