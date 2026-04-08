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

int main() {
    int b=0, i, j, n, k, c;
    std::cout << "Enter the k.";
    k=inputIntegerNumber();
    std::cout << "Enter the number of items.";
    n=inputIntegerNumber();
    int a[n]; 
    std::cout << "Enter the array.";
    for(int i = 0; i < n; i++) {
        a[i]=inputIntegerNumber();
    }

    for(i=0; i<n; i++){
        if(a[i]==k) b++;
        else{
             c=a[i]; 
            for(j=i+1; j<n; j++){
                if(c+a[j]<k) c=c+a[j];
                if(c+a[j]==k){
                     b++;
                     break;
                }
                if(c+a[j]>k) break; 
            }
        }    
    }
    std::cout<<"The count of subarray is "<<b;
}