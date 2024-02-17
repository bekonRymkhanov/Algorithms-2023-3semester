#include <iostream>
#include <cmath>
#define ll long long int
using namespace std;
string arr[99999999];

const ll P=57;

ll Hash(string str){
    ll hash_code=0;
    for(ll i=0;i<str.size();i++){
        hash_code+=pow(P,i)*str[i];
    }
    return hash_code;

}


int main(){
    ll size;
    cin>>size;

    for(ll i=0;i<size;i++){
        cin>>arr[i];
    }
    for(ll i=0;i<size;i++){
       cout<<arr[i]<<" ";
    }  
    cout<<1e9; 

}