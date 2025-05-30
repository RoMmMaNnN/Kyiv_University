package Task1;

public class Graf {
    private int[][] matrix;
    private final int size;
    private final int edges;

    public Graf(int size, int edges) {
        this.size = size;
        this.edges = edges;
        this.matrix = new int[size][size];
    }

    public Graf(int size, int edges, int[][] matrix) {
        this.size = size;
        this.edges = edges;
        this.matrix = matrix;
    }

    public int getSize() { return size; }
    public int getEdges() { return edges; }
    public int[][] getMatrix() { return matrix; }
    public void setMatrix(int[][] matrix) { this.matrix = matrix; }

    public void print() {
        if (isGrafEmpty()) {
            System.out.println("Матриця порожня.");
            return;
        }

        System.out.print("\t");
        for (int i = 0; i < size; i++) System.out.print("\033[1m" + (i + 1) + "\033[0m" + "\t");
        System.out.println();
        for (int i = 0; i < size; i++) {
            System.out.print("\033[1m" + (i + 1) + "\033[0m" + "\t");
            for (int j = 0; j < size; j++) {
                System.out.print((matrix[i][j] == Integer.MAX_VALUE || matrix[i][j] == 0 ? "∞" : matrix[i][j]) + "\t");
            }
            System.out.println();
        }
        System.out.println("=================================\n");
    }

    public boolean isGrafEmpty() {
        if (matrix.length == 0 || matrix[0].length == 0) return true;
        return false;
    }

    public boolean isConnected() {
        boolean[] visited = new boolean[size];
        dfs(0, visited);

        for (boolean v : visited) {
            if (!v) return false;
        }
        return true;
    }

    private void dfs(int v, boolean[] visited) {
        visited[v] = true;
        for (int i = 0; i < size; i++) {
            if (matrix[v][i] != 0 && matrix[v][i] != Integer.MAX_VALUE && !visited[i]) {
                dfs(i, visited);
            }
        }
    }
}

