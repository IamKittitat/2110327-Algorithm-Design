#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long f0,f1,s0,s1;
    f0 = 1;
    f1 = 2;
    for(int i =2;i<=n;i++){
        s0 = (f0+f1)%100000007;
        s1 = (f0*2+f1)%100000007;
        f0 = s0;
        f1 = s1;
    }
    cout << (f0+f1)%100000007;
}