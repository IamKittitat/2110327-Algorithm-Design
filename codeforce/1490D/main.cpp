#include<iostream>
#include<vector>

using namespace std;

int solve(int start,int stop,vector<int> &v,int q,int d){
    //cout << q << " " << start << stop << endl;
    int valMax = -1,idxMax = -1,idx = -1,valMin = 101,idxMin=-1;
    for(int i =start;i<=stop;i++){
        if(v[i] == q) idx = i;
        if(v[i] > valMax){
            idxMax = i;
            valMax = v[i];
        }
        if(v[i] < valMin){
            idxMin = i;
            valMin = v[i];
        }
    }
    
    if(idxMax == idx) return d;
    if(idx < idxMax) return solve(start,idxMax-1,v,q,d+1);
    else return solve(idxMax+1,stop,v,q,d+1);
}

int main(){
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int j = 0;j<n;j++) cin >> v[j];
        for(int k = 0;k<n;k++) cout << solve(0,v.size()-1,v,v[k],0) << " ";
        cout << endl;
    }
}