#include <physic/PhysicObject.h>
#include <environment/Platform.h>

const float PhysicObject::GRAVITY = 0.0098;


PhysicObject::PhysicObject(Float2 pos, Float2 siz, unsigned int m, float elas)
:position(pos),size(siz),mass(m),elasticity(elas)
{
    init();
}


PhysicObject::PhysicObject()
{
	position = Int2(0,0);
	size = Int2(0,0);
    mass = 0;
    elasticity = 0;
    init();
}


PhysicObject::~PhysicObject()
{}


void PhysicObject::init()
{
    // Physics
    friction = 0.5;
    friction_enabled = true;
    ground = true;
    movement.x = 0; movement.y = 0;

    if(elasticity < 0) elasticity = 0;
    else if(elasticity > 1) elasticity = 1;

    // Graphics
    body.setFillColor(Color(30,30,30));
}


void PhysicObject::animate(int dt)
{
    // Frottements
    if(friction_enabled && ground)
        movement.x *= 1-((float)dt/100*friction);

    // Mouvements
    float dx = (float)dt/1000*movement.x;
	float dy = (float)dt/1000*movement.y*mass;
    position.x += dx;
    position.y += dy;

    // Friction de l'air
    //movement.x *= 0.999;

    // Gravité
    if(mass > 0)
    {
        ground = false;
        float dy = dt*GRAVITY*mass;
        movement.y += dy;
    }

    // Arret
    if(movement.x < 1 && movement.x > -1)
        movement.x = 0;
}


void PhysicObject::display(RenderWindow* window)
{
    // Mise à jour
    body.setSize(getSize().vector());
    body.setPosition(getPosition().vector());

    // Affichage
    window->draw(body);
}


void PhysicObject::addMovement(Float2 v)
{
	movement += v;
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




PhysicObject::Directions PhysicObject::checkIntersect(const PhysicObject* obj, int eps)
{
    if(position.y + size.y > obj->position.y - eps 
    && position.y < obj->position.y + obj->size.y + eps
    && position.x + size.x > obj->position.x - eps
    && position.x < obj->position.x+obj->size.x + eps)
    {
        int offset[NB_DIRECTIONS];
        offset[LEFT]   = obj->position.x + obj->size.x - position.x + eps;
        offset[RIGHT]  = position.x + size.x - obj->position.x + eps;
        offset[TOP]    = obj->position.y + obj->size.y - position.y + eps;
        offset[BOTTOM] = position.y + size.y - obj->position.y + eps;

        int min = -1;
        int ind = NONE;

        for(int i=0; i<NB_DIRECTIONS; ++i)
            if(offset[i] >= 0 && (ind == NONE || offset[i] < min))
            {
                ind = i; 
                min = offset[i];
            }

        return Directions(ind);
    }

    return NONE;
}




void PhysicObject::checkCollisions(const Platform* obj)
{
    float eps = 5;
    Float2 obj_pos = obj->getPosition();
    Float2 obj_siz = obj->getSize();

    if(!ground && checkIntersect(obj,eps) != NONE
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
    }
}







ostream& operator << (ostream& os, const PhysicObject& obj)  
{  
    obj.print(os);  
    return os;  
} 


