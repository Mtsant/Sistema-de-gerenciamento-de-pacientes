#include "trabalho.h" // Inclui header para estrutura de dados Paciente
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void impr() {
    printf("1 - Consultar paciente\n");
    printf("2 - Atualizar paciente - indisponível\n");
    printf("3 - Remover paciente - indisponível\n");
    printf("4 - Inserir paciente - indisponível\n");
    printf("5 - Imprimir lista de pacientes\n");
    printf("Q - Sair\n");	
}


int main() {
    char r; //char que vai guardar o que foi digitado pelo usuário
    
    impr();

    int qtd = 0;
    Paciente **BDPaciente = cargar(&qtd);
    if (BDPaciente==NULL) {
        return 0;
    } //se o arquivo estiver vazio, termina a função
    scanf("%c", &r);
    while (toupper(r)!='Q') { //loop que termina somente quando o usuário digita q maiúsculo ou minúsculo
        if (r=='1') {
            consultar(BDPaciente, &qtd);
        } //caso o usuário digite 1, vai para função consultar
        
        if (r=='5') {
            imprimir_pcie(BDPaciente, &qtd);
        } //caso o usuário digite 5, imprime todos os pacientes e suas informações
            
        else { //caso o usuário digite nem q, nem 5, nem 1, imprime a mensagem "valor inválido"
            printf("Valor inválido.\n");
        }
        impr();
        scanf(" %c", &r);
    }

    fim(BDPaciente, &qtd); //chama a função para liberar espaço alocado para BDPaciente
    
    return 0;
}
