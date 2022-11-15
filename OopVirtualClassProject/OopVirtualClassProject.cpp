#include <iostream>
#include <string>
#include <vector>
using namespace std;

class IMovable
{
public:
    virtual void Move() = 0;
};

class ISleeping
{
public:
    virtual void Sleep() = 0;
};



class Animal : public IMovable, public ISleeping
{
public:
    virtual string Voice() = 0;
};

class Cat : public Animal
{
public:
    string Voice() override
    {
        return "Myau";
    }

    void Move() override
    {
        cout << "cat move\n";
    }

    void Sleep() override
    {
        cout << "cat sleeping...\n";
    }
};

class Dog : public Animal
{
public:
    string Voice() override
    {
        return "Gaff";
    }

    void Move() override
    {
        cout << "dog move\n";
    }

    void Sleep() override
    {
        cout << "dog sleeping...\n";
    }
};



class Transport //: public IMovable
{
protected:
    string title;
public:
    Transport(string title = "") : title{ title } {}
    virtual string Info()
    {
        return "transport " + title;
    }
};

class Car : public Transport
{
protected:
    int speed;
public:
    Car() : Car("", 0) {}
    Car(string title, int speed) : Transport(title), speed{ speed } {};
    string Info() override
    {
        return "car " + title + " speed = " + to_string(speed);
    }

    /*void Move() override
    {
        cout << "car move\n";
    }*/
};

class Airplane : public Transport
{
    int heigth;
public:
    Airplane() : Airplane("", 0) {}
    Airplane(string title, int heigth) : Transport(title), heigth{ heigth } {};
    string Info() override
    {
        return "Airplane " + title + " heigth = " + to_string(heigth);
    }

    /*void Move() override
    {
        cout << "airplane move\n";
    }*/
};


int main()
{
    /*Animal* animal = new Cat();
    cout << animal->Voice() << "\n";

    animal = new Dog();
    cout << animal->Voice() << "\n";*/

    /*animal = new Animal();
    cout << animal->Voice() << "\n";*/

    vector<Transport*> movableObjects;
    movableObjects.push_back(new Car("Bmv", 200));
    //movableObjects.push_back(Cat());
    movableObjects.push_back(new Airplane("Boing", 5000));
    //movableObjects.push_back(Dog());

    for (int i = 0; i < movableObjects.size(); i++)
        cout << movableObjects[i]->Info() << "\n";
}
