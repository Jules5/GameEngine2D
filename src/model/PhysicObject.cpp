#include "model/PhysicObject.h"

const float PhysicObject::GRAVITY = 0.0098;


PhysicObject::PhysicObject(Float2 pos, Float2 siz, unsigned int m, float elas)
:position(pos),size(siz),mass(m),elasticity(elas)
{
    init();
}


PhysicObject::PhysicObject()
{
    init();
	position = Int2(0,0);
	size = Int2(0,0);
    mass = 0;
    elasticity = 0;
}


PhysicObject::~PhysicObject()
{}


void PhysicObject::init()
{
    movement.x = 0; movement.y = 0;

    if(elasticity < 0) elasticity = 0;
    else if(elasticity > 1) elasticity = 1;
}


void PhysicObject::animate(int dt)
{
    // Mouvements
    float dx = (dt*movement.x*mass)/1000;
	float dy = (dt*movement.y*mass)/1000;
    position.x += dx;
    position.y += dy;

    // Frottements de l'air
    movement.x *= 0.999;

    // Gravité
    if(mass > 0)
    {
        float dy = dt*GRAVITY*mass;
        movement.y += dy;
    }
}


void PhysicObject::addMovement(Float2 v)
{
	movement.x += v.x;
	movement.y += v.y;
}


void PhysicObject::print(ostream& os) const  
{  
    os << "===PhysicObject===" << endl;
    os << "=== Position  : " << position << endl;  
    os << "=== Taille    : " << size << endl;  
    os << "=== Masse     : " << mass << endl;  
    os << "=== Mouvement : " << movement << endl;
    os << "==================";
} 


void PhysicObject::checkCollisions(PhysicObject* obj)
{
    float eps = 4;

    // Je triche et je checke que les collisions avec le sol, faut améliorer l'implémentation

    // Si on chute et qu'on percute le sol
    if(movement.y > 0 && position.y + size.y > obj->position.y - eps && position.y < obj->position.y + obj->size.y + eps)
    {
        // On plaque l'objet sur le sol
        position.y = obj->position.y - size.y;

        // Rebond (ou pas)
        if(movement.y > mass * 2)
            movement.y = -(movement.y-mass) * elasticity;
        else
            movement.y = 0;

        // Frottements avec le sol
        if(abs(movement.x) > 0)
            movement.x *= 0.9;
    }
}


ostream& operator << (ostream& os, const PhysicObject& obj)  
{  
    obj.print(os);  
    return os;  
} 


