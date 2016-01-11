#ifndef OBJETPHYSIQUE_H
#define OBJETPHYSIQUE_H

#include <iostream>
#include <algorithm>
#include <cmath>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <tools/tools.h>

using namespace std;

class Platform;



class PhysicObject
{
	public :
		enum Directions {TOP, RIGHT, BOTTOM, LEFT, NB_DIRECTIONS, NONE};
		static const float GRAVITY;
		friend ostream& operator << (ostream& os, const PhysicObject& obj);


	// Attributes
	protected :

		// Physics
		Float2 position;
		Float2 size; 
		Float2 movement;
		int mass; 
		float elasticity;
		bool ground;

		float friction;
		bool friction_enabled;

		// Graphics
		RectangleShape body; 


	// Methods
	public :
		PhysicObject(Float2 pos,Float2 siz, unsigned int m=0, float el=0.5);
		PhysicObject();
		virtual ~PhysicObject();

		void init();
		
		virtual void animate(int dt);
		virtual void display(RenderWindow* window);

		void addMovement(Float2 v);
		Directions checkIntersect(const PhysicObject*, int delta=0);
		void checkCollisions(const Platform*);

		inline Float2 getPosition() const {return position;};
		inline Float2 getSize() const     {return size;}    ;
		inline Float2 getMovement() const {return movement;};

		virtual void print(ostream& os) const;
};



/** @}*/

#endif
