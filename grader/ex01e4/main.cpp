#include<iostream>

using namespace std;

int solve(int x,int n,int k){
    if(n == 1) return x%k;
    
    int result = solve(x,n/2,k);
    if(n%2 == 0) return (result*result)%k;
    else return (((result*result)%k)*(x%k))%k;
}

int main(){
    int x,n,k;
    cin >> x >> n >> k;
    cout << solve(x,n,k);
}