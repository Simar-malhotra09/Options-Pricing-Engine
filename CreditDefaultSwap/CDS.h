#ifndef __CppOptions__CreditDefaultSwap__
#define __CppOptions__CreditDefaultSwap__
using namespace std;
#include<String>


enum UnderlyingAsset{
    UnderlyingAsset_Cash ,
    UnderlyingAsset_Bond ,
    UnderlyingAsse_Stock ,
};


class CDS{
    public: 

    CDS();
    CDS(const CDS& p);
    ~CDS();
    CDS &operator=(const CDS& p);

    //other member funcs

    string counterpart() { return m_counterpart; }
    void setCounterpart(const std::string &s);
    double payoff() { return m_payoff; }
    void setPayoff(double payoff) { m_payoff = payoff; }

   //data members 
    private:
    string m_counterpart;
    UnderlyingAsset m_underlying;
    double m_payoff;
    int m_term;
    double m_spreadCost; 

    static double m_standardPayoff;






};

#endif