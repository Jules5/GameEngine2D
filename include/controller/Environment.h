#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

/*!
 * \file Environment.h
 * \author Jules
 * \brief Déclaration de la classe Environment
 * \addtogroup Controller 
 * @{
 */

#include <iostream>
#include <list>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <model/Decor.h>
#include <model/Platform.h>

#include <view/DecorView.h>
#include <view/PlatformView.h>


using namespace std;
using namespace sf;



/*!\class Environment
 * \brief Stocke l'environnement.
 *
 * Stocke les objets de l'environnement (décors,plate-formes,destructibles).
 */
class Environment
{

	friend class Game;

	private :

		list<Decor> decors; /*!< \brief Liste des décors de l'environnement*/
		list<Platform> platforms; /*!< \brief Liste des plate-formes de l'environnement*/
		list<DecorView> decors_views;
		list<PlatformView> platforms_views;

	public :

		/*!
	     *  \brief Constructeur
	     *
	     *  Constructeur pas défaut de la classe Environment
	     */
		Environment();

		/*!
	     *  \brief Destructeur
	     *
	     *  Destructeur de la classe Environment
	     */
		~Environment();



		void update(int center); 


		/*!
	     *  \brief Affichage
	     *
	     *  Affiche tous les objets de l'environnement
	     *
	     * \param window : Fenêtre de rendu où afficher les objets
	     */
		void display(RenderWindow* window);

		/*!
	     *  \brief Ajout d'un Decor
	     *
	     *  Ajoute un Decor dans l'environnement
	     *
	     * \param siz : Taille de l'écran
	     * \param tex : Texture à appliquer au décor
	     * \param z : Indice z (pour l'effet parallaxe)
	     */
		void addDecor(Int2 pos, Int2 siz, Texture* tex=NULL, int z=0);

		/*!
	     *  \brief Ajout d'une Platform
	     *
	     *  Ajoute une Platform dans l'environnement
	     *
	     * \param pos : Position de la plate-forme
	     * \param siz : Taille de la plate-forme
	     * \param wl : Hauteur du sol de la plateforme (non traité pour le moment)
	     * \param v : Vrai si la plate-forme doit être affichée, Faux sinon.
	     * \param tex : Texture à appliquer à la plate-forme
	     * \param tex_repeat : Indique si la texture doit être répétée horizontalement et/ou verticalement.
	     */
		void addPlatform(Int2 pos, Int2 siz, int wl, bool v=true, Texture* tex=NULL, Bool2 tex_repeat=Bool2(false,false));
		

		//void addDestructible(); // TODO
};

/** @}*/

#endif