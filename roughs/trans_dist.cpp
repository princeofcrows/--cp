#include <bits/stdc++.h>

using namespace std;

const int vert_count = 55;
const int k_max = 55;

/*
Graph array of the binary tree.
Every index's 0th value is left child, 1st value 2nd child.

graph[x][0] is x vertex's left edge. graph[x][1] is x vertex's right edge.
*/
int graph[vert_count][2];

/*
Length of edges.
edge_length[x][0] is x vertex's left edge length.
edge_length[x][1] is x vertex's right edge length.
*/
int edge_length[vert_count][2];

/*
g_value[x] is the x vertex's quantity of goods.
*/
int g_value[vert_count];

/*
sum_sub_g[x] is the sum of x vertex's sub tree's quantity of goods.
*/
int sum_sub_g[vert_count];

/*
trans_dist[x] is the transport distance of x vertex if there is no other distribution center in the sub tree.
*/
int trans_dist[vert_count];

/*
dp[x][k][0] represents the minimum transport distance of the sub tree of x, including x...
if x is not a distribution center
and in that sub tree there will be k more distribution center

dp[x][k][1] means the same thing only if x is also a distribution center
*/
int dp[vert_count][k_max][2];

int calculate_sum_g_of_sub_tree(int vert)
{
    if (vert == 0)
    {
        return 0;
    }

    int left_child = graph[vert][0];
    int right_child = graph[vert][1];

    int left = calculate_sum_g_of_sub_tree(left_child);
    int right = calculate_sum_g_of_sub_tree(right_child);

    return sum_sub_g[vert] = (left + right) + g_value[vert];
}

int calculate_trans_dist_of_sub_tree(int vert)
{
    if (vert == 0)
    {
        return 0;
    }

    int left_child = graph[vert][0];
    int right_child = graph[vert][1];

    int left = calculate_trans_dist_of_sub_tree(left_child);
    int right = calculate_trans_dist_of_sub_tree(right_child);

    int left_sub_sum = sum_sub_g[left_child] * edge_length[vert][left_child];
    int right_sub_sum = sum_sub_g[right_child] * edge_length[vert][right_child];

    return trans_dist[vert] = left_sub_sum + right_sub_sum + (left + right);
}

int solve(int vert, int k, int is_center)
{
    if (vert == 0)
    {
        return 0;
    }

    if (k == 0)
    {
        return dp[vert][k][is_center] = 0;
    }

    if (is_center == 1)
    {
        int left = max(solve(graph[vert][0], k - 1, 0), solve(graph[vert][0], k - 1, 1));
        int right = max(solve(graph[vert][1], k - 1, 1), solve(graph[vert][1], k - 1, 1));

        return dp[vert][k][is_center] = trans_dist[vert] - (left + right);
    }

    int left = min(solve(graph[vert][0], k, 0), solve(graph[vert][0], k, 1));
    int right = min(solve(graph[vert][1], k, 1), solve(graph[vert][1], k, 1));

    return dp[vert][k][is_center] = (left + right);
}
