#include<iostream>
#include<vector>

using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false);cin.tie(NULL);
//     int n;
//     cin >> n;
//     vector<int> v(n),lmss(n),rmss(n);
//     for(int i =0;i<n;i++) cin >> v[i];

//     lmss[0] = v[0];
//     int maxHere = max(0,lmss[0]);
//     for(int i = 1;i<n;i++){
//         maxHere += v[i];
//         lmss[i] = max(maxHere,lmss[i-1]);
//         maxHere = max(maxHere,0);
//     }

//     rmss[n-1] = v[n-1];
//     maxHere = max(0,rmss[n-1]);
//     for(int i = n-2;i>=0;i--){
//         maxHere += v[i];
//         rmss[i] = max(maxHere,rmss[i+1]);
//         maxHere = max(maxHere,0);
//     }

//     int ans = lmss[n-1];
//     for(int i =0;i<n-1;i++){
//         ans = max(ans,lmss[i]+rmss[i+1]);
//     }
//     cout << ans;
// }

// (My) First Approach (using kadane with second max) -P-P-P-PPP
// int main(){
//     ios_base::sync_with_stdio(false);cin.tie(NULL);
//     int n;
//     cin >> n;
//     vector<int> v(n);
//     for(int i =0;i<n;i++) cin >> v[i];
//     int maxAllTime = INT32_MIN, secondMax = INT32_MIN;
//     int maxEndHere = 0;
//     for(int i =0;i<n;i++){
//         maxEndHere += v[i];
//         secondMax = max(secondMax,maxEndHere);
//         if(maxEndHere <= 0){
//             if(maxAllTime < secondMax){
//                 maxAllTime = secondMax;
//                 secondMax = INT32_MIN;
//             } else{
//                 secondMax = INT32_MIN;
//             }
//             maxEndHere = 0;
//         }
//     }

//     if(maxAllTime < secondMax){
//         swap(maxAllTime,secondMax);
//     }
//     // cout << max(secondMax,0) << endl;
//     // cout << maxAllTime << endl;
//     cout << max(secondMax,0) + maxAllTime;
// }

/*
5
1 1 -10 1 1

5
1 2 3 4 5

4
-4 -2 -3 -1

6
-1 -1 10 -1 -1 -2

10
-1 3 -1 2 -4 -5 7 -3 8 -4

11
1 2 3 5 -99 99 -99 1 2 3 6

*/