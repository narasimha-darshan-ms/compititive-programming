#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int testCases;
    cin>>testCases;
    vector< pair<string,string> > result;
    
    for(int  i = 0 ; i < testCases ; i++){
        string num,first_num,second_num;
        cin>>num;
        for(int i = 0 ; i < num.size() ; i++){
            if(num[i] != '4')  first_num += num[i],second_num += '0';
            else    first_num += '3', second_num += '1';
        }
        while(second_num[0] == '0') second_num.erase(0,1);
        
        result.push_back( make_pair(first_num,second_num) );
    }
    for(int i = 0 ; i < testCases ; i++)
        cout<<"Case #"<<i+1<<": "<<result[i].first<<" "<<result[i].second<<endl;
    return 0;
}
