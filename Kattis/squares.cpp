#include <bits/stdc++.h>
using namespace std;

// Squares

#define num long long int

const num inf = LLONG_MAX;

num GCD(num a, num b) {
    if (a == 0)
        return b;
    return GCD(b % a, a);
}

struct fraction {

        num numerator, denominator;

        fraction(){
            this->numerator = 0;
            this->denominator = 1;
        }

        fraction(num numerator, num denominator){
            if(denominator == 0){
                this->numerator = inf;
                this->denominator = 1;
            }
            else if(numerator == 0){
                this->numerator = 0;
                this->denominator = 1;
            }
            else{
                num sign = (numerator > 0 ? 1 : -1) * (denominator > 0 ? 1 : -1);
                numerator = abs(numerator), denominator = abs(denominator);
                num gcd = GCD(min(numerator, denominator), max(numerator, denominator));
                this->numerator = sign * numerator / gcd;
                this->denominator = denominator / gcd;
            }
        }

        fraction& operator=(const fraction &other) = default;
           
        bool operator<(const fraction &other) const {
            if(this->numerator == inf)
                return false;
            if(other.numerator == inf)
                return true;
            return this->numerator * other.denominator < other.numerator * this->denominator;
        }

        bool operator==(const fraction &other) const {
            return this->numerator == other.numerator && this->denominator == other.denominator;
        }

        fraction negate(){
            if(this->numerator == inf)
                return fraction(1, 0);
            if(this->numerator == 0)
                return fraction(0, 1);
            return fraction(-this->numerator, this->denominator);
        }

        fraction reverse(){
            if(this->numerator == inf)
                return fraction(0, 1);
            if(this->numerator == 0)
                return fraction(1, 0);
            return fraction(this->denominator, this->numerator);
        }

        fraction operator+(const fraction &other) const {
            return fraction(this->numerator * other.denominator + other.numerator * this->denominator, this->denominator * other.denominator);
        }

        fraction operator-(const fraction &other) const {
            return fraction(this->numerator * other.denominator - other.numerator * this->denominator, this->denominator * other.denominator);
        }

        fraction operator*(const fraction &other) const {
            return fraction(this->numerator * other.numerator, this->denominator * other.denominator);
        }

        fraction operator/(const fraction &other) const {
            fraction p(this->numerator, this->denominator);
            fraction q(other.numerator, other.denominator);
            return p * q.reverse();
        }
};

int n;
fraction m[2003], b[2003];
map<fraction, map<fraction, num>> mp;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        num x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        num dy = y2 - y1, dx = x2 - x1;
        m[i] = fraction(dy, dx);
        if(dy == 0)
            b[i] = fraction(y1, 1);
        else if(dx == 0)
            b[i] = fraction(x1, 1);
        else
            b[i] = fraction(y1, 1) - m[i] * fraction(x1, 1);
    }
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(m[i] == m[j]){
                fraction d = (b[i] - b[j]) * (b[i] - b[j]);
                if(m[i].numerator != inf && m[i].numerator != 0)
                    d = d / (fraction(1, 1) + m[i] * m[i]); 
                mp[m[i]][d]++;
            }
    num ans = 0;
    for(auto p : mp){
        fraction m = p.first;
        for(auto q : p.second){
            fraction d = q.first;
            num n1 = q.second;
            fraction pm = m.reverse().negate();
            num n2 = mp[pm][d];
            ans += n1 * n2;
        }
    }
    cout << ans / 2 << endl;
}