#include<iostream>

using namespace std;

int main(){
    int testCases,n;
    cin>>testCases;
    string inputString, result[testCases];
    for(int j = 0 ; j < testCases ; j++){
        cin>>n;
        cin>>inputString;
    
        for(int i = 0 ; i < inputString.length() ; i++){
            if(inputString[i] == 'E')   result[j] += 'S';
            else result[j] += 'E';
        }
    }
    
    for(int j = 0 ; j < testCases ; j++)    cout<<"Case #"<<j+1<<": "<<result[j]<<endl;
    
    return 0;
}
