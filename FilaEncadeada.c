#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>

//Definir os dados da Pessoa
typedef struct Pessoa{
    char nome[50];
    char cpf[12];
    int idade;
    char sexo;
    char telefone[14];
    struct Pessoa* proximo;
} Pessoa;

typedef struct Fila{
    Pessoa* inicio;
} Fila;


void adicionar(Fila* fila){
    Pessoa* pessoa = (Pessoa*) malloc(sizeof(Pessoa));
    //Verificação de alocação
    if (pessoa == NULL){
        printf("Erro de alocacao");
        return;
    } 

    //Inserção os dados da Pessoa
    printf("Digite o nome: ");
    scanf("%s", pessoa->nome);

    printf("Digite o CPF(apenas numeros): ");
    scanf("%s", pessoa->cpf);
    
    printf("Digite o idade: ");
    scanf("%d", &pessoa->idade);
    
    printf("Digite o sexo(m/f/i): ");
    scanf(" %c", &pessoa->sexo);
    
    printf("Digite o telefone(apenas numeros): ");
    scanf("%s", pessoa->telefone);

    pessoa->proximo = NULL;

    //Verificação se é o primeiro da fila
    if (fila->inicio == NULL){
        fila->inicio = pessoa;
        printf("A pessoa entrou na fila!\n"); 
        return;
    }

    //Verificação do último da fila
    Pessoa* verificacao_pessoa = fila->inicio;
    while(verificacao_pessoa->proximo != NULL){
        verificacao_pessoa = verificacao_pessoa->proximo;
    }
    verificacao_pessoa->proximo = pessoa;
}

void mostrar_fila(Fila* fila){    
    //Verificação da fila vazia
    if (fila->inicio == NULL){
        printf("Fila Vazia!\n");
        return;
    }

    Pessoa* pessoa_atual = fila->inicio;
    int posicao = 1;
    do{
        printf("Pessoa %d:\n Nome: %s\n CPF: %s\n Idade: %d\n Sexo: %c\n Telefone: %s\n",
        posicao, pessoa_atual->nome, pessoa_atual->cpf, pessoa_atual->idade, pessoa_atual->sexo, pessoa_atual->telefone);
        
        posicao++;
        pessoa_atual = pessoa_atual->proximo;

    } while (pessoa_atual != NULL);
}

void limpar_fila(Fila* fila){
    //Verificação da fila vazia
    if (fila->inicio == NULL){
        printf("Fila Vazia!\n");
        return;
    }

    Pessoa* pessoa_atual = fila->inicio;
    Pessoa* prox_pessoa = NULL; 
    do{        
        prox_pessoa = pessoa_atual->proximo;
        free(pessoa_atual);
        pessoa_atual = prox_pessoa;
    } while (pessoa_atual != NULL);

    fila->inicio = NULL;
    printf("Fila Limpa!\n");
}

void chamar(Fila* fila){
    //Verificação da fila vazia
    if (fila->inicio == NULL){
        printf("Fila Vazia!\n");
        return;
    }

    Pessoa* pessoa_atual = fila->inicio;
    Pessoa* prox_pessoa = pessoa_atual->proximo;
    free(pessoa_atual);
    fila->inicio = prox_pessoa;
    printf("Chamada Concluida!\n");
}

void alterar_posicao(Fila* fila){
    //Verificação da fila vazia
    if (fila->inicio == NULL){
        printf("Fila Vazia!\n");
        return;
    }

    char cpf_pessoa_um[11];
    char cpf_pessoa_dois[11];
    printf("Digite o CPF da pessoa que voce deseja alterar a posicao: ");
    scanf("%s", cpf_pessoa_um);
    printf("Digite o CPF da outra pessoa que voce deseja alterar a posicao: ");
    scanf("%s", cpf_pessoa_dois);

    Pessoa* pessoa_atual = fila->inicio;
    Pessoa* pessoa_um = NULL;
    Pessoa* pessoa_dois = NULL;
    do{
        if(strcmp(pessoa_atual->cpf, cpf_pessoa_um) == 0 || strcmp(pessoa_atual->cpf, cpf_pessoa_dois) == 0){
            if(strcmp(pessoa_atual->cpf, cpf_pessoa_um) == 0){
                pessoa_um = pessoa_atual;
            } else {
                pessoa_dois = pessoa_atual;
            }
        }

        //Verificação do encontro das duas pessoas
        if(pessoa_um != NULL && pessoa_dois != NULL){
            break;
        }

        pessoa_atual = pessoa_atual->proximo;
    } while (pessoa_atual != NULL);

    //Verificação do encontro das duas pessoas
    if(pessoa_um == NULL || pessoa_dois == NULL){
        printf("CPF nao encontrado!\n");
        return;
    }

    printf("oi");
    char nome_aux[50];
    int idade_aux = pessoa_um->idade;
    char sexo_aux = pessoa_um->sexo;
    char cpf_aux[12];
    char telefone_aux[14];
    strcpy(nome_aux, pessoa_um->nome);
    strcpy(cpf_aux, pessoa_um->cpf);
    strcpy(telefone_aux, pessoa_um->telefone);
printf("oi");
    strcpy(pessoa_um->nome, pessoa_dois->nome);
    strcpy(pessoa_um->cpf, pessoa_dois->cpf);
    strcpy(pessoa_um->telefone, pessoa_dois->telefone);
    pessoa_um->idade = pessoa_dois->idade;
    pessoa_um->sexo = pessoa_dois->sexo;
printf("oi");
    strcpy(pessoa_dois->nome, nome_aux);
    strcpy(pessoa_dois->cpf, cpf_aux);
    strcpy(pessoa_dois->telefone, telefone_aux);
    pessoa_dois->idade = idade_aux;
    pessoa_dois->sexo = sexo_aux;
}

void remover_pessoa(Fila* fila){
    //Verificação da fila vazia
    if (fila->inicio == NULL){
        printf("Fila Vazia!\n");
        return;
    }

    char cpf_pessoa[11];
    printf("Digite o CPF da pessoa que voce deseja excluir: ");
    scanf("%s", cpf_pessoa);

    Pessoa* pessoa_excluir = fila->inicio;
    if(strcmp(pessoa_excluir->cpf, cpf_pessoa) == 0){
        fila->inicio = pessoa_excluir->proximo;
        free(pessoa_excluir);
        return;
    } 

    Pessoa* pessoa_anterior = fila->inicio;
    pessoa_excluir = pessoa_anterior->proximo;
    do{
        if(strcmp(pessoa_excluir->cpf, cpf_pessoa) == 0){
            pessoa_anterior->proximo = pessoa_excluir->proximo;
            free(pessoa_excluir);
            printf("Remocao Concluida\n");
            break;  
        }

        pessoa_anterior = pessoa_excluir;
        pessoa_excluir = pessoa_excluir->proximo;
    } while (pessoa_excluir != NULL);

    if(pessoa_excluir == NULL){
        printf("CPF nao encontrado!\n");
    }
}

int main(void){
    Fila* fila = (Fila*) malloc(sizeof(Pessoa));
    //Verificação de alocação
    if (fila == NULL){
        printf("Erro de alocacao");
    } 

    //Inicializar fila
    fila->inicio = NULL;

    char confirmacao = ' ';
    int opcao = 0;

    do {
        printf("-------------------\n");
        printf("O que deseja fazer?\n1 - Adicionar Pessoa\n2 - Limpar Fila\n3 - Chamar Pessoa\n4 - Exibir Fila\n5 - Alterar Posicao \n6 - Remover Pessoa\n7 - Sair\n(Digite o numero referente a acao): ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                adicionar(fila);

                break;
            case 2:
                limpar_fila(fila);

                break;
            case 3:
                chamar(fila);

                break;
            case 4:
                mostrar_fila(fila);

                break;
            case 5:
                alterar_posicao(fila);

                break;
            case 6:
                remover_pessoa(fila);

                break;
            case 7:
                confirmacao = 's';

                break;
            default:
                printf("Valor invalido\n");

            break;
        }
    } while(confirmacao != 's');

    return 0;
}