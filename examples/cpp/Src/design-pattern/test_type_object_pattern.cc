// // Description: Test file for type object pattern.
// // Refenrece. https://boycoding.tistory.com/117#:~:text=각각의%20종족%20객체는,데이터로%20옮긴%20셈이다.
// class Monster;

// class Breed {
// public:
//     Monster* newMonster();
//     Breed(Breed* parent, int health, const char* attack)
//     : parent_(parent),
//       health_(health),
//       attack_(attack){};
//     int getHealth() {
//         // Overriding
//         if(health_ != 0 || parent_ == nullptr) {
//             return health_;
//         }

//         // Inheritance
//         return parent_->getHealth();
//     }
//     const char* getAttack() {
//         // Overriding
//         if(attack_ != nullptr || parent_ == nullptr) {
//             return attack_;
//         }

//         // Inheritance
//         return parent_->getAttack();
//     }

// private:
//     Breed *parent_;
//     int health_;
//     const char* attack_;
// };

// class Monster {
//     friend class Breed;

// public:
//     const char* getAttack() { return breed_.getAttack(); }

// private:
//     Monster(Breed& breed)
//     : health_(breed.getHealth()),
//       breed_(breed) {}
//     int health_;
//     Breed& breed_;
// };

// Monster* Breed::newMonster() {
//     return new Monster(*this);
// }


// void test_type_object_pattern(void) {
//     Breed someBreed(nullptr, 100, "fire");
//     Monster* monster = someBreed.newMonster();
//     delete monster;
// }
