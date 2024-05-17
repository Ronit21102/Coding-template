vector<int> parent;
vector<int> rank;
vector<int>size;

int find(int i)
{
    if (parent[i] != i)
        parent[i] = find(parent[i]);

    return parent[i];
}

void UnionR(int x, int y)
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

 void UnionS(int x, int y) {
	    int x_parent = find(x);
	    int y_parent = find(y);
	
	    if (x_parent == y_parent) 
	        return;
	
	    if(size[x_parent] > size[y_parent]) {
	        parent[y_parent] = x_parent;
	        size[x_parent]  += size[y_parent];
	    } else if(size[x_parent] < size[y_parent]) {
	        parent[x_parent] = y_parent;
	        size[y_parent]  += size[x_parent];
	    } else {
	        parent[y_parent] = x_parent;
	        size[x_parent]  += size[y_parent];
	    }
	}
