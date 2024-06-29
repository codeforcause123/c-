#include <bits/stdc++.h>
using namespace std;

int main(){
    float p,r,t;
    try{
        cin>>p>>r>>t;
        if(cin){
            float prin=(1+r/100);
            cout<<fixed<<setprecision(3)<<(p*pow(prin,t))-p;
        }
        else{
            throw 0;
        }
    }
    catch(int i){
        cout<<"Insufficient Data"<<endl;
    }
    return 0;
}