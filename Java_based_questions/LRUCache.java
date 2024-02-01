import java.util.HashMap;

public class LRUCache {

    public class Node {

        int key;
        int val;
        Node prev;
        Node next;
        Node( int key, int val, Node prev, Node next){
            this.key = key;
            this.val = val;
            this.prev = null;
            this.next = null;
        }

        Node addNode(Node newNode){
            tail.next = newNode;
            newNode.prev = tail;
            newNode.next = null;
            return newNode;
        }

        Node prepend(int key, int value){
            Node newNode = new Node(key, value, null, null);
            head.prev = newNode;
            newNode.next = head;
            newNode.prev = null;
            head = newNode;
            return newNode;
        }
    }
    HashMap<Integer, Node> map ;
    int capacity ;
    Node head;
    Node tail;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        head = new Node(-1, -1, null, null);
        tail = new Node(-1, -1, null, null);
        head.next = tail;
        tail.prev = head;
    }

    public int get(int key) {
        Node targetNode = map.get(key);

        // bring the element in the beginning.
        Node nextTargetNode = targetNode.next;
        Node prevTargetNode = targetNode.prev;

        prevTargetNode.next = nextTargetNode;
        nextTargetNode.prev = prevTargetNode;

        Node actualHead = head.next;
        actualHead.prev = targetNode;
        targetNode.next = actualHead;
        head.next = actualHead.next;
        targetNode.prev = head;
    }

    public void put(int key, int value) {
        // already we have map of full size we have to consider removing elements from map and LL
        if( map.size() == capacity) {
            // remove element from the head
            map.remove(tail.key);
            head.prepend(key ,value);
            Node newTail = tail.prev;
            tail.next = null;
            tail.prev = null;
            tail = newTail;
        }
        else{
            head.prepend(key, value);
        }


    }
}

