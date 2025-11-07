#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

int main() {
    int m, n, nonZero1, nonZero2;
    cout << "Enter rows and cols of both matrices: ";
    cin >> m >> n;

    cout << "Enter number of non-zero elements in first matrix: ";
    cin >> nonZero1;
    Element a[100];
    cout << "Enter row col val for first matrix:\n";
    for (int i = 0; i < nonZero1; i++)
        cin >> a[i].row >> a[i].col >> a[i].val;

    cout << "Enter number of non-zero elements in second matrix: ";
    cin >> nonZero2;
    Element b[100];
    cout << "Enter row col val for second matrix:\n";
    for (int i = 0; i < nonZero2; i++)
        cin >> b[i].row >> b[i].col >> b[i].val;

    // Result matrix
    Element c[200];
    int i=0,j=0,k=0;

    while(i<nonZero1 && j<nonZero2) {
        if(a[i].row < b[j].row || 
          (a[i].row == b[j].row && a[i].col < b[j].col)) {
            c[k++] = a[i++];
        } 
        else if(b[j].row < a[i].row || 
                 (b[j].row == a[i].row && b[j].col < a[i].col)) {
            c[k++] = b[j++];
        } 
        else { 
            c[k] = a[i];
            c[k].val = a[i].val + b[j].val;
            k++; i++; j++;
        }
    }
    while(i<nonZero1) c[k++] = a[i++];
    while(j<nonZero2) c[k++] = b[j++];

    cout << "\nAdded matrix triplets:\n";
    for(int x=0;x<k;x++)
        cout << c[x].row << " " << c[x].col << " " << c[x].val << endl;

    return 0;
}
