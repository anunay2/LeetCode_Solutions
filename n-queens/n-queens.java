class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> res = new ArrayList<>();
        int chess[][] = new int[n][n];
        generatePositions(res, new ArrayList<>(), chess, n, 0);
        return res;
    }
    
    public void generatePositions(List<List<String>> res, List<String> temp, int chess[][], int n, int row){
        //base
        if(row == n){
            res.add(new ArrayList<>(temp));
            return;
        }
        
        //recursion - explore every position
		//place only if queen is safe
        for(int col = 0; col < n; col++){
            if(isQueenSafe(chess, row, col)){
                chess[row][col] = 1;
                String s = placeQueen(chess, n, col);
                temp.add(s);
                generatePositions(res, temp, chess, n, row+1);
                chess[row][col] = 0;
                temp.remove(temp.size()-1);
            }
        }
    }
    //generates a row string
    public String placeQueen(int chess[][], int n, int col){
        String s = "";
        for(int i = 0; i<n; i++){
            if(i == col){
                s += "Q";
            }else{
                s += "."; 
            }
        }
        return s;
    }
    //checks queen's safety
    public boolean isQueenSafe(int chess[][], int row, int col){
        //left diag
        for(int i = row-1 , j = col-1; i >= 0 && j >= 0; i--, j--){
            if(chess[i][j] == 1)
                return false;
        }
        //right diag
        for(int i = row-1 , j = col+1; i >= 0 && j < chess.length; i--, j++){
            if(chess[i][j] == 1)
                return false;
        }
        //vertical
        for(int i = row-1 , j = col; i >= 0; i--){
            if(chess[i][j] == 1)
                return false;
        }
        return true;
    }
}