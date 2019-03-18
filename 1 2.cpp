#include <iostream>
#include <algorithm>
#include <stdio.h>
#define INF 999999999
using namespace std;
int dp[501][501], sum[501], arry[501];
 int main(){
  int numTestCases;
  ios::sync_with_stdio(false);
  scanf("%d" , &numTestCases);
   while(numTestCases--){
    int cnt;
    scanf("%d" , &cnt);
 
 
 
    for(int i = 1 ; i <= cnt ; i++)
      scanf("%d" , &arry[i]);
 
 
    for (int i = 1; i <= cnt; i++) {
 
                  sum[i] = sum[i - 1] + arry[i];
            }
 
    for(int i = 1 ; i <= cnt ; i++){
 
      for(int tx = 1 ; tx  <= cnt - i ; tx++){
        int ty = tx + i;
        dp[tx][ty] = INF;
 
        for(int k = tx ; k < ty ; k++){
          dp[tx][ty] = min(dp[tx][ty] , dp[tx][k] + dp[k + 1][ty] + sum[ty] - sum[tx-1]);
        }
      }
 
    }
 
    printf("%d\n" , dp[1][cnt] );
 
  }
 
  return 0;
}
