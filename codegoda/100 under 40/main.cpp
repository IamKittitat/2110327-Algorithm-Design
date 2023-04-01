#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;

stack<int> ss;
int maxVisit;
vector<int> dp;

void dfs(vector<vector<int>> &g,vector<int> &color,int i){
    color[i] = 1;
    for(auto &u : g[i]){
        if(color[u] == 0) dfs(g,color,u);
    }
    color[i] = 2;
    ss.push(i);
}

void dfs2(vector<vector<int>> &g,vector<int> &color,int i,set<int> &component){
    color[i] = 1;
    component.insert(i);
    for(auto &u : g[i]){
        if(color[u] == 0) dfs2(g,color,u,component);
        else{
            if(component.count(u) == 0){
                maxVisit = max(maxVisit,dp[u]);
            }
        }
    }
    color[i] = 2;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n),gt(n);
    for(int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        gt[b].push_back(a);
    }

    vector<int> color(n,0);
    for(int i = 0;i<n;i++){
        if(color[i] == 0) dfs(gt,color,i);
    }

    vector<int> color2(n,0);
    dp.resize(n,1);
    while(!ss.empty()){
        int t = ss.top();
        // cout << "t " << t +1 << endl;
        ss.pop();
        if(color2[t] == 0){
            maxVisit = 0;
            set<int> component;
            dfs2(g,color2,t,component);
            // cout << "check " <<  maxVisit << endl;
            for(auto &c : component){
                dp[c] += maxVisit + component.size() -1;
            }
        }
    }
    // for(auto &x : dp) cout << x << " ";
    int q;
    cin >> q;
    for(int i = 0;i<q;i++){
        int ip;
        cin >> ip;
        cout << dp[--ip] << "\n";
    }


    // DONT FORGET WHEN INPUT -1
    return 0;
}