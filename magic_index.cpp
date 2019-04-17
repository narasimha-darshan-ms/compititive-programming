/*
MAGIC INDEX:
A magic index in an array A ( l . .. n - 1 ] is defined to bean index such that A [ i ] =i . 
Given a sorted array of distinct integers, write a method to find a magic index, if one exists, in
array A
*/

#include<iostream>
using namespace std;

int findIndex(int arr[], int n){
    int start = 0, end = n-1 ;
    while(start <= end){
        int mid = (start + end)/2;
        if( arr[mid] == mid )     return mid;
        else if(arr[mid] < mid){    start = mid+1;     }
        else if(arr[mid] > mid){    end = mid-1;     }
    }
    
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
        cin>>arr[i];
    
    cout<<findIndex(arr,n);
    return 0;
}
