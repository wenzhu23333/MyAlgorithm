#include <bits/stdc++.h>
using namespace std;
struct Item
{
    float weight;
    int value;
};
struct Node
{
    int level, profit, bound;
    float weight;
    bool operator < (const Node &a) const
    {
        return a.bound > bound;
    }
};
bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}
int bound(Node u, int n, int W, Item arr[])
{
    if (u.weight >= W)
        return 0;
    int profit_bound = u.profit;
    int j = u.level + 1;
    int totweight = u.weight;
    while ((j < n) && (totweight + arr[j].weight <= W))
    {
        totweight    += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }
    if (j < n)
        profit_bound += (W - totweight) * arr[j].value /
                                         arr[j].weight;
    return profit_bound;
}
int knapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, cmp);
    priority_queue<Node> Q;
    Node u, v;
    u.level = -1;
    u.profit = u.weight = 0;
    Q.push(u);
    int maxProfit = 0;
    int record[n];
    for(int i = 0;i<n;i++)
        record[i] = 0;
    while (!Q.empty())
    {
        u = Q.top();
        Q.pop();
        if (u.level == -1)
            v.level = 0;
        if (u.level == n-1)
            break;
        v.level = u.level + 1;
        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;
        if (v.weight <= W && v.profit > maxProfit)
            {
                maxProfit = v.profit;
                cout<<"所选择的商品为："<<v.level+1<<"号"<<endl;;
                //record[v.level] = 1;
            }
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
            Q.push(v);
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
            Q.push(v);
    }

    return maxProfit;
}

int main()
{
    int W = 10;
    Item arr[] = {{3, 12}, {7, 42}, {5, 25},
                  {4, 40}};

          /* int W = 11;
    Item arr[] = {{3, 12}, {8, 48}, {5, 25},
                  {4, 40}};
                  */
    /*int W = 10;
    Item arr[] = {{2, 40}, {3.14, 50}, {1.98, 100},
                  {5, 95}, {3, 30}};
                  */
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n, cmp);

    cout<<"背包总重量："<<W<<endl;
     for(int i = 0;i<n;i++)
   {
       cout<<"第"<<i+1<<"号商品重量："<<arr[i].weight<<"  价值："<<arr[i].value<<endl;
   }
    cout << "背包的最大价值为："
         << knapsack(W, arr, n)<<endl;


    return 0;
}

























/*#include<bits/stdc++.h>
using namespace std;

class Item
{
    public:
    float weight;
    int value;
};

class Node
{
    public:
    int level;
    int profit;
    int bound;
    float weight;

};

struct mycmp
{
    bool operator () (const Node &a, const Node &b)
    {
        return a.bound < b.bound;
    }
};
bool cmp(Item a,Item b)
{

    double a1 = (double)a.value/a.weight;
    double a2 = (double)b.value/b.weight;
    return a1>a2;
}

int  bound(Node u,int n,int W,Item arr[])
{
    if(u.weight>W) return 0;
    int j = u.level+1;
    int profit_bound = u.profit;
    int NowWeight = u.weight;
    while ((j < n) && (NowWeight + arr[j].weight <= W))
    {
        NowWeight    += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }
    if(j<n)
        profit_bound = profit_bound+(W-NowWeight)*arr[j].value /arr[j].weight;
    return profit_bound;
}

int knapsack(int W,Item arr[],int n)
{
    sort(arr,arr+n,cmp);
    queue<Node> Q;
    //priority_queue<Node,vector<Node>,mycmp> Q;
    Node u,v;
     u.level = -1;
     u.profit = u.weight = 0;
     Q.push(u);

     int maxProfit = 0;
     while(true)
     {
         u = Q.front();
         //u = Q.top();
         Q.pop();
         if(u.level == -1) v.level = 0;
         if (u.level == n-1)
            break;
        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;
        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
            Q.push(v);
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
            Q.push(v);
     }
     return maxProfit;
}

int main()
{
    int W = 10;
    Item arr[] = {{2, 40}, {3.14, 50}, {1.98, 100},
                  {5, 95}, {3, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum possible profit = "
         << knapsack(W, arr, n);
    return 0;
}
*/















