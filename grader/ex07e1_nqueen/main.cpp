#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int n, ans = 0;

bool valid(vector<int> &sol,int len){
    for(int i = 0;i<len;i++){
        if(abs(sol[len]-sol[i]) == abs(len-i)) return false;
    }
    return true;
}

void solve(vector<int> &sol, vector<bool> &used, int len){
    if(len == n){
        ans++;
        return; 
    }
    for(int i = 0;i<n;i++){
        if(!used[i]){
            used[i] = true;
            sol[len] = i;
            if(valid(sol,len)) solve(sol,used,len+1);
            used[i] = false;
        }
    }
}

int main(){
    cin >> n;
    vector<int> sol(n,0);
    vector<bool> used(n,false);
    solve(sol,used,0);
    cout << ans;
}

/* using struct*/
// int n, ans = 0;

// struct state{
//     vector<int> sol;
//     int len;
//     vector<bool> used;

//     bool valid(){
//         for(int i = 0;i<len;i++){
//             if(abs(sol[i]-sol[len]) == abs(i-len)) return false;
//         }
//         return true;
//     }
// };


// int main(){
//     cin >> n;
//     state init;
//     vector<int> initSol(n,0);
//     vector<bool> initUsed(n,false);
//     init.sol = initSol;
//     init.len = 0;
//     init.used = initUsed;
//     stack<state> s;
//     s.push(init);
//     while(!s.empty()){
//         state t = s.top();
//         s.pop();
//         if(t.len == n) ans++;
//         else{
//             for(int i = 0;i<n;i++){
//                 if(!t.used[i]){
//                     state newT = t;
//                     newT.used[i] = true;
//                     newT.sol[t.len] = i;
//                     if(newT.valid()){
//                         newT.len++;
//                         s.push(newT);
//                     }
//                     newT.used[i] = false;
//                 }
//             }
//         }
//     }
//     cout << ans;
    
// }