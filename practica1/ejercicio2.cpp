#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
using namespace std;
typedef vector<int> array;
typedef vector<vector<int> > matriz;
void generar_matriz(matriz &M, int f, int c){
	M.resize(f);
	for(int i=0; i<f ; i++)	
		M[i].resize(c);
}
void load_rand(matriz &M,int val_max){
	srand(time(NULL));
	for (int i = 0; i < M.size(); i++){
		for (int j = 0; j < M.size(); j++)
			M[i][j] = rand()%val_max ;
	}
}
void print(matriz &M, int a , int b){
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			cout<<M[i][j]<<"\t";
		}
		cout<<endl;
	}
}
matriz mut_trad(matriz &A,int m,int n, matriz &B ,int o){
	matriz C;
	generar_matriz(C,m,o);
    print(C,m,o);		
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<o;k++){
				C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    return C;
}

matriz multi_bloques(matriz &A,int N, matriz &B){

	double bloques=32;
    matriz D;
	generar_matriz(D,N,N);
	for (int i1 = 0; i1 < N ; i1 += bloques){
		for (int j1 = 0; j1 < N ; j1 += bloques){
			for ( int k1 = 0; k1 <N ; k1 += bloques){
				for (int i = i1; i<i1+bloques&&i<N ;i++){
					for	(int j=j1; j<j1+bloques&&j<N ;j++){
						for	(int k=k1; k<k1+bloques&&k<N ;k++){
							D[i][j] = D[i][j] + A[i][k]*B[k][j];
                        }
                    }
                }
            }
        }
    }
	return D;
}	

int main()
{
    int m,n,o;
    n=100;
    m=100;
    o=100;
    for(int i=n;i<=2000;i=i+300){
	matriz M1,M2;
	generar_matriz(M1,i,i);		
	load_rand(M1,5);					
	//print(M1,i,i);		
	generar_matriz(M2,i,i);
	load_rand(M2,8);
    //print(M2,i,i);
	clock_t t0;
	t0=clock();
	matriz W=multi_bloques(M1,i,M2);
	t0=clock()-t0;
    float time1=((float)t0)/CLOCKS_PER_SEC;
	cout<<time1<<endl;
    }

}