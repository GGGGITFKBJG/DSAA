#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define LISTINCREMENT 10

typedef struct {
    int *elem;
    int length;
    int listsize;
    int incrementsize;
} Sqlist;

void initSqlist(Sqlist *psl) {
    psl->elem = malloc(sizeof(int) * MAXSIZE);
    if (psl->elem == NULL) return;
    psl->length = 0;
    psl->listsize = MAXSIZE;
    psl->incrementsize = LISTINCREMENT;
}

void insert(Sqlist *sl, int pos, int elem) {
    if (pos > sl->length + 1 || pos < 1) return;
    if (sl->length == sl->listsize) {
        int *p2 = realloc(sl->elem, sizeof(int) * (sl->listsize + sl->incrementsize));
        if (p2 == NULL) return;
        sl->elem = p2;
        sl->listsize += sl->incrementsize;
    }
    for (int i = sl->length - 1; i >= pos - 1; i--) {
        sl->elem[i + 1] = sl->elem[i];
    }
    sl->elem[pos - 1] = elem;
    sl->length += 1;
}

void deletelist(Sqlist *psl) {
    free(psl->elem);
}

int main() {
    Sqlist sl;
    initSqlist(&sl);
    for (int i = 0; i <25; i++) {
        insert(&sl, i + 1, i + 1);
    }
    
    for (int i = 0; i < sl.length; i++) {
        printf("%d\n", sl.elem[i]);
    }

    printf("length = %d\n", sl.length);
    printf("listsize = %d\n", sl.listsize);
    deletelist(&sl);

    getchar();
    return 0;
}