#include<iostream>
#include<vector>
#include<set>

using namespace std;

int id = 3,w,l;

// Encoded pond to number more than 2
void encoded(vector<vector<int>> &v,int i,int j){
    if(i<0 || j<0 || i>=l || j >= w || v[i][j] != 1) return;
    v[i][j] = id;
    // Recursively encoded
    encoded(v,i+1,j);
    encoded(v,i-1,j);
    encoded(v,i,j-1);
    encoded(v,i,j+1);
}

// Find amount of pond in searched area
int findPond(vector<vector<int>> &v,int y,int x,int nowArea){
    set<int> s;
    for(int i = y-nowArea+1;i<=y;i++){
        for(int j = x-nowArea+1;j<=x;j++){
            if(v[i][j] != 0 && v[i][j] != 2) s.insert(v[i][j]);
        }
    } 
    // Amount of pond is the distinct number of encoded pond
    return s.size();
}

int main(){
    cin >> w >> l;
    vector<vector<int>> v(l,vector<int>(w,0)),pond(l,vector<int>(w,0)),dp(l,vector<int>(w,0));
    for(int i =0;i<l;i++){
        string s;
        cin >> s;
        // Convert to integer for easier coding (I hate string and char)
        for(int j=0;j<w;j++){
            if(s[j] == 'S') v[i][j] = 0;
            else if(s[j] == 'P') v[i][j] = 1;
            else v[i][j] = 2; 
        }
    }

    // Encoded
    for(int i =0;i<l;i++){
        for(int j =0;j<w;j++){
            if(v[i][j] == 1) {
                encoded(v,i,j);
                id++;
            }
        }
    }

    // Initial Condition
    dp[0][0] = v[0][0] != 2 ? 1 : 0;
    for(int i =1;i<w;i++) dp[0][i] = v[0][i] != 2 ? 1 : 0;
    for(int i =1;i<l;i++) dp[i][0] = v[i][0] != 2 ? 1 : 0;
    
    int maxArea = -1,minPond = 4000,nowArea;
    for(int i =1;i<l;i++){
        for(int j=1;j<w;j++){
            // If not tree
            if(v[i][j] != 2){
                // Same as square map (min of three dp)
                nowArea = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
                dp[i][j] = nowArea;
                // If new area more than max area --> Find new amount of pond
                if(nowArea > maxArea){
                    maxArea = nowArea;
                    minPond = findPond(v,i,j,nowArea);
                } else if(nowArea == maxArea){
                    minPond = min(minPond,findPond(v,i,j,nowArea));
                }
            }
        }
    }
    if(maxArea != -1) cout << maxArea*maxArea << " " << minPond;
    else cout << "0 0";
}

/*
8 6
SSSSSSSS
SSSSSSSS
SPPSSSSS
SSSPSSSS
SSSSSTTS
PSSSSTSS

4 4
SPSS
TSSS
SSSP
SSPS
>> 9 2

4 4
SPSS
SSSS
SSSP
SSPS
>> 16 3

4 4
PSPS
SPSP
PSPS
SPSP
>> 16 8

4 4
PSPS
SPSP
PPPP
SPPP

4 4
PSPS
PPPP
TTTT
TTTT
*/