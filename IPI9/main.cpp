#include "fcpp.hh"
#include <iostream>
int* times_two(int i) {
    i = i+i;
    return &i;
}

int* square(int j) {
    j = j*j;
    return &j;
}

void procrastinate(int k) {
    print("Hier passiert überhaupt nichts... oder?");
}

int main() {
    /*int* p = times_two(10);
    int t = -1387498387;
    std::cout << *p <<std::endl;*/
    int test[] = {1,2,3};
    
    //print(&p);
    /*int* q = square(10);
    print(*q);
    print(*p + *q);
    procrastinate(2);
    print(*p + *q);
    return 0;
    */
}