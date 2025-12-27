#include<iostream>
#include<map>
#include<format>


using namespace std;

struct Person {
    string name;
    int age;
};
int main() {

    auto mapCmp = [](auto &a, auto &b) -> bool {
        return a.age < b.age;
    };
    map<Person, int, decltype(mapCmp)> personMap (mapCmp);

    Person alice {"alice", 20};
    Person bob {"bob", 30};
    Person charlie {"charlie", 10};

    personMap[alice] = 0;
    personMap[bob] = 1;
    personMap[charlie] = 2;

    for(auto &kv: personMap) {
        auto &p = kv.first;
        printf("person: %s age: %d\n", p.name.c_str(), p.age);
    }
    return 0;
}