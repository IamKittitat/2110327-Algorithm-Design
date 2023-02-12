#include<iostream>
#include<vector>

using namespace std;

void solve(int n,vector<int> &sol,int len,int k,int cons,bool isAns){
    if(len < n){
        sol[len] = 0;
        solve(n,sol,len+1,k,0,isAns);
        if(cons+1 == k) isAns = true;
        sol[len]  =1;
        solve(n,sol,len+1,k,cons+1,isAns);
    } else{
        if(isAns){
            for(auto &x :sol) cout << x;
            cout << "\n";
        }
    }
}

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> sol(n);
    solve(n,sol,0,k,0,false);
}
