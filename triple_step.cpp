/*
TRIPLE STEP:

A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3
steps at a time. Implement a method to count how many possible ways the child can run up the
stairs.
*/


#include<iostream>
using namespace std;

long int findWays(int steps ,long int arr[]){
    
    if(steps < 0)   return 0;
    if(steps == 0){     
        arr[steps] = 1;     }
    if(arr[steps] > -1) return arr[steps];
    arr[steps] = findWays(steps-1 ,arr) + findWays(steps-2 ,arr) + findWays(steps-3 ,arr) ;
    return arr[steps];
}

int main(){
    
    int steps;
    cin>>steps;
    long int arr[steps+1];
    for(int i = 0 ; i < steps+1 ; i++)
        arr[i] = -1;
    cout<<findWays(steps,arr);
    return 0;
    
}
