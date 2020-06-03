#include <stdio.h>
#include <exception>
#include <assert.h>
#include <iostream>
#include "Deque.h"

using namespace std;

int main()
{
    Deque<int> intQ;

    assert(intQ.size() == 0);
    intQ.insertFirst(1);
    assert(intQ.size() == 1);
    assert(intQ.removeFirst() == 1);

    assert(intQ.size() == 0);
    intQ.insertFirst(1);
    assert(intQ.size() == 1);
    assert(intQ.removeLast() == 1);

    assert(intQ.size() == 0);
    intQ.insertFirst(1);
    intQ.insertFirst(0);
    assert(intQ.size() == 2);
    assert(intQ.removeLast() == 1);
    assert(intQ.removeLast() == 0);

    assert(intQ.size() == 0);
    intQ.insertFirst(1);
    intQ.insertFirst(0);
    assert(intQ.removeFirst() == 0);
    assert(intQ.removeFirst() == 1);

    assert(intQ.size() == 0);
    intQ.insertFirst(1);
    intQ.insertFirst(0);
    assert(intQ.removeFirst() == 0);
    assert(intQ.removeLast() == 1);

    assert(intQ.size() == 0);
    intQ.insertFirst(1);
    intQ.insertFirst(0);
    assert(intQ.removeLast() == 1);
    assert(intQ.removeFirst() == 0);

    assert(intQ.size() == 0);
    intQ.insertLast(1);
    assert(intQ.size() == 1);
    assert(intQ.removeFirst() == 1);

    assert(intQ.size() == 0);
    intQ.insertLast(1);
    assert(intQ.size() == 1);
    assert(intQ.removeLast() == 1);

    assert(intQ.size() == 0);
    intQ.insertLast(0);
    intQ.insertLast(1);
    assert(intQ.size() == 2);
    assert(intQ.removeLast() == 1);
    assert(intQ.removeLast() == 0);

    assert(intQ.size() == 0);
    intQ.insertLast(0);
    intQ.insertLast(1);
    assert(intQ.removeFirst() == 0);
    assert(intQ.removeFirst() == 1);

    assert(intQ.size() == 0);
    intQ.insertLast(0);
    intQ.insertLast(1);
    assert(intQ.removeFirst() == 0);
    assert(intQ.removeLast() == 1);

    assert(intQ.size() == 0);
    intQ.insertLast(0);
    intQ.insertLast(1);
    assert(intQ.removeLast() == 1);
    assert(intQ.removeFirst() == 0);

    assert(intQ.size() == 0);
    intQ.insertFirst(1);
    intQ.insertFirst(0);
    intQ.insertLast(2);
    intQ.insertLast(3);
    intQ.insertLast(4);
    intQ.insertLast(5);
    intQ.insertLast(6);
    for (int i = 0; i < 7; i++)
    {
        assert(intQ.removeFirst() == i);
        assert(intQ.size() == 6 - i);
    }

    assert(intQ.size() == 0);
    intQ.insertFirst(1);
    intQ.insertFirst(0);
    intQ.insertLast(2);
    intQ.insertLast(3);
    intQ.insertLast(4);
    intQ.insertLast(5);
    intQ.insertLast(6);
    for (int i = 0; i < 7; i++)
    {
        assert(intQ.removeLast() == 6 - i);
        assert(intQ.size() == 6 - i);
    }

    assert(intQ.size() == 0);
    intQ.insertLast(2);
    intQ.insertLast(3);
    intQ.insertLast(4);
    intQ.insertLast(5);
    intQ.insertLast(6);
    intQ.insertFirst(1);
    intQ.insertFirst(0);
    for (int i = 0; i < 7; i++)
    {
        assert(intQ.removeLast() == 6 - i);
        assert(intQ.size() == 6 - i);
    }

    assert(intQ.size() == 0);
    intQ.insertLast(2);
    intQ.insertLast(3);
    intQ.insertLast(4);
    intQ.insertLast(5);
    intQ.insertLast(6);
    intQ.insertFirst(1);
    intQ.insertFirst(0);
    for (int i = 0; i < 7; i++)
    {
        assert(intQ.removeFirst() == i);
        assert(intQ.size() == 6 - i);
    }

    assert(intQ.isEmpty());
    intQ.insertFirst(1);
    assert(intQ.first() == 1);
    assert(intQ.last() == 1);
    assert(!intQ.isEmpty());
    assert(intQ.removeLast() == 1);

    assert(intQ.isEmpty());
    intQ.insertLast(1);
    assert(intQ.first() == 1);
    assert(intQ.last() == 1);
    assert(!intQ.isEmpty());
    assert(intQ.removeFirst() == 1);

    cout << "All tests passed." << endl;

    return 0;
}