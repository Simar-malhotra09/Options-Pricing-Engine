#include "CDS.h"
using namespace std;



void CDS::setCounterpart(const string &s){
    m_counterpart = s;
    setPayoff(m_standardPayoff);

}