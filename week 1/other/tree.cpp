#include <iostream>
#include <vector>
#define ll long long int
using namespace std;
ll cnt=0;
void knut(string s,ll size){
    ll haveZero=0;
    vector<ll> p(s.size());
    p[0]=0;
    ll j;
    for(ll i=size+1;i<s.size();i++){
        j=p[i-1];
        while(j!=0 && s[j]!=s[i]){
            j=p[j-1];
        }
        if(s[j]==s[i]){
            j++;
        }
        p[i]=j;
        if(j==1){
            cnt++;
        }
        if(j==0 and p[j-1]==0){
            haveZero++;
        }else if(j==0 and p[j-1]!=0){
            cout<<-1;
            return;
        }
    }
    if(haveZero) cnt++;
    cout<<cnt;
}

int main(){
    string str1,str2;
    cin>>str1>>str2;
    knut(str1+'#'+str2,str1.size());
    return 0;
} 