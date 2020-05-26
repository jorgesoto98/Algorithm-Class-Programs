//
//  main.cpp
//  Backtracking
//
//  Created by Jorge Soto on 5/18/20.
//  Copyright © 2020 Jorge Soto. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Variables Globales
vector<int> obj;
int n, valor;
vector<bool> include;

void sum_of_subset(int i, int acum, int total){
    if (acum + total >= valor && (acum==valor || acum+obj[i+1] <= valor)) {
        if (acum == valor) {
            for (int j=0; j<n; j++) {
                if (include[j]) {
                    cout<<obj[j]<<" ";
                }
            }
            cout<<endl;
        }
        else{
            include[i+1] = true;
            sum_of_subset(i+1, acum+obj[i+1], total-obj[i+1]);
            include[i+1] = false;
            sum_of_subset(i+1, acum, total-obj[i+1]);
        }
    }

}

int main() {
    // n= numero de objetos
    int dato, total = 0;
    cin>> n >> valor;

    for (int i=0; i<n; i++) {
        cin >> dato;
        obj.push_back(dato);
        include.push_back(false);
        total += dato;
    }

    sort(obj.begin(),obj.end());
    sum_of_subset(-1, 0, total); // -1 porque en el 0 ya esta incluido el primer dato
    return 0;
}

/*
 5 21
 10
 6
 5
 16
 11
 */
