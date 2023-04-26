#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> amount(4,0);
    for(int i = 0; i< n ;i++ ){
        cin >> v[i];
        amount[v[i]]++;
    }
    int ans = 0,j = amount[1];
    for(int i = 0;i<amount[1];i++){
        if(v[i] == 2){
            while(j<n && v[j] != 1) j++;
            ans++;
            swap(v[i],v[j]);
        }
    }
    for(int i = 0;i<amount[1];i++){
        if(v[i] == 3){
            while(j<n && v[j] != 1) j++;
            ans++;
            swap(v[i],v[j]);
        }
    }

    for(int i = amount[1]; i<amount[1]+amount[2];i++){
        if(v[i] == 3){
           ans++;
        }
    }
    cout << ans;
}