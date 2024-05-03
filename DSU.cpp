vector<int> parent;
vector<int> rank;

int find(int i)
{
    if (parent[i] != i)
        parent[i] = find(parent[i]);

    return parent[i];
}

void Union(int x, int y)
{
    int p_x = find(x);
    int p_y = find(y);

    if (p_x != p_y)
    {
        if (rank[p_x] > rank[p_y])
        {
            parent[p_y] = p_x;
        }
        else if (rank[p_y] > rank[p_x])
        {
            parent[p_x] = p_y;
        }
        else
        {
            parent[p_x] = p_y;
            rank[p_y]++;
        }
    }
}