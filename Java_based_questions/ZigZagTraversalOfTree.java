import java.util.*;

public class ZigZagTraversalOfTree {
    class TreeNode {
        int value;
        TreeNode left;
        TreeNode right;
    }
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        Queue<TreeNode> BFSQueue = new LinkedList<>();
        List<List<Integer>> elementsInZigZagOrder = new ArrayList<List<Integer>>();
        if ( root == null){
            return elementsInZigZagOrder;
        }
        BFSQueue.offer(root);
        int level = 0;
        while(!BFSQueue.isEmpty()){
            List<Integer> elementList = new ArrayList<>();

            int numOfElementsFromPrevLevel = BFSQueue.size();
            for(int i = 0; i< numOfElementsFromPrevLevel; i++){
                elementList.add(BFSQueue.element().val);
                TreeNode node = BFSQueue.element();
                BFSQueue.remove();
                if ( node.left != null ) {
                    BFSQueue.offer( node.left);
                }
                if ( node.right != null) {
                    BFSQueue.offer( node.right );
                }
            }
            if( level%2!=0){
                Collections.reverse(elementList);
            }
            elementsInZigZagOrder.add(elementList);
            level++;
        }
        return elementsInZigZagOrder;
    }
    public static void main(String[] args){

    }

}
