#include <bits/stdc++.h>
using namespace std;

// Setting Problem

int n;
pair<int, int> jobs[23];
int partial[23];

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2){
    return p1.second > p2.second;
}

int evaluate(int ans){
    int opt = ans;
    sort(jobs, jobs+n);
    do{
        partial[0] = jobs[0].first;
        for(int i = 1; i < n; i++)
            partial[i] = partial[i-1] + jobs[i].first;
        int curr = 0;
        for(int i = 0; i < n; i++)
            curr = max(curr, partial[i]) + jobs[i].second;
        if(curr < opt){
            opt = curr;
        }
    }while(next_permutation(jobs, jobs+n));
    if(opt < ans)
        cout << "There is a better answer: " << opt << endl;
    return opt;
}

vector<pair<int, int>> bad_jobs;
vector<pair<int, int>> good_jobs;

int main(){
    while(cin >> n){
        for(int i = 0; i < n; i++)
            cin >> jobs[i].first;
        for(int i = 0; i < n; i++)
            cin >> jobs[i].second;
        bad_jobs.clear();
        good_jobs.clear();
        for(int i = 0; i < n; i++){
            if(jobs[i].first < jobs[i].second)
                bad_jobs.push_back(jobs[i]);
            else good_jobs.push_back(jobs[i]);
        }
        sort(bad_jobs.begin(), bad_jobs.end());
        sort(good_jobs.begin(), good_jobs.end(), cmp);
        for(int i = 0; i < bad_jobs.size(); i++)
            jobs[i] = bad_jobs[i];
        for(int i = bad_jobs.size(); i < n; i++)
            jobs[i] = good_jobs[i - bad_jobs.size()];
        partial[0] = jobs[0].first;
        for(int i = 1; i < n; i++)
            partial[i] = partial[i-1] + jobs[i].first;
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans, partial[i]) + jobs[i].second;
        // evaluate(ans);
        cout << ans << endl;
    }
}