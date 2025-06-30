#include "bdpaciente.h" /* Header da estrutura de dados bdpaciente*/
#include "paciente.h" /* Inclui header para estrutura de dados Paciente*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct paciente 
{
   int id; /*id do paciente*/
   char cpf[15]; /*cpf do paciente do paciente, 14 dígitos do cpf + '\0'*/
   char nome[51]; /*nome do paciente, até 50 caracteres*/
   int idade; /*idade do paciente*/
   char data[11]; /*data que o paciente foi cadastrado, 10 dígitos da data + '\0'*/
};

Paciente *criar_paciente(int id, char *cpf, char *nome, int idade, char *data) {
     Paciente *paciente = (Paciente *)malloc(sizeof(Paciente)); /* Aloca memória para a estrutura da BDPaciente de pacientes*/
     paciente->id=id;
     strcpy(paciente->cpf,cpf);                                      
     strcpy(paciente->nome,nome);
     paciente->idade = idade;
     strcpy(paciente->data,data); /*define os elementos da estrutura paciente criados 
     com os valores tirados do arquivo e usa a função strcpy para copiar o conteúdo da 
     variável para estrutura caso seja uma string*/
     return paciente;
}
