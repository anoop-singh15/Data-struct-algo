#include <iostream>
#include <vector>

using namespace std;


// TC =O(logN)
// SC =O(N)

class UnionFind
{
private:
    vector<int> parent;

public:
    UnionFind(int size)
    {
        for (int i = 0; i < size; i++)
        {
            parent.push_back(i);
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return find(parent[x]);
    }
    void Union(int x, int y)
    {
        int xRep = find(x);
        int yRep = find(y);

        parent[xRep] = yRep;
    }
};

int main()
{
    int n = 5;
    UnionFind uf(n);
    uf.Union(0, 1);
    uf.Union(1, 3);
    uf.Union(1, 2);

    cout << (uf.find(0) == uf.find(3)) << " <----query 1" << endl;
    cout << (uf.find(3) == uf.find(4)) << " <----query 1" << endl;
    return 0;
}