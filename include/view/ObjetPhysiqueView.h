#ifndef OBJETPHYSIQUEVIEW_H
#define OBJETPHYSIQUEVIEW_H

/*!
 * \file ObjetPhysique.h
 * \author Jules
 * \brief Déclaration de la classe MyDrawable
 * \addtogroup View
 * @{
 */

#include <iostream>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <model/ObjetPhysique.h>

using namespace std;
using namespace sf;



class ObjetPhysiqueView
{

	public :

		ObjetPhysique* target;
		RectangleShape body; 


	public :

		ObjetPhysiqueView();
		ObjetPhysiqueView(ObjetPhysique*);
		~ObjetPhysiqueView();

		void init();

		void update();
		void display(RenderWindow* window);

};


/** @}*/

#endif
