#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int u, v, w;
    friend bool operator<(edge a, edge b)
    {
        return a.w < b.w;
    }
};
struct graph
{
    int dinh;
    int canh[100][100];
    vector<edge> edge_list;
};
void readgraph(const string &name, graph &g)
{
    fstream f(name);
    if (!f.is_open())
    {
        cout << "can not read file";
        cin;
        exit(0);
    }
    f >> g.dinh;
    for (int i = 1; i <= g.dinh; ++i)
        for (int j = 1; j <= g.dinh; ++j)
        {
            f >> g.canh[i][j];
            if (g.canh[i][j])
                g.edge_list.push_back({i, j, g.canh[i][j]});
        }
}
bool cochutrinh(graph g, int iMin, vector<edge> e, int Nhan[])
{
    if (Nhan[e[iMin].u] == Nhan[e[iMin].v])
        return 0;
    else
    {
        int tmp = Nhan[e[iMin].v];
        for (int i = 0; i < iMin; i++)
        {
            if (Nhan[e[i].v] == tmp)
            {
                Nhan[e[i].v] = Nhan[e[iMin].u];
            }
        }
        return 1;
    }
}
void kruscal(const graph &g, edge T[], int Nhan[], int &nT)
{

    for (int i = 1; i <= g.dinh; ++i)
        Nhan[i] = i;
    vector<edge> e(g.edge_list);
    sort(begin(e), end(e));
    int iMin = 0;
    while (nT < g.dinh - 1)
    {
        if (iMin < e.size())
        {
            if (!cochutrinh(g, iMin, e, Nhan))
            {
                T[nT] = e[iMin];
                nT++;
            }
            iMin++;
        }
        else
        {
            break;
        }
    }
}
int main()
{
    graph g;
    edge T[1000];
    int Nhan[1000];
    int nT;
    readgraph("input.txt", g);
    kruscal(g, T, Nhan, nT);
    for (int i = 0; i < nT; ++i)
    {
        cout << T[i].u << " " << T[i].v << endl;
    }
}