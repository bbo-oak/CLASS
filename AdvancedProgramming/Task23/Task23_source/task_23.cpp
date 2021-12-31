#include <iostream>

using namespace std;

class Figure {
public:
    virtual void draw() {};
};

class Point {
public:
    Point() : x(0), y(0) {};
    Point(int n1, int n2) : x(n1), y(n2) {};

    int x,y;
};

class Rectangle : public Figure {
public:
    Rectangle() : p1(Point()), p2(Point()) {};
    Rectangle(Point np1, Point np2) : p1(np1), p2(np2) {};

    void draw() {
        cout << "A rectangle from (" << p1.x << ", " << p1.y << ") to (" << p2.x << ", " << p2.y << ")" << endl;
    }


private:
    Point p1, p2;
};

class Circle : public Figure {
public:
    Circle() : p1(Point()), r1(0) {};
    Circle(Point np1, int nr1) : p1(np1), r1(nr1) {};

    void draw() {
        cout << "A circle with the center of (" << p1.x << ", " << p1.y << ") and the radius of " << r1 << endl;
    }


private:
    Point p1;
    int r1;

};


void draw2figues (Figure& f1, Figure& f2)

{

    cout << "First figure is: ";

    f1.draw();

    cout << "Second figure is: ";

    f2.draw();

}

 

int main ()

{

    Point p1(0,0), p2(2,2);

    Rectangle r1 (p1, p2);

    Circle c1 (p1, 2);

    draw2figues(r1, c1);

}

