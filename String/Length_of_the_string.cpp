#include <iostream>
using namespace std;
int stringLength(char str[]) {
    int length = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        length++;
    }
    return length;
}
int main() {
    char str[100];
    cin >> str;
    cout << stringLength(str);
}
