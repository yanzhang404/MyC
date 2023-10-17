#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > generate_spiral_matrix(int n) {
    vector<vector<int> > matrix(n, vector<int>(n, 0));
    int num = 1;
    int start_row = 0, end_row = n - 1;
    int start_col = 0, end_col = n - 1;
    while (start_row <= end_row && start_col <= end_col) {
        for (int i = start_col; i <= end_col; i++) {
            matrix[start_row][i] = num;
        }
        start_row++;
        for (int i = start_row; i <= end_row; i++) {
            matrix[i][end_col] = num;
        }
        end_col--;
        if (start_row <= end_row) {
            for (int i = end_col; i >= start_col; i--) {
                matrix[end_row][i] = num;
            }
            end_row--;
        }
        if (start_col <= end_col) {
            for (int i = end_row; i >= start_row; i--) {
                matrix[i][start_col] = num;
            }
            start_col++;
        }
        num++;
    }
    return matrix;
}
int main() {
    int n;
    cin >> n;
    vector<vector<int> > matrix = generate_spiral_matrix(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<< matrix[i][j]<<" ";
        }
        cout<<" "<<endl;
    }

    return 0;
}