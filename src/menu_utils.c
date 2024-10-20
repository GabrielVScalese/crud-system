#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/schedule_utils.h"

void remove_new_line(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

schedule *get_schedule_from_input() {
    schedule *one_schedule = malloc(sizeof(schedule));

    printf("Digite o nome do tutor do pet: ");
    fgets(one_schedule->tutor_name, sizeof(one_schedule->tutor_name), stdin);
    remove_new_line(one_schedule->tutor_name); // Remove '\n'

    printf("Digite o nome do pet: ");
    fgets(one_schedule->pet_name, sizeof(one_schedule->pet_name), stdin);
    remove_new_line(one_schedule->pet_name); // Remove '\n'

    printf("Digite o endereco do cliente: ");
    fgets(one_schedule->address, sizeof(one_schedule->address), stdin);
    remove_new_line(one_schedule->address); // Remove '\n'

    char buffer[100];

    printf("Digite o numero do endereco: ");
    fgets(buffer, sizeof(buffer), stdin);
    one_schedule->number = atoi(buffer);

    printf("Digite o telefone do cliente: ");
    fgets(one_schedule->telephone, sizeof(one_schedule->telephone), stdin);
    remove_new_line(one_schedule->telephone);

    printf("Digite a raca do pet: ");
    fgets(one_schedule->breed, sizeof(one_schedule->breed), stdin);
    remove_new_line(one_schedule->breed);

    printf("Digite a data do servico: ");
    fgets(one_schedule->date, sizeof(one_schedule->date), stdin);
    remove_new_line(one_schedule->date);

    printf("Digite o horario: ");
    fgets(one_schedule->horary, sizeof(one_schedule->horary), stdin);
    remove_new_line(one_schedule->horary);

    printf("Digite a duracao do servico: ");
    fgets(buffer, sizeof(buffer), stdin);
    one_schedule->time = atoi(buffer);

    return one_schedule;
}

void add_client() {
    printf("\n\033[34m-> Adicionando um cliente...\033[0m\n\n");

    schedule *schedule = get_schedule_from_input();

    schedule->id = get_last_id() + 1;
    save_schedule(schedule);

    printf("\nCliente salvo com sucesso!\n\n");
}

void list_clients() {
    printf("\n\033[34m-> Listando clientes...\033[0m\n\n");

    if (get_last_id() == 0) {
        printf("\033[31mNao existem clientes salvos!\033[0m\n\n");
        return;
    }

    list_schedules();
}

void update_client() {
    printf("\n\033[34m-> Atualizando cliente...\033[0m\n\n");

    if (get_last_id() == 0) {
        printf("\033[31mNao existem clientes salvos!\033[0m\n\n");
        return;
    }

    list_schedules();

    printf("Digite o ID do cliente a ser alterado: ");

    int id;
    scanf("%d", &id);
    getchar();

    printf("\n");
    schedule *schedule = get_schedule_from_input();
    schedule->id = id;
    update_schedule(schedule);

    printf("\nCliente alterado com sucesso!\n\n");
}

void delete_client() {
    printf("\n\033[34m-> Excluindo cliente...\033[0m\n\n");

    if (get_last_id() == 0) {
        printf("\033[31mNao existem clientes salvos!\033[0m\n\n");
        return;
    }

    list_schedules();

    printf("Digite o ID do cliente a ser excluido: ");

    int id;
    scanf("%d", &id);
    getchar();

    delete_schedule(id);

    printf("\nCliente deletado com sucesso!\n\n");
}

void menu(int *option) {
    printf("\033[32m-------------------\033[0m");
    printf("\033[32m\nAgenda de clientes\033[0m\n");
    printf("\033[32m-------------------\033[0m\n");

    printf("1 - Adicionar cliente\n");
    printf("2 - Listar clientes\n");
    printf("3 - Atualizar dados do cliente\n");
    printf("4 - Excluir cliente\n");
    printf("5 - Sair\n");

    printf("\nDigite sua opcao: ");
    scanf("%d", option);
    getchar();

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

