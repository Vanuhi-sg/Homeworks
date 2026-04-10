#include <iostream>
#include <cmath>
#include <string>

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

double function(std::string f, double x) {
    if (f == "sin") return sin(x);
    if (f == "square") return x * x;
    if (f == "exp") return exp(x);
    if (f == "log") return log(x);
    return x;
}

double acancum(std::string f, double x) {
    if (f == "sin") return cos(x);
    if (f == "square") return 2 * x;
    if (f == "exp") return exp(x);
    if (f == "log") return 1 / x;
    return 1;
}

int main() {
    int c, x;

    std::cout << "Available functions: sin(x) square(x) exp(x) log(x). How many functions do you want to use\n";
    c = inputIntegerNumber();

    std::string functions[c];

    std::cout << "Please enter the functions\n";
    for (int i = 0; i < c; i++) {
        std::cin >> functions[i];
    }

    std::cout << "Enter x:\n";
    x = inputIntegerNumber();

    double result = x;

    for (int i = c - 1; i >= 0; i--) {
        result = function(functions[i], result);
    }

    double acancyal = 1;
    double temp = x;
    for (int i = c - 1; i >= 0; i--) {
        acancyal *= acancum(functions[i], temp);
        temp = function(functions[i], temp);
    }

    std::cout << acancyal <<std::endl;

    return 0;
}