#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define MAX_LEN 1000

char undoStack[MAX][MAX_LEN];
char redoStack[MAX][MAX_LEN];
int undoTop = -1, redoTop = -1;

char doc[MAX_LEN] = "";

void pushUndo() {
    undoTop++;
    strcpy(undoStack[undoTop], doc);
}

void pushRedo() {
    redoTop++;
    strcpy(redoStack[redoTop], doc);
}

void clearRedo() {
    redoTop = -1;
}

void typeText(char *text) {
    pushUndo();
    strcat(doc, text);
    clearRedo();
}

void deleteText(int k) {
    pushUndo();
    int len = strlen(doc);
    if (k > len) k = len;
    doc[len - k] = '\0';
    clearRedo();
}

void undo() {
    if (undoTop == -1) {
        printf("Nothing to undo\n");
        return;
    }
    pushRedo();
    strcpy(doc, undoStack[undoTop]);
    undoTop--;
}

void redo() {
    if (redoTop == -1) {
        printf("Nothing to redo\n");
        return;
    }
    pushUndo();
    strcpy(doc, redoStack[redoTop]);
    redoTop--;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char cmd[20];
        scanf("%s", cmd);

        if (strcmp(cmd, "TYPE") == 0) {
            char text[100];
            scanf("%s", text);
            typeText(text);
        }
        else if (strcmp(cmd, "DELETE") == 0) {
            int k;
            scanf("%d", &k);
            deleteText(k);
        }
        else if (strcmp(cmd, "UNDO") == 0) {
            undo();
        }
        else if (strcmp(cmd, "REDO") == 0) {
            redo();
        }
        else if (strcmp(cmd, "PRINT") == 0) {
            printf("%s\n", doc);
        }
    }

    return 0;
}
