#ifndef OBJETPHYSIQUE_H
#define OBJETPHYSIQUE_H

#include <iostream>
#include <cmath>
#include <tools/tools.h>

using namespace std;


class PhysicObject
{
	public :
		friend ostream& operator << (ostream& os, const PhysicObject& obj);
		static const float GRAVITY;

	// Attributes
	protected :
		Float2 position;
		Float2 size; 
		Float2 movement; 
		unsigned int mass; 
		float elasticity;


	// Methods
	public :
		PhysicObject(Float2 pos,Float2 siz, unsigned int m=0, float el=0.5);
		PhysicObject();
		virtual ~PhysicObject();

		void init();
		virtual void animate(int dt);
		void addMovement(Float2 v);
		void checkCollisions(PhysicObject*);

		inline Float2 getPosition() const {return position;};
		inline Float2 getSize() const     {return size;}    ;
		inline Float2 getMovement() const {return movement;};

		virtual void print(ostream& os) const;
};



/** @}*/

#endif
