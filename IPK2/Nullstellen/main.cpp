#include "Nullstellen.h"

using namespace std;

int main(){
    ZeroPointCalculator * zpc = new ZeroPointCalculator();
    zpc->ObtainValues();
    zpc->PrintResultsToConsole();
}
