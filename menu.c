#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include "VectorDefinitions.h"
#include "Analicts.h"


#define TOTAL_COMPRA 15
#define MEIOS_PGMT_QNT 6

int menu(VectorDefinitions *vectorDefinitons){

    int menuOption = 0;
    printf("1 - Definir algoritmo de ordenacao\n");
    printf("2 - Definir tamanho do vetor\n");
    printf("3 - Escolher formato de entrada do vetor\n");
    printf("6 - Gerar relatorios\n");
    printf("-1 - Para sair\n");
    scanf("%d", &menuOption);

    if(menuOption == 1){
        printf("1 - BubbleSort\n");
        printf("2 - HeapSort\n");
        printf("3 - InsertionSort\n");
        printf("4 - MergeSort\n");
        printf("5 - QuickSort\n");
        printf("6 - SelectionSort\n");
        printf("7 - ShellSort\n");
        scanf("%d", &vectorDefinitons->orderAlgm);

    }else if(menuOption == 2){
        printf("Digite o tamanho do vetor\n");
        scanf("%ld", &vectorDefinitons->vectorSize);

    }else if(menuOption == 3){
        printf("1 - Ordem crescente\n");
        printf("2 - Ordem decrescente\n");
        printf("3 - Ordem aleatoria\n");
        scanf("%d", &vectorDefinitons->entryFormat);

    }else if(menuOption == 4){
        //TODO realizar ordenacao

    }else if(menuOption == -1){
        //*hasPressedEscape = 1;TODO escape
        
    }else{
        printf("Digite uma opcao valida\n");
    }
}



// void cadastroCliente(Cliente clientes[], long *clientesCount, long *lastClientId){
//     clientes[*clientesCount].id = ++(*lastClientId);
//     int clientType=0;
//     printf("Digite o nome do cliente \n");
//     scanf(" %s", &clientes[*clientesCount].nome);
//     printf("Digite o endereco do cliente \n");
//     scanf(" %s", &clientes[*clientesCount].endereco);
//     printf("Digite o telefone do cliente \n");
//     scanf(" %s", &clientes[*clientesCount].telefone);
//     printf("Digite a data que se tornou cliente \n");
//     scanf(" %s", &clientes[*clientesCount].desde);

//     printf("Digite 1 se o cliente eh Pessoa Fisica, ou\n");
//     printf("2 se o cliente eh Pessoa Juridica \n");
//     scanf("%d", &clientType);
//     if(clientType == 1){
//         printf("Digite o cpf do cliente \n");
//         scanf(" %lld", &clientes[*clientesCount].cpf);
//         clientes[*clientesCount].cnpj=0;
//         clientes[*clientesCount].inscEst=0;
//     }else if(clientType == 2){
//         printf("Digite o cnpj do cliente \n");
//         scanf(" %lld", &clientes[*clientesCount].cnpj);
//         printf("Digite a inscricao estadual do cliente \n");
//         scanf(" %lld", &clientes[*clientesCount].inscEst);
//         clientes[*clientesCount].cpf=0;
//     }
    
//     (*clientesCount)++;
// }

// void cadastroFornecedor(Fornecedor fornecedores[], long *fornecedorCount, long *lastFornecedorId){
//     fornecedores[*fornecedorCount].id = ++(*lastFornecedorId);
//     int clientType;
//     printf("Digite o nome do fornecedor \n");
//     scanf(" %s", &fornecedores[*fornecedorCount].nome);
//     printf("Digite o endereco do fornecedor \n");
//     scanf(" %s", &fornecedores[*fornecedorCount].endereco);
//     printf("Digite o telefone do fornecedor \n");
//     scanf(" %s", &fornecedores[*fornecedorCount].telefone);
//     printf("Digite o nome de uma pessoa de contato \n");
//     scanf(" %s", &fornecedores[*fornecedorCount].pessoaContato);
//     printf("Digite o cnpj do fornecedor \n");
//     scanf(" %lld",&fornecedores[*fornecedorCount].cnpj);
//     printf("Digite a inscricao estadual do fornecedor \n");
//     scanf(" %lld",&fornecedores[*fornecedorCount].inscEst);
    
//     (*fornecedorCount)++;
// }

// void cadastroProduto(Produto produtos[], long *produtosCount, long *lastProdutoCode){
//    produtos[*produtosCount].codigo = ++(*lastProdutoCode);
//     int clientType;
//     printf("Digite a descricao do produto \n");
//     scanf(" %s", &produtos[*produtosCount].descricao);
//     printf("Digite o estoque minimo do produto \n");
//     scanf(" %s", &produtos[*produtosCount].estMin);
//     printf("Digite o estoque atual do produto \n");
//     scanf(" %s", &produtos[*produtosCount].estAtual);
//     printf("Digite o custo do produto \n");
//     scanf("%.2f", &produtos[*produtosCount].custo);
//     printf("Digite o percentual de lucro do produto \n");
//     scanf("%.2f", &produtos[*produtosCount].perLucro);
//     produtos[*produtosCount].valor = produtos[*produtosCount].custo + (produtos[*produtosCount].custo * produtos[*produtosCount].perLucro);
//     produtos[*produtosCount].qntVendido = 0;
    
//     (*produtosCount)++;
// }

// void registroCompra(
//     CompraFornecedor compras[], 
//     Fornecedor fornecedores[], 
//     Produto produtos[],
//     long *comprasCount,
//     long *fornecedorCount, 
//     long *produtosCount,
//     long *lastFiscalNoteCode, 
//     long *lastFornecedorId, 
//     long *lastProdutoCode,
//     int comprasSize, 
//     int fornecedoresSize,
//     int produtoSize
//     ){
//     int hasRegister=0, fncdIndex=0;
//     printf("=======Registo de compra======= \n");
//     printf("Digite 1 se o fornecedor ja tem cadastro ou 2 para cadastrar \n");
//     scanf(" %d", &hasRegister);

//     if(hasRegister==1){
//         long long cnpj;
//         printf("Digite o cnpj do fornecedor \n");
//         scanf(" %lld", &cnpj);
//         fncdIndex = getIndexOfFornecedorByCNPJ(cnpj, fornecedores, *fornecedorCount);
//     }else if(hasRegister==2){
//         cadastroFornecedor(fornecedores, fornecedorCount, lastFornecedorId);
//         fncdIndex = *lastFornecedorId;
//     }
//     if(fncdIndex<0) {
//         printf("Nao foi possivel encontrar!");
//         return;
//     }

//     compras[*comprasCount].fornec = fornecedores[fncdIndex];

//     int produtoIndex=0;
//     printf("Digite 1 se o produto ja tem cadastro ou 2 para cadastrar \n");
//     scanf(" %d", &hasRegister);
//     if(hasRegister==1){
//         long long code;
//         printf("Digite o codigo do produto \n");
//         scanf(" %lld", &code);
//         produtoIndex = getIndexOfProdutoByCode(code, produtos, *produtosCount);
//     }else if(hasRegister==2){
//         cadastroProduto(produtos, produtosCount, lastProdutoCode);
//         produtoIndex = *lastProdutoCode;
//     }
//     if(produtoIndex<0) {
//         printf("Nao foi possivel encontrar!");
//         return;
//     }
//     compras[*comprasCount].produto = produtos[produtoIndex];

//     printf("Digite a data da compra \n");
//     scanf(" %s",  &compras[*comprasCount].data);
//     printf("Digite a quantidade comprada \n");
//     scanf(" %d", &compras[*comprasCount].qnt);

//     compras[*comprasCount].valor = (compras[*comprasCount].produto.custo * compras[*comprasCount].qnt);

//     // printf("Digite o estoque minimo do produto \n");
//     // scanf(" %s", compras[*comprasCount].estMin);
//     // printf("Digite o estoque atual do produto \n");
//     // scanf(" %s", compras[*comprasCount].estAtual);
//     // printf("Digite o custo do produto \n");
//     // scanf("%.2f", compras[*comprasCount].custo);
//     // printf("Digite o percentual de lucro do produto \n");
//     // scanf("%.2f", compras[*comprasCount].perLucro);
//     // compras[*comprasCount].valor = fornecedores[*comprasCount].custo + (fornecedores[*comprasCount].custo * fornecedores[*comprasCount].perLucro);
    
//     // compras[i].fornec = fornecedores[fncdIndex];
//     // strcpy(compras[i].data, datas[i]);
//     // compras[i].qnt = qnt[i];
//     // compras[i].valor = custos[i] * compras[i].qnt;

//     (*comprasCount)++;
// }

// void registroVenda(
//     Venda vendas[], 
//     Cliente clientes[], 
//     Produto produtos[],
//     long *vendasCount,
//     long *clientesCount, 
//     long *produtosCount,
//     long *lastClientId, 
//     long *lastProdutoCode,
//     int vendasSize, 
//     int clientesSize,
//     int produtosSize
// ){
//     int hasRegister=0, clientType=0, clientIndex=0;
//     long long cnpj=0, cpf=0, inscEst=0;
//     int meioIndex=0;
//     char meios[][15] = {"dinheiro", "cheque", "debito", "credito", "alimentacao", "fiado"};

//     printf("=======Registo de venda======= \n");
//     printf("Escolha o tipo de pagamento \n");

//     for(int i=0; i<MEIOS_PGMT_QNT;i++){
//         printf("%d - para %s", i+1, meios[i]);
//     }
//     scanf(" %d", &meioIndex);--meioIndex;
//     strcpy(vendas[*vendasCount].meioPag, meios[meioIndex]);

//     if(strcmp(meios[meioIndex], "fiado")==0){
//         printf("=======Para compras fiado eh necessario cadastro do cliente======= \n");
//         printf("Digite 1 se o cliente ja tem cadastro ou 2 para cadastrar \n");
//         scanf(" %d", &hasRegister);
//         if(hasRegister==1){
//             printf("Digite 1 para cliente pessoa fisica ou 2 para pessoa juridica \n");
//             scanf(" %d", &clientType);

//             if(clientType==1){
//                 printf("Digite o cpf do cliente \n");
//                 scanf(" %lld", &cpf);
//                 clientIndex = getClienteIndexByCPF(cpf, clientes, *clientesCount);
//             }else if(clientType==2){
//                 printf("Digite o cnpj do cliente \n");
//                 scanf(" %lld", &cnpj);              
//                 clientIndex = getClienteIndexByCNPJ(cnpj, clientes, *clientesCount);
//             }
//         }else if(hasRegister==2){
//             cadastroCliente(clientes, clientesCount, lastClientId);
//             clientIndex = *lastClientId;
//         }
//         if(clientIndex<0) {
//             printf("Nao foi possivel encontrar!");
//             return;
//         }
//         vendas[*vendasCount].cliente = clientes[clientIndex];
//     }

//     int produtoIndex=0;
//     printf("=======Produto======= \n");
//     printf("Digite 1 se o produto ja tem cadastro ou 2 para cadastrar \n");
//     scanf(" %d", &hasRegister);
//     if(hasRegister==1){
//         long long code;
//         printf("Digite o codigo do produto \n");
//         scanf(" %lld", &code);
//         produtoIndex = getIndexOfProdutoByCode(code, produtos, *produtosCount);
//     }else if(hasRegister==2){
//         cadastroProduto(produtos, produtosCount, lastProdutoCode);
//         produtoIndex = *lastProdutoCode;
//     }
//     if(produtoIndex<0) {
//         printf("Nao foi possivel encontrar!");
//         return;
//     }

//     vendas[*vendasCount].produto = produtos[produtoIndex];

//     printf("Digite a data da venda \n");
//     scanf(" %s",  &vendas[*vendasCount].data);
//     printf("Digite a quantidade comprada \n");
//     scanf(" %d", &vendas[*vendasCount].qnt);

//     vendas[*vendasCount].valor = (vendas[*vendasCount].produto.valor * vendas[*vendasCount].qnt);

//     (*vendasCount)++;
// }

// void gerarRelatorios(Venda vendas[], 
//     CompraFornecedor compras[], 
//     Produto produtos[], 
//     Cliente clientes[], 
//     Fornecedor fornecedores[],
//     int vendasSize,
//     int comprasSize,
//     int produtosSize,
//     int clientesSize,
//     int fornecedoresSize
// ){
//     //ordena Produtos e vendas pelo codigo do produto
//     sortProducsByCodigo(produtos, produtosSize);
//     sortVendasByProductCode(vendas, comprasSize);
//     //salva quantidade vendida de cada produto
//     sumAndFillEachProdutoTotal(vendas, produtos, vendasSize);
//     //escreve CSV file
//     writeVendasProdCSV(produtos, produtosSize);
//     writeEstoqueCSV(produtos, produtosSize);

//     //ordena clientes e vendas pelo id dos clientes
//     sortClientsById(clientes, clientesSize);
//     sortVendasById(vendas, vendasSize);
//     //salva a conta total de cada Cliente
//     sumAndFillEachClienteTotal(vendas, clientes, vendasSize);
//     //escreve relatorio de vendas a receber
//     writeAReceberCSV(clientes, clientesSize);
//     //ordena vendas pelo metodo de pagamento
//     sortVendasByPaymentMethod(vendas, vendasSize);
//     //escreve relatorio de vendas por meio de pagamento
//     writeVendasPgtoCSV(vendas, vendasSize);

//     //ordena fornecedores e compras pelo id dos fornecedores
//     sortComprasByFornecId(compras, comprasSize);
//     sortFornecedorById(fornecedores, fornecedoresSize);
//     //salva a conta total de cada fornecedor
//     sumAndFillEachFornecedorTotal(compras, fornecedores, comprasSize);
//     //escreve CSV file
//     writeAPagarCSV(fornecedores, fornecedoresSize);
// }

