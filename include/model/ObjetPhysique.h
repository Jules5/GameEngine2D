#ifndef OBJETPHYSIQUE_H
#define OBJETPHYSIQUE_H

/*!
 * \file ObjetPhysique.h
 * \author Jules
 * \brief Déclaration de la classe ObjetPhysique
 * \addtogroup Model 
 * @{
 */

#include <iostream>
#include <cmath>
#include <tools/tools.h>

using namespace std;


/*!\class ObjetPhysique
 * \brief Modélise un objet physique.
 *
 * Modélise un objet physique simple sur lequel on peut appliquer des forces.
 */
class ObjetPhysique
{
	/*!\relates operator <<
	 * \brief Pour afficher les information d'un objet dans le flux standard.
	 */
	friend ostream& operator << (ostream& os, const ObjetPhysique& obj);

	public :

		static const float GRAVITY;

		Float2 position; /*!< \brief Position de l'objet. */
		Float2 size; /*!< \brief Taille de l'objet. */
		Float2 movement; /*!< \brief Mouvement de l'objet. */

		unsigned int mass; /*!< \brief Masse de l'objet. */
		float elasticity; // entre 0 et 1 


	public :

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur de la classe ObjetPhysique.
	     * \param pos : Position initiale de l'objet.
	     * \param siz : Taille initiale de l'objet.
	     * \param m : Masse de l'objet.
	     */
		ObjetPhysique(Float2 pos,Float2 siz, unsigned int m=0, float el=0.5);

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe ObjetPhysique
	     */
		ObjetPhysique();

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe ObjetPhysique
	     */
		virtual ~ObjetPhysique();


		void init();

		/*!
	     * \brief Animer
	     *
	     * Déplace l"objet en fonction du temps.
	     * \param dt : Temps écoulé depuis le dernier appel de la fonction.
	     */
		virtual void animate(int dt);

		/*!
	     * \brief Retourne la position de l'objet.
	     */
		inline Float2 getPosition() {return position;};

		/*!
	     * \brief Retourne la taille de l'objet.
	     */
		inline Float2 getSize() {return size;};

		/*!
	     * \brief Retourne le vecteur de mouvement de l'objet.
	     */
		inline Float2 getMovement() {return movement;};

		/*!
	     * \brief Redéfinit la position de l'objet.
	     */
		void setPosition(Float2 pos);

		/*!
	     * \brief Redéfinit la taille de l'objet.
	     */
		void setSize(Float2 siz);

		/*!
	     * \brief Redéfinit la masse de l'objet.
	     */
		void setMass(int m);

		/*!
	     * \brief Application d'une force.
	     *
	     * Applique une force à l'objet et modifie son vecteur de mouvement en conséquence.
	     * \param v : Vecteur de la force à appliquer.
	     */
		void addMovement(Float2 v);


		void checkCollisions(ObjetPhysique*);

		/*!
	     * \brief Debug
	     *
	     * Affiche des informations sur l'objet.
	     * \param os : Flux sur lequel afficher.
	     */
		virtual void print(ostream& os) const;
		
};



/** @}*/

#endif
