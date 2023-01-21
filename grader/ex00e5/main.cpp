#include <bits/stdc++.h>

using namespace std;

void consec_one(int n,int len,vector<int> sol,int k){
    if(len < n){
        sol[len] = 0;
        consec_one(n,len+1,sol,k);
        sol[len] = 1;
        consec_one(n,len+1,sol,k);
    } else{
        int chk = 0,maxCon = 0;
        for(auto &x : sol){
            if(x == 1) chk++;
            else{
                if(chk > maxCon) maxCon = chk;
                chk = 0;
            }
        }
        if(chk > maxCon) maxCon = chk;
        if(maxCon >= k){
            for(auto &x : sol) cout << x;
            cout << "\n";
        }
    }
}

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> sol(n);
    consec_one(n,0,sol,k);
}
