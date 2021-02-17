#include "Frequencies.h"
#include "frequencysource.h"
#include <iostream>
#include <fstream>
#include "Filter.h"

void showUsage(char* progName){
    std::cout << "Usage: " << progName << " FILENAME [FILENAME...]\n\tTo read from stdin, use - as only filename.\n";
}

int main(int argc, char* argv[])
{
    auto charFilter = CharFilter();
    auto strFilter = StringFilter();

    auto freq1 = Frequencies<char>(&charFilter);
    auto freq2 = Frequencies<std::string>(&strFilter);
   
    if (argc < 2){
        showUsage(argv[0]);
        return 0;
    }
    if (argc>2){
        for (int i=1; i<argc; i++){
            if (std::string(argv[i])=="-"){
                showUsage(argv[0]);
                return 0;
            }
        }
    }

    if (std::string(argv[1])=="-"){
        auto letterSource = streamLetterSource(std::cin);
        freq1.readData(letterSource);
        freq1.printStatistics();
        return 0;
    }

    for (int i=1; i<argc; i++){
        std::ifstream fstream;
        fstream.open(argv[i]);
        auto letterSource = streamLetterSource(fstream);
        freq1.readData(letterSource);
    }
    freq1.printStatistics();
    return 0;
}
