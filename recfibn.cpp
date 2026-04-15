#include <iostream>
#include <string>
#include <math.h>
using namespace std;

string a="1", b="1", i="2", c="";

string sums(string a, string b){
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
     return sum;
}

bool lessThan(string a, string b){
    if(a.length() != b.length())
        return a.length() < b.length();
    return a < b;
}


string nfib(string n,string a, string b, string c,  string i){
   c=sums(a, b);
   a=b;
   b=c;
   i=sums(i, "1"); 
   if(c==n) return i;
   else if (lessThan(n, b)) return "-1"; 
   if (lessThan(b, n)) return nfib(n, a, b, c, i);
}

int main(){
    string n;
    cout<<"please enter the n"<<endl;
    cin>>n;
    cout<<n<<" is the "<<nfib(n, a, b, c, i)<<"th Fibonacci number" ;
}