#include <stdio.h>
#include "../include/schedule_utils.h"

void save_schedule(schedule *schedule) {
    FILE *file = fopen(OUTPUT_FILENAME, "w+");

    if (file == NULL)
        perror("Erro para abrir arquivo de saida!\n");

    fprintf(
        file,
        "Nome do Tutor: %s | Nome do Pet: %s | Endereco: %s | Numero: %d | Telefone: %s | Raca: %s | Horario: %s | Tempo (horas): %d",
        schedule->tutor_name, schedule->pet_name, schedule->address, schedule->number, schedule->telephone,
        schedule->breed, schedule->horary,
        schedule->time);

    fclose(file);
}
