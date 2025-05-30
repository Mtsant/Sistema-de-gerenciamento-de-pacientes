#include "paciente.h" /*Inclui header para estrutura de dados Paciente*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void imprimir() {
    printf("1 - Consultar paciente\n");
    printf("2 - Atualizar paciente - indisponível\n");
    printf("3 - Remover paciente - indisponível\n");
    printf("4 - Inserir paciente - indisponível\n");
    printf("5 - Imprimir lista de pacientes\n");
    printf("Q - Sair\n");	
}


int main() {
    char linha[100]; /*string que vai guardar o que foi digitado pelo usuário, 
    não da problema até 100 caracteres*/
    char resposta; 
    imprimir();
    int qtd = 0;
    Paciente **BDPaciente = carregar(&qtd);
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
            consultar(BDPaciente, &qtd); /*se o usuário digitar um, chama a função de consulta*/
        }
        else if (resposta == '5') {
            imprimir_pcie(BDPaciente, &qtd); /*se o usuário digitar cinco, chama a função de imprimir
                                                todos os pacientes*/
        }
        else {
            printf("Valor inválido.\n"); /*caso o usuário digite qualquer outro caractere, imprime que o valor é inválido*/
        }
        imprimir();/*chama a função para imprimir as opções*/
    }

    fim(BDPaciente, &qtd); /*chama a função para liberar espaço alocado para BDPaciente*/
    return 0;
}
