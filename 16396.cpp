#include <bits/stdc++.h>
int arr[10001],n,a,b,ret;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d %d",&a,&b);
		for(int i =a; i <b; i++) arr[i] =1;
	}
	for(int i =1; i<10000;i++) if(arr[i]) ret++;
	printf("%d",ret);
}