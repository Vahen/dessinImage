#include <sstream>
#include <figure/cercle.hpp>///////rm
#include <figure/triangle.hpp>////////////rm
#include <figure/rectangle.hpp>////////////rm
#include <figure/filtrage.hpp>
#include <dessin/SDLdessin.hpp>
#include <figure/serialisationJSON.hpp>
#include <condition/estPetite.hpp>

namespace figure {

	using namespace std;
	using namespace figure;
	using namespace calcul;
	using namespace dessin;
    using namespace condition;

	void main() {

		const Serialisation & serialisation = SerialisationJSON();

		SDLdessin dessin(800, 800);
		dessin.initialise();
	
		/*
        Ligne l(Point(420, 520), Point(730, 620));
        Ligne l2(Point(200, 500), Point(340, 640));
        Ligne l3(Point(340, 500), Point(200, 640));
        Cercle c(Point(140, 180), 80);
        Cercle c2(Point(580, 300), 140);
        Cercle c3(Point(580, 300), 80);
        Cercle c4(Point(580, 110), 40);
        Cercle c5(Point(480, 135), 40);
        Cercle c6(Point(408, 210), 40);
        Triangle t(Point(50, 290), Point(250, 290), Point(100, 580));
        Rectangle r(Point(400, 500), Point(750, 640));
        Image image;
        image.ajouter(c);
        image.ajouter(t);
        image.ajouter(l2);
        image.ajouter(l3);
        Image image2;
        image2.ajouter(r);
        image2.ajouter(l);
        Image image3;
        image2.ajouter(c2);
        image2.ajouter(c3);
        image2.ajouter(c4);
        image2.ajouter(c5);
        image2.ajouter(c6);
        image.ajouter(image2);
        image.ajouter(image3);
        serialisation.sauvegarde("./data/demo.json", image);
        */

        shared_ptr<Figure> figure = serialisation.charge("data/demo.json");
        figure->dessiner(dessin);
        dessin.attendTouche();
        
    }

}

int WinMain() {
    figure::main();
    return 0;
}

int main() {
    figure::main();
    return 0;
}

