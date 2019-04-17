#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int in,max;
    vector<int> arr;
    for(int i = 0 ; i < 4 ; i++){
        cin>>in;
        arr.push_back(in);
    }
    max = *max_element(arr.begin() , arr.end());
    arr.erase(max_element(arr.begin() , arr.end()));
    cout<<max - arr[0]<<" "<<max - arr[1]<<" "<<max - arr[2];
	return 0;
}
