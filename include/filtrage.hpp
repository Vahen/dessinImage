

#ifndef FILTRAGE_H
#define FILTRAGE_H

#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <list>
#include "figure.hpp"
#include "condition.hpp"

using namespace std;
using namespace condition;

class Filtrage {

public:
    static void remplitAlea(list<int> entiers, int n);

    static int compterSi(list<const Figure *> figures, Condition *condition, bool test);

    static bool supprimerSi(list<const Figure *> &figures, Condition *condition);

    static bool supprimerSiBis(list<const Figure *> &figures, Condition *condition);

    static bool supprimerSiProfond(list<const Figure *> &figures, Condition *condition);

    static bool supprimerSiProfondBis(list<const Figure *> &figures, Condition *condition);

    static Figure *getUneFigure(int x, int y);

    static list<const Figure *> creerFigures(int n);
};

#endif
