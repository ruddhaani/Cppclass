#include <iostream>
#include <cstring>
using namespace std;

class A{
    protected:
     int a;

    public:
        A() {
            a = 0;
        }

        A(int a){
            this->a = a;
            cout << "A called" << endl;
        }

        void displayA(){
            cout << "A: " << a << endl;
        }

};

class B : public virtual A{
    protected:
     int b;

    public:
        B() {
            b = 0;
        }

        B(int a , int b) : A(a){
            this->b = b;
            cout << "B called" << endl;
        }

        void displayB(){
            cout << "B: " << b << endl;
        }

};

class C : virtual public A{
    protected:
     int c;

    public:
        C() {
            c = 0;
        }

        C(int a , int c) : A(a){
            this->c = c;
            cout << "C called" << endl;
        }

        void displayC(){
            cout << "C: " << c << endl;
        }

};

class D : public B , public C{
    protected:
     int d;

    public:
        D() {
            d = 0;
        }

        D(int a , int b , int c , int d) : A(a), B(a ,b) , C (a,c){
            this->d = d;
            cout << "D called" << endl;
        }

        void displayD(){
            A::displayA();
            B::displayB();
            C::displayC();
            cout << "D: " << d << endl;
        }

};

int main(){
    D obj(10,20,30,40);

    obj.displayA();
    obj.displayB();
    obj.displayD();

    cout << sizeof(obj) << endl;

    

    return 0;
}