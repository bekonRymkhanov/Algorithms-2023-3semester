#include <iostream>
#include <math.h>
#include <unordered_map>
#define ll long long int
using namespace std;

ll Hashing(string str) {
    ll h = 0;
    ll p = 1;
    const int MOD = 1000000007;
    
    for (int i = 0; i < str.size(); i++) {
        h = (h + (str[i] - '0' + 1) * p) % MOD;
        p = (p * 11) % MOD;
    }

    return h;
}


int main() {
  ll n;
  string hashStr;
  cin>>n;
  string arr[n*2];
  unordered_map<string,long long> hashTable;
  for(ll i=0;i<n*2;i++){
    cin>>arr[i];
    hashTable[arr[i]]=Hashing(arr[i]);
  }
  int counter=0;
  for(int i=0;i<n*2;i++){
    hashStr=to_string(Hashing(arr[i]));
    if(counter>=n/2) return 0;
    if(hashTable.find(hashStr)!=hashTable.end()){
      cout<<"Hash of string  \""<<arr[i]<<"\" is "<<hashStr<<endl;
      counter++;
    }
  }
}