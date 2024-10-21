#ifndef MENU_UTILS_H
#define MENU_UTILS_H

/**
 * Define o tamanho maximo do buffer para leitura
 */
#define MAX_BUFFER_LENGTH 100

/**
 * Menu que exibe opcoes do CRUD sobre o arquivo de saida padrao ou encerramento de programa
 * @param option indica qual sera a opcao do CRUD ou se eh para encerrar programa
 */
void menu(int *option);

#endif //MENU_UTILS_H
