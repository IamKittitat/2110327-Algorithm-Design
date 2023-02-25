#include<iostream>
#include<vector>

using namespace std;


int main(){
    long long n;
    cin >> n;
    vector<long long> f(2),s(2);
    f[0] = 1; f[1] = 1;
    s[0] = 2; s[1] = 2;
    
    for(int i =3;i<=n;i++){
        int zero = (s[0] + s[1])%100000007;
        int one = (zero - f[1])%100000007;
        f[0] = s[0]; f[1] = s[1];
        s[0] = zero; s[1] = one;
    }
    // for(auto &x : dp){
    //     for(auto &y : x) cout << y << " ";
    //     cout << endl;
    // }
    cout << (s[0] + s[1])%100000007;
}