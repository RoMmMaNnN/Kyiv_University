package my_set_and_map;

public class Node<E> {
    E value;
    Node<E> left, right;

    public Node(E value) {
        this.value = value;
        left = right = null;
    }
}
