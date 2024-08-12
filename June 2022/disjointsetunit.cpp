
#include<bits/stdc++.h>s
using namespace std;

vector<int> parent;
vector<int> rank;
int count;



int findparent(int node){

    if(parent[node] == node) return node;
    else return parent[node] = findparent(parent[node]);
        
}

void unionbyrank(int x, int y){
    int upx = findparent(x);
    int upy = findparent(y);

    if(upx != upy){
        if(rank[upx] > rank[upy]){
            parent[upy] = upx;
        }else if(rank[upx] < rank[upy]){
            parent[upx] = upy;
        }
        else{
            parent[upx] = upy;
            rank[upy]++;
        }
    }else{
        count++;
    }

}