#include "trabalho.h" // Inclui header para estrutura de dados Paciente
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//void adicionar(Paciente **lista, int *qtd) {
   //qtd
//}

Paciente **cargar(int *qtd) { //carrega os arquivos de bd_paciente.csv em uma lista de pacientes
   FILE *a = fopen("bd_paciente.csv", "rt"); // Abre o arquivo para leitura
   if (a == NULL) {
      printf("Arquivo não encontrado\n");
      return NULL; // Retorna nulo caso não seja possível abrir o arquivo
   }

   Paciente **lista = (Paciente **)malloc(1000 * sizeof(Paciente*)); //aloca memória para lista
   if (lista == NULL) {
      printf("Erro ao alocar memória\n");
      return NULL; // Retorna nulo caso não seja possível abrir o arquivo
   }

   int id;
   char cpf[15];
   char nome[51];
   int idade;
   char data[11];
   int i=0; //variáveis que irão guardar os valores obtidos da linha iterada do arquivo
   while (fscanf(a, "%d,%14[^,],%50[^,],%d,%10[^\n]", &id, cpf, nome, &idade, data) == 5) { //loop percorrendo cada linha do arquivo, separando variáveis por vírgula
      Paciente *paciente = (Paciente *)malloc(sizeof(Paciente)); // Aloca memória para a estrutura da lista de pacientes
      if (paciente == NULL) {
         printf("Erro ao alocar memória para paciente, encerrando programa.");
         return NULL;
      }//encerra programa caso haja um erro ao alocar espaço para o paciente
      paciente->id=id;
      strcpy(paciente->cpf,cpf);                                      
      strcpy(paciente->nome,nome);
      paciente->idade = idade;
      strcpy(paciente->data,data); //define os elementos da estrutura paciente criados com os valores tirados do arquivo e usa a função strcpy para copiar o conteúdo da variável para estrutura caso seja uma string
      lista[i]=paciente; //adiciona o paciente ao conjunto
      i++; //contador para saber a quantidade de pacientes
   }

   *qtd = i; //quantidade de pacientes
   fclose(a); //fecha o arquivo
   return lista;
}

void consultar(Paciente **pacientes, int *qtd) {
   char n;
   char v[51]; //variável que guarda o que o usuário escreverá, é usada tanto para procura por cpf como por nome
   printf("Escolha o modo de consulta\n");
   printf("1 - Por nome\n");
   printf("2 - Por CPF\n");
   printf("3 - Retornar ao menu principal\n");
   scanf(" %c", &n);

   while(n!='3') { //loop que termina somente quando o usuário digita 3
      if (n=='1'){ //consulta por nome
         printf("Digite o nome:\n");
         scanf("%50s", v);
         printf("%-5s %-15s %-30s %-7s %-12s\n", "ID", "CPF", "Nome", "Idade", "Data Cadastro"); //imprime usando tamanho de string determinado
         for (int i=0; i<*qtd; i++) { //passa pela lista uma quantidade de vezes igual ao tamanho da lista
            if (strstr(pacientes[i]->nome, v) != NULL) { //verifica se a string presente no valor digitado pelo usuário condiz com alguma parte do nome de alguém
               printf("%-5d %-15s %-30s %-7d %-12s\n", pacientes[i]->id, pacientes[i]->cpf, pacientes[i]->nome, pacientes[i]->idade, pacientes[i]->data); //caso string v tenha uma parte igual ao nome de alguém, imprime as informações daquela pessoa
            }
         }
      }

      else if (n=='2') { //consulta por cpf
         printf("Digite o cpf:\n");
         scanf("%50s", v);
         printf("%-5s %-15s %-30s %-7s %-12s\n", "ID", "CPF", "Nome", "Idade", "Data Cadastro"); //imprime usando tamanho de string determinado
         for (int i=0; i<*qtd; i++) { //passa pela lista uma quantidade de vezes igual ao tamanho da lista
            if (strstr(pacientes[i]->cpf, v) != NULL) { //verifica se a string presente no valor digitado pelo usuário condiz com alguma parte do cpf de alguém
               printf("%-5d %-15s %-30s %-7d %-12s\n", pacientes[i]->id, pacientes[i]->cpf, pacientes[i]->nome, pacientes[i]->idade, pacientes[i]->data); //caso string v tenha uma parte igual ao nome de alguém, imprime as informações daquela pessoa
            }
         }
      }

      else if (n!='3') { //se o usuário digite 3, ele quer sair da função, portanto, essa mensagem não aparece, porém se digitar outro valor, mostra essa mensagem a ele
         printf("Valor inválido.\n");
      }
      printf("Escolha o modo de consulta\n");
      printf("1 - Por nome\n");
      printf("2 - Por CPF\n");
      printf("3 - Retornar ao menu principal\n");
      scanf(" %c", &n);
   }
}

void imprimir_pcie(Paciente **pacientes, int *qtd) {
   printf("%-5s %-15s %-30s %-7s %-12s\n", "ID", "CPF", "Nome", "Idade", "Data Cadastro"); //imprime usando tamanho de string determinado
   for (int i=0;i<*qtd;i++){ //passa pela lista uma quantidade de vezes igual ao tamanho da lista
      printf("%-5d %-15s %-30s %-7d %-12s\n", pacientes[i]->id, pacientes[i]->cpf, pacientes[i]->nome, pacientes[i]->idade, pacientes[i]->data); //imprime usando tamanho de string determinado
   }
}

void fim(Paciente **pacientes, int *qtd) { //função para liberar o espaço ocupado pelos pacientes e sua lista
   for (int i=0;i<*qtd;i++) {
      free(pacientes[i]); //passa pela lista de pacientes liberando espaço
   }
   free(pacientes); //libera espaço da lista de pacientes
}
