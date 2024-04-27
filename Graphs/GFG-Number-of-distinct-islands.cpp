//^ https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1

//* Intuition
//* We will we storing all the cordinates of the islands in a vector after subtracting them from a base case
//* Now we will push this vector consisting all the cordinates of islands into as set
//* As set will only store unique vectors
//* We can obtain number of unique islands using ste's size

// User function Template for C++

class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &vec, int row0, int col0)
    {
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;

        vec.push_back({row - row0, col - col0});

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                dfs(nrow, ncol, vis, grid, vec, row0, col0);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        // code here
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int, int>> vec;
                    dfs(i, j, vis, grid, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};