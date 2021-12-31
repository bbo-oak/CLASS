#include <iostream>

using namespace std;

class Vector2D {
public:
    Vector2D(int n1 = 0, int n2 = 0) {
        x = n1;
        y = n2;
    }
    void output();
    int get_x() const;
    int get_y() const;

private:
    int x,y;
};



void Vector2D::output() {
    printf("(%d,%d)\n", x,y);
}

int Vector2D::get_x() const {
    return x;
}

int Vector2D::get_y() const {
    return y;
}

const Vector2D operator+(const Vector2D& v1, const Vector2D& v2) {
    int x1 = v1.get_x();
    int y1 = v1.get_y();
    int x2 = v2.get_x();
    int y2 = v2.get_y();
    
    return Vector2D(x1+x2,y1+y2);
}
const Vector2D operator-(const Vector2D& v1, const Vector2D& v2) {
    int x1 = v1.get_x();
    int y1 = v1.get_y();
    int x2 = v2.get_x();
    int y2 = v2.get_y();
    
    return Vector2D(x1-x2,y1-y2);
}
const bool operator==(const Vector2D& v1, const Vector2D& v2) {
    return ((v1.get_x() == v2.get_x()) && (v1.get_y() == v2.get_y()));
}

int main()

{

  Vector2D v0, v1(2,2), v2(3,3), v3;

 

  v3 = v1 + v2;

  v3.output();

 

  v3 = v2 - v2;

  v3.output();

  if (v3 == v0)

     cout << "Operator - works!";

}