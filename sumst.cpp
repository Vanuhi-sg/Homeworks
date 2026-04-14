#include <iostream>
#include <string.h>
using namespace std;

void sum(string a, string b){
    string sum="";
    int carry=0, s, size;
    if(a.length()<b.length())size =a.length(); 
    else size = b.length();
    for(int j=1; j<=size; j++){ 
        s=(a[a.length()-j]-'0'+b[b.length()-j]-'0')+carry;
        carry=s/10;
        sum = char(s%10+'0') + sum;
    }
    int diff = abs((int)a.length() - (int)b.length());
    for(int i = diff - 1; i >= 0; i--){ 
       if(a.length() < b.length()) s = (b[i] - '0') + carry;
       else s = (a[i] - '0') + carry;
       carry = s / 10;
       sum = char(s % 10 + '0') + sum;
    }
     if(carry>0) sum = char(carry + '0') + sum;
    cout<<sum;
}

int main(){
    string a, b;
    cout<<"please enter the a"<<endl;
    cin>>a;
    cout<<"please enter the b"<<endl;
    cin>>b;
    sum(a, b);
}