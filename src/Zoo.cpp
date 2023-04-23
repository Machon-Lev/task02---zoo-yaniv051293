#include "Zoo.h"
#include "Lion.h"
#include "Monkey.h"
#include "Dog.h"
#include <string>


using namespace std;
Zoo::Zoo()
{
    create("Simba", "Lion");
    create("Nala", "Lion");
    create("Rex", "Dog");
    create("Fido", "Dog");
    create("George", "Monkey");
    create("Curious George", "Monkey");
    for (int i = 0; i < animals.size(); i++)
    {
        animals[i]->printDetails();
    }
}

void Zoo::move(int animalNum)
{
    animals[animalNum]->move();
}


void Zoo::stop(int animalNum)
{
    animals[animalNum]->stop();
}

void Zoo::del(int animalNum)
{
    delete animals[animalNum];
    animals.erase(animals.begin() + animalNum);
}

void Zoo::delAll(std::string animalType)
{
    for (int i = 0; i < animals.size(); i++)
    {
        if (animals[i]->getInitial() == animalType[0])
        {
            delete animals[i];
            animals.erase(animals.begin() + i);
        }
    }
}

void Zoo::help()
{
    std::cout << "The commands you can do:" << endl <<
        "create- add a new animal to the data " << endl <<
        "del- remove an animal from data" << endl <<
        "delAll- remove all animals of sepcific type" << endl <<
        "move- lets the animal move" << endl <<
        "stop- stops the animal from moving" << endl<<
        "step- moves all animals" << endl<<
        "help- displays all commands" << endl;
}

void Zoo::create(std::string animalName, std::string animalType)
{
    if (animalType == "Lion")
    {
        Location loc(rand() % 20, rand() % 40);
        Lion* lion = new Lion(loc, animalName);
        Zoo::animals.push_back(lion);
    }
    else
        if (animalType == "Monkey")
        {
            Location loc(rand() % 20, rand() % 40);
            Monkey* monkey = new Monkey(loc, animalName);
            Zoo::animals.push_back(monkey);
        }
        else
            if (animalType == "Dog")
            {
                Location loc(rand() % 20, rand() % 40);
                Dog* dog = new Dog(loc, animalName);
                Zoo::animals.push_back(dog);
            }
            else
                cout << "ERROR";
}

void Zoo::step()
{
    for (int i = 0; i < animals.size(); i++)
    {
        animals[i]->step();
    }
    //drawZoo();
}

void Zoo::run()
{
    std::string command;
    while (true)
    {
        std::cout << "Enter command:\n move, stop, create, del, dellAll, . , help, exit \n";
        std::cin >> command;
        if (command == "exit")
        {
            break;
        }
        else if (command == "create")
        {
            std::string type, name;
            std::cout << "Enter the animal type:";
            std::cin >> type;
            std::cout << "Enter the animal name:";
            std::cin >> name;
            create(type, name);
            for (int i = 0; i < animals.size(); i++)
            {
                animals[i]->printDetails();
            }
        }
        else if (command == "del")
        {
            int num;
            std::cout << "Enter the animal number to delete it:";
            std::cin >>  num;
            del(num);
        }
        else if (command == "dellAll")
        {
            std:: string type;
            std::cout << "Enter the animal type to delete it:";
            std::cin >> type;
            delAll(type);
        }
        else if (command == "move")
        {
            int num;
            std::cout << "Enter the animal number to allow it move:";
            std::cin >> num;
            move(num);
        }
        else if (command == "stop")
        {
            int num;
            std::cout << "Enter the animal number to make it stop:";
            std::cin >> num;
            move(num);
        }
        else if (command == ".")
        {
            step();
            for (int i = 0; i < animals.size(); i++)
            {
                animals[i]->printDetails();
            }
        }

        else if (command == " help")
        {
            help();
        }
    }
}

void Zoo:: drawZoo()
{
    Location thisLocation(0, 0);
    bool animalExist = false;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            for (int k = 0; k < animals.size(); k++) 
            {
                if (animals[k]->getLocation() == thisLocation)
                {
                    std::cout << animals[k]->getInitial();
                    animalExist = true;
                    break;
                }
            }
            if (!animalExist)
                std::cout << "-";
            animalExist = false;
            thisLocation.col++;
        }
        thisLocation.col = 0;
        thisLocation.row++;
        cout << endl;
    }
}



