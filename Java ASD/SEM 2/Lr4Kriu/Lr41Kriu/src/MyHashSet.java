public class MyHashSet {
    private Book[] books;
    private int size;

    public MyHashSet() {
        books = new Book[0];
        size = 0;
    }

    public void add(Book book) {
        if (contains(book)) return;

        if (size == books.length) {
            expandArray();
        }
        books[size++] = book;
    }

    public void remove(Book book) {
        for (int i = 0; i < size; i++) {
            if (books[i].equals(book)) {
                for (int j = i; j < size - 1; j++) {
                    books[j] = books[j + 1];
                }
                books[--size] = null;
                return;
            }
        }
    }

    public Book[] getHashSet() {
        Book[] result = new Book[size];
        System.arraycopy(books, 0, result, 0, size);
        return result;
    }

    public boolean contains(Book book) {
        for (int i = 0; i < size; i++) {
            if (books[i].equals(book)) return true;
        }
        return false;
    }

    private void expandArray() {
        int newCapacity = (books.length == 0) ? 1 : books.length * 2;
        Book[] newArray = new Book[newCapacity];
        System.arraycopy(books, 0, newArray, 0, size);
        books = newArray;
    }

    public void printTable() {
        System.out.println("┌────────────────────────────────┬──────────────────────┬────────┐");
        System.out.printf("│ %-30s │ %-20s │ %-6s │\n", "Назва книги", "Автор", "Рік");
        System.out.println("├────────────────────────────────┼──────────────────────┼────────┤");
        for (Book book : books) {
            if (book == null) continue;
            System.out.println(book);
        }
        System.out.println("└────────────────────────────────┴──────────────────────┴────────┘");
    }
}
