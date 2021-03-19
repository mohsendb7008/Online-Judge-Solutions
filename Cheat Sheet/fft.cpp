#include <bits/stdc++.h>
using namespace std;

vector<complex<double>> fft(int n, int m, vector<complex<double>> coeffs, int divisor){
    /*
    n: degree of polynomial f
    m: 2^k upper bound of n
    coeffs: coefficients of polynomial f in increasing order (a0, a1, a2, ..., an-1)
    divisor: initially should be set to 1
    returns vector of (yk)s for k from 0 to n-1 as yk = f(e^{i(k/n)*2pi})
    */
    vector<complex<double>> ans;
    if(coeffs.size() == 1){
        for(int k = 0; k < m; k += divisor)
            ans.push_back(coeffs[0]);
        return ans;
    }
    vector<complex<double>> even, odd;
    for(int i = 0; i < coeffs.size(); i++){
        if(i % 2)
            odd.push_back(coeffs[i]);
        else
            even.push_back(coeffs[i]);
    }
    vector<complex<double>> fft_even = fft(n, m, even, divisor * 2), fft_odd = fft(n, m, odd, divisor * 2);
    for(int k = 0; k < m; k += divisor)
        ans.push_back(fft_even[int(ans.size()) % (m / (divisor * 2))] + polar(1.0, (double(k) / m) * 2.0 * M_PI) * fft_odd[int(ans.size()) % (m / (divisor * 2))]);
    return ans;
}

// Driver program:
int main(){
    int n = 5, m = 8;
    vector<complex<double>> coeffs;
    for(int i = 0; i < n; i++)
        coeffs.push_back((i + 1) * (i + 1));
    vector<complex<double>> ans = fft(n, m, coeffs, 1);
    int ptr = 0;
    for(auto it : ans){
        cout << it << endl;
        // testing fft with computing f manually:
        complex<double> res = coeffs[0];
        for(int i = 1; i < n; i++){
            complex<double> p = polar(1.0, (double(ptr) / m) * 2 * M_PI);
            int j = i-1;
            while(j--)
                p *= polar(1.0, (double(ptr) / m) * 2 * M_PI);
            res += coeffs[i] * p;
        }
        cout << res << endl << endl;
        ptr++;
    }
}