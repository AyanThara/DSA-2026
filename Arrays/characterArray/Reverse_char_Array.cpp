#include <iostream>
using namespace std;
int getLength(char s[]) {
    int i = 0;
    while(s[i] != '\0') i++;
    return i;
}
void reverseCharArray(char s[]) {
    int l = 0;
    int r = getLength(s) - 1;

    while(l < r) {
        swap(s[l], s[r]);
        l++;
        r--;
    }
}
int main() {
    char s[100];
    cin >> s;
    reverseCharArray(s);
    cout << s;
}


