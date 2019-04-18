#include <iostream>
using namespace std;

int main() {
    
    int n, battery, accumulator, count = 0;
    cin>>n>>battery>>accumulator;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
        cin>>arr[i];
        
    for(int i = 0 ; i < n ; i++){
        if(battery || accumulator ){
            
            if(arr[i]){
                if(battery > 0) {   battery--; accumulator++;   }
                else accumulator--;
            }
            else{
                if(accumulator > 0) accumulator--;
                else battery--;
            }
            
            count++;
        }
        else break;
    }
    
    cout<<count;
    
	return 0;
}
