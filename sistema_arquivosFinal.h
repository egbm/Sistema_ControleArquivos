#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOVA_CELULA() ((ApontadorArquivo) malloc(sizeof(TipoCelula)))

/* ============================ESTRUTURA=====================================*/

typedef struct{

        char nome[30];
        char formato[5];
        int tamanho;

}TipoArquivo; //Arquivo da lista

typedef struct Celula *ApontadorArquivo; //Transforma a struct Celula em um ponteiro para mesma

typedef struct Celula{
    TipoArquivo Item; // Item � vari�vel com a estrutura TipoArquivo
    ApontadorArquivo Prox; //ApontadorArquivo � um ponteiro que guarda uma posi��o na mem�ria para a vari�vel Prox.
}TipoCelula; //Cria a c�lua, vari�vel que cont�m a estrutura xxCelula.Prox

typedef struct{
    ApontadorArquivo Primeiro;
    ApontadorArquivo Ultimo;
}TipoLista; // Cria a lista

/* ============================OPERA��ES=====================================*/

// 1 - INICIALIZAR SISTEMA
// Faz a lista ficar vazia
void FLVazia(TipoLista *Lista){//Ponteiro Lista. Passagem do conte�do � por refer�ncia
    //Inicializa a lista utilizando uma c�lula
    Lista->Primeiro = NOVA_CELULA();
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista){//Lista � vari�vel a passagem do valor � apenas copiada
    return (Lista.Primeiro == Lista.Ultimo);
}

// 1 - INSERIR ARQUIVOS ORDENADOS ALFABETICAMENTE

void Insere(TipoArquivo x, TipoLista *Lista){ // x � uma nova chave que ser� inserida na lista e o ponteiro *Lista � a posi��o em que x ser� inserido

    if((Vazia(*Lista)) && (strcmp(x.nome, Lista->Ultimo->Item.nome)) < 0) // Alterei para >=
    {

    Lista->Ultimo->Prox = NOVA_CELULA(); //Cria uma nova c�lula na �ltima posi��o da lista
    Lista->Ultimo = Lista->Ultimo->Prox; // A c�lula �ltimo recebe a Prox e passa a apontar para ela tendo o seu endere�o de mem�ria
    Lista->Ultimo->Item = x; //A nova c�lula que foi criada vai receber o valor de x na parte que cont�m o item.
    Lista->Ultimo->Prox = NULL; // A nova c�lula que � a �ltima recebe NULL na parte do ponteiro para indicar que a lista acabou.
    printf("\nArquivo Inserido com sucesso!");
}
    else{
        ApontadorArquivo aux, aux2;
        aux = Lista->Primeiro;

        while ((aux->Prox != NULL) && (strcmp(x.nome, Lista->Ultimo->Item.nome) < 0))//Percorre a lista
        aux = aux->Prox;

        aux2 = NOVA_CELULA();//((ApontadorArquivo) malloc(sizeof(TipoCelula)))
        aux2->Item = x;
        aux2->Prox = aux->Prox;
        aux->Prox = aux2; //aux deve vir antes de aux2

        printf("\nArquivo inserido com sucesso!");

        if(aux == Lista->Ultimo)
            Lista->Ultimo = aux2;
    }
}
// 2 - PESQUISAR ARQUIVO PELO NOME

void PesquisarArquivo(char a[], TipoArquivo *item, TipoLista *Lista)
{
    ApontadorArquivo aux;

    if(Vazia(*Lista))
    {
        printf("\nErro! Lista vazia.");
        return;
    }
    else
    {
    aux = Lista->Primeiro;

        while ((aux->Prox != NULL) && (strcmp(a, aux->Item.nome) != 0)){
                aux = aux->Prox;

          if(strcmp(a, aux->Item.nome) == 0)
                printf("\nArquivo encontrado!\nNome: %s\nFormato: %s\nTamanho Mb: %i ",aux->Item.nome, aux->Item.formato, aux->Item.tamanho);

                 else
                {
                if(aux->Prox == NULL)
                printf("\nArquivo nao encontrado");

                }

        }
        }
        }

// 3 - REMOVER ARQUIVO PELO NOME

void Retira(char arq[], TipoLista *Lista, TipoArquivo *Item)
{
    ApontadorArquivo aux, aux2;

    if(Vazia(*Lista))
    {
        printf("\nErro! Lista vazia.");
        return;
    }
    else
    {
        //Percorre a lista procurando a chave para remover
        aux = Lista->Primeiro;
        while ((aux->Prox != NULL) && strcmp(arq, aux->Prox->Item.nome)!= 0)
            aux = aux->Prox;

        if(aux->Prox == NULL)
            printf("\nArquivo nao encontrado!");
        else
        {
            //Remove a c�lula exclu�da da mem�ria
            aux2 = aux->Prox;
            *Item = aux2->Item;
            aux->Prox = aux2->Prox;

            if(aux->Prox == NULL)
                Lista->Ultimo = aux;

            //Libera a c�lula exclu�da da mem�ria
            free(aux2);
            printf("\nArquivo removido com sucesso!");
        }
    }
}

// 4 - IMPRIMIR TODOS OS ARQUIVOS

void Imprime(TipoLista Lista)
{
    ApontadorArquivo aux;
    aux = Lista.Primeiro->Prox;

    while (aux != NULL)
        {
        printf("\nNome do arquivo: %s\nFormato: %s\nTamanho Mb: %i ",aux->Item.nome, aux->Item.formato, aux->Item.tamanho);
        printf("\n");
        aux = aux->Prox; // vai percorrer at� que chegue em NULL (�ltima c�lula)
    }
}

// 5 - IMPRIMIR TODOS OS ARQUIVOS DE ACORDO COM O TIPO DE ARQUIVO SOLICITADO

void ImprimePorFormato(char a[], TipoLista *Lista)
{
    ApontadorArquivo aux;
    int cont = 0; //Vari�vel para verificar se algum arquivo no formato foi encontrado

    if(Vazia(*Lista))
    {
        printf("\nErro! Lista vazia.");
        return;
    }
    else
    {
		aux = Lista->Primeiro->Prox;

		while (aux != NULL)
		{
			if(strcmp(a, aux->Item.formato) == 0)
			{
				printf("\nArquivo encontrado!\nNome: %s\nFormato: %s\nTamanho Mb: %i \n",aux->Item.nome, aux->Item.formato, aux->Item.tamanho);
				cont++;
			}
			aux = aux->Prox;
        }

        if (cont == 0)
			printf("\nNenhum arquivo encontrado para esse formatod!");
	}
}



void Menu()
{
    printf("\n|---------- * SISTEM DE ARQUIVOS * -----------|");
    printf("\n|               MENU DE OPCOES                |");
    printf("\n|                                             |");
    printf("\n| 1 - Inserir arquivo                         |");
    printf("\n| 2 - Pesquisa arquivo pelo nome              |");
    printf("\n| 3 - Remover aquivo pelo nome                |");
    printf("\n| 4 - Imprimi todos os arquivos               |");
    printf("\n| 5 - Imprimi todos os arquivos pelo formato  |");
    printf("\n| 0 - Sair                                    |");
    printf("\n|                                             |");
    printf("\n|---------------------------------------------|");
    printf("\n| Digite a opcao desejada |\t");
}

