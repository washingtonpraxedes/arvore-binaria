
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
	struct no *esq;
	struct no *dir;
    struct no *pai;
	int telefone,rg;
    char *nome;
    char *email;

}no;
/*lembrar*/

no *raiz = NULL;


void inserirNo(no **raiz,int telefoneM, int rgM, char *nomeM, char *emailM)
{
	if(*raiz == NULL) {
        printf("Entro no if 1 \n");
    	no *aux = (no *)malloc(sizeof(no));
    	aux->telefone = telefoneM;
    	aux->rg = rgM;
    	aux-> nome=nomeM;
    	aux-> email= emailM;
    	aux->dir = aux->esq = NULL;
    	*raiz = aux;
    	printf("Elemento foi inserido com sucesso.\n");

    	printf("Raiz\n");
    	printf("%d\n",aux->telefone);
    	printf("%d\n",aux->rg);
    	printf("%s\n",aux->nome);
    	printf("%s\n",aux->email);
    	return;
	}
	if  (telefoneM<(*raiz)->telefone) {
        printf("Entrou no 2 if");
    	inserirNo(&(*raiz)->esq,telefoneM, rgM,  nomeM,  emailM);
    	return;
	}


        if( telefoneM>(*raiz)->telefone) {
            printf("Entrou no 3 if");
            inserirNo(&(*raiz)->dir,telefoneM, rgM,  nomeM,  emailM);
            return;
        }
        printf("Telefone %d ja existe na arvore.\n",telefoneM);

	}
    
int busca (no *raiz,int telefone){

        if(raiz==NULL){
            return 0;
        }
        else if (raiz->telefone==telefone){
            return 1;
        }
        else if (raiz->telefone>telefone){
            if(raiz->esq!=NULL){
                busca(telefone,raiz->esq);
            }
            else{
                return 2;
            }

        }
         else if(raiz->dir!=NULL){
            busca(telefone,raiz->dir);
            }

            else{

                return 3;
            }


}

void insercao (no x, no *raiz){
	
	int f = busca(raiz,x.telefone);
	if(f==1){
		printf("elemento já existe.");
	}
	else{
		no *pt = &x;
		if(f==0){
			raiz = pt;
		}
		else if(f==2){
			raiz->esq = pt;
		}
		else{
			raiz->dir = pt;
		}		

	}

}

    void pre_ordem(no *raiz ){
     if(raiz !=NULL){
         visitar(raiz);
         pre_ordem(raiz->esq);
         pre_ordem(raiz->dir);
     }


    }

	void visitar(no *raiz)
{
	if(raiz == NULL){
    	return;
    }

        printf("Telefone :%d\n",raiz->telefone);
        printf("Nome: %s\n",raiz->nome);
        printf("RG: %d\n",raiz->rg);
        printf("Email: %s\n",raiz->email);
        printf("<><><><><><><><><><><><><><>\n");
}





int main()
{
while(1){
    int opt;
    printf("Escolha Opcao:");
    printf("\n");
    printf("[1]- Cadastrar Numero");
    printf("\n");
    printf("[2]- Pesquisar Numero");
    printf("\n");
    printf("[3]- Remover Numero");
    printf("\n");
    printf("[4]- Listar Cadastros");
    printf("\n");
    scanf("%d",&opt);

    switch(opt){
    case 1:
	no no_ins;
        printf("Novo numero: ");
        scanf("%d",&no_ins.telefone);
        printf("Nome: ");
        fgets(no_ins.nome,20,stdin);
        printf("RG: ");
        scanf("%d",&no_ins.rg);
        printf("Email: ");
        fgets(no_ins.email,20,stdin);
        inserir(no_ins,raiz);
        break;
    case 2:
        printf("Digite o numero de pesquisa: ");

        scanf("%d",&telefone);



    case 4:
        printf("Listando:\n");
        printf("Qual ordem vc deseja listar: \n");
        printf("[1]-Pre-ordem\n");
        printf("[2]-In-ordem\n");
        printf("[3]-Pos-ordem\n");
        int op;
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("Listando em Pre-ordem:\n");
                pre_ordem(&raiz);
                break;
        }


    }


}


	return 0;

}
