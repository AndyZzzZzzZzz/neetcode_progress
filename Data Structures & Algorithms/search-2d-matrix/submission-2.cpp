class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // 2D binary search
        int n = matrix.size(), m = matrix[0].size();

        int row_l=0, row_r = n-1;
        while(row_l <= row_r)
        {
            int row_m = (row_r - row_l)/2 + row_l;
            // check if this is target row
            if(target >= matrix[row_m][0] && target <= matrix[row_m][m-1])
            {
                // start the second binary search
                int cl = 0, cr = m-1;
                while(cl <= cr)
                {
                    int cm = (cr - cl)/2 + cl;
                    if(matrix[row_m][cm] == target) return true;
                    if(matrix[row_m][cm] < target) cl = cm +1;
                    else cr = cm - 1;
                }
                return false;
            }
            if(target < matrix[row_m][0])
            {
                row_r = row_m -1;
            }
            else
            {
                row_l = row_m + 1;
            }
        }
        return false;
    }
};
