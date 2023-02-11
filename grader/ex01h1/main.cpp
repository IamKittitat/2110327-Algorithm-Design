#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(8000000);
    v[1] = 1;
    v[2] = 2;
    v[3] = 2;
    int i = 3,k=4;
    while(true){
        for(int j = 0;j<v[i];j++) v[k+j] = i;
        k += v[i];
        i++;
        if(i > v.size() || k+v[i] > v.size()) break;
    }
    // for(int i = 0;i<1000;i++) cout << v[i] << endl;
    for(int i =0;i<n;i++){
        int q;
        cin >> q;  
        int sum = 0,ans;
        for(int i =0;i<v.size();i++){
            sum+=v[i];
            if(sum>=q){
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
}

/*
4
100
9999
123456
1000000000

3
13
19
6
*/