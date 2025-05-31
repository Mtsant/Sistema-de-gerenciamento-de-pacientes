#ifndef PACIENTE_H
#define PACIENTE_H

/*Declaração de estrutura "paciente"*/
typedef struct paciente
{
   int id; /*id do paciente*/
   char cpf[15]; /*cpf do paciente do paciente, 14 dígitos do cpf + '\0'*/
   char nome[51]; /*nome do paciente, até 50 caracteres*/
   int idade; /*idade do paciente*/
   char data[11]; /*data que o paciente foi cadastrado, 10 dígitos da data + '\0'*/
} Paciente;

/*Funções*/

/*Função para carregar o arquivo .csv na coleção de pacientes BDPacientes*/
Paciente **carregar(int *qtd);

/*Função ainda não implementada*/
void inserir(Paciente **BDPaciente, int *qtd);

/*Função ainda não implementada*/
Paciente atualizar();

/*Função ainda não implementada*/
Paciente remover();

/*Função ainda não implementada*/
void consultar(Paciente **BDPaciente, int *qtd);

/*Função ainda não implementada*/
void imprimir_pcie(Paciente **BDPaciente, int *qtd);

/*Função ainda não implementada*/
void fim(Paciente **BDPaciente, int *qtd);

#endif
