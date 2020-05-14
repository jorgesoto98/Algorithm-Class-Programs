//
//  main.cpp
//  Tar10– Sum in a Triangle
//
//  Created by Jorge Soto on 4/27/20.
//  Copyright © 2020 Jorge Soto. All rights reserved.

/*

    Jorge Miguel Soto Rodriguez
    A01282936
    Tarea #10 Sum in a Triangle

 */


//
//

#include <iostream>
#include <vector>
#define MAX 10
using namespace std;

int main() {

    int n; //Test Cases
    int nX; //Numero de lineas
    int e; //Elemento
    int aux;//Auxiliar
    int D[MAX][MAX];//Matriz
    vector<int> arr; //Respuestas

    cin>> n;
    //Primer For Test Cases
    for (int cases=0;cases<n; cases++) {
        cin>>nX;
        aux=1;
        //Llenar la matriz
        for (int i=0; i<nX; i++) {
            for (int j=0; j<aux; j++) {
                cin>>e;
                D[i][j]=e;
            }
            aux++;
        }

        aux = nX-1;
        int auxDp = nX-2;
        //Dynmic Programing
        for (int i=auxDp; i>=0; i--) {
            for (int j=0; j<aux; j++) {
                int a = D[i][j] + D[i+1][j];
                int b = D[i][j] + D[i+1][j+1];
                D[i][j] = max(a,b);
            }
            aux--;
        }
        if (n>1) {
            arr.push_back(D[0][0]);
        }else {
            cout<<D[0][0];
        }
    }

    //Desplegar Respuestas
    for (int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<endl;
    }
    return 0;
}
/*

 1
 4
 1
 1
 2
 4
 1
 2
 2
 3
 1
 1

*/
