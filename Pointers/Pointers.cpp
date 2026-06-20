#include<iostream>
using namespace std;
int main() {
    int a = 10;
    int *ptr = &a;
    cout << ptr << endl;   // prints address of a 
    cout<<&a<<endl;//address of a
    cout << *ptr << endl;  // prints value stored at that address //10
    cout<<&ptr<<endl;//prints the address of pointer
}
