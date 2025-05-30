#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval {
    char *name;
    int value;
} Nameval;

typedef struct NVtab {
    int nval;
    int max;
    Nameval *nameval;
} NVtab;

enum { NVINIT = 1, NVGROW = 2 };

int addname(NVtab *nvtab, Nameval newname);
int delname(NVtab *nvtab, char *name);

int main() {
    NVtab nvtab = {0, 0, NULL};
    addname(&nvtab, (Nameval){.name = "Andy", .value = 12});
    addname(&nvtab, (Nameval){.name = "Billy", .value = 18});
    addname(&nvtab, (Nameval){.name = "Andy", .value = 13});
    addname(&nvtab, (Nameval){.name = "Billy", .value = 15});
    addname(&nvtab, (Nameval){.name = "Andy", .value = 17});
    addname(&nvtab, (Nameval){.name = "Billy", .value = 19});
    for (int i = 0; i < nvtab.nval; i++) {
        printf("%s %d\n", nvtab.nameval[i].name, nvtab.nameval[i].value);    
    }
    delname(&nvtab, "Andy");
    printf("\n*****************\n(deleted Andy12)\n");
    for (int i = 0; i < nvtab.nval; i++) {
        printf("%s %d\n", nvtab.nameval[i].name, nvtab.nameval[i].value);    
    }

    free(nvtab.nameval);
    return 0;
}

int addname(NVtab *nvtab, Nameval newname) {
    for (int i = 0; i < nvtab->nval; i++) {
        if (nvtab->nameval[i].name == NULL) {
            nvtab->nameval[i] = newname;
            return i;
        }
    }

    if (nvtab->nameval == NULL) {
        nvtab->nameval = (Nameval *)malloc(NVINIT * sizeof(Nameval));
        if (nvtab->nameval == NULL) {
            return -1;
        }
        nvtab->max = NVINIT;
        nvtab->nval = 0;
    } else if (nvtab->nval >= nvtab->max) {
        Nameval *nvp = (Nameval *)realloc(nvtab->nameval, (NVGROW * nvtab->max) * sizeof(Nameval));
        if (nvp == NULL) {
            return -1;
        }
        nvtab->max *= NVGROW;
        nvtab->nameval = nvp;
    }

    nvtab->nameval[nvtab->nval] = newname;
    return nvtab->nval++;
}

int delname(NVtab *nvtab, char *name) {
    for (int i = 0; i < nvtab->nval; i++) {
        if (nvtab->nameval[i].name != NULL && strcmp(nvtab->nameval[i].name, name) == 0) {
            nvtab->nameval[i].name = NULL;
            return 1;
        }
    }
    return 0;
}
