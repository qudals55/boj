#include <bits/stdc++.h>
std::pair<int, int> p[70];
int n,ret;
bool cmp(std::pair<int ,int> a, std::pair<int, int> b){
    if(a.first!=b.first) return a.first>b.first;
    return a.second<b.second;
}
int main(){
    scanf("%d",&n);
    for(int i =0; i <n ;i++) scanf("%d %d",&p[i].first,&p[i].second);
    std::sort(p,p+n, cmp);
    for(int i =5; i<n ;i++)
        if(p[i].first == p[4].first) ret++;
    printf("%d",ret);
}