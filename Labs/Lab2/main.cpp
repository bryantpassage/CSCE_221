#include <iostream>

using namespace std;

class Point
{
private:
    int x, y;
public:
    Point():
        x(0), y(0)
    {
        cout << "Point Default Constructor Called" << endl;
    }
    Point(int x, int y):
        x(x), y(y)
    {
        cout << "Point Parameterized Constructor Called" << endl;
    }
    ~Point()
    {
        cout << "Point Destructor Called" << endl;
    }
};

int main()
{
    /* create 5 Points on the stack */
    Point myPoints[5];
    for(int i = 0; i < 5; i++)
    {
        myPoints[i] = Point(i, i+1);
    }

    cout << endl;

    /* create 10 Points on the heap */
    Point* heapPoints = new Point[10];
    for(int i = 0; i < 10; i++)
    {
        heapPoints[i] = Point(i, i+1);
    }
    delete[] heapPoints;
}