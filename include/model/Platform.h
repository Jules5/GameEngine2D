#ifndef PLATFORM_H
#define PLATFORM_H

#include <iostream>
#include <sstream>

#include <model/PhysicObject.h>

using namespace std;


class Platform : public PhysicObject
{
	private :
		int walkline; 
		bool visibility; 


	public :
		Platform(Int2 pos, Int2 siz, int wl=0, bool vis=true);
		Platform();
		~Platform();

		inline int getWalkline() const {return walkline;};
		inline bool getVisibility() const {return visibility;};
		inline void setVisibility(bool b) {visibility = b;};

		void print(ostream& os) const;
};


/** @}*/

#endif
