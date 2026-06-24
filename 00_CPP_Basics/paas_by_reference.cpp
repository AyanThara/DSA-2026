#include <iostream>
using namespace std;

void change(int &x) {
    x = 100;
}

int main() {
    int a = 10;
    change(a);

    cout << a;
}

//output will be 100 because address is passed and changes will occurrr in original variable
