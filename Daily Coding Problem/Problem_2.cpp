/*
This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
*/
#include<iostream>

using namespace std;

int main(){
    long long int n, productLeft = 1, productRight = 1;
    cin>>n;
    long long int arr[n] , productRightArr[n] , productLeftArr[n];
    for(int i = 0 ; i < n ; i++)
        cin>>arr[i];
        
    for(int i = 0 ; i < n ; i++){
        productLeft *= arr[i];
        productLeftArr[i] = productLeft;
        
        productRight *= arr[n - i - 1];
        productRightArr[n - i - 1] = productRight;
    }
    
    cout<<productRightArr[1]<<" ";
    for(int i = 1 ; i < n-1 ; i++)
        cout<<productLeftArr[i-1] * productRightArr[i+1]<<" ";
    cout<<productLeftArr[n-2];
    
    return 0;
}

/*
--WITHOUT USING DIVISION OPERATION--
O(n) - for building the array(productLeftArr,productRightArr)
O(1) - for subsequent query
*/
