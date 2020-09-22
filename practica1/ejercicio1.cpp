#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
int main()
{
    const int MAX=3;
    double A[MAX][MAX],x[MAX],y[MAX];
    for(int i=0;i <MAX; i++){
        for(int j=0;j<MAX;j++){
            y[i]+=A[i][j]*x[j];
        }
    }
    for(int j=0;j<MAX;j++){
        for(int i=0;i<MAX;i++){
            y[i]+= A[i][j]*x[j];
        }
    }
}