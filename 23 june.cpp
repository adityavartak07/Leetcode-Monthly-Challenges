
// kth largets element using Priority queue
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& input, int k) {
     int n = input.size();
    priority_queue <int, vector<int>, greater<int> > q;
    if(n>=k){
        for(int i=0;i<k;i++){
            q.push(input[i]);
        }

        for(int i=k;i<n;i++){
            if(input[i]>q.top()){
                q.pop();
                q.push(input[i]);
            }
        }
    }else{
        return INT_MIN;
    }

    return q.top();
    }
};