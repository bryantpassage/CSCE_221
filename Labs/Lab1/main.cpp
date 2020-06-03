#include <iostream>

using namespace std;

struct Point
{
public:
    double x, y;
    Point() :
        x(0.0), y(0.0) {}
    Point(double x, double y) :
        x(x), y(y) {}
    Point operator+(const Point& rhs)
    {
        double newX = this->x + rhs.x;
        double newY = this->y + rhs.y;
        Point newPoint(newX, newY);
        return newPoint;
    }
};

class Shape
{
protected:
    Point p;
public:
    Shape() :
        p(0, 0) {}
    Shape(double x, double y) :
        p(x, y) {}
    virtual void Print() = 0;
};

class Circle : public Shape
{
private:
    double radius;
public:
    Circle():
        Shape(), radius(0) {}
    Circle(double x, double y, double r):
        Shape(x, y), radius(r) {}
    void Print()
    {
        cout << "Circle at position " << p.x << "," << p.y << " with radius " << radius << endl;
    }
};

class Square : public Shape
{
private:
    double slength;
public:
    Square() : 
        Shape(), slength(0) {}
    Square(double x, double y, double n) : 
        Shape(x, y), slength(n) {}
    void Print()
    {
        cout << "Square at position " << p.x << "," << p.y << " with side length of " << slength << endl;
    }
};

int main()
{
    Shape* mySquare1 = new Square(3,5,6);
    Shape* myCircle1 = new Circle();
    mySquare1->Print();
    myCircle1->Print();
    cout << endl;
    cout << "Addition of two points (4,8) and (3,7):" << endl;
    Point p1(4,8);
    Point p2(3,7);
    cout << "(" << (p1 + p2).x << "," << (p1 + p2).y << ")" << endl;
    delete mySquare1;
    delete myCircle1;
}