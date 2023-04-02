#include<iostream>
#include<vector>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int maxPeri = -1, maxArea = -1,tmpPeri,tmpArea;
vector<pair<int,int>> direction = {{0,1},{0,-1},{1,0},{-1,0}};

void dfs(vector<vector<int>> &g,vector<vector<int>> &color,int n,int i,int j){
    color[i][j] = 1;
    tmpPeri+= 4;
    tmpArea+= 1;
    for(auto &d : direction){
        int r = i + d.first, c = j + d.second;
        if(r >= 0 && r <n && c >= 0 && c < n && g[r][c] == 1){
            tmpPeri--;
            if(color[r][c] == 0) dfs(g,color,n,r,c);
        }
    }
    color[i][j] = 2;
}

int main(){
    setIO("perimeter");
    int n;
    cin >> n;
    vector<vector<int>> g(n,vector<int>(n));
    for(int i = 0;i<n;i++){
        string ip;
        cin >> ip;
        for(int j = 0;j<n;j++){
            if(ip[j] == '#') g[i][j] = 1;
            else g[i][j] = 0;
        }
    }

    vector<vector<int>> color(n,vector<int>(n,0));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            tmpPeri = 0;
            tmpArea = 0;
            if(color[i][j] == 0 && g[i][j] == 1){
                dfs(g,color,n,i,j);
            }
            if(tmpArea > maxArea){
                maxArea = tmpArea;
                maxPeri = tmpPeri;
            } else if(tmpArea == maxArea && tmpPeri < maxPeri){
                maxPeri = tmpPeri;
            }
        }
    }
    cout << maxArea << " " << maxPeri;
}