#pragma once
#include <cctype>
#include <string>
#include <algorithm>

template<typename Data>
class Filter{
public:
    // takes the input data and returns a transformed
    // version (e.g. capitalizes all letters)
    virtual Data transform(const Data& data)=0;
    // decides whether the input letter or word should be
    // removed from the statistics (not added to the map)
    virtual bool remove(const Data& data)=0;
};

class CharFilter : public Filter<char>{
    char transform(const char& data) override
    {
        return std::toupper(data);
    }    
    bool remove(const char& data) override
    {
        return !std::isalpha(data);
    }
};

class StringFilter : public Filter<std::string>{
    std::string transform(const std::string& data) override{
        std::string out;
        std::transform(data.begin(), data.end(), out.begin(), ::toupper);
        return out;
    }

    bool remove(const std::string& data) override{
        for (auto c : data) if (!std::isalpha(c)) return true;
    return false;
    }
};
