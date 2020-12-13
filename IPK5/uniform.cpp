#include "io.h"
#include "statistics.h"
#include "iostream"


int main(){
    auto v=uniform_distribution(10, 50, -.5, .5);
    
    std::cout << "Mean:" << mean(v)
        << "\nMedian:" << median(v)
        << "\n5th Moment:" << moment(v, 5) << endl;
}
