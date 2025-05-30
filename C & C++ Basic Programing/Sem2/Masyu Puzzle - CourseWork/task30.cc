/* ----------------------------------------------------------------<Header>-
 Name: test30.cc
 Title: Main program for Masyu puzzle solver
 Group: TV-42
 Student: Kriuchkov R. Y.
 Written: 2025-04-29
 Revised: 2025-05-14
 Description: Main program to test the Masyu puzzle solver functionality.
 ------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <locale.h>
#include "core_headers/field.h"
#include "core_headers/cell.h"
#include "logic_headers/solver.h"
#include "utils/ui.h"

/* ----------------------------------------------------------------------[<]-
 Functions: 
 - create_field_from_user
 - print_all_fields
 - print_field_by_number
 - end_program
 Synopsis: Prototypes for function calls in the main function.
-------------------------------------------------------------------------[>]*/
void create_field_from_user();
void print_all_fields();
void print_field_by_number();
void end_program();

/* ----------------------------------------------------------------------[<]-
 Functions: main
 Synopsis: Core of program. Function that start program.
-------------------------------------------------------------------------[>]*/
int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    ui::print_welcome();
    ui::sleep_for_milliseconds(SLEEP_POLITE_BOX);

    while (true) {
        ui::print_centered_title(L"Please choose Menu Item");
        ui::print_menu();
        int choice = ui::get_one_int(CHOICE);
        switch (choice) {
            case 1:
                print_all_fields();
                break;
            case 2:
                print_field_by_number();
                break;
            case 3:
                create_field_from_user();
                break;
            case 4:
                ui::show_rules();
                break;
            case 5:
                end_program();
                break;
            default:
                std::wcout << BOLD << "Invalid choice number of menu..." << RESET_COLOUR << std::endl;
                break;
        }        
        if (choice == CHOICE) break;
    }

    return 0;
}

/* ----------------------------------------------------------------------[<]-
    Function: create_field
    Synopsis: Set types of cells.
-------------------------------------------------------------------------[>]*/
&Field create_field(&Field field, std::vector<std::pair<int, int>> white_cells, std::vector<std::pair<int, int>> black_cells) {
    for (int i = 0; i < field.get_width(); i++) {
        for (int j = 0; j < field.get_height(); j++) {
            CellType type = CellType::EMPTY;

            if (std::find(black_cells.begin(), black_cells.end(), std::make_pair(i, j)) != black_cells.end()) {
                type = CellType::BLACK;
            } else if (std::find(white_cells.begin(), white_cells.end(), std::make_pair(i, j)) != white_cells.end()) {
                type = CellType::WHITE;
            }

            try {
                field.set_cell(Cell(i, j, type));
            } catch (const std::invalid_argument& e) {
                std::wcerr << L"Error setting cell in field 1: " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::wcerr << L"Error setting coordinates field 1: " << e.what() << std::endl;
            }
        }
    }
}

/* ----------------------------------------------------------------------[<]-
    Function: create_field_1
    Synopsis: Create field 1 from test 1.
-------------------------------------------------------------------------[>]*/
Field create_field_1() {
    Field field;

    std::vector<std::pair<int, int>> black_cells = {
        {4, 0}, {0, 2}, {2, 2}, {8, 2}, {10, 2},
        {4, 4}, {6, 4}, {8, 4}, {0, 6}, {4, 6},
        {8, 6}, {10, 6}, {0, 8}, {2, 8}, {6, 8},
        {8, 8}, {4, 10}, {6, 10}
    };

    std::vector<std::pair<int, int>> white_cells = {
        {6, 0}, {4, 2}, {6, 2}, {0, 4}, {2, 4},
        {10, 4}, {2, 6}, {6, 6}, {4, 8}, {10, 8}
    };

    try {
        field.init(11, 11);
    } catch (const std::invalid_argument& e) {
        std::wcerr << L"Error initialization field 1: " << e.what() << std::endl;
    }

    create_field(field, white_cells, black_cells);

    return field;
}

/* ----------------------------------------------------------------------[<]-
    Function: create_field_2
    Synopsis: Create field 2 from test 2.
-------------------------------------------------------------------------[>]*/
Field create_field_2() {
    Field field;

    std::vector<std::pair<int, int>> black_cells = {
        {4, 2}, {5, 3}, {3, 4}, {2, 5}, {7, 5},
        {3, 6}, {5, 6}, {6, 7}, {3, 9}
    };

    std::vector<std::pair<int, int>> white_cells = {
        {2, 0}, {6, 0}, {8, 1}, {2, 2}, {3, 2}, {8, 2},
        {4, 3}, {6, 3}, {7, 3}, {0, 4}, {2, 4}, {4, 4},
        {5, 4}, {7, 4}, {5, 5}, {9, 5}, {2, 6}, {4, 6},
        {7, 6}, {1, 7}, {5, 7}, {7, 7}, {1, 8}, {8, 9}
    };

    try {
        field.init(10, 10);
    } catch (const std::invalid_argument& e) {
        std::wcerr << L"Error initialization field 2: " << e.what() << std::endl;
    }

    create_field(field, white_cells, black_cells);

    return field;
}

/* ----------------------------------------------------------------------[<]-
    Function: create_field_3
    Synopsis: Create field 3 from test 3.
-------------------------------------------------------------------------[>]*/
Field create_field_3() {
    Field field;

    std::vector<std::pair<int, int>> black_cells = {
        {1, 3}, {7, 3}, {10, 3}, {10, 4},
        {1, 6}, {4, 6}, {7, 6}, {10, 6}
    };

    std::vector<std::pair<int, int>> white_cells = {
        {5, 0}, {2, 1}, {3, 1}, {8, 1}, {9, 1},
        {1, 2}, {4, 2}, {7, 2}, {10, 2},
        {1, 4}, {1, 5}, {3, 5}, {4, 5}, {7, 5}, {10, 5},
        {2, 7}, {3, 7}, {8, 7}, {9, 7},
        {6, 8}
    };

    try {
        field.init(12, 9);
    } catch (const std::invalid_argument& e) {
        std::wcerr << L"Error initialization field 3: " << e.what() << std::endl;
    }

    create_field(field, white_cells, black_cells);

    return field;
}

/* ----------------------------------------------------------------------[<]-
    Function: create_field_4
    Synopsis: Create field 4 from test 4.
-------------------------------------------------------------------------[>]*/
Field create_field_4() {
    Field field;

    std::vector<std::pair<int, int>> black_cells = {
        {0, 0}, {3, 0}, {5, 2}, {9, 3}, {10, 4}, {11, 5},
        {6, 7}, {8, 7}, {7, 8}, {3, 8}, {1, 8},
        {6, 9}, {8, 9}, {1, 10}, {3, 10}
    };

    std::vector<std::pair<int, int>> white_cells = {
        {8, 0}, {9, 0}, {12, 1},
        {7, 2}, {8, 2}, {11, 2},
        {2, 3}, {4, 3},
        {5, 4},
        {0, 5}, {1, 5}, {2, 5}, {4, 5}, {5, 5}, {8, 5},
        {9, 6},
        {12, 7},
        {11, 9}, {9, 9},
        {9, 10}, {11, 10},
        {11, 11}, {0, 11}, {1, 11}, {5, 11}, {9, 11},
        {7, 12}
    };

    try {
        field.init(13, 13);
    } catch (const std::invalid_argument& e) {
        std::wcerr << L"Error initialization field 4: " << e.what() << std::endl;
    }

    create_field(field, white_cells, black_cells);

    return field;
}


/* ----------------------------------------------------------------------[<]-
    Function: create_field_5
    Synopsis: Create field 5 from test 5.
-------------------------------------------------------------------------[>]*/
Field create_field_5() {
    Field field;

    std::vector<std::pair<int, int>> black_cells = {
        {1, 0}, {7, 0}, {13, 0}, {14, 0}, {4, 1}, {6, 1}, {10, 1},
        {7, 2}, {11, 2}, {13, 2}, {2, 4}, {0, 5}, {3, 5}, {9, 5},
        {10, 6}, {12, 6}, {16, 6}, {3, 7}, {6, 7}, {7, 7}, {9, 7},
        {5, 8}, {14, 8}, {15, 9}, {1, 11}, {3, 11}, {10, 11}, {12, 11},
        {4, 12}, {6, 13}, {8, 13}, {16, 13}, {0, 14}, {2, 14}, {14, 14},
        {7, 16}
    };

    std::vector<std::pair<int, int>> white_cells = {
        {9, 0}, {2, 2}, {14, 2}, {16, 2}, {0, 3}, {8, 3}, {10, 3},
        {11, 4}, {4, 5}, {6, 5}, {13, 5}, {15, 5}, {1, 7}, {2, 8},
        {11, 8}, {7, 9}, {9, 9}, {10, 9}, {13, 9}, {0, 10}, {4, 10},
        {6, 10}, {7, 11}, {13, 11}, {16, 11}, {14, 12}, {3, 14}, {5, 14},
        {9, 14}, {6, 15}, {10, 15}, {12, 15}, {2, 16}, {3, 16}, {9, 16}, {15, 16}
    };

    try {
        field.init(17, 17);
    } catch (const std::invalid_argument& e) {
        std::wcerr << L"Error initialization field 5: " << e.what() << std::endl;
    }

    create_field(field, white_cells, black_cells);

    return field;
}

/* ---------------------------------------------------------------------[<]-
 Function: initialize_user_field
 Synopsis: Input the user for custom field size.
 ---------------------------------------------------------------------[>]-*/
 void initialize_user_field(Field& user_field, int& width, int& height) {
    std::wcout << BOLD;

    ui::print_typing_effect(L"Enter the width and height of the field (Minimum Rows ");
    ui::print_typing_effect(width);
    ui::print_typing_effect(L" and Cols ");
    ui::print_typing_effect(height);
    ui::print_typing_effect(L" - Maximum Rows ");
    ui::print_typing_effect(MAX_SIZE_FIELD);
    ui::print_typing_effect(L" and Cols ");
    ui::print_typing_effect(MAX_SIZE_FIELD);
    ui::print_typing_effect(L")");

    std::wcout << RESET_COLOUR << std::endl;

    std::pair<int, int> size = ui::get_two_int(MAX_SIZE_FIELD, MAX_SIZE_FIELD);
    if (size.first < width || size.second < height) {
        std::wcout << BOLD;

        ui::print_typing_effect(L"Your size wasn't meet to what was asked, therefore was initialized field Rows ");
        ui::print_typing_effect(width);
        ui::print_typing_effect(L" and Cols ");
        ui::print_typing_effect(height);

        std::wcout << RESET_COLOUR << std::endl;
    } else {
        width = size.first;
        height = size.second;
    }

    try {
        user_field.init(width, height);
    } catch (const std::invalid_argument& e) {
        std::wcerr << L"Error initializing the field: " << e.what() << std::endl;
        return;
    }
}

/* ---------------------------------------------------------------------[<]-
 Function: input_user_pearls
 Synopsis: Prompts the user to enter coordinates and types (White/Black)
 ---------------------------------------------------------------------[>]-*/
void input_user_pearls(Field& user_field, int width, int height, int num_cells) {
    for (int i = 0; i < num_cells; ++i) {
        std::vector<Cell*> white = user_field.get_white_cells();
        std::vector<Cell*> black = user_field.get_black_cells();
        if (!white.empty() || !black.empty()) {
            std::wcout << BOLD;
            ui::print_typing_effect(L"Pearls already have set on: ");
            
            bool first = true;
            for (Cell* c : white) {
                if (white.empty()) break;
                if (!first) ui::print_typing_effect(L", ");
                ui::print_typing_effect(L"(" + std::to_wstring(c->get_x()) + L", " + std::to_wstring(c->get_y()) + L")");
                first = false;
            }
            first = true;
            for (Cell* c : black) {
                if (black.empty()) break;
                if (!first) ui::print_typing_effect(L", ");
                ui::print_typing_effect(L"(" + std::to_wstring(c->get_x()) + L", " + std::to_wstring(c->get_y()) + L")");
                first = false;
            }
    
            std::wcout << RESET_COLOUR << std::endl;
        }

        std::wcout << BOLD;

        ui::print_typing_effect(L"Enter the coordinates for pearl x ∈ [0, ");
        ui::print_typing_effect(width - 1);
        ui::print_typing_effect(L"], y ∈ [0, ");
        ui::print_typing_effect(height - 1);
        ui::print_typing_effect(L"]");

        std::wcout << RESET_COLOUR << std::endl;

        std::pair<int, int> coord = ui::get_two_int(width, height);
        if (coord.first == -1 || coord.second == -1) {
            std::wcerr << L"Invalid coordinate input. Skipping cell.\n";
            continue;
        }
        if (user_field.get_cell(coord.first, coord.second).get_type() == CellType::EMPTY) {
            std::wcout << BOLD;

            ui::print_typing_effect(L"Enter cell type for (");
            ui::print_typing_effect(coord.first);
            ui::print_typing_effect(L", ");
            ui::print_typing_effect(coord.second);
            ui::print_typing_effect(L")");

            std::wcout << RESET_COLOUR << std::endl;

            std::wcout << BOLD;
            ui::print_typing_effect(L"1. White\n2. Black");
            std::wcout << RESET_COLOUR << std::endl;

            int cell_type = ui::get_one_int(NUMBER_OF_TYPE_PEARL);

            if (cell_type == 1) {
                user_field.set_cell(Cell(coord.first, coord.second, CellType::WHITE));
            } else if (cell_type == 2) {
                user_field.set_cell(Cell(coord.first, coord.second, CellType::BLACK));
            } else {
                std::wcerr << L"Invalid choice. Please enter 1 for White or 2 for Black.\n";
            }
        } else {
            ui::print_typing_effect(L"Cell isn't free. Skipping...\n");
            continue;
        }
    }
}

/* ----------------------------------------------------------------------[<]-
    Function: solve_field
    Synopsis: Solve field 1 and display solving.
-------------------------------------------------------------------------[>]*/
void solve_field(Field& field) {
    try {
        if (field.is_initialized()) {
            Solver solver(field);
            if (solver.solve()) {
                ui::print_centered_title(L"Solution is found:");
                field.print_field();
                ui::print_rules(field.get_height());
            } else {
                ui::print_centered_title(L"No solution found");
            }
        }
    } catch (const std::exception& e) {
        std::wcerr << L"Error solving field: " << e.what() << std::endl;
    }
}

/* ----------------------------------------------------------------------[<]-
 Function:   create_field_from_user
 Synopsis:   User to create a field, add cells, and choose the type for each cell.
-------------------------------------------------------------------------[>]*/
void create_field_from_user() {
	Field user_field;
	int width = MIN_SIZE_FIELD, height = MIN_SIZE_FIELD;

    ui::print_centered_title(L"You chose menu item — \"Create a custom field\"");
    ui::sleep_for_milliseconds(SLEEP_TITLE);
	
	initialize_user_field(user_field, width, height);

    int max_cells = (width * height) / 2;
	int num_cells = 0;
	std::wcout << BOLD;

    ui::print_typing_effect(L"Enter the number of cells you want to set (Minimum 1 - Maximum ");
    ui::print_typing_effect(max_cells);
    ui::print_typing_effect(L"): ");

    std::wcout << RESET_COLOUR << std::endl;

	num_cells = ui::get_one_int(max_cells);

	input_user_pearls(user_field, width, height, num_cells);

	user_field.print_field();
    ui::sleep_for_milliseconds(SLEEP_BEFORE_SOLVING);

    solve_field(user_field);
	
    ui::sleep_for_milliseconds(SLEEP_AFTER_SOLVING);
}

/* ----------------------------------------------------------------------[<]-
    Function: print_field_1
    Synopsis: Print field 1.
-------------------------------------------------------------------------[>]*/
void print_field_1() {
    ui::print_centered_title(L"Field 1");

    Field field = create_field_1();

    field.print_field();
    ui::print_rules(field.get_height());
    ui::sleep_for_milliseconds(SLEEP_BEFORE_SOLVING);

    solve_field(field);

    ui::sleep_for_milliseconds(SLEEP_AFTER_SOLVING);
}

/* ----------------------------------------------------------------------[<]-
    Function: print_field_2
    Synopsis: Print field and solve field 2.
-------------------------------------------------------------------------[>]*/
void print_field_2() {
    ui::print_centered_title(L"Field 2");

    Field field = create_field_2();

    field.print_field();
    ui::print_rules(field.get_height());
    ui::sleep_for_milliseconds(SLEEP_BEFORE_SOLVING);

    solve_field(field);

    ui::sleep_for_milliseconds(SLEEP_AFTER_SOLVING);
}

/* ----------------------------------------------------------------------[<]-
    Function: print_field_3
    Synopsis: Print field and solve field 3.
-------------------------------------------------------------------------[>]*/
void print_field_3() {
    ui::print_centered_title(L"Field 3");

    Field field = create_field_3();

    field.print_field();
    ui::print_rules(field.get_height());
    ui::sleep_for_milliseconds(SLEEP_BEFORE_SOLVING);

    solve_field(field);

    ui::sleep_for_milliseconds(SLEEP_AFTER_SOLVING);
}

/* ----------------------------------------------------------------------[<]-
    Function: print_field_4
    Synopsis: Print field and solve field 4.
-------------------------------------------------------------------------[>]*/
void print_field_4() {
    ui::print_centered_title(L"Field 4");

    Field field = create_field_4();

    field.print_field();
    ui::print_rules(field.get_height());
    ui::sleep_for_milliseconds(SLEEP_BEFORE_SOLVING);

    solve_field(field);

    ui::sleep_for_milliseconds(SLEEP_AFTER_SOLVING);
}

/* ----------------------------------------------------------------------[<]-
    Function: print_field_5
    Synopsis: Print field and solve field 5.
-------------------------------------------------------------------------[>]*/
void print_field_5() {
    ui::print_centered_title(L"Field 5");

    Field field = create_field_5();

    field.print_field();
    ui::print_rules(field.get_height());
    ui::sleep_for_milliseconds(SLEEP_BEFORE_SOLVING);

    solve_field(field);

    ui::sleep_for_milliseconds(SLEEP_AFTER_SOLVING);
}

/* ----------------------------------------------------------------------[<]-
    Function: print_all_fields
    Synopsis: Display all of fields.
-------------------------------------------------------------------------[>]*/
void print_all_fields() {
    ui::print_centered_title(L"You chose menu item — \"Display all fields\"");
    ui::sleep_for_milliseconds(SLEEP_TITLE);
    print_field_1();
    print_field_2();
    print_field_3();
    print_field_4();
    print_field_5();
}

/* ----------------------------------------------------------------------[<]-
    Function: print_field_by_number
    Synopsis: Prints the field by number.
-------------------------------------------------------------------------[>]*/
void print_field_by_number() {
    ui::print_centered_title(L"You chose menu item — \"Display field by number\". Which field do you want to display?");
    ui::sleep_for_milliseconds(SLEEP_TITLE);
    int number = ui::get_one_int(NUMBER_OF_FIELDS);
    switch(number) {
        case 1:
            print_field_1();
            break;
        case 2:
            print_field_2();
            break;
        case 3:
            print_field_3();
            break;
        case 4:
            print_field_4();
            break;
        case 5:
            print_field_5();
            break;
        default:
            std::wcout << BOLD << L"Invalid field number. Please choose from 1 to " << NUMBER_OF_FIELDS << L"." << RESET_COLOUR << std::endl;
            break;
    }
}

/* ---------------------------------------------------------------------[<]- 
    End of program:
    Print exit message and wait for a few seconds before exiting.   
---------------------------------------------------------------------[>]-*/
void end_program() {
    ui::print_centered_title(L"You chose menu item — \"Exit the program\"");
    ui::sleep_for_milliseconds(SLEEP_TITLE);
    ui::print_thank_you();
    ui::sleep_for_milliseconds(SLEEP_POLITE_BOX);
    ui::print_centered_title_bottom(L"Exiting...");
    ui::sleep_for_milliseconds(SLEEP_TITLE);
}
