#include <iostream>
#include <vector>
#include <string>

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
    vector<Figure *> vc;

    string s;
    int x1, x2, y1, y2, rad;

    do
    {
        cout << "Enter figure type or draw:";
        cin >> s;

        if(s == "rectangle") {
            cout << "Enter x, y coordinates of P1:";
            cin >> x1 >> y1;

            cout << "Enter x, y coordinates of P2:";
            cin >> x2 >> y2;

            Rectangle* rec1 = new Rectangle(Point(x1,y1), Point(x2,y2));

            vc.push_back(rec1);

        } else if(s == "circle") {
            cout << "Enter x, y coordinates of P1:";
            cin >> x1 >> y1;

            cout << "Enter the radius:";
            cin >> rad;

            Circle* cir1 = new Circle(Point(x1,y1), rad);

            vc.push_back(cir1);

        } else if(s == "draw") {
            vector<Figure*>::iterator it;
            for(it = vc.begin(); it != vc.end(); it++) {
                Figure* fig = *it;

                fig->draw();
            }


            break;

        } else {
            continue;
        }

    } while (1);

    return 0;
}

