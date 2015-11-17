#include "model/ObjetPhysique.h"

const float ObjetPhysique::GRAVITY = 0.0098;


ObjetPhysique::ObjetPhysique(Float2 pos, Float2 siz, unsigned int m, float elas)
:position(pos),size(siz),mass(m),elasticity(elas)
{
    init();
}


ObjetPhysique::ObjetPhysique()
{
    init();
	position.x = 0; position.y = 0;
	size.x = 0;     size.y = 0;
    mass = 0;
}


ObjetPhysique::~ObjetPhysique()
{}


void ObjetPhysique::init()
{
    movement.x = 0; movement.y = 0;

    if(elasticity < 0) elasticity = 0;
    else if(elasticity > 1) elasticity = 1;
}


void ObjetPhysique::animate(int dt)
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


void ObjetPhysique::setPosition(Float2 pos)
{
    position.x = pos.x;
    position.y = pos.y;
}


void ObjetPhysique::setSize(Float2 siz)
{
    size.x = siz.x;
    size.y = siz.y;
}



void ObjetPhysique::setMass(int m)
{
    mass = m;
}


void ObjetPhysique::addMovement(Float2 v)
{
	movement.x += v.x;
	movement.y += v.y;
}


void ObjetPhysique::print(ostream& os) const  
{  
    os << "===ObjetPhysique===" << endl;
    os << "=== Position  : " << position << endl;  
    os << "=== Taille    : " << size << endl;  
    os << "=== Masse     : " << mass << endl;  
    os << "=== Mouvement : " << movement << endl;
    os << "==================";
} 


void ObjetPhysique::checkCollisions(ObjetPhysique* obj)
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


ostream& operator << (ostream& os, const ObjetPhysique& obj)  
{  
    obj.print(os);  
    return os;  
} 


