#ifndef PLATFORMVIEW_H
#define PLATFORMVIEW_H

/*!
 * \file PlatformView.h
 * \author Jules
 * \brief Déclaration de la classe PlatformView
 * \addtogroup View
 * @{
 */

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <model/Platform.h>

using namespace std;
using namespace sf;




/*!\class PlatformView
 * \brief Un objet Plateform affichable.
 *
 * Permet d'afficher un objet Platform. Si la plateforme a
 * une hauteur nulle, on ne l'affiche pas (c'est une plateforme
 * invisible).
 */
class PlatformView
{

	private :

		Platform* target;
		RectangleShape body; 


	public :
		
		PlatformView();
		PlatformView(Platform*);
		~PlatformView();

		void init();

		void update();
		void display(RenderWindow* window);
		
};


/** @}*/

#endif
