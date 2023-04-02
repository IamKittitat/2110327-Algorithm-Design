#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int r,c;
    cin >> r >> c;
    vector<vector<char>> g(r+1,vector<char>(c+1,0));
    for(int i = 1;i<=r;i++){
        string ip;
        cin >> ip;
        ip = " " + ip;
        for(int j = 1;j<=c;j++) g[i][j] = ip[j];
    }

    vector<pair<int,int>> direction = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> dist(r+1,vector<int>(c+1,101*101));
    queue<pair<int,int>> q;
    q.push({1,1});
    dist[1][1] = 0;
    while(!q.empty()){
        pair<int,int> t = q.front();
        q.pop();
        for(auto &d : direction){
            int i = t.first + d.first, j = t.second + d.second;
            if(i >= 1 && i <= r && j >= 1 && j <= c && g[i][j] == '.' && dist[i][j] == 101*101){
                dist[i][j] = dist[t.first][t.second] + 1;
                q.push({i,j});
            }
        }
    }
    if(dist[r][c] != 101*101) cout << dist[r][c];
    else cout << -1;
}