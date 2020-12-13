#include "io.h"
#include "statistics.h"
#include "iostream"

using namespace std;

int main(){
    auto v=read_vector();
    std::cout << "Mean:" << mean(v)
        << "\nMedian:" << median(v)
        << "\n5th Moment:" << moment(v, 5) << endl;
}
