#ifndef TRABALHO_H
#define TRABALHO_H

//Declaração de estrutura "paciente"
typedef struct paciente
{
   int id;
   char cpf[15];
   char nome[51]; 
   int idade;
   char data[11];
} Paciente;

//Funções

//Função para inserir um paciente
Paciente **cargar(int *qtd);

void inserir(Paciente **BDPaciente, int *qtd);

Paciente atualizar();

Paciente remover();

void consultar(Paciente **BDPaciente, int *qtd);

void imprimir_pcie(Paciente **BDPaciente, int *qtd);

void fim(Paciente **BDPaciente, int *qtd);

#endif
