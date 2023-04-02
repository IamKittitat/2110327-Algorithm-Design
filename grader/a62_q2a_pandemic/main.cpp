#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int r,c,t;
    cin >> r >> c >> t;
    vector<vector<int>> g(r,vector<int>(c,0)),dist(r,vector<int>(c,INT32_MAX));
    queue<pair<int,int>> q;
    for(int i= 0 ;i<r;i++){
        for(int j =0;j<c;j++){
            cin >> g[i][j];
            if(g[i][j] == 1) q.push({i,j});
        }
    }
    vector<pair<int,int>> direction = {{0,1},{0,-1},{1,0},{-1,0}};
    while(t--){
        queue<pair<int,int>> tmp;
        while(!q.empty()){
            pair<int,int> t = q.front();
            q.pop();
            for(auto &d : direction){
                int i = t.first + d.first, j = t.second + d.second;
                if(i >= 0 && i < r && j >= 0 && j < c && g[i][j] == 0){
                    g[i][j] = 1;
                    tmp.push({i,j});
                }
            }
        }
        q = tmp;
    }

    int ans = 0;
    for(auto &x : g) for(auto &y : x)if(y == 1) ans++;
    cout << ans;

}