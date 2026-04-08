#include <iostream>
#include <unordered_map>
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

    std::unordered_map<int, int>mp;
    for(i=0; i<n; i++){
        if(mp.find(a[i])!=mp.end())mp[a[i]]++;
        else mp[a[i]]=1;
    }

    while(k!=0){
        int max=0, value=0;
        for(i=0; i<n; i++){
          if(mp[a[i]]>max){
             max=mp[a[i]];
             value=a[i];
            } 
        }
        std::cout<<value<<" ";
        mp.erase(value);
        k--;
    }
     
    return 0;
}