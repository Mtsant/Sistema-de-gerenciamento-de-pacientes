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

void destruir_paciente(Paciente *paciente) {
    free(paciente);
}

// Getters
int paciente_get_id(const Paciente *paciente) {
    return paciente->id;
}
const char *paciente_get_cpf(const Paciente *paciente) {
    return paciente->cpf;
}
const char *paciente_get_nome(const Paciente *paciente) {
    return paciente->nome;
}
int paciente_get_idade(const Paciente *paciente) {
    return paciente->idade;
}
const char *paciente_get_data(const Paciente *paciente) {
    return paciente->data;
}
// Setters
void paciente_set_id(Paciente *paciente, int id) {
    paciente->id = id;
}
void paciente_set_cpf(Paciente *paciente, const char *cpf) {
    strncpy(paciente->cpf, cpf, sizeof(paciente->cpf));
    paciente->cpf[sizeof(paciente->cpf)-1] = '\0';
}
void paciente_set_nome(Paciente *paciente, const char *nome) {
    strncpy(paciente->nome, nome, sizeof(paciente->nome));
    paciente->nome[sizeof(paciente->nome)-1] = '\0';
}
void paciente_set_idade(Paciente *paciente, int idade) {
    paciente->idade = idade;
}
void paciente_set_data(Paciente *paciente, const char *data) {
    strncpy(paciente->data, data, sizeof(paciente->data));
    paciente->data[sizeof(paciente->data)-1] = '\0';
}
