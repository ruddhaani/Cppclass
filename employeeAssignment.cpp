#include <iostream>
#include <cstring>
using namespace std;

class Employee {
    char *name;
    char *address;
    int age;

    bool validateName(const char *name) {
        for (int i = 0; i < strlen(name); ++i) {
            if (!isalpha(name[i]) && !isspace(name[i])) {
                return false;
            }
        }
        return true;
    }

    bool validateAge(int age) {
        return (age >= 18 && age <= 80);
    }

    bool validateAddress(const char *address) {
        for (int i = 0; i < strlen(address); ++i) {
            if (!isalnum(address[i]) && address[i] != ' ' && address[i] != ',' && address[i] != '.') {
                return false;
            }
        }
        return true;
    }

public:
    Employee() {
        this->name = nullptr;
        this->address = nullptr;
        this->age = 18;
    }

    Employee(const char *name, int age, const char *address) {
        this->name = nullptr;
        this->address = nullptr;
        
        if (validateName(name)) {
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        } else {
            cout << "Invalid name provided. Setting default name.\n";
            setName();
        }

        if (validateAddress(address)) {
            this->address = new char[strlen(address) + 1];
            strcpy(this->address, address);
        } else {
            cout << "Invalid address provided.\n";
            setAddress();
        }

        if (validateAge(age)) {
            this->age = age;
        } else {
            cout << "Invalid age provided. Setting default age (18).\n";
            this->age = 18;
        }
    }

    void display() {
        cout << "Name: " << (this->name ? this->name : "N/A") << endl;
        cout << "Age: " << this->age << endl;
        cout << "Address: " << (this->address ? this->address : "N/A") << endl;
    }

    void setName() {
        char *tempName = new char[100];
        bool valid = false;
        while (!valid) {
            cout << "Enter name: ";
            cin.getline(tempName, 100);
            if (validateName(tempName)) {
                valid = true;
                delete[] name;
                name = new char[strlen(tempName) + 1];
                strcpy(name, tempName);
            } else {
                cout << "Invalid name. Please enter letters and spaces only.\n";
            }
        }

        delete[] tempName;
    }

    void setAddress() {
        char *tempAddress = new char[200];
        bool valid = false;
        while (!valid) {
            cout << "Enter Address: ";
            cin.getline(tempAddress, 200);
            if (validateAddress(tempAddress)) {
                valid = true;
                delete[] address;
                address = new char[strlen(tempAddress) + 1];
                strcpy(address, tempAddress);
            } else {
                cout << "Invalid address. Only letters, numbers, spaces, commas, and periods are allowed.\n";
            }
        }

        delete [] tempAddress;
    }
};

int main() {
    Employee employee("ani12", 19, "Dnyanesh Society");
    employee.display();
    employee.setAddress();
    employee.display();
    return 0;
}
