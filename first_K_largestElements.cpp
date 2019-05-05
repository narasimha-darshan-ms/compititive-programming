/*
First k largest elements in any array
Time Complexity : O(n)
Space Complexity : O(k)
*/
#include <bits/stdc++.h> 

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n], result[k];
    priority_queue <int> results;
    for(int i = 0 ; i < n ; i++)    cin>>arr[i], arr[i] = -arr[i];
    
    for(int i = 0 ; i < k ; i++)   results.push(arr[i]);
    for(int i = k ; i < n ; i++)    
        if(results.top() > arr[i])  results.pop(),results.push(arr[i]);
    
    for(int i = k-1 ; i >= 0 ; i--)   cout<<-results.top()<<" ",results.pop();
    
    return 0;
}
