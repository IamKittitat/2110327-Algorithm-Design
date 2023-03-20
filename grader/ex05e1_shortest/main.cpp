#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int r,c;
    cin >> r >> c;
    vector<vector<char>> v(r+1,vector<char>(c+1));
    vector<vector<int>> dist(r+1,vector<int>(c+1,INT32_MAX));
    for(int i = 1;i<=r;i++){
        string s;
        cin >> s;
        s = " " + s;
        for(int j = 1;j<=c;j++) v[i][j] = s[j];
    }

    queue<pair<int,int>> q;
    dist[1][1] = 0;
    q.push({1,1});

    while(!q.empty()){
        pair<int,int> p = q.front(); 
        int i = p.first, j = p.second;
        q.pop();
        if(i < r){
            if(dist[i+1][j] == INT32_MAX && v[i+1][j] == '.'){ 
                dist[i+1][j] = dist[i][j] + 1;
                q.push({i+1,j});    
            }
        }
        if(j < c){
            if(dist[i][j+1] == INT32_MAX && v[i][j+1] == '.'){
                dist[i][j+1] = dist[i][j] + 1;
                q.push({i,j+1});
            }
        }
        if(i > 1){
            if(dist[i-1][j] == INT32_MAX && v[i-1][j] == '.'){
                dist[i-1][j] = dist[i][j] + 1;
                q.push({i-1,j});
            }
        }
        if(j > 1){
            if(dist[i][j-1] == INT32_MAX && v[i][j-1] == '.'){
                dist[i][j-1] = dist[i][j] + 1;
                q.push({i,j-1});
            }
        }
    }
    if(dist[r][c] == INT32_MAX) cout << -1;
    else cout << dist[r][c];
}