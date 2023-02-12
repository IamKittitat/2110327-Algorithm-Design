#include<iostream>
#include<vector>

using namespace std;

int solve(int n,int start,int stop,int l,int r){
    // cout << n << " " << start << " " << stop << " " <<  l << " " << r << endl;
    if(n == 1) return 1;
    if(n == 0) return 0;

    int m = (start+stop)/2;
    int left =0,right=0;
    // Divide to [left] mid [right]
    if(l<m) left = solve(n/2,start,m-1,l,min(m-1,r)); // min(m-1,r) for right pointer in the left case.
    if(r>m) right = solve(n/2,m+1,stop,max(m+1,l),r); // max(m+1,l) for left pointer in the right case.

    int ans = left + right;
    // Check mid condition if %2 == 1
    if(l<=m && r >=m && n%2 == 1) ans++;
    return ans;
}

int main(){
    int n,l,r;
    cin >> n >> l >> r;

    int tmp = n,len = 1,i = 2;
    while(tmp>1){
        len += i;
        tmp /= 2;
        i*=2;
    }

    cout << solve(n,0,len-1,l-1,r-1);
}  