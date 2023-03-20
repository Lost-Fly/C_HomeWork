#include <iostream>
#include <cmath>

using namespace std;

class Point {
public:
    void set(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int x;
    int y;
};

class Vector {
public:
    Vector(Point p1, Point p2) {
        this->pstart.x = p1.x;
        this->pstart.y = p1.y;
        this->pend.x = p2.x;
        this->pend.y = p2.y;
    }


    ~Vector() { cout << "Vector object deleted" << endl; }

    double length() const {
        double dx = this->pend.x - this->pstart.x;
        double dy = this->pend.y - this->pstart.y;
        return sqrt(dx * dx + dy * dy);
    }

    Vector add(const Vector& addv) const {
        double x1 = this->pstart.x + addv.pstart.x;
        double y1 = this->pstart.y + addv.pstart.y;
        double x2 = this->pend.x + addv.pend.x;
        double y2 = this->pend.y + addv.pend.y;
        Point p1, p2;
        p1.set(x1, y1);
        p2.set(x2, y2);
        return Vector(p1, p2);
    }

    bool contains(const Point& point) const {
        double dx1 = point.x - this->pstart.x;
        double dy1 = point.y - this->pstart.y;
        double dx2 = point.x - this->pend.x;
        double dy2 = point.y - this->pend.y;
        return abs(dx1) + abs(dy1) == abs(this->pend.x - this->pstart.x) + abs(this->pend.y - this->pstart.y)
            && abs(dx2) + abs(dy2) == abs(this->pend.x - this->pstart.x) + abs(this->pend.y - this->pstart.y);
    }

    void show() {
        cout << '(' << pstart.x << ',' << pstart.y << ')' << "------->" << '(' << pend.x << ',' << pend.y << ')' << endl;
    }

private:
    Point pstart;
    Point pend;
};

// пример использования класса
int main() {
    // создаем векторы
    Point p1, p2, p3;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    p1.set(x1, y1);
    p2.set(x2, y2);
    p3.set(x1 + x2, y1 + y2);
    Vector v1(p1, p2);
    Vector v2(p2, p1);
    v1.show();
    v2.show();
    // выводим длину радиус-вектора
    cout << "Length of v1: " << v1.length() << endl;

    // складываем два вектора
    Vector v3 = v1.add(v2);
    v3.show();

    // проверяем принадлежность точки вектору
    
    cout << "p1 is contained in v3: " << v3.contains(p1) << endl;
    cout << "p3 is contained in v3: " << v3.contains(p3) << endl;

    return 0;
}
