# Ep1
Trabalho prático de programação

Projeto para a leitura e manipulação de um arquivo "bd_paciente.csv", armazenamento de seus dados em uma estrutura paciente e funções que permitam que o usuário altere o arquivo de determinadas maneiras. Até o momento, apenas as funções de impressão dos dados dos pacientes que atendam aos parâmetros de pesquisa por nome e CPF e impressão dos dados de todos os pacientes foram implementadas.

# Execução

Para compilar, digita make e o arquivo será executado automaticamente.

Ao executar o programa, será impresso 6 opções, 3 delas disponíveis procurar um paciente por seu nome ou CPF "1 - Consultar paciente", imprimir as informações de todos os paciente "5 - Imprimir lista de pacientes" e de encerrar o programa "Q - Sair". Para acessar a elas, é precisso digitar somente o caractere que aparece antes do hífen, caso outro caractere (que não o 1, o 5 ou o Q) seja digitado, o programa irá imprimir a mensagem:
"Valor inválido."

Ao digitar "1", o programa te dará 3 opções, digitar 1 para buscar um paciente por nome, digitar 2 para buscar um paciente por CPF, ou digitar 3 para voltar a tela anterior. Então, você deverá digitar o parâmetro escolhido para que o programa procure na lista de pacientes aquele que diz respeito ao que foi digitado, então, o programa imprime as informações de todos os pacientes que tenham dentro do parâmetro de pesquisa selecionado algum trecho igual àquilo digitado pelo usuário. 

Para pesquisa por nome, é necessário digitar letras maiúsculas e para pesquisa por CPF, é necessário digitar os pontos e hífens.
