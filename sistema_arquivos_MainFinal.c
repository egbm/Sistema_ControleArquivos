#include "sistema_arquivosFinal.h"

int main()
{
    TipoLista l;
    TipoArquivo item;
    int opcao = -1;

    FLVazia(&l);
    system("cls"); //limpar tela

    while (opcao != 0)
    {
        Menu();
        scanf("%d", &opcao);
        system("cls");

        if(opcao ==1)//1- Inserir arquivos ordenados alfabeticamente
        {
            printf("\nInforme o nome do arquivo que deseja inserir: ");
            fflush(stdin);
            gets(item.nome);

            printf("\nInforme o fomato do arquivo: ");
            fflush(stdin);
            gets(item.formato);

            printf("\nInforme o tamanho do arquivo: ");
            scanf("%d", &item.tamanho);

            Insere(item, &l);

            printf(" Tecle ENTER para continuar...");
            fflush(stdin); // limpa o buffer
            getchar();
            system("cls");
        }
        else if(opcao == 2)//2 - Pesquisar um arquivo pelo nome
        {
            printf("\nDigite o nome do arquivo para a pesquisa: ");
            fflush(stdin);
            gets(item.nome);

            PesquisarArquivo(item.nome, &item, &l);

            printf(" Tecle ENTER para continuar...");
            fflush(stdin); // limpa o buffer
            getchar();
            system("cls");
        }
        else if(opcao == 3)//3 - Remover um aquivo pelo nome
        {

            printf("\nDigite o nome do arquivo para retirar: ");
            fflush(stdin);
            gets(item.nome);

            Retira(item.nome, &l, &item);

            printf(" Tecle ENTER para continuar...");
            fflush(stdin); // limpa o buffer
            getchar();
            system("cls");
        }
        else if(opcao == 4)// Imprimir todos os arquivos
        {
            Imprime(l);

            printf(" Tecle ENTER para continuar...");
            fflush(stdin); // limpa o buffer
            getchar();
            system("cls");
        }

            else if(opcao == 5)// Imprimir todos os arquivos pesquisados por um determinado formato
        {
            printf("Informe o formato do arquivo para impressao: ");
            fflush(stdin);
            gets(item.formato);

            ImprimePorFormato(item.formato, &l); //Alterei para apenas 2 parâmetros

            printf(" Tecle ENTER para continuar...");
            fflush(stdin); // limpa o buffer
            getchar();
            system("cls");
        }
    }
    return (0);
    }

