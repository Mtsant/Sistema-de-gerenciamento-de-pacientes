#include "trabalho.h" // Inclui header para estrutura de dados Paciente
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void impr() {
    printf("1 - Consultar paciente\n");
    printf("2 - Atualizar paciente\n");
    printf("3 - Remover paciente\n");
    printf("4 - Inserir paciente\n");
    printf("5 - Imprimir lista de pacientes\n");
    printf("Q - Sair\n");	
}


int main() {
    char r;

    Paciente **lista = cargar();
    if (lista==NULL) {
        return 0;
    }
    Paciente *paciente;
    impr();
    paciente = lista[0];
    scanf("%c", &r);
    if (r=='1') {
        printf("oi\n");
    }

    return 0;
}
