#include <bits/stdc++.h>

using namespace std;

map <string, int> folders;

int main() 
{
    int n;
    cin >> n;
    cin.ignore();

    while (n--)
    {
        string line;
        getline(cin, line);
        
        if(folders.find(line) == folders.end())
            folders[line] = 0;
        else
        {
            folders[line]++;
            folders[line + " (" + to_string(folders[line]) + ")"] = 0;
        }

        for(auto it = folders.begin(); it != folders.end(); it++)
        {
            cout << "'" << it -> first << "'";
            if (next(it) == folders.end())
                cout << endl;
            else
                cout << ", ";
        }
    }
    return 0;
}