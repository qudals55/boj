#include <cstdio>
#include <vector>
#include <algorithm>
int n,k;
int main(){
	scanf("%d",&n);
	std::vector<int> v;
	v.push_back(-1);
	for(int i =0; i < n;i++){
		scanf("%d",&k);
		if(v.back()<k) v.push_back(k);
		else{auto it = std::lower_bound(v.begin(),v.end(),k);*it=k;}
	}
	printf("%d",n-v.size()+1);
}