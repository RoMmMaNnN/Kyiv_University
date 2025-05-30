#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ----- Коди для стилізації виводу -----
#define RESET "\033[0m"
#define FONT_GREEN "\033[32m"
#define FONT_RED "\033[31m"
#define FONT_YELLOW "\033[33m"          // Жовтий 
#define FONT_WHITE "\033[97m"           // Білий
#define FONT_BLACK "\033[90m"           // Чорний (світліша версія)
#define BG_WHITE "\033[46m"             // ціановий 
#define BG_BLACK "\033[44m"             // темно-синій
#define BG_MAGENTA "\033[45m"
#define BG_BRIGHT_MAGENTA "\033[105m"
#define BG_GREEN "\033[42m"
#define BG_BRIGHT_GREEN "\033[102m"
#define BG_RED "\033[41m"
#define BG_BRIGHT_RED "\033[101m"
#define BOLD "\033[1m"
#define RESET_BOLD "\033[22m"
#define ITALIC "\033[3m"
#define RESET_ITALIC "\033[23m"
// ------ Коди для очищення консолі ------
#define CONS_ERASE "\033[2J" 
#define CONS_ERASE_LINE "\033[2K"
#define CONS_ERASE_CURSOR_TO_END "\033[0J"
#define CONS_ERASE_CURSOR_LINE "\033[0K"
// ---- Коди для маніпуляцій курсором ----
#define CURSOR_SAVE "\033[s"
#define CURSOR_RESTORE "\033[u"
#define CURSOR_HOME "\033[H"
#define CURSOR_DOWN(num) "\033[" #num "B"
#define CURSOR_LEFT(num) "\033[" #num "D"
// ------- Коди символів для рамок -------
#define BORDER_TL "\u2554"          // top-left вугол рамки
#define BORDER_TR "\u2557"          // top-right вугол рамки
#define BORDER_BL "\u255A"          // bottom-left вугол рамки
#define BORDER_BR "\u255D"          // bottom-right вугол рамки
#define BORDER_HORIZ "\u2550"       // ═
#define BORDER_VERT "\u2551"        // ║
#define BORDER_CROSSED "\u256C"     //  ╬
#define BORDER_VERT_R "\u2560"     // ╠  
#define BORDER_VERT_L "\u2563"      // ╣
#define BORDER_HORIZ_B "\u2566"     // ╦ 
#define BORDER_HORIZ_T "\u2569"     // ╩
// ------- Різні фіксовані розміри -------
#define ROWS 8
#define COLS 8
#define MAX_CODE_LEN 16
#define MAX_COMMAND_LEN 6 // + '\0'
#define BOARD_END_LINE 25 // Рядок, на якому останній рядок дошки
// змінні для пошуку потрібної клітинки (відлік починається зверху та зліва)
// Вони вказують на першу клітинку на ігровій дошці
#define LINES_FROM_TOP 10
#define COLS_FROM_LEFT 5
// відстань, після якої зустріниться початок наступної клітинки
#define SQUARE_X_GAP 5 
#define SQUARE_Y_GAP 2 
// sidebar
#define SIDEBAR_LEFT_POS COLS_FROM_LEFT + SQUARE_X_GAP * (COLS + 1)
#define SIDEBAR_WIDTH 32

#define COL_CHAR(col) 'a' + col
#define ROW_CHAR(row) '1' + row

// ---------------- Шахи ----------------
typedef enum {
    KING = 200,
    QUEEN = 9,
    ROOK = 5,
    BISHOP = 4,
    KNIGHT = 3,
    PAWN = 1,
} ChessPiece; // b)

typedef enum {
    WHITE, 
    BLACK
} Colour;

typedef struct {
    int row;
    int col;
} Coordinates;

typedef struct {
    ChessPiece piece;
    Colour colour;
    int first_move;
    Coordinates coord;
} Piece;

typedef Piece *Board[ROWS][COLS]; // матриця з поінтерів на фігури

typedef struct {
    Board board;
    Colour current_side;
    Piece *white_king;
    Piece *black_king;
    int is_check;
} GameData;
// ---------- Динамічний масив ----------
// динамічний масив для координат
typedef struct {
    unsigned int length;
    unsigned int current_max;
    Coordinates *arr;
} ArrayList;

// --------------------------------------
typedef enum {
    ERR,
    SHOW_MOVES,
    MOVE,
    RESTART,
    QUIT,
} Action;

// ------------------------------ Moves ------------------------------
// 1) Функції з дописом _move не переставляють фігури, а повертають int:
// 1, якщо можуть походити на цю клітинку;
// 0, якщо не можуть походити на цю клітинку.
// move_piece пересовує фігури, якщо це можливо.
// 2) move_piece: move_to & write_possibles опціональні параметри, поінтер на координати та массив координат.
// Можна передавати NULL Замість них. Записує всі можливі ходи, якщо переданий масив координат;
// повертає 1, якщо на передані координати можна перемістити цю фігуру, інакше - 0.
int king_move(GameData *game, Coordinates *from, Coordinates *move_to, ArrayList *write_possibles);
int queen_move(GameData *game, Coordinates *from, Coordinates *move_to, ArrayList *write_possibles);
int rook_move(GameData *game, Coordinates *from, Coordinates *move_to, ArrayList *write_possibles);
int bishop_move(GameData *game, Coordinates *from, Coordinates *move_to, ArrayList *write_possibles);
int knight_move(GameData *game, Coordinates *from, Coordinates *move_to, ArrayList *write_possibles);
int pawn_move(GameData *game, Coordinates *from, Coordinates *move_to, ArrayList *write_possibles);
int move_piece(GameData *game, Coordinates *from, Coordinates *move_to, ArrayList *write_possibles);
int is_in_range(int row, int col);
int exclude_check_moves(GameData *game, Piece *piece, ArrayList *moves);
int is_under_check(GameData *game);
// ---------------------------- Array list ----------------------------
ArrayList *new_list();
Coordinates *list_at(ArrayList *list, int idx);
int list_push(ArrayList *list, Coordinates coord);
int list_remove_at(ArrayList *list, int idx);
int list_empty(ArrayList *list);
int list_contains(ArrayList *list, Coordinates *p_coord);
void free_list(ArrayList *list);
// ---------------------------- User input ----------------------------
Action read_input(GameData *game, Coordinates *from, Coordinates *to);
// поверне 1, якщо зустрівся спец. символ і варто вивести дошку повторно
int clear_input();
// ------------------------------ Output ------------------------------
void print_square(GameData *p_game, Coordinates *p_coords, char *white_bg, char *black_bg);
void display_board(GameData *p_game);
void rerender(GameData *p_game);
void display_piece(Piece *p_piece);
void clear_console();
void print_error(char *str);
void board_update_move(GameData *game, Coordinates *from, Coordinates *to);
void board_add_marks(GameData *game, Coordinates *active_coord, ArrayList *squares);
void board_remove_marks(GameData *game, ArrayList *squares);
void board_add_check_mark(GameData *game);
void board_remove_check_mark(GameData *game);
void sidebar_display();
void sidebar_current_turn(Colour current_side);
void move_cursor_to(int line, int row);
// ------------------------------ Utils -------------------------------
void init_game(GameData *p_game);
Piece *new_piece(ChessPiece piece, Colour colour, int start_row, int start_col);
void free_board(GameData *p_game);

int main(void) {
    // const int piece_value[] = {200, 9, 5, 3, 3, 1}; // a)
    GameData game;
    ArrayList *available_moves = NULL;
    init_game(&game);
    rerender(&game);

    while (1) {
        Coordinates from, to;
        printf("Enter command -> " BOLD);
        Action action = read_input(&game, &from, &to);
        move_cursor_to(BOARD_END_LINE + 2, 1);
        printf(CONS_ERASE_CURSOR_TO_END RESET);

        // прибрати мітки з дошки та очистити пам'ять після використаного масиву
        if (available_moves) {
            board_remove_marks(&game, available_moves);
            free(available_moves);
            available_moves = NULL;
        }

        // Якщо королю шах - додати помітку
        board_add_check_mark(&game);

        Piece *piece;
        switch (action) {
            case ERR:
                print_error("Invalid input! Try again.");
                break;
            
            case QUIT:
                return 0;
            
            case RESTART:
                // Очистимо виділену для фігур пам'ять перед тим, як створити нову гру
                free_board(&game);    
                init_game(&game);
                rerender(&game);
                break;
            
            case SHOW_MOVES:
                piece = game.board[from.row][from.col];
                if (!piece) {
                    print_error("Invalid move! No piece on the square.");
                    break;
                }
                if (piece->colour != game.current_side) {
                    print_error("Invalid move! Other team's turn.");
                    break;
                }
                
                available_moves = new_list();
                move_piece(&game, &from, NULL, available_moves);
                printf(
                        FONT_GREEN ITALIC BOLD "%c%c" RESET_BOLD " can move to: " BOLD,
                        COL_CHAR(from.col),
                        ROW_CHAR(from.row)
                      );

                if (available_moves->length == 0) {
                    printf(FONT_YELLOW "No available moves.\n" RESET);
                } else {
                    for (int i = 0; i < available_moves->length; i++) {
                        Coordinates *coord = available_moves->arr + i;
                        printf(
                                BOLD "%c%c" RESET_BOLD,
                                COL_CHAR(coord->col), 
                                ROW_CHAR(coord->row)
                              );

                        if(i != available_moves->length - 1) {
                            printf(", ");
                        }
                    }
                    printf(RESET "\n");
                }

                board_add_marks(&game, &from, available_moves);
                // під кінець, використаємо цей динамічний масив, як масив помічених клітинок
                list_push(available_moves, from);

                break;

            case MOVE:
                piece = game.board[from.row][from.col];
                if (!piece) {
                    print_error("Invalid move! No piece on the square.");
                    break;
                }
                if (piece->colour != game.current_side) {
                    print_error("Invalid move! Other team's turn.");
                    break;
                }

                int can_move = move_piece(&game, &from, &to, NULL);
                if (!can_move) {
                    print_error("Invalid move! Can not make this move.");
                    break;
                }

                board_update_move(&game, &from, &to);
                sidebar_current_turn(game.current_side);
                board_remove_check_mark(&game);
                break;
        }
       
    }
    
    return 0;
}

// ------------------------------ Moves ------------------------------
int king_move(GameData *game, Coordinates *from, Coordinates *move_to, ArrayList *write_possibles) {
    if (!write_possibles) {
        return 0;
    }

    Piece *piece = game->board[from->row][from->col];
    for (int row_offset = -1; row_offset <= 1; row_offset++) {
        for (int col_offset = -1; col_offset <= 1; col_offset++) {
            if (row_offset == 0 && col_offset == 0) continue;
            
            int row = piece->coord.row + row_offset;
            int col = piece->coord.col + col_offset;
            if (is_in_range(row, col)) {
                Piece *piece_on_square = game->board[row][col];
                if (!piece_on_square || piece->colour != piece_on_square->colour) {
                    list_push(write_possibles, (Coordinates){row, col});
                }
            }
        }
    }

    int can_move = list_contains(write_possibles, move_to);
    return can_move;
}

int queen_move(GameData *game, Coordinates *from, Coordinates *move_to, ArrayList *write_possibles) {
    if (!write_possibles) {
        return 0;
    }

    Piece *piece = game->board[from->row][from->col];
    for (int x_dir = -1; x_dir <= 1; x_dir++) {
        for (int y_dir = -1; y_dir <= 1; y_dir++) {
            if (x_dir == 0 && y_dir == 0) continue;

            int row = piece->coord.row + y_dir;
            int col = piece->coord.col + x_dir;
            while (is_in_range(row, col)) {
                Piece *piece_on_square = game->board[row][col]; 
                if (piece_on_square) {
                    if (piece_on_square->colour != piece->colour) {
                        list_push(write_possibles, (Coordinates){row, col});
                    }
                    break;
                }

                list_push(write_possibles, (Coordinates){row, col});
                row += y_dir;
                col += x_dir;
            }
        }
    }

    int can_move = list_contains(write_possibles, move_to);
    return can_move;
}

int rook_move(GameData *game, Coordinates *from, Coordinates *move_to, ArrayList *write_possibles) {
    if (!write_possibles) {
        return 0;
    }
    
    Piece *piece = game->board[from->row][from->col];
    for (int x_dir = -1; x_dir <= 1; x_dir++) {
        if (x_dir == 0) continue;
        
        int row = piece->coord.row;
        int col = piece->coord.col + x_dir;
        while (is_in_range(row, col)) {
            Piece *piece_on_square = game->board[row][col]; 
            if (piece_on_square) {
                if (piece_on_square->colour != piece->colour) {
                    list_push(write_possibles, (Coordinates){row, col});
                }
                break;
            }
         
            list_push(write_possibles, (Coordinates){row, col});
            col += x_dir;
        }
    }

    for (int y_dir = -1; y_dir <= 1; y_dir++) {
        if (y_dir == 0) continue;
        
        int row = piece->coord.row + y_dir;
        int col = piece->coord.col;
        while (is_in_range(row, col)) {
            Piece *piece_on_square = game->board[row][col]; 
            if (piece_on_square) {
                if (piece_on_square->colour != piece->colour) {
                    list_push(write_possibles, (Coordinates){row, col});
                }
                break;
            }

            list_push(write_possibles, (Coordinates){row, col});
            row += y_dir;
        }
    }

    int can_move = list_contains(write_possibles, move_to);
    return can_move;
}

int bishop_move(GameData *game, Coordinates *from, Coordinates *move_to, ArrayList *write_possibles) {
    if (!write_possibles) {
        return 0;
    }
    
    Piece *piece = game->board[from->row][from->col];
    for (int x_dir = -1; x_dir <= 1; x_dir++) {
        if (x_dir == 0) continue;
        
        for (int y_dir = -1; y_dir <= 1; y_dir++) {
            if (y_dir == 0) continue;

            int row = piece->coord.row + y_dir;
            int col = piece->coord.col + x_dir;
            while (is_in_range(row, col)) {
                Piece *piece_on_square = game->board[row][col]; 
                if (piece_on_square) {
                    if (piece_on_square->colour != piece->colour) {
                        list_push(write_possibles, (Coordinates){row, col});
                    }
                    break;
                }

                list_push(write_possibles, (Coordinates){row, col});
                row += y_dir;
                col += x_dir;
            }
        }
    }

    int can_move = list_contains(write_possibles, move_to);
    return can_move;
}

int knight_move(GameData *game, Coordinates *from, Coordinates *move_to, ArrayList *write_possibles) {
    if (!write_possibles) {
        return 0;
    }
    
    Piece *piece = game->board[from->row][from->col];
    for (int x_dir = -1; x_dir <= 1; x_dir++) {
        if (x_dir == 0) continue;
        
        for (int y_dir = -1; y_dir <= 1; y_dir++) {
            if (y_dir == 0) continue;

            int row = piece->coord.row;
            int col = piece->coord.col;

            Coordinates square1 = {row + 1 * y_dir, col + 2 * x_dir};
            Coordinates square2 = {row + 2 * y_dir, col + 1 * x_dir};
            if (is_in_range(square1.row, square1.col)) {
                Piece *piece_on_square = game->board[square1.row][square1.col]; 
                if (!piece_on_square || piece_on_square->colour != piece->colour) {
                    list_push(write_possibles, square1);
                }
            }
            if (is_in_range(square2.row, square2.col)) {
                Piece *piece_on_square = game->board[square2.row][square2.col]; 
                if (!piece_on_square || piece_on_square->colour != piece->colour) {
                    list_push(write_possibles, square2);
                }
            }
        }
    }
 
    int can_move = list_contains(write_possibles, move_to);
    return can_move;
}

int pawn_move(GameData *game, Coordinates *from, Coordinates *move_to, ArrayList *write_possibles) {
    if (!write_possibles) {
        return 0;
    }
    
    Piece *piece = game->board[from->row][from->col];
    int direction = piece->colour == WHITE ? -1 : 1;
    int row = piece->coord.row + direction; // перевірка передніх клітинок
    int col = piece->coord.col;
 
    if (!is_in_range(row, col)) {
        return 0;
    }

    // перевірка чи можна побити ворожі фігури
    for (int i = -1; i <= 1; i++) {
        if (i == 0) continue;

        if (is_in_range(row, col - i) ) {
            Piece *piece_on_square = game->board[row][col - i];
            if (piece_on_square && piece_on_square->colour != piece->colour) {
                list_push(write_possibles, (Coordinates){row, col - i});   
            }
        }
    }

    // клітинка попереду
    if (!game->board[row][col]) {
        list_push(write_possibles, (Coordinates){row, col});

        // якщо перший хід 
        if (
            piece->first_move &&
            is_in_range(row + direction, col) && 
            !game->board[row + direction][col]
        ) {
            list_push(write_possibles, (Coordinates){row + direction, col});
        }
    }
    
    int can_move = list_contains(write_possibles, move_to);
    return can_move;
}

int move_piece(GameData *game, Coordinates *from, Coordinates *move_to, ArrayList *write_possibles) {
    int can_move = 0;
    int is_writing = 1;
 
    Piece *piece = game->board[from->row][from->col];
    if (!piece && piece->colour != game->current_side) {
        return 0;
    }
    
    if (!write_possibles) {
        is_writing = 0;
        write_possibles = new_list();
    }
 
    switch (piece->piece) { 
        case KING:
            can_move = king_move(game, from, move_to, write_possibles);
            break;
        case QUEEN:
            can_move = queen_move(game, from, move_to, write_possibles);
            break;
        case ROOK:
            can_move = rook_move(game, from, move_to, write_possibles);
            break;
        case BISHOP:
            can_move = bishop_move(game, from, move_to, write_possibles);
            break;
        case KNIGHT:
            can_move = knight_move(game, from, move_to, write_possibles);
            break;
        case PAWN:
            can_move = pawn_move(game, from, move_to, write_possibles);
            break;
    }

    // виключимо всі ходи, при яких королю відкриється шах
    exclude_check_moves(game, piece, write_possibles);
    if (!list_contains(write_possibles, move_to)) {
        return 0;
    }

    if (!is_writing) {
        free(write_possibles);
    }


    if (!can_move) {
        return 0;
    }
    
    int row = move_to->row;
    int col = move_to->col;
    
    // якщо на клітинці знаходиться інша фігура, то її б'ють
    // (вона буде точно іншого кольору, бо функції вище повернули б 0)
    if (game->board[row][col]) {
        free(game->board[row][col]);
    }

    game->board[row][col] = piece;
    game->board[piece->coord.row][piece->coord.col] = NULL;
    piece->coord.row = row;
    piece->coord.col = col;

    piece->first_move = 0;
    game->current_side = game->current_side == WHITE ? BLACK : WHITE;

    return 1;
} 

int is_in_range(int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS;
}

int exclude_check_moves(GameData *game, Piece *piece, ArrayList *moves) {
    // імітуємо атаки фігур для короля. Якщо під клітинку, де є фігура, попадеться власник цього руху,
    // тоді король під шахом на цій клітині
    ArrayList *danger_moves = new_list();
    Piece *king = 
        piece->colour == WHITE ? game->white_king : game->black_king;

    // щоб не повторювати код, викличемо кожну функцію за допомогою циклу
    const int fun_num = 6;
    int (*move_funcs[])(GameData *, Coordinates *, Coordinates *, ArrayList *) = {
        king_move,
        queen_move,
        rook_move,
        bishop_move,
        knight_move,
        pawn_move
    };
    const ChessPiece move_owners[] = {
        KING,
        QUEEN,
        ROOK,
        BISHOP,
        KNIGHT,
        PAWN
    };

    // Якщо перевіряємо короля, то потрібно буде оновлювати дані де він зараз знаходиться на дошці,
    // тому початкові дані потрібно запам'ятати
    Coordinates king_start_coords = king->coord; 

    // переставимо фігуру у клітинку, яку потрібно перевірити, для імітації атак короля
    int start_row = piece->coord.row;
    int start_col = piece->coord.col;
    game->board[start_row][start_col] = NULL;

    for (int i = moves->length - 1; i >= 0; i--) {
        int row = moves->arr[i].row;
        int col = moves->arr[i].col;
        Piece *temp = game->board[row][col]; // якщо є якась фігура, то потрібно зберегти її 
        game->board[row][col] = piece;

        for (int j = 0; j < fun_num; j++) {
            if (piece == king) {
                king->coord.row = row;
                king->coord.col = col;
            }

            move_funcs[j](game, &king->coord, NULL, danger_moves);
            int is_check = 0;

            for (int k = 0; k < danger_moves->length; k++) {
                int row = danger_moves->arr[k].row;
                int col = danger_moves->arr[k].col;
                Piece *piece_on_square = game->board[row][col];
                if (
                    piece_on_square && 
                    piece_on_square->piece == move_owners[j] &&
                    piece_on_square->colour != king->colour
                ) {
                    is_check = 1;
                    list_remove_at(moves, i);
                    break;
                }
            }
        
            list_empty(danger_moves);
            if (is_check) {
                break;
            }
        }

        game->board[row][col] = temp;
    }

    king->coord = king_start_coords;
    game->board[start_row][start_col] = piece;
    free_list(danger_moves);
    return 0;
}

int is_under_check(GameData *game) {
    const int fun_num = 6;
    int (*move_funcs[])(GameData *, Coordinates *, Coordinates *, ArrayList *) = {
        king_move,
        queen_move,
        rook_move,
        bishop_move,
        knight_move,
        pawn_move
    };
    const ChessPiece move_owners[] = {
        KING,
        QUEEN,
        ROOK,
        BISHOP,
        KNIGHT,
        PAWN
    };

    ArrayList *moves = new_list();
    Piece *king = 
        game->current_side == WHITE ? game->white_king : game->black_king;
   
    for (int i = 0; i < fun_num; i++) {
        move_funcs[i](game, &king->coord, NULL, moves);
        for (int j = 0; j < moves->length; j++) {
            int row = moves->arr[j].row;
            int col = moves->arr[j].col;
            Piece *piece_on_square = game->board[row][col];
            if (
                    piece_on_square && 
                    piece_on_square->piece == move_owners[i] &&
                    piece_on_square->colour != king->colour
               ) {
                return 1;
            }
        }

        list_empty(moves);
    }

    free_list(moves);
    return 0;
}
// ---------------------------- Array list ----------------------------
ArrayList *new_list() {
    const unsigned int initial_size = 4;
    ArrayList *list = malloc(sizeof(ArrayList));
    if (!list) {
        return NULL;
    }

    list->length = 0;
    list->current_max = initial_size;
    list->arr = calloc(initial_size, sizeof(Coordinates));

    return list;
}

Coordinates *list_at(ArrayList *list, int idx) {
    if (idx < 0 || idx >= list->length) {
        return NULL;
    }

    return list->arr + idx;
}

int list_push(ArrayList *list, Coordinates coord) {
    if (list->length == list->current_max) {
        list->current_max *= 2;
        list->arr = realloc(list->arr, list->current_max * sizeof(Coordinates));

        if (!list->arr) {
            return 0;
        } 
    }

    list->arr[list->length] = coord;
    list->length++;

    return 1;
}

int list_remove_at(ArrayList *list, int idx) {
    if (idx < 0 || idx >= list->length) {
        return 0;
    }

    list->length--;
    if (idx == list->length) {
        return 1;
    }

    for (int i = idx; i < list->length; i++) {
        list->arr[i] = list->arr[i + 1];
    }

    return 1;
}

int list_empty(ArrayList *list) {
    for (int i = list->length - 1; i >= 0; i--) {
        int is_success = list_remove_at(list, i);
        if (!is_success) {
            return 0;
        }
    }

    return 1;
}

int list_contains(ArrayList *list, Coordinates *p_coord) {
    if (!p_coord) {
        return 0;
    }

    Coordinates *arr = list->arr;
    for (int i = 0; i < list->length; i++) {
        if (arr[i].row == p_coord->row && arr[i].col == p_coord->col) {
            return 1;
        }
    }

    return 0;
}

void free_list(ArrayList *list) {
    free(list->arr);
    free(list);
}
// ---------------------------- User input ----------------------------
Action read_input(GameData *p_game, Coordinates *from, Coordinates *to) {
    unsigned char read_str[MAX_COMMAND_LEN] = {'\0'};
    
    int length = 0;
    while (length < MAX_COMMAND_LEN - 1) {
        char ch = getchar();
        if (ch == '\n') {
            break;
        }
        if (!isprint(ch)) {
            int is_rerender = clear_input();
            if (is_rerender || ch == '\033') {
                rerender(p_game);
            }

            return ERR;
        }

        read_str[length] = ch;
        length++;
    }
    if (length == 5) {
        int is_rerender = clear_input();
        if (is_rerender) rerender(p_game);
    }

    // точно не правильний ввід
    if (length == 0 || length == 4) {
        return ERR;
    }

    if (length == 1) {
        switch (read_str[0]) {
            case 'q':
                return QUIT;
            case 'r':
                return RESTART;
            default:
                return ERR;
        }
    }

    // 3й символ, якщо є, має бути пробільним
    if (length > 2 && !isspace(read_str[2])) {
        return ERR;
    }
    
    from->col = read_str[0] - 'a';
    from->row = read_str[1] - '1';
    if (!is_in_range(from->row, from->col)) {
        return ERR;
    }

    if (length == 5) {
        to->col = read_str[3] - 'a';
        to->row = read_str[4] - '1';
        if (!is_in_range(to->row, to->col)) {
            return ERR;
        }

        return MOVE;
    }

    return SHOW_MOVES;
}

int clear_input() {
    // якщо наявний символ '\033', то, скоріш за все, варто заново вивести дошку 
    int is_special_key = 0;
    
    char ch;
    while ((ch = getchar()) != '\n') {
        if (ch == '\033') {
            is_special_key = 1;
        } 
    }
    
    return is_special_key;
}
// ------------------------------ Output ------------------------------
void print_square(GameData *p_game, Coordinates *p_coords, char *white_bg, char *black_bg) {
    // колір клітинки
    int row = p_coords->row;
    int col = p_coords->col;

    if ((row + col) % 2 == 0) { // Біла клітинка
        printf("%s", white_bg);
    } else {
        printf("%s", black_bg);
    }

    Piece *p_piece = p_game->board[row][col];
    display_piece(p_piece);
    printf("%s║", RESET FONT_YELLOW);   
}

void board_horiz_border(char *left, char *right, char *split_ch) {
    printf("═══%s", left);

    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < SQUARE_X_GAP - 1; j++) {
            printf("%s", BORDER_HORIZ);
        }
        
        if (i != COLS - 1) {
            printf("%s", split_ch);
        }
    }

    printf("%s\n", right);
}
void display_board(GameData *p_game) {
    // підказки
    puts(FONT_YELLOW "=================== Hints ===================");
    printf("[%scoord1 coord2%s] - move from sqr1 to sqr2;\n", BOLD, RESET_BOLD);
    printf("[%scoord1%s] - show all moves for piece;\n", BOLD, RESET_BOLD);
    printf("[%sr%s] - restart game;\n", BOLD, RESET_BOLD);
    printf("[%sq%s] - quit;\n", BOLD, RESET_BOLD);
    printf("%s\n\n", "=============================================");

    puts(FONT_YELLOW "   ║  a ║  b ║  c ║  d ║  e ║  f ║  g ║  h ║");
    board_horiz_border(BORDER_CROSSED, BORDER_VERT_L, BORDER_CROSSED);

    for (int row = 0; row < ROWS; row++) {
        printf(" %d ║", row + 1);

        for (int col = 0; col < COLS; col++) {
            print_square(p_game, &(Coordinates){row, col}, BG_WHITE, BG_BLACK);
        }
        
        putchar('\n');
     
        if (row != ROWS - 1) {
            board_horiz_border(BORDER_CROSSED, BORDER_VERT_L, BORDER_CROSSED);
        }
    }

    board_horiz_border(BORDER_HORIZ_T, BORDER_BR, BORDER_HORIZ_T);
    printf(RESET "\n");
}

void rerender(GameData *p_game) {
    printf(RESET);
    clear_console();
    display_board(p_game);
    sidebar_display();
    sidebar_current_turn(p_game->current_side);
}

void display_piece(Piece *p_piece) {
    if (!p_piece) {
        printf("    ");
        return;
    }

    // Колір фігури
    if (p_piece->colour == WHITE) {
        printf(FONT_WHITE BOLD);
    } else {
        printf(FONT_BLACK BOLD);
    }

    switch (p_piece->piece) { 
        case KING:
            printf(" Kg ");
            break;
        case QUEEN:
            printf(" Qn ");
            break;
        case ROOK:
            printf(" Rk ");
            break;
        case BISHOP:
            printf(" Bs ");
            break;
        case KNIGHT:
            printf(" Kn ");
            break;
        case PAWN:
            printf(" Pw ");
            break;
        default:
            printf(" ?? ");
            break;
    }
}

void clear_console() {
    printf(CONS_ERASE "\033[1J" CURSOR_HOME);
}

void print_error(char *str) {
    printf(FONT_RED BOLD ITALIC "%s\n" RESET, str);
}

void board_update_move(GameData *game, Coordinates *from, Coordinates *to) {
    printf(CURSOR_SAVE);

    int line1 = LINES_FROM_TOP + SQUARE_Y_GAP * from->row;
    int col1 = COLS_FROM_LEFT + SQUARE_X_GAP * from->col;
    move_cursor_to(line1, col1);
    print_square(game, from, BG_WHITE, BG_BLACK);
    
    int line2 = LINES_FROM_TOP + SQUARE_Y_GAP * to->row;
    int col2 = COLS_FROM_LEFT + SQUARE_X_GAP * to->col;
    move_cursor_to(line2, col2);
    print_square(game, to, BG_WHITE, BG_BLACK);

    printf(CURSOR_RESTORE RESET);
}

void board_add_marks(GameData *game, Coordinates *active_coord, ArrayList *squares) {
    printf(CURSOR_SAVE);
    
    int active_line = LINES_FROM_TOP + SQUARE_Y_GAP * active_coord->row;
    int active_col = COLS_FROM_LEFT + SQUARE_X_GAP * active_coord->col;
    move_cursor_to(active_line, active_col);
    print_square(game, active_coord, BG_BRIGHT_GREEN, BG_GREEN);
    
    for (int i = 0; i < squares->length; i++) {
        Coordinates *coord = squares->arr + i;
        int line = LINES_FROM_TOP + SQUARE_Y_GAP * coord->row;
        int col = COLS_FROM_LEFT + SQUARE_X_GAP * coord->col;
        move_cursor_to(line, col);
        print_square(game, coord, BG_BRIGHT_MAGENTA, BG_MAGENTA);
    }

    printf(CURSOR_RESTORE RESET);
}

void board_remove_marks(GameData *game, ArrayList *squares) {
    printf(CURSOR_SAVE);

    for (int i = 0; i < squares->length; i++) {
        Coordinates *coord = squares->arr + i;
        int line = LINES_FROM_TOP + SQUARE_Y_GAP * coord->row;
        int col = COLS_FROM_LEFT + SQUARE_X_GAP * coord->col;
        move_cursor_to(line, col);
        print_square(game, coord, BG_WHITE, BG_BLACK);
    }

    printf(CURSOR_RESTORE RESET);
    
    // Якщо був шах і було замінено мітку - повернути мітку
    board_add_check_mark(game);
}

void board_add_check_mark(GameData *game) {
    int is_check = is_under_check(game);
    if (!is_check) {
        return;
    }

    printf(CURSOR_SAVE);

    Piece *king = 
        game->current_side == WHITE ? game->white_king : game->black_king;

    int line = LINES_FROM_TOP + SQUARE_Y_GAP * king->coord.row;
    int col = COLS_FROM_LEFT + SQUARE_X_GAP * king->coord.col;
    move_cursor_to(line, col);
    print_square(game, &king->coord, BG_BRIGHT_RED, BG_RED);
    
    printf(CURSOR_RESTORE RESET);
}

void board_remove_check_mark(GameData *game) {
    printf(CURSOR_SAVE);

    Piece *king = 
        game->current_side == WHITE ? game->white_king : game->black_king;

    int line = LINES_FROM_TOP + SQUARE_Y_GAP * king->coord.row;
    int col = COLS_FROM_LEFT + SQUARE_X_GAP * king->coord.col;
    move_cursor_to(line, col);
    print_square(game, &king->coord, BG_WHITE, BG_BLACK);
    
    printf(CURSOR_RESTORE RESET);
}

// Допоміжна функція для sidebar_display
void sidebar_horiz_border(char *left_br, char *right_br, int length) {
    printf("%s", left_br);
    for(int i = 0; i < length - 2; i++) {
        printf(BORDER_HORIZ);
    }
    printf("%s", right_br);
}
void sidebar_display() {
    printf(CURSOR_SAVE FONT_YELLOW);
    move_cursor_to(1, SIDEBAR_LEFT_POS);
   
    const char title[] = "Side Bar";
    const int title_len = strlen(title);
    const int title_side_margin = (SIDEBAR_WIDTH - title_len - 2) / 2; // -2 - рамки 

    // верхня рамка
    sidebar_horiz_border(BORDER_TL, BORDER_TR, SIDEBAR_WIDTH);

    // заголовок
    move_cursor_to(2, SIDEBAR_LEFT_POS);
    printf(
        "%2s%*s %*s",
        BORDER_VERT,
        title_side_margin + title_len, title, 
        title_side_margin + 2, BORDER_VERT // + довжина самого символу 
    );
    move_cursor_to(3, SIDEBAR_LEFT_POS);
    sidebar_horiz_border(BORDER_VERT_R, BORDER_VERT_L, SIDEBAR_WIDTH);

    // тіло 
    for (int i = 4; i < BOARD_END_LINE; i++) { 
        move_cursor_to(i, SIDEBAR_LEFT_POS);
        printf(BORDER_VERT);
        move_cursor_to(i, SIDEBAR_LEFT_POS + SIDEBAR_WIDTH - 1);
        printf(BORDER_VERT);
    }

    // нижня рамка
    move_cursor_to(BOARD_END_LINE, SIDEBAR_LEFT_POS);
    sidebar_horiz_border(BORDER_BL, BORDER_BR, SIDEBAR_WIDTH);

    printf(CURSOR_RESTORE);
}

void sidebar_current_turn(Colour current_side) {
    printf(CURSOR_SAVE);
    const int lines_from_top = 4;
    const int str_length = 12;
    const int side_margin = (SIDEBAR_WIDTH - str_length - 2) / 2;

    move_cursor_to(lines_from_top, SIDEBAR_LEFT_POS + 2);
    printf(
        BOLD "%*c%s's %sturn", 
        side_margin - 1, ' ',
        current_side == WHITE ? FONT_WHITE "White" : FONT_BLACK "Black",
        FONT_YELLOW RESET_BOLD
    );

    printf(CURSOR_RESTORE RESET);
}

void move_cursor_to(int line, int col) {
    printf("\033[%d;%dH", line, col);
}
// ------------------------------ Utils -------------------------------
void init_game(GameData *p_game) {
    p_game->current_side = WHITE;
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < ROWS; col++) {
            p_game->board[row][col] = NULL;
        }
    }
    
    p_game->black_king = p_game->board[0][4] = new_piece(KING, BLACK, 0, 4);
    p_game->board[0][3] = new_piece(QUEEN, BLACK, 0, 3);
    p_game->board[0][0] = new_piece(ROOK, BLACK, 0, 0);
    p_game->board[0][7] = new_piece(ROOK, BLACK, 0, 7);
    p_game->board[0][1] = new_piece(KNIGHT, BLACK, 0, 1);
    p_game->board[0][6] = new_piece(KNIGHT, BLACK, 0, 6);
    p_game->board[0][2] = new_piece(BISHOP, BLACK, 0, 2);
    p_game->board[0][5] = new_piece(BISHOP, BLACK, 0, 5);

    p_game->white_king = p_game->board[7][4] = new_piece(KING, WHITE, 7, 4);
    p_game->board[7][3] = new_piece(QUEEN, WHITE, 7, 3);
    p_game->board[7][0] = new_piece(ROOK, WHITE, 7, 0);
    p_game->board[7][7] = new_piece(ROOK, WHITE, 7, 7);
    p_game->board[7][1] = new_piece(KNIGHT, WHITE, 7, 1);
    p_game->board[7][6] = new_piece(KNIGHT, WHITE, 7, 6);
    p_game->board[7][2] = new_piece(BISHOP, WHITE, 7, 2);
    p_game->board[7][5] = new_piece(BISHOP, WHITE, 7, 5);

    for (int i = 0; i <= 7; i++) {
        p_game->board[1][i] = new_piece(PAWN, BLACK, 1, i);
        p_game->board[6][i] = new_piece(PAWN, WHITE, 6, i);
    }
}

Piece *new_piece(ChessPiece piece, Colour colour, int start_row, int start_col) {
    Piece *p_piece = malloc(sizeof(Piece));
    p_piece->piece = piece;
    p_piece->colour = colour;
    p_piece->coord = (Coordinates){start_row, start_col};
    p_piece->first_move = 1;

    return p_piece;
}

void free_board(GameData *p_game) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            Piece *p_piece = p_game->board[row][col];
            if (p_piece) {
                free(p_piece);
            }
        }
    }
}

