#include "doglist.h"
#include <QDebug>
#include <QMessageBox>
#include <QWidget>
#include <QApplication>

DogList::DogList(QObject* parent):QAbstractListModel(parent)
{
    add("Боня", "Тибетский Мастиф", "5", "Писарев М.Р.");
    add("Юстас", "Немецкая овчарка", "4", "Кольцова А.Д.");
     add("Юстас", "Немецкая овчарка", "4", "Кольцова А.Д.");
}

DogList::~DogList()
{

}

int DogList::rowCount(const QModelIndex&) const //число элементов в data
{
    return listOfDogs.size();
}


QVariant DogList::data(const QModelIndex &index, int role) const //возвращает данные элемента
{
    if (index.row() < 0 || index.row() >= listOfDogs.size())
            return QVariant();
      {
        switch (role) {
                case name:
                    return QVariant(listOfDogs.at(index.row()).getName());
                case breed:
                    return QVariant(listOfDogs.at(index.row()).getBreed());
                case age:
                    return QVariant(listOfDogs.at(index.row()).getAge());
                case fio:
                    return QVariant(listOfDogs.at(index.row()).getFio());

                default:
                    return QVariant();
            }

    }
}

QHash<int, QByteArray> DogList::roleNames() const //возвращает список ролей, доступных в делегате
{
    QHash<int, QByteArray> roles; //элементы произвольно упорядочиваются + происходит оч быстрый поиск значения, связанного с ключом
    roles[name] = "nameOfDog";
    roles[breed] = "breedOfDog";
    roles[age] = "ageOfDog";
    roles[fio] = "fioOfDog";

       return roles;
}

void DogList::add(const QString& nameRiv, const QString& breedRiv, const QString& ageRiv, const QString& fioRiv){
     Dog dog;
     dog.setName(nameRiv);
     dog.setBreed(breedRiv);
     dog.setAge(ageRiv);
     dog.setFio(fioRiv);


    beginInsertRows(QModelIndex(),listOfDogs.size(),listOfDogs.size()); //издаст нужные сигналы о том что готовится добавление элементов
    listOfDogs.append(dog);  //добавление в конец списка
    endInsertRows(); //издаёт сигнал о том что в модель добавились элементы
}

QAbstractListModel* DogList::getModel()
{
    return this;
}

void DogList::del(const int index)
{

     if (index >= 0 && index < listOfDogs.size())
     {

    // сообщение модели о процессе удаления данных
         beginRemoveRows(QModelIndex(), index, index);
        listOfDogs.removeAt(index);
              endRemoveRows();
     }
     //else qDebug() << "Error index";

}

QString DogList::count(const QString& textSelBreed){ //считаем речки, полощадь бассейна которых больше указанного числа
    int count = 0;
    for(int i = 0; i < listOfDogs.size(); i++)
    {
        QString temp = listOfDogs[i].getBreed();
        if(temp.compare(textSelBreed, Qt::CaseInsensitive) == 0)
            count++;
    }
    QString c = QString::number(count);
    return c;
}

void DogList::edit(const QString& nameRiv, const QString& breedRiv, const QString& ageRiv, const QString& fioRiv, const int index) {
     if(index >= 0 && index < listOfDogs.size() )
     {
        auto& currentDog = listOfDogs[index];
        if (currentDog.getName().compare(nameRiv)!=0 || currentDog.getBreed() != breedRiv || currentDog.getAge() != ageRiv
                || currentDog.getFio() != fioRiv)
        {
            currentDog.setName(nameRiv);
            currentDog.setBreed(breedRiv);
            currentDog.setAge(ageRiv);
            currentDog.setFio(fioRiv);


            auto modelIndex = createIndex(index, 0); //создавать индексы моделей для использования другими компонентами
            emit dataChanged(modelIndex, modelIndex); //выдается всякий раз, когда изменяются элементы данных, предоставляемые моделью
            //qDebug() << listOfDogs[index].getArea();
        }

     }
      //else qDebug() << "Error index";
}
