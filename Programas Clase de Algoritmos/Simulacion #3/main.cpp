//
//  main.cpp
//  Simulacion #3
//
//  Created by Jorge Soto on 5/21/20.
//  Copyright © 2020 Jorge Soto. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int  maxProfit(vector<int>arr,int n){
    int ans = 0;
    int start = 0;
    long end = arr.size()-1;
    int bot = arr[start];
    int top = arr[arr.size()-1];

    for (int j=1; j<=n; j++) {
        if (bot <= top) {
            ans += bot * j;
            start++;
            bot = arr[start];
        }else if (top <= bot) {
            ans += top * j;
            end--;
            top = arr[end];
        }
    }

    return ans;
}


int main() {
    int N, datos;
    vector<int> arr;

    cin>>N;

    for (int i=0; i<N; i++) {
        cin>> datos;
        arr.push_back(datos);
    }

    cout << maxProfit(arr,N);

    return 0;
}
