#include <iostream>
using namespace std;

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int n = 3;

    int primary = 0;
    int secondary = 0;

    for (int i = 0; i < n; i++) {
        primary += matrix[i][i];
        secondary += matrix[i][n - 1 - i];
    }

    cout << "Primary diagonal: " << primary << endl;
    cout << "Secondary diagonal: " << secondary << endl;

    return 0;
}
