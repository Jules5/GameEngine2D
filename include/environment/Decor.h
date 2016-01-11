#ifndef DECOR_H
#define DECOR_H

#include <iostream>
#include <sstream>

#include <physic/PhysicObject.h>

using namespace std;


class Decor : public PhysicObject
{
	private :
		int z;
		int dx;


	public :
		Decor(Int2 pos, Int2 siz, int z=0, int dx=0);
		Decor();
		~Decor();

		void init();

		void animate(int x);
		virtual void display(RenderWindow* window);

		inline int getDeltaX() const {return dx;};

		void print(ostream& os) const;

};



/** @}*/

#endif
