#include <iostream>
#include <cstring>
using namespace std;

class A{
    protected:
        int a;

    public:
        A(){
            a = 0;
        }

        A(int a){
            this->a = a;
        }

        void display(){
            cout << "a: " << a << endl;
        }
};

class B{
    protected:
        int b;

    public:
        B(){
            b = 0;
        }

        B(int b){
            this->b = b;
        }

        void displby(){
            cout << "b: " << b << endl;
        }
};

class C : public A , public B{
    protected:
        int c;

    public:
        C(){
            c = 0;
        }

        C(int a , int b ,int c) : B(b) , A(a){
            this->c = c;
        }

        void displcy(){
            A::display();
            B::displby();
            cout << "c: " << c << endl;
        }
};

int main(){
        C obj(10,20,30);

        obj.display();
        obj.displby();
        obj.displcy();


}