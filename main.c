#include "bdpaciente.h" /* Header da estrutura de dados bdpaciente*/
#include "paciente.h" /* Inclui header para estrutura de dados Paciente*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void imprimir() {
    printf("1 - Consultar paciente\n");
    printf("2 - Atualizar paciente\n");
    printf("3 - Remover paciente\n");
    printf("4 - Inserir paciente\n");
    printf("5 - Imprimir lista de pacientes\n");
    printf("Q - Sair\n");	
}


int main() {
    char linha[100]; /*string que vai guardar o que foi digitado pelo usuário, 
    não da problema até 100 caracteres*/
    char resposta; 
    imprimir();
    BDPaciente *BDPaciente = carregar();
    if (BDPaciente==NULL) {
        return 0;
    } /*se o arquivo estiver vazio, termina a função*/
    
    while (1) { /*loop que se matém infinitamente até ser dado o break em algum if*/
        printf("Digite sua opção: ");
        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            printf("Valor inválido.\n");
            imprimir();
            continue;
        } /*pega o valor digitado pelo usuário, coloca na variável "linha" e, caso o usuário digite 
        mais de um caractere, imprime valor inválido e reinicia o loop*/

        resposta = toupper(linha[0]); /*coloca o resultado da linha em maiúsculo de forma que
                                        não tenha diferença se o usuário digita q ou Q*/

        if (linha[0] == '\n' || linha[1] != '\n') {
            printf("Valor inválido.\n");
            imprimir();
            continue;
        }/*verifica se a resposta não é apenas enter, se for, imprime valor inválido e reinicia o loop*/
        
        if (resposta == 'Q') {
            break; /*se o usuário digitar q, encerra o loop*/
        }
        else if (resposta == '1') { 
            consultar(BDPaciente); /*se o usuário digitar um, chama a função de consulta*/
        }
        else if (resposta == '2') { 
            atualizar(BDPaciente); /*se o usuário digitar dois, chama a função de atualizar*/
        }
        else if (resposta == '3') { 
            remover(BDPaciente); /*se o usuário digitar três, chama a função de remover*/
        }
        else if (resposta == '4') { 
            inserir(BDPaciente); /*se o usuário digitar quatro, chama a função de inserir*/
        }
        else if (resposta == '5') {
            imprimir_pcie(BDPaciente); /*se o usuário digitar cinco, chama a função de imprimir
                                                todos os pacientes*/
        }
        else {
            printf("Valor inválido.\n"); /*caso o usuário digite qualquer outro caractere, imprime que o valor é inválido*/
        }
        imprimir();/*chama a função para imprimir as opções*/
    }

    terminar(BDPaciente); /*chama a função para liberar espaço alocado para BDPaciente*/
    return 0;
}
