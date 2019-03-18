#include <bits/stdc++.h>
#define ll long long
ll dp[101][10][(1<<10)+1],n,ret;

int solve(int p, int i, int q){
    if(i>9 || i<0) return 0;
    if(p==1){
    if((q|(1<<i)) == (1<<10)-1) return 1;
     return 0;
    }
    ll& ret = dp[p][i][q];
    if(ret != -1) return ret;
    ret = (solve(p-1, i-1, q| (1<<i)) + solve(p-1, i+1, q| (1<<i)))%(int)1e9;
    return ret;
}
int main(){
    scanf("%lld",&n);
    memset(dp, -1,sizeof(dp));
    for(int i =1; i <=9 ;i++)
        ret= (ret+solve(n,i,0))%(int)1e9;
    printf("%lld",ret);
}
