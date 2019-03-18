#include <bits/stdc++.h>
#define ll long long
int arr[35][35],n;
ll  dp[35][35][3];
int main(){
    scanf("%d",&n);
    for(int i =1; i <=n ;i++) for(int j =1; j <=n; j++) scanf("%d",&arr[i][j]);
    dp[1][2][0]=(ll)1;
    for(int i =1; i <=n ;i++){
        for(int j =1;j <=n; j++){
                if(arr[i][j]) continue;
                if(!arr[i][j-1] && !arr[i-1][j])dp[i][j][2] += dp[i-1][j-1][0]+dp[i-1][j-1][1]+dp[i-1][j-1][2];
                dp[i][j][1] += dp[i-1][j][1]+dp[i-1][j][2];
                dp[i][j][0] += dp[i][j-1][0]+dp[i][j-1][2];
        }
    }
    printf("%lld",dp[n][n][0]+dp[n][n][1]+dp[n][n][2]);
}