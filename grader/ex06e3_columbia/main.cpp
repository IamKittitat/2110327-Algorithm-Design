#include<iostream>
#include<vector>
#include<queue>

using namespace std;


typedef pair<int,pair<int,int>> edge;

int main(){
    int r,c;
    cin >> r >> c;
    vector<vector<int>> w(r,vector<int>(c,1001));
    vector<vector<int>> dist(r,vector<int>(c,INT32_MAX));
    for(int i = 0;i<r;i++){
        for(int j =0;j<c;j++) cin >> w[i][j];
    }
    vector<pair<int,int>> direction = {{0,1},{0,-1},{1,0},{-1,0}};
    priority_queue<edge,vector<edge>,greater<edge>> pq;
    dist[0][0] = 0;
    pq.push({0,{0,0}});
    while(!pq.empty()){
        edge e = pq.top();
        pq.pop();
        int x = e.second.first, y = e.second.second;
        for(auto &di : direction){
            int r1 = x + di.first, c1 = y + di.second;
            if(r1 >= 0 && r1 < r && c1 >= 0 && c1 < c && (dist[x][y] + w[r1][c1] < dist[r1][c1])){
                dist[r1][c1] = w[r1][c1] + dist[x][y];
                pq.push({dist[r1][c1],{r1,c1}});
            }
        }
    }

    for(auto &x : dist){
        for(auto &y : x) cout << y << " ";
        cout << "\n";
    }

}