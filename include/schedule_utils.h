#ifndef SCHEDULE_UTILS_H
#define SCHEDULE_UTILS_H

/**
 * Define o nome do arquivo de saida que contera os dados persistidos
 */
#define OUTPUT_FILENAME "output.txt"

/**
 * Define tamanho maximo da string nome do tutor
 */
#define TUTOR_NAME_LENGTH 100

/**
 * Define tamanho maximo da string nome do pet
 */
#define PET_NAME_LENGTH 100

/**
 * Define tamanho maximo da string endereco do cliente
 */
#define ADDRESS_LENGTH 30

/**
 * Define tamanho maximo da string horario
 */
#define HORARY_LENGTH 5

/**
 * Define tamanho maximo da string telefone
 */
#define TELEPHONE_LENGTH 11

/**
 * Define tamanho maximo da string raca
 */
#define BREED_LENGTH 30

/**
 * Define tamanho maximo da string date
 */
#define DATE_LENGTH 8

/**
 * Estrutura para armazenar dados uteis de um agendamento por parte do pet sitter
 */
typedef struct schedule {
 char tutor_name[TUTOR_NAME_LENGTH];
 char pet_name[PET_NAME_LENGTH];
 char address[ADDRESS_LENGTH];
 int number;
 char telephone[TELEPHONE_LENGTH];
 char breed[BREED_LENGTH];
 char date[DATE_LENGTH];
 char horary[HORARY_LENGTH];
 int time;
} schedule;

/**
 * Salva os dados de um agendamento num arquivo de saida padrao
 * @param schedule estrutura que contem os dados do agendamento
 */
void save_schedule(schedule *schedule);

#endif //SCHEDULE_UTILS_H
