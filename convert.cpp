#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

string convert(string num, int base1, int base2){
    //num=11201 base1 = 3  
    int num2=0;
    string num3=""; //bace3=10
    for(int i = 0; i<num.length(); i++){
        num2 = num2 +  ((num[i])-'0')*pow(base1, (num.length()-i-1));
    }
    while(num2>0){
       num3 = char((num2 % base2)+'0') + num3;
       num2/=base2; 
    }
    
    
    return num3;
}
int main(){
    int base, cBase;
    string num;
    cout<<"Please enter the base"<<endl;
    cin>>base;
    cout<<"Please enter the base that you want to convert"<<endl;
    cin>>cBase;
    cout<<"Please enter the numbers"<<endl;
    cin>>num;

    cout<<"number is "<<convert(num, base, cBase);

}