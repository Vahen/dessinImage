#include "cercle.hpp"

#include "matrice2D.hpp"

namespace figure {

Cercle Cercle::temoin = Cercle(Point(0, 0), 0);

Cercle::Cercle() : Cercle(Point(0,0), 0) {

}
Cercle::Cercle(const Point &centre) : Cercle(centre, 0) {

}

Cercle::Cercle(const Point &centre, int rayon) : _centre(centre), _rayon(rayon) {

}

shared_ptr<Figure> Cercle::copy() const {
    return std::make_shared<Cercle>(this->_centre, this->_rayon);
}

void Cercle::deplacer(const Point &p) {
    _centre += p;
}

void Cercle::translation(int x, int y) {
	Matrice2D transformation = Matrice2D::translation(x,y);
	_centre = transformation * _centre;
}

void Cercle::rotation(float theta) { //TODO rotation d'un cercle ?
	
}
	
void Cercle::homothetie(float k) {
	Matrice2D transformation = Matrice2D::homothetie(k);
	_centre = transformation * _centre;
	_rayon *= k;
}

void Cercle::dessiner(ostream &os) const {
    os << *this << endl;;
}

double Cercle::surface() const {
    return 3.1416 * _rayon * _rayon;
}

void Cercle::afficher(ostream &os) const {
    os << "cercle : (" << _centre << ", " << _rayon << ")" << endl;
}

}
