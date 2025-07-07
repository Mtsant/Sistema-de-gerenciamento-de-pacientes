#ifndef BDPACIENTE_H
#define BDPACIENTE_H

// Declaração de structs opacas
typedef struct bdpaciente BDPaciente;
typedef struct bdpaciente_no BDPno;

#include "paciente.h"

// Funções públicas
BDPaciente *criar_bd();//cria o banco
BDPaciente *carregar();//carregas os arquivos de bd_paciente.csv no BDPaciente
void inserir(BDPaciente *BDPaciente); //insere um paciente no BDPaciente
void atualizar(BDPaciente *BDPaciente); //atualiza um paciente no BDPaciente
void remover(BDPaciente *BDPaciente); //remove um paciente do BDPaciente
void consultar(BDPaciente *BDPaciente); //consulta um paciente no BDPaciente
void imprimir_pcie(BDPaciente *BDPaciente); //imprime todos os pacientes
BDPno* procurarNo(BDPaciente *BDPaciente, int id); //procura um paciente no BDPaciente
void terminar(BDPaciente *BDPaciente); //encerra o programa liberando memória e registrando as alterações no banco
void terminar_erro(BDPaciente *BDPaciente); //encerra o programa liberando memória caso dê erro ao carregar os pacientes em BPPaciente

#endif