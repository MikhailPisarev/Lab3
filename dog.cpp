#include "dog.h"

Dog::Dog(/*QString ID, QString Name, QString Age, QString Breed, QString Fio, QObject *parent): QObject(parent*/)
{
    /*id = ID;
    name = Name;
    age = Age;
    breed = Breed;
    fio = Fio;
    area = Area;*/
}

void Dog::setID(const QString ID)
{
    id = ID;
}
void Dog::setName(const QString Name)
{
    name = Name;
}
void Dog::setAge(const QString Age)
{
    age = Age;
}
void Dog::setBreed(const QString Breed)
{
    breed = Breed;
}
void Dog::setFio(const QString Fio)
{
    fio = Fio;
}

QString Dog::getID() const
{
    return id;
}
QString Dog::getName() const
{
    return name;
}
QString Dog::getAge() const
{
    return age;
}
QString Dog::getBreed() const
{
    return breed;
}
QString Dog::getFio() const
{
    return fio;
}


Dog::~Dog()
{
}
