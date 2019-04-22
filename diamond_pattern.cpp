#include<iostream>
using namespace std;
int main(){
    int n=5;
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++)
            cout<<" ";
        int k=i;
        while(k--)
            cout<<"* ";
        cout<<endl;
    }
     for(int i=n;i>0;i--){
        for(int j=n-i;j>0;j--)
            cout<<" ";
        int k=i;
        while(k--)
            cout<<"* ";
        cout<<endl;
    }
    return 1;
}
