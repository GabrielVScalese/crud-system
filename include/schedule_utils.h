#ifndef SCHEDULE_UTILS_H
#define SCHEDULE_UTILS_H

/**
 * Define o nome do arquivo de saida que contera os dados persistidos
 */
#define OUTPUT_FILENAME "output.txt"

/**
 * Define o tamanho maximo da linha do arquivo de saida
 */
#define MAX_LINE_LENGTH 1000

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
#define ADDRESS_LENGTH 100

/**
 * Define tamanho maximo da string horario
 */
#define HORARY_LENGTH 6

/**
 * Define tamanho maximo da string telefone
 */
#define TELEPHONE_LENGTH 12

/**
 * Define tamanho maximo da string raca
 */
#define BREED_LENGTH 100

/**
 * Define tamanho maximo da string date
 */
#define DATE_LENGTH 11

/**
 * Estrutura para armazenar dados uteis de um agendamento por parte do pet sitter
 */
typedef struct schedule {
 int id;
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

/**
 * Printa uma lista de todos os agendamentos no console
 */
void list_schedules();

/**
 * Obtem o ID do ultimo cliente
 * @return ID do ultimo cliente
 */
int get_last_id();

/**
 * Atualiza um agendamento (especificado pelo id) dentro da base de dados
 * @param schedule informacoes atualizadas do agendamento
 */
void update_schedule(schedule *schedule);

/**
 * Deleta um agendamento (especificado pelo id) dentro da base de dados
 * @param schedule_id id do agendamento a ser deletado
 */
void delete_schedule(int schedule_id);

#endif //SCHEDULE_UTILS_H
