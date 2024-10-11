#ifndef EXOS_
#define EXOS_

class vector2
{
    public:
    float x, y;
    vector2(float x, float y);

    float GetPosX();
    void SetPosX(float X);

    float GetPosY();
    void SetPosY(float Y);

};

class entity
{
    vector2 coordinates;
    public:
        entity(float, float);

    virtual vector2 GetEntityCo();
    virtual void SetEntityCo(vector2);
};

class AMovable
{
    public:
        vector2 direction;
        float speed;

        AMovable(vector2, float);
        
        virtual void SetDirection(vector2 vector);
        virtual void SetSpeed(float f);

        virtual vector2 MoveEntity();
};


class Alive
{
    float MaxHealth;
    float CurrentHealth;

    public:
    Alive(float);

    virtual float GetMaxHealth();
    virtual float GetCurrentHealth();
    virtual void EditHealth(float edit);

};

class IAttacker 
{
    public:
        virtual void Attack(Alive* MaxHealth, float edit) = 0;
};

class StaticObject : public entity
{
    public:
        StaticObject(vector2);
};

class BreakableObject: public entity, public Alive
{
    public:
        BreakableObject(vector2, float, float);

        void EditHealth(float edit) override;
};

#endif