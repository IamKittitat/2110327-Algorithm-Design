#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void selectionSort(vector<int> &v){
    int pos = v.size()-1;
    for(;pos >= 0;pos--){
        int maxIdx = pos;
        for(int j = pos-1;j>=0;j--) if(v[j] > v[maxIdx]) maxIdx = j;
        swap(v[maxIdx],v[pos]);
    }
}

int main(){
    vector<int> v = {42,5,1,50,123,50,-1,9,0,1,-43,123,5,1,-111,-3333,5,123,123};
    vector<int> tmp = v;
    sort(tmp.begin(),tmp.end());
    for(auto &x : tmp) cout << x << " ";
    cout << endl;
    selectionSort(v);
    for(auto &x : v) cout << x << " ";
}