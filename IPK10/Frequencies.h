#pragma once

#include <cctype>
#include <iostream>
#include <map>
#include "IFrequencies.h"
#include "frequencysource.h"
#include "Filter.h"

template<typename Map>
class Frequencies : public IFrequencies<Map>
{
    public:
    Frequencies(Filter<Map>* newFilter){filter = newFilter;}
    template <typename Source>
    void readData(Source &source)
    {
        while (true)
        {
            auto data = source.next();
            if (not data.second)
            {
                break;
            }
            if (filter->remove(data.first)){
                continue;
            }
            Map transformedData = filter->transform(data.first);
            map[transformedData] += 1;
        }
    }

    void printStatistics()
    {
        std::size_t total = 0;

        for (auto entry : map)
            total += entry.second;

        for (auto entry : map)
            std::cout << entry.first << ": "
                      << static_cast<double>(entry.second) / total << std::endl;
    }

    private:
    std::map<Map, int> map;
    Filter<Map>* filter = nullptr;
};
