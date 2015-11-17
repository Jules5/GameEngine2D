#ifndef DECORVIEW_H
#define DECORVIEW_H

/*!
 * \file DecorView.h
 * \author Jules
 * \brief Déclaration de la classe DecorView
 * \addtogroup View
 * @{
 */

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <model/Decor.h>
// #include <view/MyDrawable.h>

using namespace std;
using namespace sf;




class DecorView
{

	private :

		Decor* target;
		RectangleShape body; 


	public :
		

		DecorView();

		DecorView(Decor*);

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe DecorView
	     */
		~DecorView();

		void init();

		/*!
	     * \brief Affichage
	     *
	     * Affiche l'objet dans une fenêtre de rendu.
	     * \param window : Fenêtre d'affichage
	     */
		void display(RenderWindow* window);

		void update();

};


/** @}*/

#endif
