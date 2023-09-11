// // [ING] Proto type pattern

// class Monster {
// public:
//     virtual ~Monster() {}
//     virtual Monster* clone() = 0;
// };

// class Ghost : public Monster {
// public:
//     Ghost(int health, int speed)
//     : health_(health),
//      speed_(speed) {
//      }

//     virtual Monster* clone() {
//         return new Ghost(health_, speed_);
//     }

// private:
//     int health_;
//     int speed_;
// };

// class Spawner {
// public:
//     Spawner(Monster* prototype) : prototype_(prototype) {}

//     virtual ~Spawner() {}
//     virtual Monster* spawnMonster() = 0;

// private:
//     Monster* prototype_;
// };

// template <class T>
// class SpawnerFor : public Spawner {
// public:
//     virtual Monster* spawnMonster() {
//         return new T();
//     }
// };


// void test_proto_type(void){

//     Spawner* ghostSpawner = new SpawnerFor<Ghost>();

//     delete ghostSpawner;
// }