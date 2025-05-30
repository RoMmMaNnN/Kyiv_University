#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    int startX, startY;
    int endX, endY;
    char piece;
} LastMove;

LastMove lastMove = {-1, -1, -1, -1, '_'};

char board[8][8] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'_', '_', '_', '_', '_', '_', '_', '_'},
    {'_', '_', '_', '_', '_', '_', '_', '_'},
    {'_', '_', '_', '_', '_', '_', '_', '_'},
    {'_', '_', '_', '_', '_', '_', '_', '_'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

int count = 0;

void printChessBoard();
void whiteOrBlack();
void clearBuffer();
bool isPathClear(int x1, int y1, int x2, int y2);
bool isValidMove(int x1, int y1, int x2, int y2);
bool isWhitePiece(char piece);
bool isBlackPiece(char piece);
void pieceMove(int x1, int y1, int x2, int y2);
void choicePiece(int* x, int* y);
void choicePlace(int* x, int* y);
bool isEnPassant(int x1, int y1, int x2, int y2);
void performEnPassant(int x1, int y1, int x2, int y2);
void updateLastMove(int x1, int y1, int x2, int y2);
bool isCastling(int x1, int y1, int x2, int y2);
void performCastling(int x1, int y1, int x2, int y2);
bool isPromotion(int x2);
void performPromotion(int x2, int y2);
void doMove();
void printMove(int x1, int y1, int x2, int y2);

int main() {
    while(1) {
        printChessBoard();
        whiteOrBlack();
        doMove();
    }
    return 0;
}

void printChessBoard(char* arr) {
    printf("\n  ");
    for (int k = 0; k < 8; k++) {
        printf("%d\t", k + 1);
    }

    for (int i = 0; i < 8; i++) {
        printf("\n%d ", i + 1);
        for (int j = 0; j < 8; j++) {
            printf("%c\t", board[i][j]);
        }
    }
    printf("\n\n");
}

void whiteOrBlack() {
    if (count % 2 == 0) printf("\nMoving WHITE:\n");
    if (count % 2 == 1) printf("\nMoving BLACK:\n");
    count++;
}

void updateLastMove(int x1, int y1, int x2, int y2) {
    lastMove.startX = x1;
    lastMove.startY = y1;
    lastMove.endX = x2;
    lastMove.endY = y2;
    lastMove.piece = board[x2][y2];
}

void clearBuffer() {
    while (getchar() != '\n');
}

bool isWhitePiece(char piece) {
    return islower(piece);
}

bool isBlackPiece(char piece) {
    return isupper(piece);
}

bool isPathClear(int x1, int y1, int x2, int y2) {
    int dx = (x2 - x1) == 0 ? 0 : (x2 - x1) / abs(x2 - x1);
    int dy = (y2 - y1) == 0 ? 0 : (y2 - y1) / abs(y2 - y1);
    int i = x1 + dx, j = y1 + dy;

    while (i != x2 || j != y2) {
        if (board[i][j] != '_') {
            return false;
        }
        i += dx;
        j += dy;
    }
    return true;
}

bool isValidMove(int x1, int y1, int x2, int y2) {
    bool validColor = (count % 2 == 0);
    char piece = board[x1][y1];
    char target = board[x2][y2];

    if (isWhitePiece(piece) && isWhitePiece(target)) return false;
    if (isBlackPiece(piece) && isBlackPiece(target)) return false;
    if (isWhitePiece(piece) != validColor) return false;
    if (piece == '_') return false;

    switch (toupper(piece)) {
        case 'P': {
            int direction1 = isWhitePiece(piece) ? 1 : -1;
            int direction2 = isWhitePiece(piece) ? 2 : -2;
            if (x2 == x1 + direction1 && y2 == y1 && target == '_') return true;
            if (x2 == x1 + direction1 && abs(y2 - y1) == 1 && target != '_') return true;
            if (x2 == x1 + direction2 && y2 == y1 && target == '_') return true;
            if (x2 == x1 + direction2 && abs(y2 - y1) == 1 && target != '_') return true;
            break;
        }
        case 'R':
            if (x1 == x2 && y1 != y2) return isPathClear(x1, y1, x2, y2);
            if (x1 != x2 && y1 == y2) return isPathClear(x1, y1, x2, y2);
            break;
        case 'N':
            if ((abs(x1 - x2) == 2 && abs(y1 - y2) == 1) || (abs(x1 - x2) == 1 && abs(y1 - y2) == 2)) return true;
            break;
        case 'B':
            if (abs(x1 - x2) == abs(y1 - y2)) return isPathClear(x1, y1, x2, y2);
            break;
        case 'Q':
            if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2)) return isPathClear(x1, y1, x2, y2);
            break;
        case 'K':
            if (abs(x1 - x2) <= 1 && abs(y1 - y2) <= 1) return true;
            break;
    }
    return false;
}

bool isEnPassant(int x1, int y1, int x2, int y2) {
    if (toupper(lastMove.piece) == 'P' &&
        abs(lastMove.startX - lastMove.endX) == 2 &&
        lastMove.endX == x1 &&
        abs(lastMove.endY - y2) == 1 &&
        board[x1][y1] == 'P' &&
        board[lastMove.endX][lastMove.endY] == '_') {
        return true;
    }
    return false;
}

void performEnPassant(int x1, int y1, int x2, int y2) {
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = '_'; 
    board[lastMove.endX][lastMove.endY] = '_';
}

bool isCastling(int x1, int y1, int x2, int y2) {
    if (toupper(board[x1][y1]) != 'K' || abs(y2 - y1) != 2) return false;
    int row = x1;
    int colRook = y2 > y1 ? 7 : 0;
    if (board[row][colRook] != 'R' && board[row][colRook] != 'r') return false;
    return isPathClear(row, y1, row, colRook);
}

void performCastling(int x1, int y1, int x2, int y2) {
    int row = x1;
    int colKing = y2 > y1 ? y1 + 2 : y1 - 2;
    int colRook = y2 > y1 ? 7 : 0;
    int newRookCol = y2 > y1 ? colKing - 1 : colKing + 1;

    board[row][colKing] = board[x1][y1];
    board[row][newRookCol] = board[row][colRook];
    board[x1][y1] = '_';
    board[row][colRook] = '_';
}

bool isPromotion(int x2) {
    return x2 == 0 || x2 == 7;
}

void performPromotion(int x2, int y2) {
    char choice;
    do {
        printf("Promote pawn to (Q, R, B, N): ");
        scanf(" %c", &choice);
        choice = toupper(choice);
    } while (choice != 'Q' && choice != 'R' && choice != 'B' && choice != 'N');
    board[x2][y2] = isWhitePiece(board[x2][y2]) ? choice : choice + 32;
}

void getValidCoordinate(int* x, int* y) {
    while (scanf("%d %d", x, y) != 2 || *x < 1 || *x > 8 || *y < 1 || *y > 8) {
        clearBuffer();
        if (*x < 1 || *x > 8 || *y < 1 || *y > 8) printf("Invalid input. Coordinates must be between 1 and 8. Try again: ");
    }
    clearBuffer();
    --(*x);
    --(*y);
}

void choicePiece(int* x, int* y) {
    printf("Enter the correct coordinates of the piece (row and column) to move: ");
    getValidCoordinate(x, y);
}

void choicePlace(int* x, int* y) {
    printf("Enter the correct coordinates of the destination (row and column): ");
    getValidCoordinate(x, y);
}

void pieceMove(int x1, int y1, int x2, int y2) {
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = '_';
}

void doMove() {
    int x1, y1, x2, y2;
    
    do {
        choicePiece(&x1, &y1);
        choicePlace(&x2, &y2);
        if (isEnPassant(x1, y1, x2, y2)) {
            performEnPassant(x1, y1, x2, y2);
            updateLastMove(x1, y1, x2, y2);
            return;
        }
    } while (!isValidMove(x1, y1, x2, y2));

    pieceMove(x1, y1, x2, y2);
    if (toupper(board[x2][y2]) == 'P' && isPromotion(x2)) {
        performPromotion(x2, y2);
    }
    updateLastMove(x1, y1, x2, y2);
    printMove(x1, y1, x2, y2);
}

void printMove(int x1, int y1, int x2, int y2) {
    printf("Trying to move piece from (%d, %d) to (%d, %d)\n", x1 + 1, y1 + 1, x2 + 1, y2 + 1);
}
