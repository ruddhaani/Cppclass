#include <iostream>
#include <cstring>

using namespace std;

class Person{
    protected:
        int *age;
        char *name;

    public:
        Person(){
            this->name = new char[20];
            this-> age = new int(1);
            strcpy(this->name , "Aniruddha");
        }

        Person(char *name , int age){
            this->name = new char[strlen(name)+1];
            strcpy(this->name , name);
            this->age = new int(age);
        }

        void displayPerson(){
            cout << "Name: " << name << endl << "Age: " << *age << endl;
        }

        ~Person(){
            delete [] name;
            delete age;
            cout << "Everything in the dynamic memory is deleted!" << endl;
        }

};

class Employee: public Person{
    protected:
        int *eid;
        float *salary;

    public:
        Employee(){
            this-> eid = new int(1);
            this->salary = new float(600000);
        }

        Employee(char *name , int age , int eid , float salary):Person(name, age){
            this->eid = new int(eid);
            this->salary = new float(salary);
        }

        void displayEmployee(){
            cout << "Name: "<< name << endl <<"Age : " << *age << endl << "Employee Id: "  << *eid << endl << "Salary : " << *salary << endl;
        }

        ~Employee(){
            delete [] name;
            delete age;
            delete salary;
            delete eid;
            cout << "Everything in the dynamic memory is deleted!" << endl;
        }

};

class Developer : public Employee{
    char *projectName;

    public: 
    Developer(){
        projectName = new char[20];
        strcpy(projectName, "Default");
    }

    Developer(char *name , int age , int eid , float salary ,char *projectName): Employee(name , age , eid,salary ){
        this->projectName = new char[strlen(projectName)+1];
        strcpy(this->projectName, projectName);
    }

    void displayDeveloper(){
        displayEmployee();
        cout << "Project Name: " << projectName << endl;
    }

    ~Developer(){
            delete [] name;
            delete age;
            delete salary;
            delete eid;
            delete [] projectName;
            cout << "Everything in the dynamic memory is deleted!" << endl;
        }
};

int main(){

    Person p("John Doe" , 11);
    p.displayPerson();
    // p.displayEmployee();

    Employee e;
    e.displayPerson();
    e.displayEmployee();
}
