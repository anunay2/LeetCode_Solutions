import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

/*Given an array consisting of N integers.
In one move, We can choose any element in this array and replace it with any other number.
 Find the longest possible length of consistent segment given max 3 moves.

 */
public class LongestPossibleSegment {
    static int findLongestPossibleSegment(int[] arr){
        int windowStartIndex = 0, windowEndIndex = 0, maxWindowSize = -1;
        Map<Integer, Integer> frequencyMap = new HashMap<>();
        while( windowEndIndex < arr.length){
            frequencyMap.put(arr[windowEndIndex], frequencyMap.getOrDefault(arr[windowEndIndex] ,0) + 1);
            while( frequencyMap.size() > 3) {
                frequencyMap.put(arr[windowStartIndex], frequencyMap.get(arr[windowStartIndex])-1);
                if( frequencyMap.get(arr[windowStartIndex]) == 0){
                    frequencyMap.remove(arr[windowStartIndex]);
                }
                windowStartIndex++;
            }
            maxWindowSize = Math.max(maxWindowSize, windowEndIndex - windowStartIndex + 1);
            windowEndIndex++;
        }
        return maxWindowSize;
    }
    public static void main(String[] args){
            int []arr = {2,3,3,3,3,1};
            int ans = findLongestPossibleSegment(arr);
            System.out.println("Longest possible Segment" + ans);
    }

}
