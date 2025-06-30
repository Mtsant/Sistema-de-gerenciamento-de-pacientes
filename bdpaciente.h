#ifndef BDPACIENTE_H
#define BDPACIENTE_H

/*Declaração de estrutura bdpaciente*/
typedef struct bdpaciente BDPaciente;
typedef struct bdpaciente_no BDPno;

#include "paciente.h"

struct bdpaciente {
   int qtd; /*qtd de pacientes no banco*/
   BDPno *primeiro;
   BDPno *ultimo;
};

struct bdpaciente_no {
   Paciente *info;
   BDPno *next;
   BDPno *prev;
};

/*Funções*/

BDPaciente *criar_bd();

/*Função para carregar o arquivo .csv na coleção de pacientes BDPacientes*/
BDPaciente *carregar();

/*Função */
void inserir(BDPaciente *BDPaciente);

/*Função ainda não implementada*/
void atualizar();

/*Função ainda não implementada*/
void remover();

/*Função ainda não implementada*/
void consultar(BDPaciente *BDPaciente);

int consultar_aux(BDPaciente *BDPaciente);

/*Função ainda não implementada*/
void imprimir_pcie(BDPaciente *BDPaciente);

/*Função ainda não implementada*/
void terminar(BDPaciente *BDPaciente);

#endif