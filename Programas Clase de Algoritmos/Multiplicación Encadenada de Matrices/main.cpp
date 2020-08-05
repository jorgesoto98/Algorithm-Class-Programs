//
//  main.cpp
//  Multiplicación encadenada de matrices
//
//  Created by Jorge Soto on 4/13/20.
//  Copyright © 2020 Jorge Soto. All rights reserved.
//

#include <iostream>
#include <climits>

using namespace std;

#define MAX 51

void calcula(int D[MAX][MAX], int P[MAX][MAX], int d[MAX], int n){
    int aux, menk;
    for (int i=1; i<=n; i++){
        D[i][i] = 0;
    }

    int j;
    for (int diag=1; diag<= n-1; diag++){
        for (int i = 1; i<=n-diag; i++) {
            j = i + diag;
            int men = INT_MAX;
            for (int k=i; k<j; k++){
                aux = D[i][k] + D[k+1][j] + d[i-1]*d[k]*d[j];
                if (aux < men){
                    men = aux;
                    menk = k;
                }
            }
            D[i][j] = men;
            P[i][j] = menk;
        }
    }
}
/*
 4
 20 2 30 12 8

 RESP = 1232
 (A)x(((B)x(C))x(D))
 */
void recorre(int P[MAX][MAX], int ini, int fin){
    if (P[ini][fin] != 0){
        cout << "(";
        recorre(P, ini, P[ini][fin]);
        cout << ")x(";
        recorre(P, P[ini][fin]+1, fin);
        cout << ")";
    }
    else{
        char ch='A'+ini-1;
        cout << ch;
    }
}

void despliega(int P[MAX][MAX], int n){
    recorre(P,1,n);
    cout << endl;
}

int main(){
    int d[MAX]; // Las dimenciones de las matrices
    int D[MAX][MAX], P[MAX][MAX];
    int n; // cantidad de matrices a mult.

    cin >> n;
    for (int i=0; i<=n; i++){
        cin >> d[i];
    }
    // A  8 x 2
    // B  2 x 5
    // C  5 x 4
    // n = 3
    // d  8 2 5 4

    calcula(D, P, d, n);
    cout << D[1][n]<< endl;
    // despliega(P, n);

}
