/*
  main.cpp
  Reto#3 Practica - Reducing Dishes DP

  Created by Jorge Soto on 5/18/20.
  Copyright © 2020 Jorge Soto. All rights reserved.

 link: https://leetcode.com/problems/reducing-dishes/
 Hard

 A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.
 Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level  i.e.  time[i]*satisfaction[i]
 Return the maximum sum of Like-time coefficient that the chef can obtain after dishes preparation.
 Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.


 Example 1:
 Input: satisfaction = [-1,-8,0,5,-9]
 Output: 14
 Explanation: After Removing the second and last dish, the maximum total Like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14). Each dish is prepared in one unit of time.

 Example 2:
 Input: satisfaction = [4,3,2]
 Output: 20
 Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)

 Example 4:
 Input: satisfaction = [-2,5,-1,0,3,-3]
                        5,3,0,-1,-2,-3
 Output: 35
 */

#include <iostream>
#include <vector>
using namespace std;

int maxSatisfaction(vector<int>& satisfaction) {
    long n = satisfaction.size();
    sort(satisfaction.begin(),satisfaction.end());
    int curr = 0, acum = 0, ans = 0;

    for (long i = n-1 ;i>=0; i--) {
        curr += acum + satisfaction[i];
        acum += satisfaction[i];
        ans = max(ans, curr);
    }
    return ans;
}

int main() {

    vector<int> satisfaction;

    int n =0, dato;
    cout<<"Cant ? "<<endl;
    cin>> n;

    for (int i=0; i<n;i++) {
        cin>>dato;
        satisfaction.push_back(dato);
    }

    cout<< maxSatisfaction(satisfaction);
    return 0;
}
