#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int arr[3], week[7] = {0,1,2,0,2,1,0}, additional_days = 0;
    cin>>arr[0]>>arr[1]>>arr[2];
    
    int no_of_weeks = min(arr[0]/3 , min( arr[1]/2 , arr[2]/2 ));
    arr[0] = abs(arr[0] - no_of_weeks*3);
    arr[1] = abs(arr[1] - no_of_weeks*2);
    arr[2] = abs(arr[2] - no_of_weeks*2);
    
    if(arr[0] == max( arr[0], max(arr[1],arr[2]) )){
        int i = 6;
        while(arr[week[i]] != 0){
            arr[week[i]]--;
            if(i >= 0 && i < 6) i++;
            else i = 0;
            additional_days++;
        }
    }
    else {
         int i = 1;
        while(arr[week[i]] != 0){
            arr[week[i]]--;
            if(i >= 0 && i < 6) i++;
            else i = 0;
            additional_days++;
        }
    }
    
   cout<<no_of_weeks*7 + additional_days;
    
    return 0;
}
