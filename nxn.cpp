#include <iostream>

int inputIntegerNumber() {
   int number = 0;
   std::cin >> number;
   while (std::cin.fail()) {
      std::cout << "Error!!! input again";
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cin >> number;
    }
 return number;
}

int main(){
    int n, i, j;
    std::cout<<"Please enter the n"<<std::endl;
    n=inputIntegerNumber();
    int a[n*n];
    std::cout<<"Please enter the numbers"<<std::endl;
    for(i=0; i<n*n; i++){
        a[i]=inputIntegerNumber();
    }

    for(i=0; i<n; i++){
         std::cout<<"[ ";
        for(j=n-1; j>=0; j--){
            std::cout<<a[j*n+i]<<" ";
        }
        std::cout<<"] ";
    }
    return 0;
}