#include <bits/stdc++.h>
int arr[101][101],n,m,r,t,arr_cp[101][101];
void solve(int t){
    if(t==1){
        for(int i =0; i <n/2; i++) for(int j =0;j  <m ;j++) arr_cp[i][j] = arr[n-1-i][j], arr_cp[n/2+i][j] =arr[n/2-1-i][j];
    }
    else if(t==2){
        for(int i =0; i <n; i++) for(int j =0; j <m/2;j++) arr_cp[i][j] = arr[i][m-1-j],arr_cp[i][m/2+j]= arr[i][m/2-j-1];
    }
    else if(t==3){
        for(int i=0; i<n ;i++) for(int j =0; j <m;j++) arr_cp[j][i] = arr[n-1-i][j];
        std::swap(n,m);
    }
    else if(t==4){
        for(int i =0; i <n ;i++) for(int j =0; j <m ;j++) arr_cp[j][i]= arr[i][m-1-j];
        std::swap(n,m);
    }
    else if(t==5){
        for(int i =0; i<n/2;i++) for(int j =0; j <m/2;j++) 
        arr_cp[i][j] = arr[i+n/2][j], arr_cp[i+n/2][j] = arr[i+n/2][j+m/2], arr_cp[i][j+m/2] =arr[i][j], arr_cp[i+n/2][j+m/2] = arr[i][j+m/2];
    }
    
    else{
        for(int i =0; i<n/2;i++) for(int j =0; j <m/2;j++) 
        arr_cp[i][j] = arr[i][j+m/2], arr_cp[i][j+m/2] = arr[i+n/2][j+m/2], arr_cp[i+n/2][j] =arr[i][j], arr_cp[i+n/2][j+m/2] = arr[i+n/2][j];
    }

    memcpy(arr, arr_cp, sizeof(arr));
}
int main(){
    scanf("%d %d %d",&n,&m,&r);
    for(int i =0; i <n; i ++) for(int j =0;j < m;j++) scanf("%d",&arr[i][j]);
    while(r--){
        scanf("%d",&t);
        solve(t);
    }
    for(int i =0; i <n ;i++){
        for(int j =0; j<m;j++) printf("%d ",arr[i][j]);
        puts("");
    }
}