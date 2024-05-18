#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c|-w] [input_file_name]\n", argv[0]);
        return 1;
    }

    char *param = argv[1];
    char *filename = argv[2];

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("�޷����ļ� %s\n", filename);
        return 1;
    }

    int charCount = 0;
    int wordCount = 0;
    int inWord = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        charCount++;
        if (ch == ' ' || ch == ',') {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            wordCount++;
        }
    }

    fclose(file);

    if (strcmp(param, "-c") == 0) {
        printf("�ַ���: %d\n", charCount);
    } else if (strcmp(param, "-w") == 0) {
        printf("������: %d\n", wordCount);
    } else {
        printf("��Ч����: %s\n", param);
        return 1;
    }

    return 0;
}

