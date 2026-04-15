#include <iostream>
#include <string.h>
using namespace std;
int a=1, b=1, i=2, c;

int nfib(int n, int a, int b, int c){
    c=a+b;
    a=b;
    b=c;
    i++;
    if(c==n) return i;
    else if (c>n) return -1;
    if(b<n) return nfib(n, a, b, c);
}

int main(){
    int n;
    cout<<"please enter the n"<<endl;
    cin>>n;
    cout<<nfib(n,a ,b, c);
}