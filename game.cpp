#include <bits/stdc++.h>
using namespace std;
string s[100001];
pair<string, int> p[100001];
int tree[100001],n;
long long k;
void update(int i, int val){
    while(i<=n) tree[i]+=val,i+=i&-i;
}
int query(int i){
    int ans=0;
    while(i>0)ans+=tree[i],i-=i&-i;
    return ans;
}
int main(){
    cin>>n;
    for(int i =0; i <n ; i++) cin>>s[i];
    sort(s,s+n);
    for(int i =0;i<n;i++) p[i]={s[i],i+1};
    for(int i =0; i<n;i++) reverse(p[i].first.begin(),p[i].first.end());
    sort(p,p+n);
    for(int i =0; i<n;i++) k+=(long long)query(n)-query(p[i].second), update(p[i].second,1);
    cout<<k;
}

// reverse 를 먼저체크 ->  현재의 나보다 먼저본 애들이 사전순으로 앞섬, 먼저본 애들이 원래의 나보다 뒤에있다는건 원래의 나보다 사전순으로 뒤에있음 원래의 내가 사전순으로 앞섬