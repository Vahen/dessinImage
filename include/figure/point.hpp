#ifndef POINT_H
#define POINT_H

#include <iostream>

namespace figure {

    using namespace std;

    class Point {

    public:

        /**
         * Construit un point vide
         */
        explicit Point();

        /**
         * Construit un point
         * \param x : la valeur du point en abscisse
         * \param y : la valeur du point en ordonnee
         */
        explicit Point(float x, float y);

        /**
         * Renvoie la valeur en abscisse du point
         * \return la valeur en abscisse du point
         */
        float getX() const;

        /**
         * Renvoie la valeur en ordonnee du point
         * \return la valeur en ordonnee du point
         */
        float getY() const;

        /**
         * Realise l'addition terme a terme de deux points
         * \param p : le point a additionner
         * \return le point resultant de l'addition
         */
        Point operator+(const Point &p) const; //TODO rm

        /**
         * Realise l'incrementation terme a terme d'un point
         * \param p : valeur du point a ajouter
         * \return une reference vers l'instance du point
         */
        Point &operator+=(const Point &p); //TODO rm

        /**
         * Ecrit un point dans un flux
         * \param os : le flux
         * \param p : le point a ecrire
         * \return le flux
         */
        friend ostream &operator<<(ostream &os, const Point &p);

    private:

        float _x;
        float _y;

    };

}

#endif