#include "figure/point.hpp"

namespace figure {

    Point::Point(float x, float y) : _x(x), _y(y) {}

    Point::Point() : Point(0, 0) {};

    float Point::Point::getX() const {
        return _x;
    }

    float Point::Point::getY() const {
        return _y;
    }
    
    Point operator+ (const Point &p1, const Point &p2) {
		return Point(p1._x + p2._x, p1._y + p2._y);
	}
    
	Point operator* (const Matrice2D &matrice, const Point &point) {
		float x = point._x;
		float y = point._y;
		matrice.transformePoint(x,y);
		return Point(x,y);
	}
    
    ostream &operator<<(ostream &os, const Point &p) {
        return (os << '(' << p._x << ',' << p._y << ')');
    }

}
