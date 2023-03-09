#include<iostream>

using namespace std;

int getLen(int n){
    if(n == 1) return 1;
    return 2*getLen(n/2) + 1;
}

int solve(int n,int l,int r,int start,int stop){
    if(l > r) return 0;
    if(n == 1) return 1;
    if(n == 0) return 0;

    int m = (start+stop)/2;
    int leftAns = solve(n/2,l,min(r,m-1),start,m-1);
    int midAns = n%2 == 1 && (l <= m && r >= m) ? 1 : 0;
    int rightAns = solve(n/2,max(m+1,l),r,m+1,stop);
    return leftAns + midAns + rightAns;
}

int main(){
    int n,l,r;
    cin >> n >> l >> r;
    cout << solve(n,l,r,1,getLen(n));
}