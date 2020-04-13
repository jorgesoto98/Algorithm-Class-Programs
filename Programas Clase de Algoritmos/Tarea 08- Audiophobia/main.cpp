//
//  main.cpp
//  Tarea 08- Audiophobia
//
//  Created by Jorge Soto on 4/3/20.
//  Copyright © 2020 Jorge Soto. All rights reserved.

//  Se modifico el algoritmo de floyd para guardar el valor del nodo mayor en el
//  que se encontrara dentro del trayecto.

#include <iostream>
#include <climits>

using namespace std;

void leeArcos(int mat[100][100], int m, int n){
    int a,b,c;
    for (int i=0; i<100; i++) {
        mat[i][i] = 0;
        for (int j=i+1; j<100; j++) {
            mat[i][j] = mat[j][i] = INT_MAX;
        }
    }
    for (int i=1; i<=m; i++) {
        cin>> a >> b >>c;
        mat[a-1][b-1] = mat[b-1][a-1] = c;
    }
}

void floyd(int mat[100][100], int n){
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (mat[i][k] != INT_MAX && mat[k][j] != INT_MAX && mat[i][j] > max(mat[i][k], mat[k][j])) {
                    mat[i][j] = max(mat[i][k], mat[k][j]);
                }
            }
        }
    }
}

void consulta(int mat[100][100], int q){
    int a,b;
    for (int i =1; i<=q; i++) {
        cin >> a >>b;
        if (mat[a-1][b-1] == INT_MAX) {
            cout<<"No path"<<endl;
        }else{
            cout<< mat[a-1][b-1]<<endl;
        }
    }
}


int main() {
    int mat[100][100];
    int casos;
    int n, m, q;

    // n - Cant Nodos
    // m - Cant Arcos
    // q - Cant de Consultas

    cin>> casos;

    for (int i=0 ;i<casos; i++) {
        cin>> n >> m >> q;
        leeArcos(mat, m, n);
        floyd(mat, n);
        cout<< "Case "<<i+1 <<":"<<endl;
        consulta(mat, q);
    }

    return 0;
}

