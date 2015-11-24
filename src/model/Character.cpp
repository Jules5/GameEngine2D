#include "model/Character.h"

Character::Character()
:PhysicObject()
{
	init();
}


Character::Character(Float2 pos, Float2 siz, unsigned int m, float el)
:PhysicObject(pos,siz,m,el)
{
	init();
}


void Character::init()
{
	// frottements = 0;
	running = false;
	elasticity = 0;
	left = false;
}


void Character::animate(int dt)
{
	PhysicObject::animate(dt);

	if(running)
	{
		movement.x += (left ? -mass*0.3 : mass*0.3);
		if(movement.x > mass*2) movement.x = mass*2;
		if(movement.x < -mass*2) movement.x = -mass*2;
	}
}


void Character::run(bool l)
{
	running = true;
	left = l;
}

void Character::stop()
{
	running = false;
}


void Character::jump(int j)
{
	if(ground)
		addMovement(Float2(0,-j*mass));
}


void Character::checkCollisions(const Platform* obj)
{
    Float2 obj_pos = obj->getPosition();
    Float2 obj_siz = obj->getSize();
    Directions dir = checkIntersect(obj,10);

    // Pas de collision
    if(dir == NONE)
    	return;

    // Si on chute et qu'on percute le sol
    else if(!ground && dir == BOTTOM
    && position.x + size.x > obj_pos.x + size.x/3
    && position.x < obj_pos.x + obj_siz.x - size.x/3
    )
    {
        // On plaque l'objet sur le sol
        ground = true;
        position.y = obj_pos.y - size.y;

        // Rebond (ou pas)
        if(movement.y > mass * 2)
            movement.y = -(movement.y-mass) * elasticity;
        else
            movement.y = 0;

        // Frottements avec le sol
        if(abs(movement.x) > 0)
            movement.x *= frottements;
    }

    // Percussion d'un mur ou du plafond
    else if(dir == TOP && movement.y < 0)
    {
    	movement.y = 0;
    	position.y = obj_pos.y+obj_siz.y;
    }

    else if(dir == LEFT && movement.x < 0)
    {
    	movement.x = 0;
    	position.x = obj_pos.x+obj_siz.x;
    }

    else if(dir == RIGHT && movement.x > 0)
    {
    	movement.x = 0;
    	position.x = obj_pos.x-size.x;
    }


}