#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    vector<vector<int>> v(1001,vector<int>(1001,0));
    for(int i = 0;i<n;i++){
        int r, c;
        cin >> r >> c;
        v[r][c] = 1;
    }

    vector<pair<int,int>> direction = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> dist(1001,vector<int>(1001,INT32_MAX));
    queue<pair<int,int>> q,tmp;
    q.push({a,b});
    int x = 0;
    while(!q.empty() || !tmp.empty()){
        while(!q.empty()){
            pair<int,int> p = q.front(); 
            q.pop();
            dist[p.first][p.second] = x;
            for(auto &d : direction){
                int r1 = p.first + d.first, c1 = p.second + d.second;
                if(r1 >= 1 && r1 <= 1000 && c1 >= 1 && c1 <= 1000 && dist[r1][c1] == INT32_MAX){
                    if(v[r1][c1] == 1){
                        dist[r1][c1] = x+1;
                        tmp.push({r1,c1});
                    } else{
                        dist[r1][c1] = x;
                        q.push({r1,c1});
                    }
                }
            }
        }
        while(!tmp.empty()){
            q.push(tmp.front());
            tmp.pop();
        }
        x++;
    }
    

    int ans = 1005*1005;

    for(int i = 1; i<= 1000;i++){
        for(int j = 1;j<= 1000;j++){
            if(i == 1 || j == 1 || i == 1000 || j == 1000){
                ans = min(ans,dist[i][j]);
            }
        }
    }
    cout << ans;
}