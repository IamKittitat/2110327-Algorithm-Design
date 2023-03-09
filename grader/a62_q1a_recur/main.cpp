#include<iostream>
#include<vector>

using namespace std;

void solve(vector<vector<int>> &v,int a,int b,int sx,int sy,int len){
    if(a == 0){
        v[sy][sx] = b;
        return;
    }
    solve(v,a-1,b,sx,sy,len/2);
    solve(v,a-1,b-1,sx+len/2,sy,len/2);
    solve(v,a-1,b+1,sx,sy+len/2,len/2);
    solve(v,a-1,b,sx+len/2,sy+len/2,len/2);
}

int main(){
    int a,b;
    cin >> a >> b;
    vector<vector<int>> v(1<<a,vector<int>(1<<a,0));
    solve(v,a,b,0,0,1<<a);
    for(auto &x : v){
        for(auto &y : x) cout << y << " ";
        cout << endl;
    }
}