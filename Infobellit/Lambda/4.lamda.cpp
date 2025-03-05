#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a Person class
class Person {
public:
    string name;
    int age;

    // Constructor
    Person(string name, int age) : name(name), age(age) {}

    // Getter for name
    string get_name() const {
        return name;
    }

    int get_age() const {
        return age;
    }
    // Overload << operator for printing
    friend ostream& operator<<(ostream& os, const Person& p) {
        os << p.name << " (" << p.age << ")";
        return os;
    }
};

int main() {
    // Create a vector of Person objects
    vector<Person> stooges{
        {"Larry", 18},
        {"Moe", 30},
        {"Curly", 25},
        {"Anil", 5}

    };

    // Sort by name
    sort(begin(stooges), end(stooges), [](const Person &p1, const Person &p2) {
        return p1.get_name() < p2.get_name();
    });

    // Print sorted persons
    for_each(begin(stooges), end(stooges), [](const Person &p) {
        cout << p << endl;
    });
    sort(begin(stooges), end(stooges), [](const Person &p1, const Person &p2) {
        return p1.get_age() < p2.get_age();
    });
    for_each(begin(stooges), end(stooges), [](const Person &p) {
        cout << p << endl;
    });

    return 0;
}
