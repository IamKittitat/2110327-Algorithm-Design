#include <iostream>
#include<vector>

using namespace std;

void perm(int n,vector<int> &sol,vector<bool> &used,int len){
    if(len < n){
        for(int i = 1;i<=n;i++){
            if(!used[i]){
                used[i] = true;
                sol[len] = i;
                perm(n,sol,used,len+1);
                used[i] = false;
            }
        }
    } else{
        for(int i =0;i<sol.size();i++) cout << sol[i] << " ";
        cout << "." << endl;
    }
    
}

void perm_kn(int n,vector<int> &sol,int len,vector<bool> &used,int k){
    if(len < k){
        for(int i =1;i<=n;i++){
            if(!used[i]){
                used[i] = true;
                sol[len] = i;
                perm_kn(n,sol,len+1,used,k);
                used[i] = false;
            }
        }
    } else{
        for(int i =0;i<k;i++) cout << sol[i] << " ";
        cout << endl;
    }
}

void perm_kn_replace(int n,vector<int> &sol,int len,int k){
    if(len < k){
        for(int i =1;i<=n;i++){
            sol[len] = i;
            perm_kn_replace(n,sol,len+1,k);
        }
     }
    else{
        for(int i =0;i<k;i++) cout << sol[i];
        cout << endl;
    }
}

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> sol(n);
    vector<bool> used(n);
    // perm(n,sol,used,0);
    // perm_kn(n,sol,0,used,k);
    perm_kn_replace(n,sol,0,k);
}
