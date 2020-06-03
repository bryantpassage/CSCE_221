#include <iostream>
#include "Point.h"

using namespace std;

int main()
{
    double firstPos[3] = {3.2, 1.1, 6.7}; 
    Point<double, 3> firstPoint(firstPos); //first 3D point with float location
    firstPoint.printLoc();

    double secondPos[3] = {9.7, 6.3, 4.4};
    Point<double, 3> secondPoint(secondPos); //second 3D point with float location
    secondPoint.printLoc();

    double x = findDistance(firstPoint, secondPoint);
    cout << x << endl;

    int thirdPos[2] = {1,1};
    Point<int, 2> thirdPoint(thirdPos); //first 2D point with int location
    thirdPoint.printLoc();

    int fourthPos[2] = {9, 8};
    Point<int, 2> fourthPoint(fourthPos); //seond 2D point with int location
    fourthPoint.printLoc();

    double y = findDistance(thirdPoint, fourthPoint);
    cout << y << endl;
}