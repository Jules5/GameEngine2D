#include "model/Platform.h"

Platform::Platform(Int2 pos, Int2 siz, int wl, bool vis)
:PhysicObject(pos,siz), walkline(wl), visibility(vis)
{
	if(walkline > siz.y)
		walkline = siz.y;
}



Platform::Platform()
:PhysicObject(), walkline(0), visibility(true)
{}


Platform::~Platform()
{
}


void Platform::print(ostream& os) const 
{

}
