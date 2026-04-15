#include <iostream>
using namespace std;

int fact(int i, int n, int f) {
    f*=i;
    if (f == n) return i; 
    if (f>n) return -1;
    if (f<n) return fact(++i, n, f);       
}

int main() {
    int n, f=1;
    cout<<"Please enter the n"<<endl;
    cin >> n;

    cout << fact(1, n, f);

    return 0;
}