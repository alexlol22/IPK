#include "iostream"

int fibonacciOrder;
unsigned long long fib1 = 0;
unsigned long long fib2 = 1;

void nextFib(){
    unsigned long long fib3 = fib1 + fib2;
    fib1 = fib2;
    fib2 = fib3;
}

int main(){
    std::cout << "Enter the order of the fibonacci set: ";
    std::cin >> fibonacciOrder;
    for (int i=0; i<fibonacciOrder-1; i++){
        nextFib();
    }
    printf("%llu\n", fib2);
}