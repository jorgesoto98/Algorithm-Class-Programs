//
//  main.cpp
//  Reto#3 Practica -  Minimum Add to Make Parentheses Valid Greedy
//
//  Created by Jorge Soto on 5/18/20.
//  Copyright © 2020 Jorge Soto. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

int minAddToMakeValid(string S) {
    int aux = 0, ans = 0;
    for (int i=0; i<S.size(); i++) {
        if (S[i] == '(') {
            aux++;
        }else{
            if (aux==0) {
                ans++;
            }else aux--;
        }
    }

    ans = aux + ans;

    return ans ;
}

int main() {
    string s;
    cout<<"String?"<<endl;
    cin>>s;


    cout<< minAddToMakeValid(s);
    return 0;
}
