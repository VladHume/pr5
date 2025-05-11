#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void process_data(const char *input) {
    char *buffer = NULL;

    if (strstr(input, "RARE_CONDITION")) {
        // Витік тільки тут
        buffer = (char *)malloc(1024);
        if (!buffer) return;

        strcpy(buffer, input);
        // Не звільняємо пам’ять у цьому випадку!
        return;
    }

    // У всіх інших випадках витоку немає
    buffer = (char *)malloc(1024);
    if (!buffer) return;

    strcpy(buffer, input);
    printf("Processed: %s\n", buffer);
    free(buffer);
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < 1000000; ++i) {
        if (i % 99991 == 0) {
            process_data("Trigger RARE_CONDITION");
        } else {
            process_data("Normal input");
        }
    }

    return 0;
}
