#include <stdio.h>
#include <stdlib.h>
#include "../include/schedule_utils.h"

int get_last_id() {
    FILE *file = fopen(OUTPUT_FILENAME, "r");

    if (file == NULL)
        return 1;

    int id = 0;

    char file_line[MAX_LINE_LENGTH];
    while (fgets(file_line, sizeof(file_line), file) != NULL)
        sscanf(file_line, "ID: %d", &id);

    fclose(file);

    return id;
}

void save_schedule(schedule *schedule) {
    FILE *file = fopen(OUTPUT_FILENAME, "a+");

    if (file == NULL)
        perror("Erro para abrir arquivo de saida!\n");

    fprintf(
        file,
        "ID: %d | Nome do Tutor: %s | Nome do Pet: %s | Endereco: %s | Numero: %d | Telefone: %s | Raca: %s | Data: %s | Horario: %s | Tempo (horas): %d\n",
        schedule->id,
        schedule->tutor_name, schedule->pet_name, schedule->address, schedule->number, schedule->telephone,
        schedule->breed, schedule->date, schedule->horary,
        schedule->time);

    fclose(file);
}

void list_schedules() {
    FILE *file = fopen(OUTPUT_FILENAME, "r");

    char file_line[MAX_LINE_LENGTH];
    while (fgets(file_line, sizeof(file_line), file) != NULL)
        puts(file_line);

    fclose(file);
}

void update_schedule(schedule *schedule) {
    FILE *file = fopen(OUTPUT_FILENAME, "r");
    FILE *temp = fopen("temp.txt", "w+");

    if (file == NULL)
        perror("Erro para abrir arquivo de saida!\n");

    char file_line[MAX_LINE_LENGTH];
    while (fgets(file_line, sizeof(file_line), file) != NULL) {
        int id;
        sscanf(file_line, "ID: %d", &id);

        if (schedule->id == id)
            fprintf(
                temp,
                "ID: %d | Nome do Tutor: %s | Nome do Pet: %s | Endereco: %s | Numero: %d | Telefone: %s | Raca: %s | Data: %s | Horario: %s | Tempo (horas): %d\n",
                schedule->id,
                schedule->tutor_name, schedule->pet_name, schedule->address, schedule->number, schedule->telephone,
                schedule->breed, schedule->date, schedule->horary,
                schedule->time);
        else
            fputs(file_line, temp);
    }

    fclose(file);
    fclose(temp);

    remove(OUTPUT_FILENAME);
    rename("temp.txt", OUTPUT_FILENAME);
}

void delete_schedule(int schedule_id) {
    FILE *file = fopen(OUTPUT_FILENAME, "r");
    FILE *temp = fopen("temp.txt", "w+");

    if (file == NULL)
        perror("Erro para abrir arquivo de saida!\n");

    char file_line[MAX_LINE_LENGTH];
    while (fgets(file_line, sizeof(file_line), file) != NULL) {
        int id;
        sscanf(file_line, "ID: %d", &id);

        if (id == schedule_id)
            continue;

        fputs(file_line, temp);
    }

    fclose(file);
    fclose(temp);

    remove(OUTPUT_FILENAME);
    rename("temp.txt", OUTPUT_FILENAME);
}
