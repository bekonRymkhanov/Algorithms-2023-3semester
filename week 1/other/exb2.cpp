#include <bits/stdc++.h>
using namespace std;

int main() {
    short a,b;
    cin>>a>>b;
    short c=0;
    list<int> ll;
    while (a!=b) {
        ll.push_front(b);
        if(a>b){
            ll.pop_front();
            while(b!=a) {
                ll.push_front(b);
                c++;
                b++;
            }
            break;
        }
        if(b%2==1){
            b++;
            c++;
            ll.push_front(b);
        }
        b=b/2;
        c++;
    }
    if(c==0){
        cout<<0;
    }else{
        cout<<c<<endl;
    }
    for(int i=0;i<c;i++) {
        cout<<ll.front()<<' ';
        ll.pop_front();
    }
    return 0;
}