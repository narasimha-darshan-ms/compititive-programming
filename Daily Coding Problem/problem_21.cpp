/*
Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), 
find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
*/

#include<bits/stdc++.h>

using namespace std;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 

int main(){
    vector< pair<int,int> >schedules;
    int n, num1, num2;
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        cin>>num1>>num2;
        schedules.push_back( make_pair(num1,num2) );
    }
    
    if(n == 1){    cout<<"1"; return 0;  }
    
    sort(schedules.begin() , schedules.end() , sortbysec);
    
    int max = INT_MIN, count = 1, index = 0;
    for(int i = 1 ; i < n ; i ++){
        if(max < count)      max = count;
        while(schedules[i].first >= schedules[index].second)     index++,count--;
        count++;
    }
    
    cout<<count;
    return 0;
}
