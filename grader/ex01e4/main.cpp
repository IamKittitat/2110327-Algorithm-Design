#include<bits/stdc++.h>

using namespace std;

int solve(int x,int n,int k){
    if(n == 1) return x%k;

    int subProb = solve(x,n/2,k);
    if(n%2 == 1) return ((subProb*subProb%k)*(x%k))%k;
    else return subProb*subProb%k;
}

int main()
{
    int x,n,k;
    cin >> x >> n >> k;
    cout << solve(x,n,k);
}
