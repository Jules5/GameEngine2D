#ifndef DECOR_H
#define DECOR_H

/*!
 * \file Decor.h
 * \author Jules
 * \brief Déclaration de la classe Decor
 * \addtogroup Model 
 * @{
 */

#include <iostream>
#include <sstream>

#include <model/ObjetPhysique.h>

using namespace std;



/*!\class Decor
 * \brief Modélise un decor.
 *
 * Objet simple modélisant un arrière-plan. Son attribut z permet
 * de simuler un effet d'éloignement grâce à l'effet parallaxe.
 */
class Decor : public ObjetPhysique
{
	friend class DecorView;
	
	protected :

		int z; /*!< \brief Indice d'éloignement du décor. */
		int dx; /*< \brief Décalage pour le parallaxe. */


	public :


		Decor(Int2 pos, Int2 siz, int z=0, int dx=0);
		Decor();
		~Decor();

		void print(ostream& os) const;

		void animate(int x);

};



/** @}*/

#endif
