#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
#define MAX 100
#define oo 1000
int n = 6;
int G[MAX][MAX] = {
    {0, 1, 0, 1, 1, 1},
    {1, 0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0, 0},
    {1, 0, 1, 0, 0, 0},
    {1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0}
};

int dist[MAX];
int truoc[MAX];

void bfs(int s)
{
    queue<int> Q;

    for (int u = 0; u < n; u++)
        dist[u] = oo;

    truoc[s] = -1;
    dist[s] = 0;
    Q.push(s);

    while (Q.empty() != true)
    {
        int u = Q.front();
        Q.pop();
        for (int v = 0; v < n; v++)
            if (G[u][v] == 1)
            {
                if (dist[v] == oo)
                {
                    Q.push(v);
                    truoc[v] = u;
                    dist[v] = dist[u] + 1;
                }
            }
    }
}
void findPath(int s, int u)
{
    bfs(s);
    while (u != s)
    {
        cout << u << "<-";
        u = truoc[u];
    }
    cout << s << endl;
}


int main(int argc, char const *argv[])
{
   findPath(0, 2);

    return 0;
}
