#include <bits/stdc++.h>
#define ll long long int
using namespace std;
string arr[9999];
void merge(string arra[],ll left,ll left_end,ll right_start,ll right){

    string Left_arr[left_end+1-left], Right_arr[right+1-right_start];

    for (int i = 0; i < left_end+1-left; i++)
        Left_arr[i] = arra[left + i];
    for (int j = 0; j < right+1-right_start; j++)
        Right_arr[j] = arra[right_start + j];
    ll i=0,j=0,k=left;
    while(i<left_end+1-left && j<right+1-right_start){
        if(Left_arr[i].size()>Right_arr[j].size()){
            arra[k]=Right_arr[j];
            j++;
        }else{
            arra[k]=Left_arr[i];
            i++;
        }
        k++;
    }
    while(i<left_end+1-left){
        arra[k]=Left_arr[i];
        i++;
        k++;
    }
    while(j<right+1-right_start){
        arra[k]=Right_arr[j];
        j++;
        k++;
    }

}



void merge_sort(string arra[],ll left,ll right){
    if(right==left){
        return;
    }
    merge_sort(arra,left,left+(right-left)/2);
    merge_sort(arra,(left+(right-left)/2)+1,right);
    merge(arra,left,left+(right-left)/2,(left+(right-left)/2)+1,right);
}


int main() {
    ll size,cnt;
    string line;
    cin>>size;
    cin.ignore();
    for(ll i=0;i<size;i++){
        getline(cin, line);
        stringstream stream(line);
        string tok;
        cnt=0;
        while(getline(stream,tok,' ')){
            arr[cnt]=tok;
            cnt++;
        }
        merge_sort(arr,0,cnt-1);
        for(ll j=0;j<cnt;j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl;
    }
}