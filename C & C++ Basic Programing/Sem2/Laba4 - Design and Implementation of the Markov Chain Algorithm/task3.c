#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXGEN 100
#define NPREF 2
#define NHASH 100
#define MULTIPLIER 31
#define MAX_ATTEMPTS 10

typedef struct state {
    char *pref[NPREF];
    struct suffix *suf;
    struct state *next;
} State;

typedef struct suffix {
    char *word;
    struct suffix *next;
} Suffix;

State *statetab[NHASH];
char NONWORD[] = "\n";

unsigned int hash(char *s[NPREF]) {
    unsigned int h = 0;
    unsigned char *p;
    int i;

    for (i = 0; i < NPREF; i++) {
        if (s[i] == NULL) {
            printf("Error: NULL prefix encountered in hash function.\n");
            exit(1);
        }
        for (p = (unsigned char *)s[i]; *p != '\0'; p++) {
            h = MULTIPLIER * h + *p;
        }
    }
    return h % NHASH;
}

State *lookup(char *prefix[NPREF], int create) {
    int i;
    unsigned int h = hash(prefix);
    State *sp;

    if (prefix == NULL) {
        printf("Error: NULL prefix passed to lookup.\n");
        return NULL;
    }

    for (sp = statetab[h]; sp != NULL; sp = sp->next) {
        for (i = 0; i < NPREF; i++) {
            if (prefix[i] == NULL || sp->pref[i] == NULL) {
                printf("Error: NULL pointer encountered in lookup.\n");
                return NULL;
            }
            if (strcmp(prefix[i], sp->pref[i]) != 0)
                break;
        }
        if (i == NPREF)
            return sp;
    }

    if (create) {
        sp = (State *)malloc(sizeof(State));
        if (sp == NULL) {
            perror("Memory allocation error in lookup");
            exit(1);
        }
        for (i = 0; i < NPREF; i++) {
            if (prefix[i] == NULL) {
                printf("Error: NULL prefix at index %d in lookup.\n", i);
                return NULL;
            }
            sp->pref[i] = prefix[i];
        }
        sp->suf = NULL;
        sp->next = statetab[h];
        statetab[h] = sp;
        return sp;
    }

    return NULL;
}

void addsuffix(State *sp, char *suffix) {
    if (sp == NULL || suffix == NULL) {
        printf("Error: NULL state or suffix passed to addsuffix.\n");
        return;
    }

    Suffix *suf = (Suffix *)malloc(sizeof(Suffix));
    if (suf == NULL) {
        perror("Memory allocation error in addsuffix");
        exit(1);
    }
    suf->word = suffix;
    suf->next = sp->suf;
    sp->suf = suf;
}

void add(char *prefix[NPREF], char *suffix) {
    if (prefix == NULL || suffix == NULL) {
        printf("Error: NULL prefix or suffix passed to add.\n");
        return;
    }

    State *sp = lookup(prefix, 1);
    if (sp == NULL) {
        printf("Error: Failed to find or create state in add function.\n");
        return;
    }
    addsuffix(sp, suffix);

    memmove(prefix, prefix + 1, (NPREF - 1) * sizeof(prefix[0]));
    prefix[NPREF - 1] = suffix;
}

void build(char *prefix[NPREF], FILE *f) {
    char buf[100], fmt[10];
    snprintf(fmt, sizeof(fmt), "%%%lds", sizeof(buf) - 1);

    while (fscanf(f, fmt, buf) != EOF) {
        if (buf[0] == '\0') {
            printf("Error: Empty word encountered in file.\n");
            continue;
        }
        add(prefix, strdup(buf));
    }
}

void generate(int nwords) {
    srand(time(NULL));

    if (statetab[0] == NULL) {
        printf("No data available to generate text.\n");
        return;
    }

    char *prefix[NPREF] = {NONWORD, NONWORD};
    char *last_words[MAXGEN] = {NULL};
    int last_index = 0;
    int words_generated = 0;
    int attempts = 0;

    for (int i = 0; i < nwords; i++) {
        State *sp = lookup(prefix, 0);
        if (sp == NULL) {
            printf("Error: No matching state found at word %d, resetting prefix.\n", i);
            memmove(prefix, prefix + 1, (NPREF - 1) * sizeof(prefix[0]));
            prefix[NPREF - 1] = NONWORD;
            attempts++;
            if (attempts > MAX_ATTEMPTS) {
                printf("Error: Too many attempts, stopping generation.\n");
                break;
            }
            continue;
        }

        int nmatch = 0;
        Suffix *suf = sp->suf;
        int generated = 0;

        while (suf != NULL) {
            if (rand() % ++nmatch == 0) {
                char *w = suf->word;

                if (strcmp(w, NONWORD) == 0) {
                    break;
                }

                int repeat = 0;
                for (int j = 0; j < last_index; j++) {
                    if (last_words[j] != NULL && strcmp(last_words[j], w) == 0) {
                        repeat = 1;
                        break;
                    }
                }

                if (repeat) {
                    continue;
                }

                last_words[last_index] = w;
                last_index = (last_index + 1) % MAXGEN;
                printf("%s ", w);
                words_generated++;

                memmove(prefix, prefix + 1, (NPREF - 1) * sizeof(prefix[0]));
                prefix[NPREF - 1] = w;

                generated = 1;
                break;
            }
            suf = suf->next;
        }

        if (!generated) {
            printf("Error: No matching suffix found at word %d, resetting prefix.\n", i);
            memmove(prefix, prefix + 1, (NPREF - 1) * sizeof(prefix[0]));
            prefix[NPREF - 1] = NONWORD;
            i--;
            attempts++;
            if (attempts > MAX_ATTEMPTS) {
                printf("Error: Too many attempts, stopping generation.\n");
                break;
            }
        }

        if (words_generated >= nwords) {
            break;
        }
    }
}

int main(void) {
    int i, nwords = MAXGEN;
    char *prefix[NPREF] = {NONWORD, NONWORD};

    FILE *file = fopen("text3.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    if (file) {
        build(prefix, file);
        fclose(file);
    }

    for (i = 0; i < NPREF; i++) {
        add(prefix, NONWORD);
    }

    generate(nwords);

    return 0;
}
