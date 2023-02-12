#include <iostream>
#include<vector>
#include<map>

using namespace std;

void solve(int n,vector<int> &sol,vector<bool> &used,map<int,int> &m,int len){
    if(len < n){
        for(int i =0;i<n;i++){
            if(!used[i] && (m.count(i) == 0 || used[m[i]])){
                sol[len] = i;
                used[i] = true;
                solve(n,sol,used,m,len+1);
                used[i] = false;
            }
        }
    } else{
        for(auto &x : sol) cout << x << " ";
        cout <<"\n";
    }
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<int> sol(n);
    vector<bool> used(n);
    map<int,int> m;
    for(int i =0;i<k;i++){
        int a,b;
        cin >> a >> b;
        m[b] = a;
    }
    solve(n,sol,used,m,0);
}
