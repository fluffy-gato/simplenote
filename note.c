#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOTES_FILE "notes.txt"

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void show_notes() {
    char line[100];
    FILE* file = fopen(NOTES_FILE, "r");
    if (file == NULL) {
        printf("No notes found.\n");
        return;
    }

    printf("Your notes:\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("- %s", line);
    }
    fclose(file);
}

void add_note() {
    char note[100];
    printf("Enter your note: ");
    fgets(note, sizeof(note), stdin);

    FILE* file = fopen(NOTES_FILE, "a");
    if (file == NULL) {
        printf("Error.\n");
        return;
    }

    fprintf(file, "%s", note);
    fclose(file);
    printf("Note added successfully!\n");
}

void delete_notes() {
    if (remove(NOTES_FILE) == 0) {
        printf("All notes deleted successfully.\n");
    } else {
        printf("Error.\n");
    }
}

int main() {
    while (1) {
        printf("\nSimple Note by Fluffy Gato\n");
        printf("1. My Notes\n");
        printf("2. Write a Note\n");
        printf("3. Remove all Notes\n");
        printf("4. Leave\n");
        
        int choice;
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clear_input_buffer();
            continue;
        }

        clear_input_buffer();

        switch (choice) {
            case 1:
                show_notes();
                break;
            case 2:
                add_note();
                break;
            case 3:
                delete_notes();
                break;
            case 4:
                printf("Leaving Simple Note.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}

