#include <iostream>
#include "exos.h"

//exercice 1
vector2::vector2(float BuildX, float BuildY) : x(BuildX), y(BuildY){}

void vector2::SetPosX(float X) 
{
    x = X;
}
float vector2::GetPosX(void) 
{
    return x;
}

void vector2::SetPosY(float Y) 
{
    y = Y;
}
float vector2::GetPosY(void) 
{
    return y;
}



//exercice 2
vector2 entity::GetEntityCo(void) 
{ 
	return coordinates;
}

void entity::SetEntityCo(vector2 vector) 
{
	coordinates = vector;
}



//exercice 3
AMovable::AMovable(vector2 b_vector, float b_speed) : direction(b_vector), speed(b_speed){}

void AMovable::SetDirection(vector2 vector) 
{
	direction = vector;
}

void AMovable::SetSpeed(float f) 
{
	speed = f;
}

vector2 AMovable::MoveEntity(void) 
{
	float x = direction.GetPosX();
	x += speed;

	float y = direction.GetPosY();
	y += speed;

	vector2 NewCoordinates(x, y);

	return NewCoordinates;
}



//exercice 4
Alive::Alive(float BuildMaxHealth) : MaxHealth(BuildMaxHealth), CurrentHealth(BuildMaxHealth){}

float Alive::GetMaxHealth()
{
	return MaxHealth;
}

float Alive::GetCurrentHealth()
{
	return CurrentHealth;
}

void Alive::EditHealth(float edit)
{
	CurrentHealth+= edit;
}



//exercice 6
StaticObject::StaticObject(vector2 BuildPosition) : entity(BuildPosition.GetPosX(), BuildPosition.GetPosY())
{
    SetEntityCo(BuildPosition);

        std::cout << "Breakable Object just created at x = " << BuildPosition.GetPosX() << " and y = " << BuildPosition.GetPosY() << std::endl;
}



//exercice 7
BreakableObject::BreakableObject(vector2 BuildCoordinates, float BuildMaxHealth, float BuildCurrentHealth) : entity(BuildCoordinates.GetPosX(), BuildCoordinates.GetPosY()), Alive(BuildMaxHealth){}

void BreakableObject::EditHealth(float EditHealth)
{
    Alive::EditHealth(EditHealth);

    std::cout << "BreakableObject just broke." << std::endl;
}




int main() 
{
    // Exercice 1 : vector2
    vector2 v(10.0f, 20.0f);
    std::cout << "--------------------------------------------EXERCICE NUMERO 1 DÉBUT--------------------------------------" << std::endl;
    std::cout << "Position initiale: (" << v.GetPosX() << ", " << v.GetPosY() << ")" << std::endl;
    v.SetPosX(15.0f);
    v.SetPosY(25.0f);
    std::cout << "Position après modification: (" << v.GetPosX() << ", " << v.GetPosY() << ")" << std::endl;
    std::cout << "----------------------------------------EXERCICE NUMERO 1 FIN--------------------------------------------" << std::endl;

    // Exercice 2 : entity
    entity e(10.0f, 20.0f);
    std::cout << "--------------------------------------------EXERCICE NUMERO 2 DÉBUT--------------------------------------" << std::endl;
    vector2 coords = e.GetEntityCo();
    std::cout << "Coordonnées initiales: (" << coords.GetPosX() << ", " << coords.GetPosY() << ")" << std::endl;
    e.SetEntityCo(vector2(15.0f, 25.0f));
    coords = e.GetEntityCo();
    std::cout << "Coordonnées après modification: (" << coords.GetPosX() << ", " << coords.GetPosY() << ")" << std::endl;
    std::cout << "----------------------------------------EXERCICE NUMERO 2 FIN--------------------------------------------" << std::endl;

    // Exercice 3 : AMovable
    AMovable am(vector2(10.0f, 20.0f), 5.0f);
    std::cout << "--------------------------------------------EXERCICE NUMERO 3 DÉBUT--------------------------------------" << std::endl;
    std::cout << "Direction initiale: (" << am.direction.GetPosX() << ", " << am.direction.GetPosY() << ")" << std::endl;
    am.SetDirection(vector2(15.0f, 25.0f));
    std::cout << "Direction après modification: (" << am.direction.GetPosX() << ", " << am.direction.GetPosY() << ")" << std::endl;
    am.SetSpeed(10.0f);
    std::cout << "Vitesse après modification: " << am.speed << std::endl;
    vector2 newCoords = am.MoveEntity();
    std::cout << "Nouvelles coordonnées après mouvement: (" << newCoords.GetPosX() << ", " << newCoords.GetPosY() << ")" << std::endl;
    std::cout << "----------------------------------------EXERCICE NUMERO 3 FIN--------------------------------------------" << std::endl;

    // Exercice 4 : Alive
    Alive al(100.0f);
    std::cout << "--------------------------------------------EXERCICE NUMERO 4 DÉBUT--------------------------------------" << std::endl;
    std::cout << "Santé maximale: " << al.GetMaxHealth() << std::endl;
    std::cout << "Santé actuelle: " << al.GetCurrentHealth() << std::endl;
    al.EditHealth(-20.0f);
    std::cout << "Santé après modification: " << al.GetCurrentHealth() << std::endl;
    std::cout << "----------------------------------------EXERCICE NUMERO 4 FIN--------------------------------------------" << std::endl;

    // Exercice 6 : StaticObject
    StaticObject so(vector2(10.0f, 20.0f));
    std::cout << "--------------------------------------------EXERCICE NUMERO 6 DÉBUT--------------------------------------" << std::endl;
    std::cout << "Objet créé à la position: (" << so.GetEntityCo().GetPosX() << ", " << so.GetEntityCo().GetPosY() << ")" << std::endl;
    std::cout << "----------------------------------------EXERCICE NUMERO 6 FIN--------------------------------------------" << std::endl;

    // Exercice 7 : BreakableObject
    BreakableObject bo(vector2(10.0f, 20.0f), 100.0f, 80.0f);
    std::cout << "--------------------------------------------EXERCICE NUMERO 7 DÉBUT--------------------------------------" << std::endl;
    std::cout << "Objet créé à la position: (" << bo.GetEntityCo().GetPosX() << ", " << bo.GetEntityCo().GetPosY() << ")" << std::endl;
    bo.EditHealth(-20.0f);

    return 0;
}