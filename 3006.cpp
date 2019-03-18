#include <iostream>
#include <cstdio>
#include <algorithm>
 
using namespace std;
typedef pair<int, int> pii;
 
pii arr[100002];
int tree[100002];
int n;
 
void update(int i, int diff)
{
    while (i <= n)
    {
        tree[i] += diff;
        i += (i & -i);
    }
}
 
int sum(int i)
{
    int ans = 0;
 
    while (i > 0)
    {
        ans += tree[i];
        i -= (i & -i);
    }
 
    return ans;
}
 
int main()
{
    scanf("%d", &n);
 
    // 값과 인덱스를 pair로 받는다.
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i].first);
        arr[i].second = i;
 
        update(i, 1); // 각 인덱스에 1씩 값을 부여
    }
 
    // 값에 대해 정렬
    sort(arr, arr + n + 1);
 
    // p1은 처음부터 p2는 끝부터 시작
    int p1 = 1, p2 = n;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            // p1의 인덱스에 해당하는 값을 sum, update
            printf("%d\n", sum(arr[p1].second) - 1);
            update(arr[p1].second, -1); 
            p1++;
        }
 
        else
        {
            printf("%d\n", sum(n) - sum(arr[p2].second - 1) - 1);
            update(arr[p2].second, -1);
            p2--;
        }
    }
    return 0;
}
 


