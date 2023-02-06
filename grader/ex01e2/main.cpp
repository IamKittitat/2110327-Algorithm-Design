#include<iostream>
#include<vector>

using namespace std;

int mss(vector<int> &v){
    int max_end_here = 0;
    int max_all_time = v[0];
    for(int i =0;i<v.size();i++){
        max_end_here += v[i];
        max_all_time = max(max_all_time,max_end_here);
        max_end_here = max(0,max_end_here);
    }
    return max_all_time;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    cout << mss(v);
}

// DC Approach with O(nlgn) PPPPPPPPPP
// int get_sum(vector<int> &S,int a, int b){
//     if(a <1 ) return S[b];
//     return S[b]-S[a-1];
// }

// int mss(int start,int stop,vector<int> &v,vector<int> &S){
//     // cout << "!" << start << " " << stop << endl;
//     if(start == stop) return v[start];
//     int m = (start+stop)/2;

//     int r1 = mss(start,m,v,S);
//     int r2 = mss(m+1,stop,v,S);

//     int maxLeft = get_sum(S,m,m);
//     for(int i =start;i<m;i++) maxLeft = max(maxLeft,get_sum(S,i,m));
//     int maxRight = get_sum(S,m+1,m+1);
//     for(int i =m+2;i<=stop;i++) maxRight = max(maxRight,get_sum(S,m+1,i));
//     int r3 = maxLeft + maxRight;

//     return max(max(r1,r2),r3);
// }

// int main(){
//     int n;
//     cin >> n;
//     vector<int> v(n),S(n);
//     for(int i=0;i<n;i++) cin >> v[i];
//     S[0] = v[0];
//     for(int i = 1;i<n;i++) S[i] = S[i-1]+v[i];
//     cout << mss(0,v.size()-1,v,S);
// }