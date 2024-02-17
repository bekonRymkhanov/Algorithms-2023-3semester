#include <bits/stdc++.h>
using namespace std;

int kmp(string s, int m){
    int n = s.length();
    int limit = 0;
    vector<int> v(n, 0);

    for(int i = 1; i < n; i++){
        int j = v[i-1];
        while(j > 0 && s[j] != s[i]){
            j = v[j-1];
        }
        if(s[j]==s[i]) {
            v[i] = ++j;
            if(limit <j && i >= m)
                limit = j;
        }
    }

    return limit;
}

int main(){
    string a, b, a0;

    getline(cin, a);
    getline(cin, b);

    a0 = a;
    int m = b.length();

    int response = 1;

    while(a.length() < b.length()){
        a += a0;
        response++;
    }

    int limit = 0;
    int curr = 0;

    while(true){
        curr = kmp(b + "#" + a, m);
        if(limit < curr)
            limit = curr;
        else
            break;
        if(curr == m){
            cout<<response;
            return 0;
        }
        a += a0;
        response++;
    }

    cout<<-1;
    return 0;
}