#include <iostream>
#include <string.h>
using namespace std;
int main(){
    string a, rle="";
    int i=0, j=1;
    cout<<"please enter the a"<<endl;
    cin>>a;

    for(i; i<a.length(); i++){
        if(a[i]==a[i+1]) j++;
        else{ if(j==1) rle+=a[i];
             else rle+= to_string(j) + a[i];
             j=1;
            }
    }
    cout<<rle;
}