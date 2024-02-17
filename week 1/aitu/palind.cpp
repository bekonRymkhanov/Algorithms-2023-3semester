#include <iostream>
#define ll long long int
#define ss short  
using namespace std;

bool ispalind(string s){
    for(ll i=0;i<s.size()/2;i++){
        if(s[i]!=s[(s.size()-1)-i]) return false;
    }
    return true;
}

int main(){
    string str;
    cin>>str;
    while(true){
        if(ispalind(str)){
            cout<<"yes";
            return 0;
        }else if(str[str.size()-1]=='0'){
            str.erase(str.size()-1);
        }else{
            cout<<"no";
            return 0;
        }
    }
    return 0;
}