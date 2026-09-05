// 🟡 In Encapsulation, We keep the "data private within the class" mainly for we don't want anyone to update/get those information directly.
// 🟡 To have access/get the private information we create public method, instead of having direct access.

#include <iostream>

class Player {
   private:
    int health = 100;

   public:
    void takeDamage(int dmg) {
        health -= dmg;
        if (health < 0)
            health = 0;
    }

    int getHealth() { return health; }
};

int main() {
    Player player;

    player.takeDamage(20);
    player.takeDamage(90);
    std::cout << "Current Health is: " << player.getHealth() << std::endl;

    return 0;
}
