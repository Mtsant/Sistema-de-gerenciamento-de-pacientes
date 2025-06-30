#ifndef PACIENTE_H
#define PACIENTE_H

/*Declaração de estrutura "paciente"*/
typedef struct paciente Paciente;

/*Funções*/

/*Função */
Paciente *criar_paciente(int id, char *cpf, char *nome, int idade, char *data); //aloca memória para a estrutura paciente

#endif
