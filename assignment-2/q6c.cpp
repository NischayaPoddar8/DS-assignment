#include <iostream>
#include <vector>
using namespace std;

struct Element {
    int row, col, val;
};

int main() {
    int m,n,p,nonZero1,nonZero2;
    cout<<"Enter rows cols of A and cols of B: ";
    cin>>m>>n>>p; // A is m×n, B is n×p

    cout<<"Enter number of non-zero in A: ";
    cin>>nonZero1;
    Element A[100];
    for(int i=0;i<nonZero1;i++)
        cin>>A[i].row>>A[i].col>>A[i].val;

    cout<<"Enter number of non-zero in B: ";
    cin>>nonZero2;
    Element B[100];
    for(int i=0;i<nonZero2;i++){
        cin>>B[i].row>>B[i].col>>B[i].val;
    }
    
    int C[50][50]={0}; 

    for(int i=0;i<nonZero1;i++){
        for(int j=0;j<nonZero2;j++){
            if(A[i].col==B[j].row){
                C[A[i].row][B[j].col]+=A[i].val*B[j].val;
            }
        }
    }

    cout<<"\nMultiplication result triplet:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            if(C[i][j]!=0){
                cout<<i<<" "<<j<<" "<<C[i][j]<<endl;
            }
        }
    }

    return 0;
}
