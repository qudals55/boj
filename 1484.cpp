#include <bits/stdc++.h>
int ret,s=1,e=1,sum;
double n;
int f(){
	return pow(e,2)-pow(s,2);
}
int main(){
	scanf("%lf",&n);
	if(n!= (int)n) {
		puts("-1");
		return 0;
	}

	while(1){
		if(f()>=n) s++;
		else if((e-s==1 && f()>n) || e>=n){
			if(!ret) puts("-1");
			return 0;
		}
		else e++;
		if(f()==n) printf("%d\n",e),ret++;
	}
}