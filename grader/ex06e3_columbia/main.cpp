#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int,pair<int,int>> node;

int main(){
    int r,c;
    cin >> r >> c;
    vector<vector<int>> g(r,vector<int>(c)),dist(r,vector<int>(c,INT32_MAX));
    for(int i =0;i<r;i++){
        for(int j=0;j<c;j++) cin >> g[i][j];
    }
    vector<pair<int,int>> direction = {{0,1},{0,-1},{1,0},{-1,0}};
    dist[0][0] = 0;
    priority_queue<node,vector<node>,greater<node>> pq;
    pq.push({0,{0,0}});
    while(!pq.empty()){
        node t = pq.top();
        pq.pop();
        int w = t.first, i = t.second.first, j = t.second.second;
        for(auto &d : direction){
            int r1 = i + d.first, c1 = j + d.second;
            if(r1 >= 0 && r1 < r && c1 >= 0 && c1 < c && dist[i][j] + g[r1][c1] < dist[r1][c1]){
                dist[r1][c1] = dist[i][j] + g[r1][c1];
                pq.push({dist[r1][c1],{r1,c1}});
            }
        }
    }
    for(auto &x : dist){
        for(auto &y : x) cout << y << " ";
        cout << "\n";
    }
}