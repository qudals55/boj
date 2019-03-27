#include <bits/stdc++.h>
int N, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, pos[5], ret, arr[21][21], tmp[21][21];
bool visit[21][21];
bool safe(int x, int y)
{
    return (x >= 0 && y >= 0 && x < N && y < N);
}
void go(int cx, int cy, int i)
{
    while (1)
    {
        if (!safe(cx + dx[pos[i]], cy + dy[pos[i]])) break;
        int cur = tmp[cx][cy], next = tmp[cx + dx[pos[i]]][cy + dy[pos[i]]];
        if(!next) std::swap(tmp[cx][cy], tmp[cx + dx[pos[i]]][cy + dy[pos[i]]]);
        else{
        if(cur != next || visit[cx + dx[pos[i]]][cy + dy[pos[i]]]) break;
        if(!visit[cx][cy])
            tmp[cx + dx[pos[i]]][cy + dy[pos[i]]] *= 2, tmp[cx][cy] = 0, visit[cx +dx[pos[i]]][cy + dy[pos[i]]] = true;
        }
        cx += dx[pos[i]], cy += dy[pos[i]];
    }
}
void solve()
{
    memcpy(tmp, arr, sizeof(tmp));
    for (int i = 0; i < 5; i++)
    {
        memset(visit, false, sizeof(visit));
        for (int x = 0, rx = N - 1; x < N; x++, rx--)
        {
            for (int y = 0, ry = N - 1; y < N; y++, ry--)
            {
                if(pos[i] == 0 && tmp[rx][y]) go(rx,y,i);
                if(pos[i]==1 && tmp[x][ry]) go(x, ry,i);
                if((pos[i]==2||pos[i]==3) && tmp[x][y]) go(x,y,i);
            }
        }
    }
    for(int i =0; i <N ;i++) for(int j =0; j <N;j++) ret=std::max(ret,tmp[i][j]);
}
void dfs(int p)
{
    if (p == 5) {   solve();  return;}
    for (int i = 0; i < 4; i++) pos[p] = i, dfs(p + 1);
}
int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &arr[i][j]),ret = std::max(ret, arr[i][j]);
    dfs(0);
    printf("%d", ret);
}