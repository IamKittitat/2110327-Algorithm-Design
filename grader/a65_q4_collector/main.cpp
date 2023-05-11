#include <bits/stdc++.h>

using namespace std;

int n,k,ans = INT32_MAX;
vector<int> price;
vector<vector<int>> seller;

struct state{
    vector<int> sol;
    int len;
    int lb;

    bool operator<(const state &rhs)const{
        return lb > rhs.lb;
    }
};

bool finish(vector<bool> &got){
    for(int i = 1;i<=n;i++) if(got[i] == false) return false;
    return true;
}

bool moreGot(vector<bool> &got,int idx){
    bool newBook = false;
    for(auto &x : seller[idx]){
         got[x] = true;
         newBook = true;
    }
    return newBook;
}

bool cantComplete(vector<bool> got,int len){
    for(int i = len;i<k;i++){
        for(auto &x : seller[i]) got[x] = true;
    }
    return !finish(got);
}

void dfs(vector<int> &sol,vector<bool> &got,int len,int total){
    if(total > ans) return;
    if(cantComplete(got,len)) return;
    if(len == k){
        if(finish(got))ans = min(total,ans);
        return;
    }

    vector<int> sol0 = sol,sol1 = sol;
    vector<bool> got0 = got, got1 = got;

    sol0[len] = 0;
    dfs(sol0,got0,len+1,total);

    sol1[len] = 1;
    if(moreGot(got1,len)) dfs(sol1,got1,len+1,total+price[len]);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    price.resize(k);
    seller.resize(k);
    for(int i = 0;i<k;i++){
        cin >> price[i];
        int m;
        cin >> m;
        vector<int> ip(m);
        for(int j = 0;j<m;j++) cin >> ip[j];
        seller[i] = ip;
    }

    vector<int> sol(k,0);
    vector<bool> got(n+1,0);
    dfs(sol,got,0,0);
    cout << ans;



}