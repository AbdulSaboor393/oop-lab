#include<iostream>
using namespace std;

class Character {
    protected:
    int characterID;
    string characterName;
    int healthPoints;
    int experienceLevel;
    string primaryWeapon;
    
    public:
    Character(int id, string name, int health, int level, string weapon)
        : characterID(id), characterName(name), healthPoints(health), experienceLevel(level), primaryWeapon(weapon) {}
    
    virtual void attack() {
        cout << characterName << " attacks with a " << primaryWeapon << endl;
    }

    virtual void defend() {
        cout << characterName << " defends against the attack!" << endl;
    }

    virtual void displayInfo() {
        cout << "Character ID: " << characterID << endl;
        cout << "Name: " << characterName << endl;
        cout << "Health: " << healthPoints << endl;
        cout << "Level: " << experienceLevel << endl;
        cout << "Weapon: " << primaryWeapon << endl;
    }
};

class Warrior : public Character {
    protected:
    int armorRating;
    int meleeDamage;
    
    public:
    Warrior(int id, string name, int health, int level, string weapon, int armor, int damage)
        : Character(id, name, health, level, weapon), armorRating(armor), meleeDamage(damage) {}
    
    void attack() override {
        cout << characterName << " strikes fiercely with a " << primaryWeapon 
             << ", dealing " << meleeDamage << " damage and gaining " << armorRating << " armor strength." << endl;
    }
};

class Mage : public Character {
protected:
    int manaPoints;
    int magicPower;

public:
    Mage(int id, string name, int health, int level, string weapon, int mana, int power)
        : Character(id, name, health, level, weapon), manaPoints(mana), magicPower(power) {}

    void defend() override {
        cout << characterName << " casts a magical shield, reducing incoming damage!" << endl;
    }
};

class Archer : public Character {
private:
    int arrowCount;
    int shootingAccuracy;

public:
    Archer(int id, string name, int health, int level, string weapon, int arrows, int accuracy)
        : Character(id, name, health, level, weapon), arrowCount(arrows), shootingAccuracy(accuracy) {}

    void attack() override {
        if (arrowCount > 0) {
            cout << characterName << " fires an arrow with a " << shootingAccuracy 
                 << "% accuracy!" << endl;
            arrowCount--;
        } else {
            cout << characterName << " is out of arrows!" << endl;
        }
    }
};

class Rogue : public Character {
protected:
    int stealthLevel;
    int agilityRating;

public:
    Rogue(int id, string name, int health, int level, string weapon, int stealth, int agility)
        : Character(id, name, health, level, weapon), stealthLevel(stealth), agilityRating(agility) {}

    void displayInfo() override {
        Character::displayInfo();
        cout << "Stealth Level: " << stealthLevel << endl;
        cout << "Agility Rating: " << agilityRating << endl;
    }
};

int main() {
    Warrior warrior(1, "Normand", 20000, 1000, "Katana", 30, 25);
    Mage mage(2, "Sung Jin woo", 9000, 100, "Staff", 100, 50);
    Archer archer(3, "Archer", 15000, 70, "Bow", 15, 90);
    Rogue rogue(4, "Sasuke", 13000, 120, "Shuriken", 82, 1500);

    warrior.displayInfo();
    warrior.attack();

    mage.displayInfo();
    mage.defend();

    archer.displayInfo();
    archer.attack();

    rogue.displayInfo();

    return 0;
}

