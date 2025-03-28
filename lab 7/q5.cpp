#include <iostream>
#include <string>
using namespace std;

class Character {
protected:
    string characterID, name, weaponType;
    int level, healthPoints;
public:
    Character(string id, string n, int lvl, int hp, string weapon) : characterID(id), name(n), level(lvl), healthPoints(hp), weaponType(weapon) {}
    virtual void attack() { cout << name << " attacks" << endl; }
    virtual void defend() { cout << name << " defends" << endl; }
    virtual void displayStats() {
        cout << "Character: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Health: " << healthPoints << endl;
        cout << "Weapon: " << weaponType << endl;
    }
};

class Warrior : public Character {
    int armorStrength, meleeDamage;
public:
    Warrior(string id, string n, int lvl, int hp, string weapon, int armor, int damage) : Character(id, n, lvl, hp, weapon), armorStrength(armor), meleeDamage(damage) {}
    void attack() override { cout << name << " smashes with melee damage of " << meleeDamage << endl; }
};

class Mage : public Character {
    int manaPoints, spellPower;
public:
    Mage(string id, string n, int lvl, int hp, string weapon, int mana, int spell) : Character(id, n, lvl, hp, weapon), manaPoints(mana), spellPower(spell) {}
    void defend() override { cout << name << " casts a magical barrier with power " << spellPower << endl; }
};

class Archer : public Character {
    int arrowCount, rangedAccuracy;
public:
    Archer(string id, string n, int lvl, int hp, string weapon, int arrows, int accuracy) : Character(id, n, lvl, hp, weapon), arrowCount(arrows), rangedAccuracy(accuracy) {}
    void attack() override { cout << name << " shoots an arrow with accuracy " << rangedAccuracy << endl; }
};

class Rogue : public Character {
    int stealthLevel, agility;
public:
    Rogue(string id, string n, int lvl, int hp, string weapon, int stealth, int agil) : Character(id, n, lvl, hp, weapon), stealthLevel(stealth), agility(agil) {}
    void displayStats() override {
        cout << "Character: " << name << endl;
        cout << "Stealth Level: " << stealthLevel << endl;
        cout << "Agility: " << agility << endl;
    }
};

int main() {
    Warrior w("1", "Obama bin Laden", 10, 100, "Sword of Doom", 50, 30);
    Mage m("2", "Wizard Hussein", 8, 80, "Staff of Confusion", 100, 60);
    Archer a("3", "Arrow Bin Shooter", 9, 90, "Bow of Shadows", 20, 85);
    Rogue r("4", "Sneaky Saddam", 7, 75, "Dagger of Night", 95, 70);
    
    w.displayStats(); w.attack();
    m.displayStats(); m.defend();
    a.displayStats(); a.attack();
    r.displayStats();
    
    return 0;
}
