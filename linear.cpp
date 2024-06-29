#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a;
    cout<<"Enter no of elements"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"enter element to be found"<<endl;
    cin>>k;
    for(int j=0;j<n;j++){
        if(arr[j]==k){
            a=j;
        }
        else{
            a=-1;
        }
    }
    cout<<a<<endl;
    
    return 0;
}