# Sistema de gerenciamento de dados
## Trabalho prático de programação

Projeto para a leitura e manipulação de um arquivo "bd_paciente.csv", armazenamento de seus dados em uma estrutura paciente e funções que permitam que o usuário altere o arquivo de determinadas maneiras. Até o momento, apenas as funções de impressão dos dados dos pacientes que atendam aos parâmetros de pesquisa por nome e CPF e impressão dos dados de todos os pacientes foram implementadas.

# Repositório

O arquivo makefile é usado para compilar e executar o programa, bd_paciente.csv contém a lista de pacientes, main.c contém o programa principal, paciente.c contém as funções e trabalho.h é o header, que referencia as funções no arquivo paciente.c.

# Execução

Para compilar, digite "make", e o arquivo será executado automaticamente.

Ao executar o programa, será impresso 6 opções, 3 delas disponíveis procurar um paciente por seu nome ou CPF "1 - Consultar paciente", imprimir as informações de todos os paciente "5 - Imprimir lista de pacientes" e de encerrar o programa "Q - Sair". Para acessar a elas, é precisso digitar somente o caractere que aparece antes do hífen, caso outro caractere (que não o 1, o 5 ou o Q) seja digitado, o programa irá imprimir a mensagem:
"Valor inválido."

Ao digitar "1", o programa te dará 3 opções, digitar 1 para buscar um paciente por nome, digitar 2 para buscar um paciente por CPF, ou digitar 3 para voltar a tela anterior. Então, você deverá digitar o parâmetro escolhido para que o programa procure na lista de pacientes aquele que diz respeito ao que foi digitado, então, o programa imprime as informações de todos os pacientes que tenham dentro do parâmetro de pesquisa selecionado algum trecho igual àquilo digitado pelo usuário. 

Para pesquisar por nome, o programa diferencia letras maiúsculas de minúscalas. Para pesquisar por CPF, é necessário digitar os pontos e hífens.

# Funções

## carregar()
Essa função é chamada ao iniciar o programa e ela é responsável por ler o arquivo "bd_paciente.csv", a primeira informação é o id, a segunda o CPF, a terceira o nome, a quarta a idade e, por fim, a data em que o paciente foi cadastrado no sistema. Esses dados são gravados na estrutura "paciente" que, por sua vez, é guardada em BDPaciente. Essas informações são separadas por vírgula no arquivo, ou seja, ao encontrar uma vírgula, o programa parte para o próximo campo e, ao chegar no final da linha, armazena a estrutura em BDPaciente e passa para a próxima.

## consultar()
Função chamada ao digitar "1" no munu principal, passa por todos os pacientes (guardados em BDPaciente) e compara a string digitada pelo usuário, se o paciente em questão conter aquela string no respectivo campo escolhido pelo usuário, imprime todas as informações dele.

## consultar_aux()
Função chamada pelas funções **atualizar()**, **inserir()** e **remover()** que necessitam realizar uma consulta antes de realizarem seu objetivo principal, difere da função **consultar()** porque caso o usuário não digita nem "1" nem "2", ou seja, caso haja algum erro na consulta, encerra e também encerra a função que a chamou.

## procurarNo()
Função auxiliar utilizada pelas funções **remover()** e **atualizar()** para achar o nó informado pelo usuário para ser alterado.

## remover()
Função que convoca uma consulta para que o usuário possa ter certeza do paciente a ser removido e, então, pede um id. Caso o id não esteja presente em BDPaciente acaba a função, se ele existir, imprime as informações do paciente e pede confirmação para liberar espaço do nó que guarda o paciente e do próprio paciente. 

## atualizar()
Função que convoca uma consulta para que o usuário possa ter certeza do paciente a ser atualizado, que vai digitar o id do paciente, caso ele não exista encerra a função. Então o usuário terá de digitar todos os campos do paciente, se não quiser alterar determinado campo ele pode apenas digitar "-" que vai manter o mesmo. É impresso como as informações do paciente ficarão após a atualização e pede confirmação do usuário para atualizar.

## inserir()
Função que coloca outro paciente em BDPaciente. É solicitado do usuário que preencha cada campo e, após terminar, pede-se que confirme as informações.

## imprimir_pcie()
Função chamada ao digitar "5" no menu principal, passa por todos os pacientes (guardados em BDPaciente) e imprime suas informações na tela.

## terminar()
Função chamada ao digitar "q" (maiúsculo ou minúsculo) no menu principal. Ela recebe BDPaciente e itera por ele, liberando o espaço associado a cada nó da estrutura e cada paciente dentro do nó usando a função malloc por meio da função free(), antes de liberar memória, no entanto, registra as alterações feitas no banco e as escreve no arquivo .csv. Por fim, libera também a memória alocada a BDPaciente usando free().

# TADs

## paciente
O campo id e idade são números inteiros, correspondem ao identificador e à idade do paciente respectivamente. Os campos nome, data e cpf são strings que, com exceção do primeiro, têm um tamanho fixo para todos os pacientes, sendo ele o tamanho padrão do campo mais o caractere "\0", que delimita o final da string. A exemplo do cpf, que sempre possui 14 caracteres (incluindo pontos e hífen) além do último caractere "\0", totalizando 15 caracteres, registra o cpf do paciente. Como o nome pode ter um valor desconhecido de caracteres a depender do paciente, lhe foi dado um tamanho arbitrário de 50, mais o último caractere. A data corresponde ao dia de quando foi criado o paciente no sistema.

## bdpaciente_no
Cada nó armazena informações de determinado paciente e um ponteiro para o nó anterior e para o próximo, caso ele seja o primeiro seu ponteiro para o nó anterior é nulo da mesma forma que se ele for o último não possui ponteiro para nó posterior.

## bdpaciente
BDPaciente é uma lista duplamente encadeada com um ponteiro para o primeiro e o último nó e a quantidade de paciente.
