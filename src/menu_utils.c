#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/schedule_utils.h"

schedule *get_schedule_from_input() {
    schedule *schedule = malloc(sizeof(schedule));

    printf("Digite o nome do tutor do pet: ");
    fgets(schedule->tutor_name, sizeof(schedule->tutor_name), stdin);
    schedule->tutor_name[strlen(schedule->tutor_name) - 1] = '\0';

    printf("\nDigite o nome do pet: ");
    fgets(schedule->pet_name, sizeof(schedule->pet_name), stdin);
    schedule->pet_name[strlen(schedule->pet_name) - 1] = '\0';

    printf("\nDigite o endereco do cliente: ");
    fgets(schedule->address, sizeof(schedule->address), stdin);
    schedule->address[strlen(schedule->address) - 1] = '\0';

    printf("\nDigite o numero do endereco: ");
    scanf("%d", &schedule->number);

    printf("\nDigite o telefone do cliente: ");
    scanf("%s", &schedule->telephone);

    printf("\nDigite a raca do pet: ");
    scanf("%s", &schedule->breed);

    printf("\nDigite a raca do pet: ");
    scanf("%s", &schedule->breed);

    printf("\nDigite a data do servico: ");
    scanf("%s", &schedule->date);

    printf("\nDigite o horario: ");
    scanf("%s", &schedule->horary);

    printf("\nDigite a duracao do servico: ");
    scanf("%s", &schedule->horary);
}

void add_client() {
    system("clear");
    printf("Adicionando um cliente...\n");

    schedule *schedule = get_schedule_from_input();
    schedule->id = get_last_id();
    save_schedule(schedule);

    printf("\n\n Cliente salvo com sucesso!");
}

void list_clients() {
    printf("Listando clientes...\n");

    list_schedules();
}

void update_client() {
    printf("Atualizando cliente...\n");

    list_schedules();

    printf("Digite o ID do cliente a ser alterado: ");

    int id;
    scanf("%d", &id);
    getchar();

    schedule *schedule = get_schedule_from_input();
    update_schedule(schedule, id);

    printf("\n\nCliente alterado com sucesso!");
}

void delete_client() {
    printf("Excluindo cliente...\n");

    list_schedules();

    printf("Digite o ID do cliente a ser excluido: ");

    int id;
    scanf("%d", &id);
    getchar();

    delete_schedule(id);

    printf("\n\nCliente deletado com sucesso!");
}

void menu(int *option) {
    system("clear");
    printf("Agenda de clientes\n");
    printf("--------------\n\n");

    printf("1 - Adicionar cliente\n");
    printf("2 - Listar clientes\n");
    printf("3 - Atualizar dados do cliente\n");
    printf("4 - Excluir cliente\n");
    printf("5 - Sair\n");

    printf("\nDigite sua opcao: ");
    scanf("%d", option);

    switch (*option) {
        case 1: add_client();
            break;
        case 2: list_clients();
            break;
        case 3: update_client();
            break;
        case 4: delete_client();
            break;
        case 5: *option = 5;
            break;
    }

    if (*option != 5)
        menu(option);
}

