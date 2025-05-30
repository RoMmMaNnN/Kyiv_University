class Node {
    String key;
    Author value;
    Node next;
    Node prevLink;
    Node nextLink;

    Node(String key, Author value) {
        this.key = key;
        this.value = value;
    }
}
