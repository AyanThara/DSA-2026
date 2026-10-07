#include <iostream>
#include <climits>
using namespace std;
pair<int, int> maxsum(int matrix[3][3], int row, int col) {
    int maxrowsum = INT_MIN;
    int maxrow = 0;
    for (int i = 0; i < col; i++) {
        int rowsum = 0;
        for (int j = 0; j < row; j++) {
            rowsum += matrix[j][i];
        }if (rowsum > maxrowsum) {
            maxrowsum = rowsum;
            maxrow = i;
        }
    }return {maxrowsum, maxrow};
}
int main() {
    int matrix[3][3] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    int row = 3;
    int col = 3;
    pair<int, int> ans = maxsum(matrix, row, col);
    cout << "Maximum row sum: " << ans.first << endl;
    cout << "Row index: " << ans.second << endl;
}
