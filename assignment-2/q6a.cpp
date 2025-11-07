#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

int main() {
    int m, n, nonZero;
    cout << "Enter rows and cols of matrix: ";
    cin >> m >> n;
    cout << "Enter number of non-zero elements: ";
    cin >> nonZero;

    Element a[100]; 
    cout << "Enter row, col, value for each non-zero element:\n";
    for (int i = 0; i < nonZero; i++) {
        cin >> a[i].row >> a[i].col >> a[i].val;
    }

    // Transpose
    Element t[100];
    for (int i = 0; i < nonZero; i++) {
        t[i].row = a[i].col;
        t[i].col = a[i].row;
        t[i].val = a[i].val;
    }

    cout << "\nTranspose (row col val):\n";
    for (int i = 0; i < nonZero; i++) {
        cout << t[i].row << " " << t[i].col << " " << t[i].val << endl;
    }

    return 0;
}
