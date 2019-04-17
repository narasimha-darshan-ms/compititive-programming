#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int in,n,difference,prev_difference;
    cin>>n;
    vector<int> arr; 
    for(int i = 0 ; i < n ; i++){
        cin>>in;
        arr.push_back(in);
    }
    
    sort(arr.begin() , arr.end());
    arr.erase( unique( arr.begin(), arr.end() ), arr.end() );
    
    if(arr.size() > 3){   cout<<"-1"; return 0;   }
    
    else if(arr.size() == 3){   
        if( (arr[1] - arr[0]) == (arr[2] - arr[1]) )  cout<<arr[2]-arr[1];
        else cout<<"-1";
        
    }
    
    else if(arr.size() == 2){
        if( (arr[1]-arr[0]) % 2 == 0)   cout<<(arr[1]-arr[0])/2;
        else cout<<arr[1]-arr[0];
    }
    else cout<<"0";
    return 0;
}
