#include<iostream>
#include<vector>

using namespace std;

int ans = -1,tmp;

void dfs(vector<int> &g,vector<int> &color,int v){
    color[v] = 1;
    tmp++;
    if(g[v] != -1 && color[g[v]] == 0) dfs(g,color,g[v]);
    color[v] = 2;
}

int main(){
    int n;
    cin >> n;
    vector<int> g(n+1,0);
    for(int i = 1;i<=n;i++) cin >> g[i];

    for(int i = 1;i<=n;i++){
        tmp = 0;
        vector<int> color(n+1,0);
        dfs(g,color,i);
        ans = max(ans,tmp);
    }
    cout << ans;
}