/*
Reachable Numbers:

Let's denote a function f(x) in such a way: we add 1 to x, then, while there is at least one trailing zero in the resulting number, we remove that zero. For example,

f(599)=6: 599+1=600→60→6;
f(7)=8: 7+1=8;
f(9)=1: 9+1=10→1;
f(10099)=101: 10099+1=10100→1010→101.
We say that some number y is reachable from x if we can apply function f to x some (possibly zero) times so that we get y as a result. For example, 102 is reachable from 10098 because f(f(f(10098)))=f(f(10099))=f(101)=102; and any number is reachable from itself.

You are given a number n; your task is to count how many different numbers are reachable from n.

Input
The first line contains one integer n (1≤n≤109).

Output
Print one integer: the number of different numbers that are reachable from n.

Examples

input:
1098
output:
20
Note:
The numbers that are reachable from 1098 are:
1,2,3,4,5,6,7,8,9,11,12,13,14,15,16,17,18,19,1098,1099.

input
10
output
19

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, count = 1;
    unordered_set<int> nums;
    cin>>n;
    nums.insert(n);
    n++;
    do{
        while(n % 10 != 0 && nums.find(n) == nums.end() ){     
            nums.insert(n);
            n++;
            count++;
        }
        while(n % 10 == 0){     n /= 10;    }
        
    } while(nums.find(n) == nums.end());
    cout<<count;
    return 0;
}
