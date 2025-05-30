import java.util.Scanner;

public class MyLinkedHashMap {
    private Node[] table;
    private Node head, tail;
    private int size = 0;
    private int capacity = 16;

    public MyLinkedHashMap() {
        table = new Node[capacity];
    }

    public Node getHead() { return head; }
    public Node getTail() { return tail; }

    private int hash(String key) {
        return Math.abs(key.hashCode() % capacity);
    }

    public void add(String key, Author value) {
        if ((float)(size + 1) / capacity > 0.75f) resize();

        int index = hash(key);
        Node current = table[index];

        while (current != null) {
            if (current.key.equals(key)) {
                current.value = value;
                return;
            }
            current = current.next;
        }

        Node newNode = new Node(key, value);
        newNode.next = table[index];
        table[index] = newNode;

        if (head == null) head = tail = newNode;
        else {
            tail.nextLink = newNode;
            newNode.prevLink = tail;
            tail = newNode;
        }

        size++;
    }

    public boolean remove(String key) {
        int index = hash(key);
        Node current = table[index];
        Node prev = null;

        while (current != null) {
            if (current.key.equals(key)) {
                if (prev == null) {
                    table[index] = current.next;
                } else {
                    prev.next = current.next;
                }
                if (current.prevLink != null) {
                    current.prevLink.nextLink = current.nextLink;
                } else {
                    head = current.nextLink;
                }
                if (current.nextLink != null) {
                    current.nextLink.prevLink = current.prevLink;
                } else {
                    tail = current.prevLink;
                }
                size--;
                return true;
            }
            prev = current;
            current = current.next;
        }
        return false;
    }

    public Author get(String key) {
        int index = hash(key);
        Node current = table[index];
        while (current != null) {
            if (current.key.equals(key)) return current.value;
            current = current.next;
        }
        return null;
    }

    private void resize() {
        capacity *= 2;
        Node[] newTable = new Node[capacity];

        Node current = head;
        while (current != null) {
            int index = hash(current.key);
            Node newNode = new Node(current.key, current.value);
            newNode.next = newTable[index];
            newTable[index] = newNode;
            current = current.nextLink;
        }

        table = newTable;
    }

    public void printTable() {
        System.out.println("┌──────────────────────────────┬───────────────┬────────────┬──────────────────────┐");
        System.out.printf("│ %-28s │ %-13s │ %-10s │ %-20s │\n", "Автор", "Всього книг", "Рік нар.", "За останні 10 років");
        System.out.println("├──────────────────────────────┼───────────────┼────────────┼──────────────────────┤");

        Node current = head;
        while (current != null) {
            Author author = current.value;
            System.out.printf("│ %-28s │ %-13d │ %-10d │ %-20d │\n",
                    current.key, author.getTotalBooks(), author.getBirthYear(), author.getRecentBooks());
            current = current.nextLink;
        }

        System.out.println("└──────────────────────────────┴───────────────┴────────────┴──────────────────────┘");
    }

    public void findByName() {
        Scanner sc = new Scanner(System.in);
        String name = sc.nextLine();
        Node current = head;
        while (current != null) {
            if (current.key.equals(name)) {
                Author author = current.value;
                System.out.println("Дані автора " + name + ":");
                System.out.println("Всього книг: " + author.getTotalBooks());
                System.out.printf("Рік народження: %d\n", author.getBirthYear());
                System.out.printf("Книг за 10 років: %d\n", author.getRecentBooks());
                return;
            }
            current = current.nextLink;
        }
        System.out.println("Такого автора не існує");
    }

    public int size() {
        return size;
    }
}
