#include "bdpaciente.h" /* Header da estrutura de dados bdpaciente*/
#include "paciente.h" /* Inclui header para estrutura de dados Paciente*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct bdpaciente {
   int qtd; //qtd de pacientes no banco
   BDPno *primeiro; //ponteiro para o primeiro paciente
   BDPno *ultimo; //ponteiro para o último paciente
};

struct bdpaciente_no { //estrutura que guarda os pacientes
   Paciente *info; //ponteiro para a estrutura paciente
   BDPno *next; //ponteiro para o próximo paciente
   BDPno *prev; //ponteiro para o paciente anterior
};

/*função para criar o BDPaciente*/
BDPaciente *criar_bd() { 
	BDPaciente *bd = (BDPaciente *)malloc(sizeof(BDPaciente)); //aloca memória para a estrutura BDPaciente
	bd->qtd = 0; //inicializa a quantidade de pacientes como 0
	bd->primeiro = NULL; //inicializa o primeiro paciente como NULL
	bd->ultimo = NULL; //inicializa o último paciente como NULL
	return bd;
}

BDPaciente *carregar() { /*carrega os arquivos de bd_paciente.csv em uma BDPaciente de pacientes*/
   FILE *a = fopen("bd_paciente.csv", "rt"); /* Abre o arquivo para leitura*/
   if (a == NULL) {
	  printf("Arquivo não encontrado\n");
	  return NULL; /* Retorna nulo caso não seja possível abrir o arquivo*/
   }

   BDPaciente *BDPaciente = criar_bd(); /*cria BDPaciente*/
   if (BDPaciente == NULL) {
	  printf("Erro ao alocar memória\n");
	  return NULL; /* Retorna nulo caso não seja possível abrir o arquivo*/
   }

   int id;
   char cpf[15];
   char nome[51];
   int idade;
   char data[11];
   int i=0; /*variáveis que irão guardar os valores obtidos da linha iterada do arquivo*/
   while (fscanf(a, "%d,%14[^,],%50[^,],%d,%10[^\n]", &id, cpf, nome, &idade, data) == 5) { /*loop percorrendo cada linha do arquivo, separando variáveis por vírgula*/
	   Paciente *paciente = criar_paciente(id, cpf, nome, idade, data);
	   if (paciente == NULL) {
		  printf("Erro ao alocar memória para paciente, encerrando programa.");
		  terminar_erro(BDPaciente);
		  return NULL;
	   } /*encerra programa caso haja um erro ao alocar espaço para o paciente*/
	   BDPno *no = (BDPno *)malloc(sizeof(BDPno));
	   no->info = paciente;
	   no->next = BDPaciente->primeiro;
	   no->prev = NULL;
	   if (i == 0) {
		   BDPaciente->ultimo = no;
	   }
	   else {
		   BDPaciente->primeiro->prev = no;
	   }
	   BDPaciente->primeiro = no; /*adiciona o paciente ao conjunto*/
	   i++; /*contador para saber a quantidade de pacientes*/
   }

   BDPaciente->qtd=i; /*quantidade de pacientes*/
   fclose(a); /*fecha o arquivo*/
   return BDPaciente;
}

void consultar(BDPaciente *BDPaciente) {
   char linha[10];
   char n;
   char v[51]; /*variável que guarda o que o usuário escreverá, é usada tanto para procura 
   por cpf como por nome*/

   while(1) { /*loop que termina somente quando o usuário digita 3*/

	  printf("Escolha o modo de consulta\n");
	  printf("1 - Por nome\n");
	  printf("2 - Por CPF\n");
	  printf("3 - Retornar ao menu principal\n");

	  fgets(linha, sizeof(linha), stdin);

	  if (strlen(linha) != 2 || linha[1] != '\n') {
		 printf("Valor inválido.\n");
		 continue;
	  }

	  n = linha[0];

	  if (n=='3') {
		 break;
	  }

	  if (n=='1'){ /*consulta por nome*/
		 BDPno *no = BDPaciente->ultimo;
		 printf("Digite o nome:\n");
		 fgets(v, sizeof(v), stdin);
		 v[strcspn(v, "\n")] = 0; //remove o enter
		 printf("%-5s %-15s %-30s %-7s %-12s\n", "ID", "CPF", "Nome", "Idade", "Data Cadastro"); /*imprime usando tamanho de string determinado*/
		 while (no!=NULL) { /*passa por BDPaciente uma quantidade de vezes igual ao tamanho de BDPaciente*/
			if (strstr(paciente_get_nome(no->info), v) != NULL) { /*verifica se a string presente no valor digitado pelo usuário condiz com alguma parte do nome de alguém*/
			   printf("%-5d %-15s %-30s %-7d %-12s\n", paciente_get_id(no->info), paciente_get_cpf(no->info), paciente_get_nome(no->info), paciente_get_idade(no->info), paciente_get_data(no->info)); /*caso string v tenha uma parte igual ao nome de alguém, imprime as informações daquela pessoa*/
			}
			no = no->prev;
		 }
	  }

	  else if (n=='2') { /*consulta por cpf*/
		 BDPno *no = BDPaciente->ultimo;
		 printf("Digite o cpf:\n");
		 fgets(v, sizeof(v), stdin);
		 v[strcspn(v, "\n")] = 0; //remove o enter
		 printf("%-5s %-15s %-30s %-7s %-12s\n", "ID", "CPF", "Nome", "Idade", "Data Cadastro"); /*imprime usando tamanho de string determinado*/
		 while (no!=NULL) { /*passa por BDPaciente uma quantidade de vezes igual ao tamanho da BDPaciente*/
			if (strstr(paciente_get_cpf(no->info), v) != NULL) { /*verifica se a string presente no valor digitado pelo usuário condiz com alguma parte do cpf de alguém*/
				printf("%-5d %-15s %-30s %-7d %-12s\n", paciente_get_id(no->info), paciente_get_cpf(no->info), paciente_get_nome(no->info), paciente_get_idade(no->info), paciente_get_data(no->info)); /*caso string v tenha uma parte igual ao nome de alguém, imprime as informações daquela pessoa*/
			}
			no = no->prev;
		 }
	  }

	  else { /*se o usuário digite 3, ele quer sair da função, portanto, essa mensagem não aparece, porém se digitar outro valor, mostra essa mensagem a ele*/
		 printf("Valor inválido.\n");
	  }
   }
}

/*função auxiliar para consulta usada por outras funções, diferente da outra porque se o usuário não colocar nem 1 nem 2 a função encerra*/
int consultar_aux(BDPaciente *BDPaciente) {
   char linha[10];
   char n;
   char v[51]; /*variável que guarda o que o usuário escreverá, é usada tanto para procura 
   por cpf como por nome*/

   printf("Escolha o modo de consulta\n");
   printf("1 - Por nome\n");
   printf("2 - Por CPF\n");
   printf("Outro caractere qualquer - Retornar ao menu principal\n");
   fgets(linha, sizeof(linha), stdin);

   n = linha[0];


	if (n=='1'){ /*consulta por nome*/
		BDPno *no = BDPaciente->ultimo;
		printf("Digite o nome:\n");
		fgets(v, sizeof(v), stdin);
		v[strcspn(v, "\n")] = 0; //remove o enter
		printf("%-5s %-15s %-30s %-7s %-12s\n", "ID", "CPF", "Nome", "Idade", "Data Cadastro"); /*imprime usando tamanho de string determinado*/
		while (no!=NULL) { /*passa por BDPaciente uma quantidade de vezes igual ao tamanho de BDPaciente*/
			if (strstr(paciente_get_nome(no->info), v) != NULL) { /*verifica se a string presente no valor digitado pelo usuário condiz com alguma parte do nome de alguém*/
			   printf("%-5d %-15s %-30s %-7d %-12s\n", paciente_get_id(no->info), paciente_get_cpf(no->info), paciente_get_nome(no->info), paciente_get_idade(no->info), paciente_get_data(no->info)); /*caso string v tenha uma parte igual ao nome de alguém, imprime as informações daquela pessoa*/
			}
			no = no->prev;
		}
		return 0;
	}

	if (n=='2') { /*consulta por cpf*/
		BDPno *no = BDPaciente->ultimo;
		printf("Digite o cpf:\n");
		fgets(v, sizeof(v), stdin);
		v[strcspn(v, "\n")] = 0; //remove o enter
		printf("%-5s %-15s %-30s %-7s %-12s\n", "ID", "CPF", "Nome", "Idade", "Data Cadastro"); /*imprime usando tamanho de string determinado*/
		while (no!=NULL) { /*passa por BDPaciente uma quantidade de vezes igual ao tamanho da BDPaciente*/
			if (strstr(paciente_get_cpf(no->info), v) != NULL) { /*verifica se a string presente no valor digitado pelo usuário condiz com alguma parte do cpf de alguém*/
				printf("%-5d %-15s %-30s %-7d %-12s\n", paciente_get_id(no->info), paciente_get_cpf(no->info), paciente_get_nome(no->info), paciente_get_idade(no->info), paciente_get_data(no->info)); /*caso string v tenha uma parte igual ao nome de alguém, imprime as informações daquela pessoa*/
			}
			no = no->prev;
		}
		return 0;
	}


	if (n!='1' || n!='2') {
		return 1;
	} /*se o usuário não digitar nem 1 ou 2 encerra a função e retorna 1 de modo a alertar a função que a chama para ser cancelada*/

}

void imprimir_pcie(BDPaciente *BDPaciente) {
   printf("%-5s %-15s %-30s %-7s %-12s\n", "ID", "CPF", "Nome", "Idade", "Data Cadastro"); /*imprime usando tamanho de string determinado*/
   BDPno *no = BDPaciente->ultimo;
   while (no!=NULL){ /*passa por BDPaciente uma quantidade de vezes igual ao tamanho da BDPaciente*/
	  printf("%-5d %-15s %-30s %-7d %-12s\n", paciente_get_id(no->info), paciente_get_cpf(no->info), paciente_get_nome(no->info), paciente_get_idade(no->info), paciente_get_data(no->info)); /*imprime usando tamanho de string determinado*/
	  no = no->prev;
   }
}

/*passa por BDPaciente procurando o paciente do mesmo id*/
BDPno* procurarNo(BDPaciente *BDPaciente, int id) {
	BDPno *no = BDPaciente->primeiro;
	while ((no != NULL) && (paciente_get_id(no->info) != id)){
		no = no->next;
	}
	return no;
}

void atualizar(BDPaciente *BDPaciente) {
	BDPno *no;
	int id;
	char r[10];
	char linha[10];
	char cpf[12];
	char cpff[15];
	char nome[51];
	int idade;
	char data[11];
	int ch;
	
	if (consultar_aux(BDPaciente)==1) {
		printf("Retornando ao menu.\n");
		return;
	} /*função auxiliar que, se der erro encerra essa função também*/

	printf("Digite o ID do registro a ser atualizado:\n");
	fgets(linha, sizeof(linha), stdin);
	sscanf(linha, "%d", &id);

	no = procurarNo(BDPaciente, id);
	if (no==NULL) {
		printf("ID não encontrado, retornando ao menu.\n");
		return;
	} /*procurando o paciente com o id digitado pelo usuário, se não existir, encerra a função*/

	printf("Digite o novo valor para os campos: CPF (apenas dígitos), nome, idade, e data de cadastro. Para manter o valor atual, digite '-'.\n");
	printf("CPF:\n");
	fgets(cpf, sizeof(cpf), stdin);
	cpf[strcspn(cpf, "\n")] = 0;
	if (strlen(cpf)!=11 && strcmp(cpf, "-") != 0) {
		printf("CPF inválido\n");
		return;
	} /*se o cpf não tiver 11 dígitos e não for igual a '-', encerra a função*/
	printf("Nome:\n");
	fgets(nome, sizeof(nome), stdin);
	nome[strcspn(nome, "\n")] = 0;
	printf("Idade:\n");
	fgets(linha, sizeof(linha), stdin);
	linha[strcspn(linha, "\n")] = 0;
	printf("Data de cadastro:\n");
	fgets(data, sizeof(data), stdin);
	data[strcspn(data, "\n")] = 0;

	if (strcmp(cpf, "-") == 0) {
		strcpy(cpf, paciente_get_cpf(no->info));
	}
	else {
		sprintf(cpff, "%.3s.%.3s.%.3s-%.2s", cpf, cpf + 3, cpf + 6, cpf + 9);
	} /*adiciona os pontos e hífen ao cpf*/
	if (strcmp(nome, "-") == 0) {
		strcpy(nome, paciente_get_nome(no->info));
	}
	if (strcmp(linha, "-") == 0) {
		sprintf(linha, "%d", paciente_get_idade(no->info));
	}
	if (strcmp(data, "-") == 0){
		strcpy(data, paciente_get_data(no->info));
	} /*se o usuário digitar hífen para o campo não muda ele*/

	printf("Para confirmar novos valores para o registro abaixo digite 'S'.\n\n");
	printf("%-5s %-15s %-30s %-7s %-12s\n", "ID", "CPF", "Nome", "Idade", "Data Cadastro");
	printf("%-5d %-15s %-30s %-7d %-12s\n", id, cpf, nome, atoi(linha), data);

	fgets(r, sizeof(r), stdin);
	if (r[0]=='S' || r[0]=='s') {
		paciente_set_cpf(no->info, cpf);
		paciente_set_nome(no->info, nome);
		if (sscanf(linha, "%d", &idade)==1) {
			paciente_set_idade(no->info, idade);
		}
		paciente_set_data(no->info, data);
		printf("Registro alterado.\n");
	}
}

void remover(BDPaciente *BDPaciente) {
	BDPno *no;
	int id;
	char r[10];
	char linha[10];
	
	if (consultar_aux(BDPaciente)==1) {
		printf("Retornando ao menu.\n");
		return;
	}
	printf("Digite o ID do registro a ser removido:\n");
	fgets(linha, sizeof(linha), stdin);
	sscanf(linha, "%d", &id);

	no = procurarNo(BDPaciente, id);
	if (no==NULL) {
		printf("ID não encontrado, retornando ao menu.");
		return;
	}

	printf("Tem certeza que deseja excluir o registro? Digite 'S' para confirmar.\n\n");
	printf("%-5s %-15s %-30s %-7s %-12s\n", "ID", "CPF", "Nome", "Idade", "Data Cadastro");
	printf("%-5d %-15s %-30s %-7d %-12s\n", paciente_get_id(no->info), paciente_get_cpf(no->info), paciente_get_nome(no->info), paciente_get_idade(no->info), paciente_get_data(no->info));

	fgets(r, sizeof(r), stdin);
	if (r[0]=='S' || r[0]=='s') {
		if (BDPaciente->primeiro==no) {
			BDPaciente->primeiro = no->next;
		} /*acerta os ponteiros, se for o primeiro paciente ou o último muda o ponteiro de BDPaciente, se não só muda o ponteiro de um nó para o outro*/
		else {
			no->prev->next = no->next;
		}
		if (BDPaciente->ultimo==no) {
			BDPaciente->ultimo = no->prev;
		}
		else {
			no->next->prev = no->prev;
		}
		free(no->info);
		free(no); /*libera a memória do paciente e do nó*/
	}
}

void inserir(BDPaciente *BDPaciente) {
	char linha[10];
	char cpf[12];
	char cpff[15];
	char nome[51];
	int idade;
	char data[11];
	char r[10];
	int ch;

	printf("Digite o valor para os campos: CPF (apenas dígitos), nome, idade, e data de cadastro.\n");
	printf("CPF:\n");
	fgets(cpf, sizeof(cpf), stdin);
	cpf[strcspn(cpf, "\n")] = 0;
	if (strlen(cpf)!=11) {
		printf("CPF inválido\n");
		return;
	}
	while ((ch = getchar()) != '\n' && ch != EOF);
	sprintf(cpff, "%.3s.%.3s.%.3s-%.2s", cpf, cpf + 3, cpf + 6, cpf + 9);
	printf("Nome:\n");
	fgets(nome, sizeof(nome), stdin);
	nome[strcspn(nome, "\n")] = 0;
	printf("Idade:\n");
	fgets(linha, sizeof(linha), stdin);
	linha[strcspn(linha, "\n")] = 0;
	if (sscanf(linha, "%d", &idade)!=1) {
		printf("Idade inválida.\n");
		return;
	}

	printf("Data de cadastro:\n");
	fgets(data, sizeof(data), stdin);
	data[strcspn(data, "\n")] = 0;
	while ((ch = getchar()) != '\n' && ch != EOF);


	printf("Confirma os valores para o novo registro? Digite 'S' para confirmar.\n\n");
	int novo_id = 1;
	if (BDPaciente->primeiro != NULL) {
		novo_id = paciente_get_id(BDPaciente->primeiro->info) + 1; 
	}
	printf("%-5s %-15s %-30s %-7s %-12s\n", "ID", "CPF", "Nome", "Idade", "Data Cadastro");
	printf("%-5d %-15s %-30s %-7d %-12s\n", novo_id, cpff, nome, atoi(linha), data);

	fgets(r, sizeof(r), stdin);
	if (r[0]=='S' || r[0]=='s') {
		Paciente *paciente = criar_paciente(novo_id, cpff, nome, idade, data);

		BDPno *no = (BDPno *)malloc(sizeof(BDPno));
		no->info = paciente;
		no->next = BDPaciente->primeiro;
		no->prev = NULL;
		if (BDPaciente->primeiro==NULL) {
			BDPaciente->ultimo = no;
		}
		else {
			BDPaciente->primeiro->prev = no;
		}
		BDPaciente->primeiro = no;
	}
}

void terminar(BDPaciente *BDPaciente) { /*função para liberar o espaço ocupado pelos pacientes e BDPaciente*/
	FILE *a = fopen("bd_paciente.csv", "wt"); /* Abre o arquivo para leitura*/
	   if (a == NULL) {
		  printf("Arquivo não encontrado\n");
		  return; /* Retorna nulo caso não seja possível abrir o arquivo*/
	}
	BDPno *no = BDPaciente->ultimo;
	BDPno *no2;
	while (no!=NULL) {
		no2 = no->prev;
		fprintf(a, "%d,%s,%s,%d,%s\n", paciente_get_id(no->info), paciente_get_cpf(no->info), paciente_get_nome(no->info), paciente_get_idade(no->info), paciente_get_data(no->info)); //escreve no arquivo as alterações no bqanco
		destruir_paciente(no->info); /*passa por BDPaciente liberando espaço da estrutura paciente individual*/
		free(no);
		no = no2;
   }
	fclose(a);
	free(BDPaciente); /*libera espaço de BDPaciente*/
}

void terminar_erro(BDPaciente *BDPaciente) { /*função para liberar o espaço ocupado pelos pacientes e BDPaciente*/
	BDPno *no = BDPaciente->ultimo;
	BDPno *no2;
	while (no!=NULL) {
		no2 = no->prev;
		destruir_paciente(no->info); /*passa por BDPaciente liberando espaço da estrutura paciente individual*/
		free(no);
		no = no2;
   }
	free(BDPaciente); /*libera espaço de BDPaciente*/
}