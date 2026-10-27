class Solution {
public:

    bool areValuesSame(vector<vector<int>> &grid, int rowStart, int rowEnd, int colStart, int colEnd){
        int val = grid[rowStart][colStart];
        for(int i=rowStart;i<=rowEnd;i++)
        {
            for(int j= colStart;j<=colEnd;j++)
            {
                if(grid[i][j]!= val)
                    return false;
            }
        }
        return true;
    }

    Node* helper(vector<vector<int>> &grid, int rowStart, int rowEnd, int colStart, int colEnd)
    {

        Node* newNode = new Node(grid[rowStart][colStart], true);

        if( (rowStart == rowEnd && colStart == colEnd) || areValuesSame(grid, rowStart, rowEnd, colStart, colEnd) )
        {
            return newNode;
        }

        newNode->isLeaf = false;

        int rowMid = rowStart+(rowEnd-rowStart)/2;
        int colMid = colStart+(colEnd-colStart)/2;

        newNode->topLeft = helper(grid, rowStart, rowMid , colStart, colMid);
        newNode->topRight = helper(grid, rowStart, rowMid, colMid+1, colEnd);
        newNode->bottomLeft = helper(grid, rowMid+1, rowEnd, colStart, colMid);
        newNode->bottomRight = helper(grid, rowMid+1, rowEnd, colMid+1, colEnd);

		return newNode;
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return helper(grid,0,n-1,0,n-1);
    }
};
