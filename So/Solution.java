class Solution {
    public int maximumWealth(int[][] accounts) {
        for (int[] accounts1 : accounts){
            for (int i = 1; i < accounts1.length; i++){
                accounts1[i] += accounts1[i-1];
            }
        }
        int t = accounts.length;
        int j = accounts[0].length;
        int moreWealthy = 0;
        
        for (int a = 0; a < t ; a++){
            int userWealthy = accounts[a][j - 1];
            System.out.println(userWealthy);
            if(moreWealthy < accounts[a][j - 1]){
                moreWealthy = accounts[a][j-1];
            }
        }
        return moreWealthy;
    }
}