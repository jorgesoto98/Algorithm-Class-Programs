//
//  main.cpp
//  Reto#3 Practica - Greedy Florist
//
//  Created by Jorge Soto on 5/18/20.
//  Copyright © 2020 Jorge Soto. All rights reserved.
//  https://www.hackerrank.com/challenges/greedy-florist/problem
//

/*
 Sample Input 0
 3 3
 2 5 6
 Sample Output 0
 13

 Sample Input 1
 3 2
 2 5 6
 Sample Output 1
 15
 */

#include <iostream>
#include <vector>
using namespace std;


int getMinimumCost(int k, vector<int> c) {
    int ans = 0;
    int n = c.size();
    sort(c.begin(), c.end(),greater<>());

    for(int i = 0; i < n; ++i) {
        ans += ((i / k) + 1) * c[i];
    }

    return ans;
}


int main() {
    vector<int> c;
    int n, k, dato;
    cout<<"Numero de flores ?"<<endl;
    cin >> n;
    cout<<"Numero de Amigos ?"<<endl;
    cin>>k;

    for(int i=0; i<n; i++){
        cin>>dato;
        c.push_back(dato);
    }

    cout<<getMinimumCost(k, c);
    return 0;
}
