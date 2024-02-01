import java.util.Arrays;

public class prefixSuffixMultiplication {
    static int[] findProductArray(int[] arr){
        int[] leftProd = new int[arr.length], rightProd = new int[arr.length];
        int leftMult = arr[0];
        leftProd[0] = 1;
        for( int i = 1; i<arr.length ; i++){
            leftProd[i] = leftMult;
            leftMult = leftMult * arr[i];
        }

        int n = arr.length;
        int rightMult = arr[n-1];
        rightProd[n-1] = 1;
        for(int i = n - 2; i>=0; i--){
            rightProd[i] = rightMult;
            rightMult = rightMult * arr[i];
        }
        int[] ans = new int[n];
        for( int i = 0; i<n; i++){
            ans[i] = leftProd[i] * rightProd[i];
        }
        return ans;

    }
    public static void main(String[] args){
        int[] arr = {1, 2, 3, 4, 5};
        int[] ans = findProductArray(arr);
        System.out.println(Arrays.toString(ans));
    }
}


