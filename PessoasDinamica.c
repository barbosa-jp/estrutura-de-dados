#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Pessoa{
    char nome[50];
    char cpf[12];
    int idade;
    char sexo;
    char telefone[14];
} Pessoa;

void erro_alocacao(void* endereco){
    if (endereco == NULL){
        printf("--------------\n");
        printf("Erro de alocacao\n");
        exit(1);
    }
}

void cadastrar(Pessoa** nova_pessoa, int cont){ 
    nova_pessoa[cont] = (Pessoa*) malloc(sizeof(Pessoa));
    erro_alocacao(nova_pessoa);

    printf("--------------\n");
    printf("Digite o nome: ");
    scanf("%s", nova_pessoa[cont]->nome);
    
    printf("Digite o CPF(apenas numeros): ");
    scanf("%s", nova_pessoa[cont]->cpf);
    
    printf("Digite o idade: ");
    scanf("%d", &nova_pessoa[cont]->idade);
    
    printf("Digite o sexo(m/f/i): ");
    scanf(" %c", &nova_pessoa[cont]->sexo);
    
    printf("Digite o telefone(apenas numeros): ");
    scanf("%s", nova_pessoa[cont]->telefone);

    printf("A pessoa foi cadastrada!\n");
}

void excluir(Pessoa** excluir_pessoa, int total_pessoas){
    if(total_pessoas == 0){
        printf("--------------\n");
        printf("Sem pessoas cadastradas\n");
        return;
    }

    char excluir_cpf[12];
    int cont = 0;

    printf("Qual o CPF da pessoa que deseja excluir(apenas numeros)? ");
    scanf("%s", excluir_cpf);

    while (cont < total_pessoas){
        if (strcmp(excluir_pessoa[cont]->cpf, excluir_cpf) == 0){
            for(int i = cont + 1; i < total_pessoas; i++){
                excluir_pessoa[i-1] = excluir_pessoa[i];
            }

            free(excluir_pessoa[total_pessoas - 1]);
            excluir_pessoa[total_pessoas - 1] = NULL;
            printf("Pessoas excluida");
            return;
        }
        cont++;
    }

    printf("--------------\n");
    printf("Pessoa nao encontrada\n");
}

void alterar(Pessoa** alterar_pessoa, int total_pessoas){
    char alterar_cpf[12];
    int cont = 0;
    int alterar_opcao;

    if(total_pessoas == 0){
        printf("--------------\n");
        printf("Sem pessoas cadastradas\n");
        return;
    }

    printf("--------------\n");
    printf("Qual o CPF da pessoa que deseja alterar(apenas numeros)? ");
    scanf("%s", alterar_cpf);

    while (cont < total_pessoas){
        if (strcmp(alterar_pessoa[cont]->cpf, alterar_cpf) == 0){
            printf("O que deseja alterar?\n1 - Nome\n2 - CPF\n3 - Idade\n4 - Sexo\n5 - Telefone\n(Digite o numero referente a acao): ");
            scanf("%d", &alterar_opcao);

            switch (alterar_opcao){
                case 1:
                    printf("Novo valor: ");
                    scanf("%s", alterar_pessoa[cont]->nome);
                    printf("Pessoa alterada");
                break;            
                case 2:
                    printf("Novo valor(apenas numeros): ");
                    scanf("%s", alterar_pessoa[cont]->cpf);
                    printf("Pessoa alterada");
                break;
                case 3:
                    printf("Novo valor: ");
                    scanf("%d", &alterar_pessoa[cont]->idade);
                    printf("Pessoa alterada");
                break;
                case 4:
                    printf("Novo valor(m/f/i): ");
                    scanf(" %c", &alterar_pessoa[cont]->sexo);
                    printf("Pessoa alterada");
                break;
                case 5:
                    printf("Novo valor(apenas numeros): ");
                    scanf("%s", alterar_pessoa[cont]->telefone);
                    printf("Pessoa alterada");                
                break;
                default:
                    printf("Opcao Invalidan\n");
                break;
            }
            return;
        }
        cont++;
    }

    printf("--------------\n");
    printf("Pessoa nao encontrada\n");
}

void exibir_um(Pessoa** exibir_pessoa, int total_pessoas){
    char exibir_cpf[12];
    int cont = 0;
    
    if(total_pessoas == 0){
        printf("--------------\n");
        printf("Sem pessoas cadastradas\n");
        return;
    }

    printf("Digite o CPF da pessoa(apenas numeros): ");
    scanf("%s", exibir_cpf);

    while (cont < total_pessoas){
        if (strcmp(exibir_pessoa[cont]->cpf, exibir_cpf) == 0){
            printf("--------------\n");
            printf("Nome: %s\nCPF: %s\nIdade: %d\nSexo: %c\nTelefone: %s\n",
                exibir_pessoa[cont]->nome, exibir_pessoa[cont]->cpf, 
                exibir_pessoa[cont]->idade, exibir_pessoa[cont]->sexo,
                exibir_pessoa[cont]->telefone);
            
            return;
        }

        cont++;
    }

    printf("Pessoa nao encontrada!\n");
}

void exibir_todos(Pessoa** exibir_pessoas, int cont){
    if(exibir_pessoas == 0){
        printf("--------------\n");
        printf("Sem pessoas cadastradas\n");
        return;
    }
    for(int i = 0; i < cont; i++){
        printf("--------------\n");
        printf("Nome: %s\nCPF: %s\nIdade: %d\nSexo: %c\nTelefone: %s\n\n",
            exibir_pessoas[i]->nome, exibir_pessoas[i]->cpf, exibir_pessoas[i]->idade,
            exibir_pessoas[i]->sexo, exibir_pessoas[i]->telefone);
    }
}

int main(void){
    Pessoa** pessoas;
    int contador = 0;
    char confirmacao = ' ';
    int opcao = 0;
    pessoas = (Pessoa**) malloc(2*sizeof(Pessoa*));
    erro_alocacao(pessoas);

    do {
        printf("--------------\n");
        printf("O que deseja fazer?\n1 - Cadastrar\n2 - Excluir\n3 - Alterar\n4 - Exibir\n5 - Sair\n(Digite o numero referente a acao): ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                cadastrar(pessoas, contador);                
                contador++;

                break;
            case 2:
                excluir(pessoas, contador);
                contador--;

                break;
            case 3:
                alterar(pessoas, contador);

                break;
            case 4:   
                printf("Voce deseja:\n1 - Exibir Um\n2 - Exibir Todos\n(digite o numero referente a acao): ");
                scanf("%d", &opcao);

                if (opcao == 1){
                    exibir_um(pessoas, contador);
                    break;
                } 

                exibir_todos(pessoas, contador);

                break;
            case 5:
                confirmacao = 's';

                break;
            default:
                printf("Valor invalido\n");
                
            break;
        }
    } while(confirmacao != 's');

    return 0;
}