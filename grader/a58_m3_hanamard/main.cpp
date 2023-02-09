#include<iostream>
#include<vector>

using namespace std;


void hadamard(int start,int stop,vector<int> &v, vector<int> &ans){
    if(start == stop){
        ans.push_back(v[start]);
        return ;
    }

    int mid = (start+stop)/2;
    vector<int> left,right;

    hadamard(start,mid,v,left);
    hadamard(mid+1,stop,v,right);
    
    for(int i =0 ;i<left.size();i++) ans.push_back(left[i]+right[i]);
    for(int i =0 ;i<left.size();i++) ans.push_back(left[i] - right[i]);
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n),ans;
    for(int i = 0; i< n;i++) cin >> v[i];
    hadamard(0,n-1,v,ans);
    for(auto &x : ans) cout << x << " ";
}


// O(n**2) PPPPPTTTTT
// void hadamard(vector<int> &ans,vector<int> &v,int l,int sx,int sy,bool ex){
//     if(l == 1){
//         ans[sy] += v[sx];
//         return;
//     }
//     if(l == 2 && !ex){
//         ans[sy] += v[sx];
//         ans[sy] += v[sx+1];
//         ans[sy+1] += v[sx];
//         ans[sy+1] -= v[sx+1];
//         return ;
//     }
//     if(l == 2 && ex){
//         ans[sy] -= v[sx];
//         ans[sy] -= v[sx+1];
//         ans[sy+1] -= v[sx];
//         ans[sy+1] += v[sx+1];
//         return ;
//     }
//     hadamard(ans,v,l/2,sx,sy,ex);
//     hadamard(ans,v,l/2,sx+l/2,sy,ex);
//     hadamard(ans,v,l/2,sx,sy+l/2,ex);
//     hadamard(ans,v,l/2,sx+l/2,sy+l/2,!ex);
// }

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(0);
//     int n;
//     cin >> n;
//     vector<int> v(n);
//     for(int i = 0; i< n;i++) cin >> v[i];
//     vector<int> ans(n);
//     hadamard(ans,v,n,0,0,false);    
//     for(auto &x : ans) cout << x << " ";
// }