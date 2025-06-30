#ifndef BDPACIENTE_H
#define BDPACIENTE_H

// Declaração de structs opacas
typedef struct bdpaciente BDPaciente;
typedef struct bdpaciente_no BDPno;

#include "paciente.h"

// Funções públicas
BDPaciente *criar_bd();
BDPaciente *carregar();
void inserir(BDPaciente *BDPaciente);
void atualizar(BDPaciente *BDPaciente);
void remover(BDPaciente *BDPaciente);
void consultar(BDPaciente *BDPaciente);
void imprimir_pcie(BDPaciente *BDPaciente);
BDPno* procurarNo(BDPaciente *BDPaciente, int id);
void terminar(BDPaciente *BDPaciente);

#endif