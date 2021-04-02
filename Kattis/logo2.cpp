    #include <bits/stdc++.h>
    using namespace std;

    // Logo 2

    #define EPS 1e-7

    inline double deg_to_rad(double deg){
        return (deg * M_PI) / 180; 
    }

    int m, n, ind;
    pair<string, string> commands[1003];
    string ucommand;

    int main(){
        cin >> m;
        while(m--){
            cin >> n;
            for(int i = 0; i < n; i++){
                cin >> commands[i].first >> commands[i].second;
                if(commands[i].second == "?")
                    ind = i, ucommand = commands[i].first; 
            }
            if(ucommand == "lt" || ucommand == "rt"){
                for(int brute = 0; brute < 360; brute++){
                    double x = 0, y = 0;
                    int theta = 0;
                    for(int i = 0; i < n; i++){
                        string c = commands[i].first;
                        int l = (i == ind) ? brute : stoi(commands[i].second);
                        if(c == "lt")
                            theta = (theta + l) % 360;
                        else if(c == "rt")
                            theta = (theta - l + 360) % 360;
                        else if(c == "fd")
                            x += l * cos(deg_to_rad(theta)), y += l * sin(deg_to_rad(theta));
                        else
                            x -= l * cos(deg_to_rad(theta)), y -= l * sin(deg_to_rad(theta)); 
                    }
                    if(fabs(x) < EPS && fabs(y) < EPS){
                        cout << brute << endl;
                        break;
                    }
                }
            }
            else{
                double x = 0, y = 0;
                int theta = 0;
                for(int i = 0; i < n; i++){
                    if(i == ind)
                        continue;
                    string c = commands[i].first;
                    int l = stoi(commands[i].second);
                    if(c == "lt")
                        theta = (theta + l) % 360;
                    else if(c == "rt")
                        theta = (theta - l + 360) % 360;
                    else if(c == "fd")
                        x += l * cos(deg_to_rad(theta)), y += l * sin(deg_to_rad(theta));
                    else
                        x -= l * cos(deg_to_rad(theta)), y -= l * sin(deg_to_rad(theta)); 
                }
                int ans = static_cast<int>(hypot(x, y) + EPS);
                cout << ans << endl;
            }
        }
    }