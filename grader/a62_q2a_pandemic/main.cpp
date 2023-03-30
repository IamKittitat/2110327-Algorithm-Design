#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int r,c,t;
    cin >> r >> c >> t;
    vector<vector<int>> v(r,vector<int>(c));
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin >> v[i][j];
        }
    }
    
    vector<pair<int,int>> direction = {{-1,0},{1,0},{0,1},{0,-1}};
    queue<pair<int,int>> q;

    // Loop t times
    for(int i = 0;i<t;i++){
        // Put every 1 to queue
        for(int j = 0;j<r;j++) for(int k =0;k<c;k++) if(v[j][k] == 1) q.push({j,k});       
        // Do 4 direction for every items in queue
        while(!q.empty()){
            pair<int,int> p = q.front(); q.pop();
            for(auto &d : direction){
                int r1 = p.first + d.first, c1 = p.second + d.second;
                if(r1 >= 0 && r1 < r && c1 >= 0 && c1 < c && v[r1][c1] != 2){
                    v[r1][c1] = 1;
                }
            }
        }
    }
    int ans = 0;
    for(auto &x : v) for(auto &y : x) if(y == 1) ans++;
    cout << ans;
}