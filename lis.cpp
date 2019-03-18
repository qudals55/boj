#include <cstdio>
#include <vector>
#include <algorithm>
std::vector<int> v;
int n,k;
int main(){
    scanf("%d %d",&n,&k); v.push_back(k);
    for(int i =0; i < n-1 ;i++){
        scanf("%d",&k);
        if(v.back()<k) v.push_back(k);
        else {auto it=std::lower_bound(v.begin(),v.end(),k);*it=k;}
    }
    printf("%d",v.size());
}
