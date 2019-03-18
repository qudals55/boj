#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end){
	if(start == end) return tree[node] = arr[start];
	int mid = (start+end)/2;
	return tree[node] = init(arr, tree, node*2, start, mid) + init(arr, tree, node*2+1,mid+1, end);
}
void update(vector<ll> &arr, vector<ll> &tree, int node, int start, int end ,int index, int diff){
	if(!(start<=index && index<=end)) return;
	tree[node]+=diff;
	if(start!=end){
	int mid = (start+end)/2;
	update(arr, tree, node*2, start ,mid, index,diff);
	update(arr, tree, node*2+1,mid+1,end,index,diff);
}
}
ll sum(vector<ll> &tree, int node, int start, int end, int left, int right){
	if(left> end || right <start) return 0;
	else if(left<=start && end <=right) return tree[node];
	int mid = (start +end)/2;
	return sum(tree, node*2, start,mid,left,right) + sum(tree,node*2+1,mid+1,end,left,right);
}
int main(){
	int n,m,k,h;
	scanf("%d %d %d",&n,&m,&k);
	h = ceil(log2(n));
	int _size= (1<<(h+1));
	vector <ll> arr(n);
	vector <ll> tree(_size);
	for(int i =0; i <n ; i++) scanf("%lld", &arr[i]);
	init(arr, tree, 1, 0, n-1);
	k= k+m;
	while(k--){
		int x,y,z;
		scanf("%d %d %d", &x,&y,&z);
		if(x==1){
			int diff = z-arr[y-1];
		arr[y-1]=z;
		update(arr, tree, 1, 0, n-1,y-1,diff);
		} 
		if(x==2){
			long long s=sum(tree,1,0,n-1,y-1,z-1);
			printf("%lld\n",s);
		} 
	}
}