#include <bits/stdc++.h>
using namespace std;

// Biking Duck

#define y1 y11
#define EPS 1e-9

int n;
double vw, vb, x1, y1, x2, y2, xg, yg, xd, yd, x[1003], y[1003];

inline double f(double xf, double yf, double xs, double ys){
    return hypot(xg - xf, yg - yf) / vw + hypot(xf - xs, yf - ys) / vb + hypot(xs - xd, ys - yd) / vw;
}

inline double find_best(double xf, double yf, bool vertical, int index){
    if(vertical){
        double X = index ? x1 : x2;
        double lo = y1, hi = y2;
        while(fabs(hi - lo) > EPS){
            double m1 = lo + (hi - lo) / 3, m2 = m1 + (hi - lo) / 3;
            if(f(xf, yf, X, m1) < f(xf, yf, X, m2))
                hi = m2;
            else
                lo = m1;
        }
        return f(xf, yf, X, lo);
    }
    double Y = index ? y1 : y2;
    double lo = x1, hi = x2;
    while(fabs(hi - lo) > EPS){
        double m1 = lo + (hi - lo) / 3, m2 = m1 + (hi - lo) / 3;
        if(f(xf, yf, m1, Y) < f(xf, yf, m2, Y))
            hi = m2;
        else
            lo = m1;
    }
    return f(xf, yf, lo, Y);
}

// Go to one bike station, take a bike then go to another bike station and leave the bike and finally go to destination

int main(){
    cin >> vw >> vb >> x1 >> y1 >> x2 >> y2 >> xg >> yg >> xd >> yd >> n;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    // No stations:
    double ans = hypot(xg - xd, yg - yd) / vw;
    // Point stations:
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ans = min(ans, f(x[i], y[i], x[j], y[j]));
    // Boundary and Point stations, ternary search:
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            double X = j ? x1 : x2;
            double lo = y1, hi = y2;
            while(fabs(hi - lo) > EPS){
                double m1 = lo + (hi - lo) / 3, m2 = m1 + (hi - lo) / 3;
                if(f(X, m1, x[i], y[i]) < f(X, m2, x[i], y[i]))
                    hi = m2;
                else
                    lo = m1;
            }
            ans = min(ans, f(X, lo, x[i], y[i]));
            lo = y1, hi = y2;
            while(fabs(hi - lo) > EPS){
                double m1 = lo + (hi - lo) / 3, m2 = m1 + (hi - lo) / 3;
                if(f(x[i], y[i], X, m1) < f(x[i], y[i], X, m2))
                    hi = m2;
                else
                    lo = m1;
            }
            ans = min(ans, f(x[i], y[i], X, lo));
        }
        for(int j = 0; j < 2; j++){
            double Y = j ? y1 : y2;
            double lo = x1, hi = x2;
            while(fabs(hi - lo) > EPS){
                double m1 = lo + (hi - lo) / 3, m2 = m1 + (hi - lo) / 3;
                if(f(m1, Y, x[i], y[i]) < f(m2, Y, x[i], y[i]))
                    hi = m2;
                else
                    lo = m1;
            }
            ans = min(ans, f(lo, Y, x[i], y[i]));
            lo = x1, hi = x2;
            while(fabs(hi - lo) > EPS){
                double m1 = lo + (hi - lo) / 3, m2 = m1 + (hi - lo) / 3;
                if(f(x[i], y[i], m1, Y) < f(x[i], y[i], m2, Y))
                    hi = m2;
                else
                    lo = m1;
            }
            ans = min(ans, f(x[i], y[i], lo, Y));
        }
    }
    // Boundary stations, nested ternary search:
    for(int i = 0; i < 2; i++){
        double X = i ? x1 : x2;
        double lo, hi;
        for(int j = 0; j < 2; j++){
            lo = y1, hi = y2;
            while(fabs(hi - lo) > EPS){
                double m1 = lo + (hi - lo) / 3, m2 = m1 + (hi - lo) / 3;
                if(find_best(X, m1, 1, j) < find_best(X, m2, 1, j))
                    hi = m2;
                else
                    lo = m1;
            }
            ans = min(ans, find_best(X, lo, 1, j));
        }
        for(int j = 0; j < 2; j++){
            lo = y1, hi = y2;
            while(fabs(hi - lo) > EPS){
                double m1 = lo + (hi - lo) / 3, m2 = m1 + (hi - lo) / 3;
                if(find_best(X, m1, 0, j) < find_best(X, m2, 0, j))
                    hi = m2;
                else
                    lo = m1;
            }
            ans = min(ans, find_best(X, lo, 0, j));
        }
    }
    for(int i = 0; i < 2; i++){
        double Y = i ? y1 : y2;
        double lo, hi;
        for(int j = 0; j < 2; j++){
            lo = x1, hi = x2;
            while(fabs(hi - lo) > EPS){
                double m1 = lo + (hi - lo) / 3, m2 = m1 + (hi - lo) / 3;
                if(find_best(m1, Y, 0, j) < find_best(m2, Y, 0, j))
                    hi = m2;
                else
                    lo = m1;
            }
            ans = min(ans, find_best(lo, Y, 0, j));
        }
        for(int j = 0; j < 2; j++){
            lo = x1, hi = x2;
            while(fabs(hi - lo) > EPS){
                double m1 = lo + (hi - lo) / 3, m2 = m1 + (hi - lo) / 3;
                if(find_best(m1, Y, 1, j) < find_best(m2, Y, 1, j))
                    hi = m2;
                else
                    lo = m1;
            }
            ans = min(ans, find_best(lo, Y, 1, j));
        }
    }
    cout << fixed << setprecision(7) << ans << endl;
}