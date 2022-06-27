
//Partitioning Into Minimum Number Of Deci-Binary Numbers
//https://www.youtube.com/watch?v=iL5QKlJ_eMU


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for (char x:n){
            int curr = x - 48;
            ans = max(curr,ans);
        }
        return ans;
    }
};