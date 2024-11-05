#include <iostream>
#include <string.h>
using namespace std;

class Person {
    int *age;
    char *name;

    public:
        Person(int age, char *name) {
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);

            this->age = new int(age);
        }

        void display() {
            cout << "Name: " << name << ", Age: " << *age << endl;
        }
};

int main() {
    Person *p = new Person(25, "John Doe");

    // (*p).display();
    p->display();
}