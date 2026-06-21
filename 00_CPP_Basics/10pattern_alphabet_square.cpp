#include <iostream>
using namespace std;
// Alphabet square pattern
// Example:
// Input: 4
// Output:
// AAAA
// BBBB
// CCCC
int main() {
    int n;
    cin >> n;
    int row = 1;
    while (row <= n) {
        int col = 1;
        char ch = 'A' + row - 1;    
        while (col <= n) {
            cout << ch;
            col++;
        }
        cout << endl;
        row++;
    }
}
