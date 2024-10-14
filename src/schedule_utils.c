#include <stdio.h>
#include "../include/schedule_utils.h"

void save_schedule(schedule *schedule) {
    FILE *file = fopen(OUTPUT_FILENAME, "w+");

    if (file == NULL)
        perror("Erro para abrir arquivo de saida!\n");

    fprintf(
        file,
        "Nome do Tutor: %s | Nome do Pet: %s | Endereco: %s | Numero: %d | Telefone: %s | Raca: %s | Data: %s | Horario: %s | Tempo (horas): %d",
        schedule->tutor_name, schedule->pet_name, schedule->address, schedule->number, schedule->telephone,
        schedule->breed, schedule->date, schedule->horary,
        schedule->time);

    fclose(file);
}

void list_schedules(schedule schedules[], int quantity) {
    printf("Lista de clientes:\n\n");
    
    for (int i = 0; i < quantity; i++) 
        printf("Nome do Tutor: %s | Nome do Pet: %s | Endereco: %s | Numero: %d | Telefone: %s | Raca: %s | Data: %s | Horario: %s | Tempo (horas): %d\n",
               schedules[i].tutor_name, schedules[i].pet_name, schedules[i].address, schedules[i].number, schedules[i].telephone,
               schedules[i].breed, schedules[i].date, schedules[i].horary, schedules[i].time);
}
