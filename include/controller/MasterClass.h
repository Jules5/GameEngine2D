#ifndef MASTERCLASS_H
#define MASTERCLASS_H

/*!
 * \file MasterClass.h
 * \author Jules
 * \brief Déclaration de la classe MasterClass
 * \addtogroup Controller 
 * @{
 */

#include <iostream>
#include <list>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <controller/Game.h>
#include <controller/Config.h>

using namespace std;
using namespace sf;


/*! \class MasterClass
 * \brief Initialisation du jeu
 *
 * Déclare la fenêtre de rendu, initialise et lance le jeu.
 */
class MasterClass
{

	private :

		RenderWindow window; /*!< \brief Fenêtre de rendu. */
		
		Game game; /*!< \brief Objet de gestion du jeu. */
		Config config; /*!< \brief Stockage de la configuration. */

		string title;
		bool play;


	public :

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe MasterClass
	     */
		MasterClass();

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe MasterClass
	     */
		~MasterClass();

		/*!
	     * \brief Lance le programme
	     *
	     * Méthode principale qui selon l'état de MasterClass lance le menu principal, le jeu, ...
	     */
		void playApp();
		
		/*!
	     * \brief Jouer !
	     *
	     * Lance le jeu ! L'objet Game s'occupe de tout, MasterClass ne reprend la main que quand la partie est terminée.
	     */
		void playGame();


		void applyConfig();


		float getFramerate(Clock*);

};

/** @}*/

#endif
