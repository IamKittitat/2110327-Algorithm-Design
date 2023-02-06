#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &v,int start,int stop){
    int pivot = v[start];
    int left = start,right = stop;
    while(left<right){
        do{ left++; } while(v[left]<pivot);
        do { right--;} while(v[right] > pivot);
        if(left < right) swap(v[left],v[right]);
        else return right;
    }
    return right;
}

void quickSort(vector<int> &v,int start,int stop){
    if(start < stop){
        int p = partition(v,start,stop);
        quickSort(v,start,p);
        quickSort(v,p+1,stop);
    }
}

int main()
{
    vector<int> v = {14,6392,124,19,-14,54,1,0,256,9,12,54,643,4,6,913,2,5,3123,54,331};
    quickSort(v,0,v.size()-1);
    for(auto &x : v) cout << x << " " ;
}