#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a(6);
    for(int i=0;i<6;i++) cin>>a[i];
    int t1,t2;
    cin>>t1>>t2;
    vector<int> idx(6);
    iota(idx.begin(), idx.end(), 0);
    vector<int> first, second;
    bool found=false;
    for(int i=0;i<6 && !found;i++){
        for(int j=i+1;j<6 && !found;j++){
            for(int k=j+1;k<6 && !found;k++){
                int s = a[i]+a[j]+a[k];
                if(s==t1){
                    first={a[i],a[j],a[k]};
                    for(int p=0;p<6;p++){
                        if(p!=i && p!=j && p!=k) second.push_back(a[p]);
                    }
                    found=true;
                }
            }
        }
    }
    if(!found){
        for(int i=0;i<6 && !found;i++){
            for(int j=i+1;j<6 && !found;j++){
                for(int k=j+1;k<6 && !found;k++){
                    int s = a[i]+a[j]+a[k];
                    if(s==t2){
                        second={a[i],a[j],a[k]};
                        for(int p=0;p<6;p++){
                            if(p!=i && p!=j && p!=k) first.push_back(a[p]);
                        }
                        found=true;
                    }
                }
            }
        }
    }
    sort(first.begin(), first.end(), greater<int>());
    sort(second.begin(), second.end(), greater<int>());
    for(int x:first) cout<<x<<" ";
    for(int i=0;i<(int)second.size();i++){
        cout<<second[i];
        if(i+1<(int)second.size()) cout<<" ";
    }
    cout<<"\n";
    return 0;
}
