// https://boycoding.tistory.com/108
#include<iostream>

class Monster {
 public:
    virtual ~Monster() {}
    virtual Monster* clone() = 0;
};

class Ghost : public Monster {
 public:
    Ghost(int health, int speed)
    : health_(health),
     speed_(speed) {
        std::cout << "Ghost()" << std::endl;
     }

    virtual Monster* clone() {
        return new Ghost(health_, speed_);
    }

 private:
    int health_;
    int speed_;
};

class GhostTemplete : public Monster {
 public:
    GhostTemplete() {
        std::cout << "GhostTemplete()" << std::endl;
    }

    virtual Monster* clone() {
        return new GhostTemplete();
    }
};

class Spawner {
 public:
    Spawner(Monster* prototype) : prototype_(prototype) {
        std::cout << "Spawner()" << std::endl;
    }

    Monster* spawnMonster() {
        return prototype_->clone();
    }

 private:
    Monster* prototype_;
};

class SpawnerTemplete {
 public:
    virtual ~SpawnerTemplete() {}
    virtual Monster* spawnMonster() = 0;
};

template <class T>
class SpawnerFor : public SpawnerTemplete {
 public:
    virtual Monster* spawnMonster() {
        std::cout << "SpawnerFor spawnMonster()" << std::endl;
        return new T();
    }
};

void test_proto_type(void) {
    std::cout << "test_proto_type()" << std::endl;
    Monster* ghostPrototype = new Ghost(15, 3);
    Spawner* ghostSpawner = new Spawner(ghostPrototype);
    delete ghostPrototype;
    delete ghostSpawner;

    SpawnerTemplete* ghostSpawner2 = new SpawnerFor<GhostTemplete>();
    GhostTemplete* ghost = reinterpret_cast<GhostTemplete*>(
        ghostSpawner2->spawnMonster());
    delete ghostSpawner2;

}