#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    string line;
    vector<int> arr;
    while(getline(cin,line)){
        
        int i=0 , pos;
        pos = line.find(" ");
    
        while(pos != string::npos){
            
            arr.push_back( stoi( line.substr(0 , pos) ) );
            pos = line.find(" ",i);
            line.erase(0, pos+1 );
            
        } 
    }
    
    for(int i = 0 ; i < arr.size() ; i++)
        cout<<arr[i]<<" ";
        
    return 0;
}