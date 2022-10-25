#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

//criação listas/nós

typedef struct _node{//node representando dados do aluno

    //dados do alunos
    char name[50];
    int enrollment;
    float note;
    float frequency;
    char class;
    
    //ponteiro para o próximo nó
    struct _node *next;

}node_aluno;

typedef struct{//representação da lista

    node_aluno *begin; //ponteiro para o primeiro nó da lista
    node_aluno *end;    //ponteiro para o último nó da lista

} Lista;

//fim das listas/nós


//criação das funções do funcionamento da lista

Lista* onCreate(){//cria lista

    //criando a lista (obs; a lista em si é um ponteiro, pois aponta paras os nós)
    Lista *lista = (Lista*) malloc(sizeof(Lista)); 

    if(lista == NULL){//caso não haja memória

        printf("\nMemória insuficiente!\n");
        exit(1); 

    }

    lista->begin = NULL;//setando inicio/fim da lista
    lista->end = NULL;  //(no caso NULL, pois n há elementos)

    return lista; //retornando a lista

}

void insert_aluno(Lista *lista, int mat, char nome[], float nota, float frequencia, char turma){

    //lista não criada
    if(lista == NULL) return;

    //criando nó (obs; o nó em si é um ponteiro, pois aponta para seus respectivos valores)
    node_aluno *node = (node_aluno*) malloc(sizeof(node_aluno));

    if(node == NULL){//caso não haja memória

        printf("\nMemória insuficiente!\n");
        exit(1); 

    }

    //passando dados para os nós
    strcpy(node -> name, nome);
    node -> enrollment = mat;
    node -> note = nota;
    node -> frequency = frequencia;
    node -> class = turma;

    

    //atualizando posições
    node -> next = lista -> begin;  //o nó começa a apontar para o que era o primeiro nó (begin)
    lista -> begin = node;          //e ele passa a ser o primeiro nó

    if(lista -> begin == NULL){

        //caso o inicio seja nulo não existem nós
        //portanto esse novo nó passa a ser o fim
        lista -> end = node;        

    }

    printf("\nAluno cadastrado com sucesso!\n");

}

void remove_aluno(Lista *lista, int mat){

    //lista não criada
    if(lista == NULL){
         printf("\nLista não criada.\n");
         return;
    }
    //não há nós
    if(lista -> begin == NULL){
        printf("\nNão há alunos.\n");
        return;
    }


    //criando dois nós auxiliares, 
    node_aluno *before, *after;
    //(um vai ser o nó anterior, e o outro o próximo)

    //este for esta em função do after (ate ele chegar no fim)
    for(after = lista -> begin; after != NULL; before = after, after = after -> next ){
    //a cada laço, ambos os nós (after e before) avança

        //achando a matrícula
        if(after -> enrollment == mat){

            //caso só tenha UM nó
            if(lista -> begin == lista -> end){

                lista -> begin == NULL;
                lista -> end == NULL;

            }else{
            //caso não

                //se for o primeiro nó
                if(lista -> begin == after){

                    lista -> begin == after -> next;
                    //o inicio pega o próximo nó

                }else if(lista -> end == after){

                    lista -> end = before;
                    before -> next = NULL;
                    //o inicio pega o ultimo nó

                }else{

                    //o nó anterior passa a apontar para o nó da frente do proximo
                    before -> next = after -> next;

                }
            }
            //em todos os casos, isolamos o nó after

            free(after);
            //liberamos o nó isolado

            printf("\nAluno removido com sucesso.\n");
            return;
        }
        

    }//fim do for

    printf("\nAluno não encontrado.\n");
    return;

}

void onDestroy(Lista *lista){

    //lista não criada
    if(lista == NULL) return;
    //não há nós
    if(lista -> begin == NULL) return;

    node_aluno *node;
    //se não houver memória
    if(node == NULL){

        printf("\nMemória insuficiente!\n");
        exit(1); 

    }

    while(lista -> begin != NULL){

        //aux assume o valor do inicio da lista
        node = lista -> begin;

        //inicio da lista pega o próximo valor (um dps do aux)
        lista -> begin = node -> next;

        //libera aux
        free(node);
    }

    //libera lista
    free(lista);

}
//fim das funções do funcionamento da lista



//funções logicas

int Check_Mat(Lista *lista, int mat){

    //lista não criada
    if(lista == NULL){

        printf("\nLista não criada!\n"); 
        return;

    }
    //não há alunos

    node_aluno *i;
    for(i = lista -> begin; i != NULL ; i = i -> next){

        if(i -> enrollment == mat){

            return 1;

        }

    }
    return 0;


}

void print_name(Lista *lista, char nome[]){

    if(lista == NULL){

        printf("\nLista não criada!\n"); 
        return;

    }
    //não há alunos

    node_aluno *i;

    for(i = lista -> begin; i != NULL; i = i -> next){

        if(strcmp(nome, i -> name)==0){

            printf("\nMatr��cula: %d\n", i -> enrollment);
            printf("Nome: %s\n", i -> name);
            printf("Nota: %.2f\n", i -> note);
            printf("Frequ�ncia: %.2f\n", i -> frequency);
            printf("Turma: %c\n", i -> class);
            printf("\n");
            return;

        }

    }
    
    printf("\nAluno não encontrado!\n");
    return;

}

void print_mat(Lista *lista, int mat){

    if(lista == NULL){

        printf("\nLista não criada!\n"); 
        return;

    }
    //não há alunos

    node_aluno *i;

    for(i = lista -> begin; i != NULL; i = i -> next){

        if(i -> enrollment == mat){

            printf("\nMatr��cula: %d\n", i -> enrollment);
            printf("Nome: %s\n", i -> name);
            printf("Nota: %.2f\n", i -> note);
            printf("Frequ�ncia: %.2f\n", i -> frequency);
            printf("Turma: %c\n", i -> class);
            printf("\n");
            return;

        }

    }
    
    printf("\nAluno não encontrado!\n");
    return;

}
//fim das funções lógicas

int main()
{
    setlocale(LC_ALL, "portuguese");
    int o=0;
    char nome[50], name[50], turma;
    int mat,m;
    float frequencia, nota;

    Lista *lista = onCreate(); //criando lista

    do
    {
        
        printf("Escolha uma op��o:\n\n");
        printf("1. Cadastrar aluno no in��cio da lista;\n");
        printf("2. Remover aluno;\n");
        printf("3. Pesquisar aluno pelo nome;\n");
        printf("4. Pesquisar aluno por matr��cula;\n");
        printf("5. Mostrar todos os alunos de uma turma;\n");
        printf("6. Mostrar os alunos com a maior e menor nota;\n");
        printf("7. Ordenar toda a lista de alunos por nome;\n");
        printf("8. Sair.\n");
        printf("\nDigite sua op��o:");
        scanf("%d",&o);
        printf("\n");

        switch (o){

        case 1:
            
            printf("1 . Cadastrar aluno:\n\n");


            printf("Digite a matrícula do(a) aluno(a): ");
            scanf("%d",&mat);
            while(mat>99999||mat<0){
                printf("Matrícula inválida, são aceitos números entre 0 e 99999\nInsira uma matrícula válida: ");
                scanf("%d",&mat);
            }
            //checagem de matrícula
            while(Check_Mat(lista,mat)==1){
                printf("Matrícula já cadastrada!\nInsira outro número de matricula:");
                scanf("%d",&mat);
            }
                    

            printf("Digite o nome do(a) aluno(a): ");
            setbuf(stdin,NULL);
            gets(nome);


            printf("Digite a nota do(a) aluno(a): ");
            scanf("%f",&nota);
            while(nota>10.0||nota<0.0){
                printf("Nota inválida, são aceitos números entre 0,0 e 10,0\nInsira uma nota válida: ");
                scanf("%f",&nota);
            }



            printf("Digite a frequência do(a) aluno(a): ");
            scanf("%f",&frequencia);
            while(frequencia>100.0||frequencia<0.0){
                printf("Frequência inválida, são aceitos números entre 0,0 e 100,0\nInsira uma frequência válida: ");
                scanf("%f",&frequencia);
            }
            setbuf(stdin,NULL);



            printf("Digite A para aluno(a) na turma A ou B para aluno(a) na turma B: ");
            scanf("%c",&turma);
            setbuf(stdin,NULL);
            while(turma!='A'&&turma!='B'){
                printf("Turma inválida, são aceitos os caracteres 'A' e 'B'\nInsira uma turma válida: ");
                scanf("%c",&turma);
                setbuf(stdin,NULL);
            }

            //inserindo dados na lista
            insert_aluno(lista,mat,nome,nota,frequencia,turma);
            
            break;
        

        case 2:

            printf("2 . Remover Aluno:\n\n");

            printf("Digite o número de matrícula do aluno que será removido: ");
            scanf("%d",&m);
        
            remove_aluno(lista,m);
            
            break;
        

        case 3:

            printf("3 . Pesquisar aluno pelo nome:\n\n");

            printf("Digite o nome do aluno que será pesquisado: ");
            setbuf(stdin,NULL);
            gets(name);

            print_name(lista,name);
            
            break;
        

        case 4:

            printf("3 . Pesquisar aluno pela matr�cula:\n\n");

            printf("Digite a matr�cula do aluno que será pesquisado: ");
            scanf("%d", &mat);

            print_mat(lista,mat);
            
            break;
        

        case 5:
            
            break;
        

        case 6:
            
            break;
        

        case 7:
            
            break;
        
        default:

            break;
        }



    } while(o!=8);
    

    return 0;
}
