// 🟡 Inheritance in OOPS, mean one class can "reusing, overriding, or adding new method/data" of another class (base/parent class).

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Character {
   private:
    std::string name;
    int         health;

   public:
    Character(std::string name, int health) : name(std::move(name)), health(health) {}
    virtual ~Character()    = default;
    virtual void useSkill() = 0;

    void attack(int dmg) {
        health -= dmg;
        if (health < 0) {
            health = 0;
        }
    }
};

class Warrior : public Character {
   public:
    Warrior(std::string name, int health) : Character(std::move(name), health) {}
    void useSkill() override { std::cout << "Using Warrior skill" << std::endl; }
};

class Archer : public Character {
   public:
    Archer(std::string name, int health) : Character(std::move(name), health) {}
    void useSkill() override { std::cout << "Using Archer skill" << std::endl; }
};

int main() {
    std::vector<std::unique_ptr<Character>> party;
    party.push_back(std::make_unique<Warrior>("Conan", 120));
    party.push_back(std::make_unique<Archer>("Legolas", 90));

    for (auto& c : party) {
        c->useSkill();  // same call, different skill per character
    }
    return 0;
}
