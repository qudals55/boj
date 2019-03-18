#include <bits/stdc++.h>
#define ll long long
ll ret=5, n;
int main(){
    scanf("%lld",&n);
    for(ll i=2; i<=n ;i++)
        ret+=3*i+1,ret%=45678;
    printf("%lld",ret);
}