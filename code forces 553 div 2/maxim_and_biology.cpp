#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
    
    int n;
    string in, genome = "ACTG";
    cin>>n>>in;
    int min = INT_MAX;
    
    for(int i = 0 ; i < n-3 ; i++){
        string test = in.substr(i, i+4);
        int count = 0;
        for(int j = 0 ; j < 4 ; j++){
            count += std::min( abs(test[j]-genome[j]) , 'Z' - std::max(test[j],genome[j]) + std::min(test[j],genome[j]) - 'A' + 1 ); 
        }
        if(min > count) min = count;    
    }
    
    cout<<min;
	return 0;
}
