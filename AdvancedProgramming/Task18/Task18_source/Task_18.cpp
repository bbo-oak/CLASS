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
    const int operator*(const Vector2D& v2) const;
    friend const Vector2D operator+(const Vector2D& v1, const Vector2D& v2);
    friend const Vector2D operator-(const Vector2D& v1, const Vector2D& v2);
    friend const bool operator==(const Vector2D& v1, const Vector2D& v2);
    friend const Vector2D operator* (const int n, const Vector2D& v1);
    friend ostream& operator <<(ostream& output, const Vector2D& v1);

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

const int Vector2D::operator*(const Vector2D& v2) const {
    return x * v2.y + y * v2.x;
}

const Vector2D operator+(const Vector2D& v1, const Vector2D& v2) {
    return Vector2D(v1.x + v2.x, v1.y + v2.y);
}

const Vector2D operator-(const Vector2D& v1, const Vector2D& v2) {
    return Vector2D(v1.x - v2.x, v1.y - v2.y);
}

const bool operator==(const Vector2D& v1, const Vector2D& v2) {
    return ((v1.x == v2.x) && (v1.y == v2.y));
}

const Vector2D operator* (const int n, const Vector2D& v1) {
    return Vector2D(v1.x * n, v1.y * n);
}

ostream& operator <<(ostream& output, const Vector2D& v1) {
    output << "(" << v1.x << " , " << v1.y << ")";

    return output;
}

int main()

{

  Vector2D v0, v1(2,2), v2(3,3), v3;

  cout << v1 << endl;

  cout << v1 + v2 << endl;

}

