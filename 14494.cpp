#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
ll dp[1001][1001],n,m;
int main(){
    scanf("%lld %lld",&n,&m);
    dp[1][1]=(ll)1;
    for(int i =1;i<=n;i++)
        for(int j =1; j <=m; j++) dp[i][j] += (dp[i-1][j-1]+dp[i-1][j])%MOD, dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
    printf("%lld",dp[n][m]%MOD);
    
}