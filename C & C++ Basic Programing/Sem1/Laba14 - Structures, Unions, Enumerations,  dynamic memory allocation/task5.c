#include <stdio.h>
#include <string.h>

typedef struct {
    int number;
    char name[100];
    int year;
    char base_frequency[20];
    char boost_frequency[20];
    char cores_threads[20];
} Processor;

void printProcessors(Processor processors[], int n);
void printMenu();
void newYear(Processor *processor);
void newBaseFrequency(Processor *processor);
void newBoostFrequency(Processor *processor);
void newCoresThreads(Processor *processor);
void continueProgram(char* choice);
void getUserChoice(int* option);
void selectProcessor(Processor* processors, int n, int* number);

int main() {
    Processor processors[10] = {
        {1, "AMD Ryzen Threadripper PRO 7995WX", 2023, "2500 MHz", "5100 MHz", "96 / 192"},
        {2, "AMD Ryzen Threadripper 7980X", 2022, "3200 MHz", "5100 MHz", "64 / 128"},
        {3, "AMD Ryzen Threadripper PRO 7985WX", 2022, "3200 MHz", "5100 MHz", "64 / 128"},
        {4, "AMD EPYC 9684X", 2023, "2550 MHz", "3700 MHz", "96 / 192"},
        {5, "AMD EPYC 9654", 2022, "2400 MHz", "3550 MHz", "96 / 192"},
        {6, "AMD EPYC 9654P", 2022, "2400 MHz", "3700 MHz", "96 / 192"},
        {7, "AMD EPYC 9554", 2021, "3100 MHz", "3750 MHz", "64 / 128"},
        {8, "AMD EPYC 9554P", 2021, "3100 MHz", "3750 MHz", "64 / 128"},
        {9, "AMD EPYC 9634", 2021, "2250 MHz", "3700 MHz", "84 / 168"},
        {10, "AMD EPYC 9474F", 2021, "3600 MHz", "4100 MHz", "48 / 96"}
    };
    int choice, number;
    char continue_choice;

    do {
        printProcessors(processors, 10);
        selectProcessor(processors, 10, &number);
        printMenu();
        getUserChoice(&choice);

        switch (choice) {
            case 1:
                newYear(&processors[number - 1]);
                printProcessors(processors, 10);
                break;
            case 2:
                newBaseFrequency(&processors[number - 1]);
                printProcessors(processors, 10);
                break;
            case 3:
                newBoostFrequency(&processors[number - 1]);
                printProcessors(processors, 10);
                break;
            case 4:
                newCoresThreads(&processors[number - 1]);
                printProcessors(processors, 10);
                break;
            default:
                printf("Invalid choice!\n");
        }

        continueProgram(&continue_choice);
    } while (continue_choice == '+');

    return 0;
}

void printProcessors(Processor processors[], int n) {
    printf("\nProcessor List:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", processors[i].number, processors[i].name);
        printf("   Year: %d\n", processors[i].year);
        printf("   Base Frequency: %s\n", processors[i].base_frequency);
        printf("   Boost Frequency: %s\n", processors[i].boost_frequency);
        printf("   Cores/Threads: %s\n\n", processors[i].cores_threads);
    }
}

void printMenu() {
    printf("\nSelect the option to update:\n");
    printf("1. Year\n");
    printf("2. Base Frequency\n");
    printf("3. Boost Frequency\n");
    printf("4. Cores/Threads\n");
    printf("Enter your choice: ");
}

void newYear(Processor *processor) {
    printf("\nEnter new year (current: %d): ", processor->year);
    scanf("%d", &processor->year);
    printf("Processor year updated to %d!\n", processor->year);
}

void newBaseFrequency(Processor *processor) {
    printf("\nEnter new base frequency (current: %s): ", processor->base_frequency);
    scanf("%s", processor->base_frequency);
    printf("Processor base frequency updated to %s!\n", processor->base_frequency);
}

void newBoostFrequency(Processor *processor) {
    printf("\nEnter new boost frequency (current: %s): ", processor->boost_frequency);
    scanf("%s", processor->boost_frequency);
    printf("Processor boost frequency updated to %s!\n", processor->boost_frequency);
}

void newCoresThreads(Processor *processor) {
    printf("\nEnter new cores/threads (current: %s): ", processor->cores_threads);
    scanf("%s", processor->cores_threads);
    printf("Processor cores/threads updated to %s!\n", processor->cores_threads);
}

void continueProgram(char* choice) {
    printf("\nIf you want to continue, enter '+' or '-' to exit: ");
    while (scanf(" %c", choice) != 1 || (*choice != '+' && *choice != '-')) {
        printf("Invalid input. Please enter '+' or '-': ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
}

void getUserChoice(int* option) {
    while (scanf("%d", option) != 1 || *option < 1 || *option > 4) {
        printf("Invalid input. Please enter a number between 1 and 4: ");
        while (getchar() != '\n');
    }
}

void selectProcessor(Processor* processors, int n, int* number) {
    printf("\nEnter the processor number to update (1-%d), or 0 to exit: ", n);
    while (scanf("%d", number) != 1 || (*number < 0 || *number > n)) {
        printf("Invalid processor number! Please enter a number between 1 and %d, or 0 to exit: ", n);
        while (getchar() != '\n');
    }
    if (*number > 0) {
        printf("\nSelected Processor:\n");
        printf("%d. %s\n", processors[*number - 1].number, processors[*number - 1].name);
        printf("   Year: %d\n", processors[*number - 1].year);
        printf("   Base Frequency: %s\n", processors[*number - 1].base_frequency);
        printf("   Boost Frequency: %s\n", processors[*number - 1].boost_frequency);
        printf("   Cores/Threads: %s\n", processors[*number - 1].cores_threads);
    }
}

