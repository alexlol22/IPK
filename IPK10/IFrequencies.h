template<typename Map>
class IFrequencies{
    public:
    template<typename Source>
    void readData(Source& source);
    virtual void printStatistics()=0;
};