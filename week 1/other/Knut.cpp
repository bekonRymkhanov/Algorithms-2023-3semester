#include<bits/stdc++.h> 
#define ll long long int
using namespace std;

vector<ll> knut(string s){
    vector<ll> p(s.size());
    p[0]=0;
    ll j;
    for(ll i=1;i<s.size();i++){
        j=p[i-1];
        while(j!=0 && s[j]!=s[i]){
            j=p[j-1];
        }
        if(s[j]==s[i]) j++;
        p[i]=j;
    }
    return p;
}


int main(){
    string str;
    cin>>str;
    return 0;

}