#include <iostream>
// El Tesoro de la Tortuga
// Matricula: A01282936
// Nombre: Jorge Miguel Soto Rodriguez

using namespace std;
#define MAX 100

int turtle(int mat[MAX][MAX], int n, int m){
    // AquÃ­ va tu codigo

    //actualizar primer reglon y primera columna
    //regnlon
    for (int i=1; i<m; i++) {
        mat[0][i] = mat[0][i] + mat[0][i-1];
    }
    //columna
    for (int i=1; i<n; i++) {
        mat[i][0] = mat[i][0] + mat[i-1][0];
    }

    //Comparar arriba y a la izquierda
    int a,b;
    for (int i =1; i<n; i++) {
        for (int j=1; j<m; j++) {
            a = mat[i][j-1];
            b = mat[i-1][j];
            mat[i][j] = max(a, b) + mat[i][j];
        }
    }

    return mat[n-1][m-1];
    return 0;
}

void print(int mat[MAX][MAX], int n, int m){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << mat[i][j]<< " ";
        }
        cout << endl;
    }
}

int main(){
    int n, m;
    int mat[MAX][MAX];
    cin >> n  >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> mat[i][j];
        }
    }
        //print(mat, n, m);
    cout << turtle(mat, n, m)<<endl;
}

/*
 3 5
 1 2 1 1 3
 2 10 2 2 3
 1 1 0 1 3
 Resp: 23

 3 4
 163 141 752 620
 672 91 899 120
 50 974 456 297
 Resp: 2708
 */
