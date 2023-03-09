#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void insertionSort(vector<int> &v){
    for(int pos = v.size()-2;pos>=0;pos--){
        int posVal = v[pos];
        int i = pos+1;
        while(i < v.size() && v[i] < posVal){
            v[i-1] = v[i];
            i++;
        }
        v[i-1] = posVal;
    }
}

int main(){
    vector<int> v = {42,5,1,50,123,50,-1,9,0,1,-43,123,5,1,-111,-3333,5,123,123};
    vector<int> tmp = v;
    sort(tmp.begin(),tmp.end());
    for(auto &x : tmp) cout << x << " ";
    cout << endl;
    insertionSort(v);
    for(auto &x : v) cout << x << " ";
}