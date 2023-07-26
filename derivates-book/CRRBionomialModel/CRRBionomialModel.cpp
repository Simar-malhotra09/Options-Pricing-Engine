#include "CRRBionomialModel.h"

CRRBinomial::CRRBinomial(double S, double K, double T, double r, double sigma, int N, char Option_type) {
    this->S = S;
    this->K = K;
    this->T = T;
    this->r = r;
    this->sigma = sigma;
    this->N = N;
    this->Option_type = Option_type;
}


double CRRBinomial::calculateOptionPrice() {
    double u = exp(sigma * sqrt(T / N));
    double d = exp(-sigma * sqrt(T / N));
    double pu = ((exp(r * T / N)) - d) / (u - d);
    double pd = 1 - pu;
    double disc = exp(-r * T / N);

    double* St = new double[N + 1];
    double* C = new double[N + 1];

    St[0] = S * pow(d, N);

    for (int j = 1; j <= N; j++) {
        St[j] = St[j - 1] * u / d;
    }

    for (int j = 1; j <= N; j++) {
        if (Option_type == 'P') {
            C[j] = fmax(K - St[j], 0);
        }
        else if (Option_type == 'C') {
            C[j] = fmax(St[j] - K, 0);
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            C[j] = disc * (pu * C[j + 1] + pd * C[j]);
        }
    }

    double result = C[0];

    delete[] St;
    delete[] C;

    return result;
}
