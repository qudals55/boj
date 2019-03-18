#include <iostream>
#include <queue>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    string n,ans="0";
    int k;
    queue <string> q;
    cin>>n>>k;
    q.push(n);
    for(int i =0;i<k;i++){
        int s= q.size();
        set<string> cnt;
        while(s--){
            string f=q.front(); q.pop();
            if(cnt.count(f)) continue;
            cnt.insert(f);
            for(int x=0;x<f.size()-1;x++){
                for(int y=x+1;y<f.size();y++){
                    if(x==0 && f[y]=='0') continue;
                    swap(f[x],f[y]); q.push(f); swap(f[x],f[y]);
                }
            }
        }
    }
    while(!q.empty()) ans=max(ans,q.front()), q.pop();
    ans=="0"?cout<<"-1":cout<<ans;
}