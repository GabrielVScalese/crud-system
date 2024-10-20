#include <stdio.h>
#include <stdlib.h>
#include "../include/schedule_utils.h"

int get_last_id() {
    FILE *file = fopen(OUTPUT_FILENAME, "r");

    if (file == NULL)
        return 1;

    int id;
    while (fscanf(file, "ID: %d", &id) != 1);
    fclose(file);

    return id;
}

void save_schedule(schedule *schedule) {
    FILE *file = fopen(OUTPUT_FILENAME, "w+");

    if (file == NULL)
        perror("Erro para abrir arquivo de saida!\n");

    fprintf(
        file,
        "ID: %d | Nome do Tutor: %s | Nome do Pet: %s | Endereco: %s | Numero: %d | Telefone: %s | Raca: %s | Data: %s | Horario: %s | Tempo (horas): %d",
        schedule->id,
        schedule->tutor_name, schedule->pet_name, schedule->address, schedule->number, schedule->telephone,
        schedule->breed, schedule->date, schedule->horary,
        schedule->time);

    fclose(file);
}

void list_schedules(schedule schedules[], int quantity) {
    printf("Lista de clientes:\n\n");

    for (int i = 0; i < quantity; i++)
        printf(
            "Nome do Tutor: %s | Nome do Pet: %s | Endereco: %s | Numero: %d | Telefone: %s | Raca: %s | Data: %s | Horario: %s | Tempo (horas): %d\n",
            schedules[i].tutor_name, schedules[i].pet_name, schedules[i].address, schedules[i].number,
            schedules[i].telephone,
            schedules[i].breed, schedules[i].date, schedules[i].horary, schedules[i].time);
}

void update_schedule(schedule *schedule, int schedule_id) {
    FILE *file = fopen(OUTPUT_FILENAME, "r");
    FILE *temp = fopen("temp.txt", "w+");

    if (file == NULL)
        perror("Erro para abrir arquivo de saida!\n");

    char file_line[MAX_LINE_LENGTH];
    while (fgets(file_line, sizeof(file_line), file) != NULL) {
        int id;
        sscanf(file_line, "ID: %d", &id);

        if (id == schedule_id)
            fprintf(
                temp,
                "ID: %d | Nome do Tutor: %s | Nome do Pet: %s | Endereco: %s | Numero: %d | Telefone: %s | Raca: %s | Data: %s | Horario: %s | Tempo (horas): %d",
                schedule->id,
                schedule->tutor_name, schedule->pet_name, schedule->address, schedule->number, schedule->telephone,
                schedule->breed, schedule->date, schedule->horary,
                schedule->time);
        else
            fputs(temp, file_line);
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

        fputs(temp, file_line);
    }

    fclose(file);
    fclose(temp);

    remove(OUTPUT_FILENAME);
    rename("temp.txt", OUTPUT_FILENAME);
}
