//
//  main.cpp
//  Simulacion #3 Backtraking
//
//  Created by Jorge Soto on 5/21/20.
//  Copyright © 2020 Jorge Soto. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> obj;
vector<bool> include;
int N, valor;

void maxProfit(int i, int acum, int total){
    
};



int main() {
    cin>>N;

    for (int i=0; i<N; i++) {
        cin>> valor;
        obj.push_back(valor);
    }

    return 0;
}

/*
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
*/
