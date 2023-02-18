#include<iostream>
#include<vector>

using namespace std;

vector<int> v(50);

int solve(int n){
    // Top down
    // if(n <= 1) return n;
    // if(v[n] > 0) return v[n];
    // v[n] = solve(n-1)+solve(n-2);
    // return v[n];

    // Bottom Up
    // for(int i = 2;i<=n;i++){
    //     v[i] = v[i-1]+v[i-2];
    // }
    // return v[n];

    // Bottom Up with optimized memory
    if(n < 2) return n;
    int f2 = 0,f1 = 1,f;
    for(int i =2;i<=n;i++){
        f = f1 + f2;

        f2 = f1;
        f1 = f;
    }
    return f;
}

int main(){
    int n;
    cin >> n;
    v[0] = 0;
    v[1] = 1;
    cout << solve(n);
}