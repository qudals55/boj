#include <bits/stdc++.h>
int N, arr[12][12], dp[3][101][12][12], sx, sy,ex,ey,ret=1e9;
bool safe(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N);
}
struct Node
{
    int pos, num, x, y, cost;
};
int dx[3][8] = {{1, -1, 0, 0}, {1, 1, -1, -1}, {1, 1, -1, -1, 2, 2, -2, -2}};
int dy[3][8] = {{0, 0, 1, -1}, {1, -1, -1, 1}, {2, -2, 2, -2, 1, -1, 1, -1}};
std::queue<Node> Q;
int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 1)
                sx = i, sy = j;
            if(arr[i][j]== N*N) ex=i,ey=j;
        }
    }

    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < 3; i++)
        Q.push({i, 1, sx, sy,0}), dp[i][1][sx][sy] = 0;
    while (!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        int flag = 0;
        if (cur.pos == 0 || cur.pos==1)
        {
            for (int k = 1; k <= N; k++)
            {
                for (int i = 0; i < 4; i++)
                {
                    int nx = cur.x + dx[cur.pos][i] * k, ny = cur.y + dy[cur.pos][i] * k;
                    if (!safe(nx, ny))
                        continue;
                    if (cur.num + 1 == arr[nx][ny])
                    {
                        if (dp[cur.pos][cur.num + 1][nx][ny] == -1 || dp[cur.pos][cur.num + 1][nx][ny] > dp[cur.pos][cur.num][cur.x][cur.y] + 1)
                            dp[cur.pos][cur.num + 1][nx][ny] = cur.cost + 1, Q.push({cur.pos, cur.num + 1, nx, ny,cur.cost + 1});
                    }
                    else
                    {
                        if (dp[cur.pos][cur.num][nx][ny] == -1 || dp[cur.pos][cur.num][nx][ny] > cur.cost + 1)
                            dp[cur.pos][cur.num][nx][ny] = cur.cost + 1, Q.push({cur.pos, cur.num, nx, ny,cur.cost + 1});
                    }
                }
            }
        }
        else{
            for (int i = 0; i < 8; i++)
                {
                    int nx = cur.x + dx[cur.pos][i], ny = cur.y + dy[cur.pos][i];
                    if (!safe(nx, ny))
                        continue;
                    if (cur.num + 1 == arr[nx][ny])
                    {
                        if (dp[cur.pos][cur.num + 1][nx][ny] == -1 || dp[cur.pos][cur.num + 1][nx][ny] > cur.cost + 1)
                            dp[cur.pos][cur.num + 1][nx][ny] = cur.cost + 1, Q.push({cur.pos, cur.num + 1, nx, ny,cur.cost + 1});
                    }
                    else
                    {
                        if (dp[cur.pos][cur.num][nx][ny] == -1 || dp[cur.pos][cur.num][nx][ny] > cur.cost + 1)
                            dp[cur.pos][cur.num][nx][ny] = cur.cost + 1, Q.push({cur.pos, cur.num, nx, ny,cur.cost + 1});
                    }
                }
        }
    for(int i =0; i <3; i++)
        if(dp[i][cur.num][cur.x][cur.y] == -1 || dp[i][cur.num][cur.x][cur.y] > cur.cost + 1)
            dp[i][cur.num][cur.x][cur.y] = cur.cost + 1, Q.push({i,cur.num,cur.x,cur.y,cur.cost + 1});
    }
    for(int i =0; i <3; i++)
        ret = std::min(ret, dp[i][N*N][ex][ey]);
    printf("%d",ret);
}