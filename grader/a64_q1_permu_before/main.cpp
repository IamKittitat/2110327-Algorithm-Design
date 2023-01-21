#include <bits/stdc++.h>

using namespace std;

void perm_with_cons(int n,int len,vector<int> &sol,vector<bool> &used,map<int,int> &constraint){
    if(len < n){
        for(int i = 0; i<n;i++){
            if(used[i] == false &&(constraint.find(i) != constraint.end() && used[constraint[i]] == true || constraint.find(i) == constraint.end())){
                used[i] = true;
                sol[len] = i;
                perm_with_cons(n,len+1,sol,used,constraint);
                used[i] = false;
            }
        }
    } else{
        for(auto &x:sol) cout << x << " ";
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,a,b;
    cin >> n >> m;
    map<int,int> constraint;
    vector<int> sol(n);
    vector<bool> used(n);
    for(int i = 0; i<m;i++){
        cin >> a >> b;
        constraint[b] = a;
    }
    perm_with_cons(n,0,sol,used,constraint);
}
