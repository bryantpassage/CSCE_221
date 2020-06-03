#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

template<typename T, int n>
class Point
{
private:
    T location[n];
public:
    Point();
    Point(T pos[n])
    {
        for(int i = 0; i < n; i++)
        {
            location[i] = pos[i];
        }
    }
    void printLoc() const
    {
        for(int i = 0; i < n; i++)
        {
            std::cout << location[i];
            if(i < n - 1)
                std::cout << ",";
        }
        std::cout << std::endl;
    }
    int getDimension() const { return n; }

    const T* getLocation() const { return location; }
};

template<typename T>
double findDistance(T& p1, T& p2)
{
    int n = p1.getDimension();
    double dist[n];
    for(int i = 0; i < n; i++)
    {
        dist[i] = static_cast<double>(p1.getLocation()[i]) - p2.getLocation()[i];
        // std::cout << dist[i] << " "; //debug
    }
    // std::cout << std::endl;
    double total = 0;
    for(int i = 0; i < n; i++)
    {
        total += (dist[i]) * (dist[i]);
    }
    // std::cout << total << std::endl; //debug
    double totalDistance = sqrt(total);
    return totalDistance;
}

#endif