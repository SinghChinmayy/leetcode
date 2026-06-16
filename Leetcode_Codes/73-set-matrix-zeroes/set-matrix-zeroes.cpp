class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        // O(1) solution
        bool RowZero = false;
        // row 1 and onwards are handled using [1,0] and [2, 0]....
        for(int c = 0; c < COLS; c++){
            for(int r = 0; r < ROWS; r++){
                //Update ist row value to 0 to track 0 cols
                if(matrix[r][c] == 0){
                    matrix[0][c] = 0;
                    // track rows too
                    if(r > 0){
                        matrix[r][0] = 0;
                    } else{
                        RowZero = true;
                    }
                }
            }
        }

        // update matrix based on the tracked zeros from (1,1)
        for(int r = 1; r < ROWS; r++){
            for(int c = 1; c < COLS; c++){
                if(r == 0){
                    if(RowZero == true) matrix[r][c] = 0;
                }else{
                    if(matrix[0][c] == 0 || matrix[r][0] == 0){
                        matrix[r][c] = 0;
                    }
                }
            }
        }
        // check first coulmn then only check first row
        // else it can overwrite the (0,0) value
        for(int r = 0; r < ROWS; r++){
            if(matrix[0][0]==0){matrix[r][0] = 0;}
        }
        // check 1st row 
        if(RowZero == true){ 
            for(int c = 0; c < COLS; c++){
                matrix[0][c] = 0;
            }
        }
    }
};