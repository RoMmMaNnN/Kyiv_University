public class Author {
    private int totalBooks;
    private int birthYear;
    private int recentBooks;

    public Author(int totalBooks, int birthYear, int recentBooks) {
        this.totalBooks = totalBooks;
        this.birthYear = birthYear;
        this.recentBooks = recentBooks;
    }

    public int getTotalBooks() { return totalBooks; }
    public int getBirthYear() { return birthYear; }
    public int getRecentBooks() { return recentBooks; }

    public void setTotalBooks(int totalBooks) { this.totalBooks = totalBooks; }
    public void setBirthYear(int birthYear) { this.birthYear = birthYear; }
    public void setRecentBooks(int recentBooks) { this.recentBooks = recentBooks; }

    @Override
    public String toString() {
        return String.format("%-15d │ %-10d │ %-19d", totalBooks, birthYear, recentBooks);
    }
}
