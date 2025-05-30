public class Lr11String {
    private String sentence;

    public Lr11String(java.lang.String sentence) {
        this.sentence = sentence;
    }

    public java.lang.String getSentence() {
        return sentence;
    }

    public void setSentence(java.lang.String sentence) {
        this.sentence = sentence;
    }

    public Lr11String concatenate(Lr11String other) {
        return new Lr11String(this.sentence + " " + other.sentence);
    }

    public Lr11String substring(int start, int end) {
        if (start < 0 || end > sentence.length() || start > end) {
            System.out.println("Invalid substring range");
        }
        return new Lr11String(sentence.substring(start, end));
    }

    public boolean equals(Lr11String other) {
        return this.sentence.equals(other.sentence);
    }

    public boolean notEquals(Lr11String other) {
        return !this.equals(other);
    }

    public boolean lessThan(Lr11String other) {
        return this.sentence.compareTo(other.sentence) < 0;
    }

    public boolean greaterThan(Lr11String other) {
        return this.sentence.compareTo(other.sentence) > 0;
    }
}
