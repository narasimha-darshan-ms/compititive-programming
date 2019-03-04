#include<iostream>
using namespace std;
int main(){
    int n=5,array[n][n]={},num=1;
    
    for(int k=0;k<n/2+1;k++){
        if(k>0) num=array[k][k-1]+1;cout<<num<<endl;
    for(int i=0;i<n-2*k;i++){
       if(i<=n-k-1) array[k][i+k]=num;
       if(i<n-k-1) array[i+k][n-k-1]=num+n-2*k-1;
       if(n-i-k-1>k) array[n-k-1][n-k-i-1]=num+2*(n-2*k-1);
       if(n-i-k-1>k) array[n-k-i-1][k]=num+3*(n-2*k-1);
        num++;
    }
    }
   
    
    
   for(int i=0;i<n;i++)  {
     for(int j=0;j<n;j++){
          if(array[i][j]<10)  cout<<array[i][j]<<"   ";
          else    cout<<array[i][j]<<"  ";
    }
    cout<<endl;
}
   
    return 0;
}