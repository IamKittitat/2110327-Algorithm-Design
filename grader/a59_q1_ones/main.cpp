#include<iostream>
#include<vector>

using namespace std;

/*
int number_of_one(int one){
    int ans = 0;
    do {
        ++ans; 
        one /= 10;
    } while (one != 0);
    return ans;
}
*/

int solve(int n,int len,int one){
    // Trivial Cases
    switch(n){
        case(0): return 0; case(1): return 1; case(2): return 2;
        case(3): return 3; case(4): return 4; case(5): return 5;
        case(6): return 6; case(7): return 6; case(8): return 5;
        case(9): return 4; case(10): return 3; case(11): return 2;
    }
    if(one == 1) return n;
    
    int x = n/one;
    if(n%one == 0) return x*len; 

    int fc = solve(n-x*one,len-1,one/10) + x*len;
    int sc = solve((x+1)*one-n,len-1,one/10) + (x+1)*len;
    return min(fc,sc);
}

int main(){
    int one = 1,len=1;
    int n;
    cin >> n;
    while(one < n){
        one = one*10 + 1;
        len++;
    }
    cout << solve(n,len,one);
}