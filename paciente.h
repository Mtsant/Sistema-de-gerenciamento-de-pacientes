#ifndef PACIENTE_H
#define PACIENTE_H

/*declaração de estrutura paciente opaca*/
typedef struct paciente Paciente;

/*funções de criação e destruição*/
Paciente *criar_paciente(int id, char *cpf, char *nome, int idade, char *data);
void destruir_paciente(Paciente *paciente);

/*getters*/
int paciente_get_id(const Paciente *paciente);
const char *paciente_get_cpf(const Paciente *paciente);
const char *paciente_get_nome(const Paciente *paciente);
int paciente_get_idade(const Paciente *paciente);
const char *paciente_get_data(const Paciente *paciente);

/*setters*/
void paciente_set_id(Paciente *paciente, int id);
void paciente_set_cpf(Paciente *paciente, const char *cpf);
void paciente_set_nome(Paciente *paciente, const char *nome);
void paciente_set_idade(Paciente *paciente, int idade);
void paciente_set_data(Paciente *paciente, const char *data);

#endif
