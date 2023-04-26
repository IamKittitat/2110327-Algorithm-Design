#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    // Amount of one, two, three
    vector<int> amount(4,0);
    for(int i = 0; i< n ;i++ ){
        cin >> v[i];
        amount[v[i]]++;
    }
    int ans = 0,j = amount[1];
    for(int i = 0;i<amount[1];i++){
        if(v[i] == 2){
            // Find next 1
            while(j<n && v[j] != 1) j++;
            ans++;
            swap(v[i],v[j]);
        }
    }
    for(int i = 0;i<amount[1];i++){
        if(v[i] == 3){
            // Find next 1
            while(j<n && v[j] != 1) j++;
            ans++;
            swap(v[i],v[j]);
        }
    }
    // If here : All 1 belong to their place + some of 2 belong to their place

    // If found three in 2 place ==> Need swap
    for(int i = amount[1]; i<amount[1]+amount[2];i++){
        if(v[i] == 3){
           ans++;
        }
    }
    cout << ans;
}