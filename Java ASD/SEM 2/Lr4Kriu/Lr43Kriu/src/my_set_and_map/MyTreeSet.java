package my_set_and_map;

import java.util.Iterator;

public class MyTreeSet<E extends Comparable<E>> implements Iterable<E> {
    private Node<E> root;
    private int size;

    public MyTreeSet() {
        root = null;
        size = 0;
    }

    protected static class Node<E> {
        E value;
        Node<E> left, right;

        Node(E value) {
            this.value = value;
            left = right = null;
        }
    }

    public boolean add(E element) {
        if (root == null) {
            root = new Node<>(element);
            size++;
            return true;
        } else {
            return addRecursive(root, element);
        }
    }

    private boolean addRecursive(Node<E> node, E element) {
        if (element.compareTo(node.value) < 0) {
            if (node.left == null) {
                node.left = new Node<>(element);
                size++;
                return true;
            } else {
                return addRecursive(node.left, element);
            }
        } else if (element.compareTo(node.value) > 0) {
            if (node.right == null) {
                node.right = new Node<>(element);
                size++;
                return true;
            } else {
                return addRecursive(node.right, element);
            }
        } else {
            return false;
        }
    }

    public boolean contains(E element) {
        return containsRecursive(root, element);
    }

    private boolean containsRecursive(Node<E> node, E element) {
        if (node == null) {
            return false;
        }
        if (element.compareTo(node.value) < 0) {
            return containsRecursive(node.left, element);
        } else if (element.compareTo(node.value) > 0) {
            return containsRecursive(node.right, element);
        } else {
            return true;
        }
    }

    public int size() {
        return size;
    }

    public Iterator<E> iterator() {
        return new TreeIterator<>(root);
    }

    private static class TreeIterator<E> implements Iterator<E> {
        private Node<E> current;
        private final java.util.Stack<Node<E>> stack;

        TreeIterator(Node<E> root) {
            stack = new java.util.Stack<>();
            current = root;
            while (current != null) {
                stack.push(current);
                current = current.left;
            }
        }

        @Override
        public boolean hasNext() {
            return !stack.isEmpty();
        }

        @Override
        public E next() {
            Node<E> node = stack.pop();
            E value = node.value;
            if (node.right != null) {
                current = node.right;
                while (current != null) {
                    stack.push(current);
                    current = current.left;
                }
            }
            return value;
        }
    }
}
