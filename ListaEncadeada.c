#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

//criaï¿½ï¿½o listas/nï¿½s

typedef struct _node{//node representando dados do aluno

    //dados do alunos
    char name[50];
    int enrollment;
    float note;
    float frequency;
    char class;
    
    //ponteiro para o prï¿½ximo nï¿½
    struct _node *next;

}node_aluno;

typedef struct{//representaï¿½ï¿½o da lista

    node_aluno *begin; //ponteiro para o primeiro nï¿½ da lista
    node_aluno *end;    //ponteiro para o ï¿½ltimo nï¿½ da lista

} Lista;

//fim das listas/nï¿½s


//criaï¿½ï¿½o das funï¿½ï¿½es do funcionamento da lista

Lista* onCreate(){//cria lista

    //criando a lista (obs; a lista em si ï¿½ um ponteiro, pois aponta paras os nï¿½s)
    Lista *lista = (Lista*) malloc(sizeof(Lista)); 

    if(lista == NULL){//caso nï¿½o haja memï¿½ria

        printf("\nMemï¿½ria insuficiente!\n");
        exit(1); 

    }

    lista->begin = NULL;//setando inicio/fim da lista
    lista->end = NULL;  //(no caso NULL, pois n hï¿½ elementos)

    return lista; //retornando a lista

}

void insert_aluno(Lista *lista, int mat, char nome[], float nota, float frequencia, char turma){

    //lista nï¿½o criada
    if(lista == NULL) return;

    //criando nï¿½ (obs; o nï¿½ em si ï¿½ um ponteiro, pois aponta para seus respectivos valores)
    node_aluno *node = (node_aluno*) malloc(sizeof(node_aluno));

    if(node == NULL){//caso nï¿½o haja memï¿½ria

        printf("\nMemï¿½ria insuficiente!\n");
        exit(1); 

    }

    //passando dados para os nï¿½s
    strcpy(node -> name, nome);
    node -> enrollment = mat;
    node -> note = nota;
    node -> frequency = frequencia;
    node -> class = turma;

    

    //atualizando posiï¿½ï¿½es
    node -> next = lista -> begin;  //o nï¿½ comeï¿½a a apontar para o que era o primeiro nï¿½ (begin)
    lista -> begin = node;          //e ele passa a ser o primeiro nï¿½

    if(lista -> begin == NULL){

        //caso o inicio seja nulo nï¿½o existem nï¿½s
        //portanto esse novo nï¿½ passa a ser o fim
        lista -> end = node;        

    }

    printf("\nAluno cadastrado com sucesso!\n");

}

void remove_aluno(Lista *lista, int mat){

    //lista nï¿½o criada
    if(lista == NULL){
         printf("\nLista nï¿½o criada.\n");
         return;
    }
    //nï¿½o hï¿½ nï¿½s
    if(lista -> begin == NULL){
        printf("\nNï¿½o hï¿½ alunos.\n");
        return;
    }


    //criando dois nï¿½s auxiliares, 
    node_aluno *before, *after;
    //(um vai ser o nï¿½ anterior, e o outro o prï¿½ximo)

    //este for esta em funï¿½ï¿½o do after (ate ele chegar no fim)
    for(after = lista -> begin; after != NULL; before = after, after = after -> next ){
    //a cada laï¿½o, ambos os nï¿½s (after e before) avanï¿½a

        //achando a matrï¿½cula
        if(after -> enrollment == mat){

            //caso sï¿½ tenha UM nï¿½
            if(lista -> begin == lista -> end){

                lista -> begin = NULL;
                lista -> end = NULL;

            }else{
            //caso nï¿½o

                //se for o primeiro nï¿½
                if(lista -> begin = after){

                    lista -> begin = after -> next;
                    //o inicio pega o prï¿½ximo nï¿½

                }else if(lista -> end == after){

                    lista -> end = before;
                    before -> next = NULL;
                    //o inicio pega o ultimo nï¿½

                }else{

                    //o nï¿½ anterior passa a apontar para o nï¿½ da frente do next
                    before -> next = after -> next;

                }
            }
            //em todos os casos, isolamos o nï¿½ after

            free(after);
            //liberamos o nï¿½ isolado

            printf("\nAluno removido com sucesso.\n");
            return;
        }
        

    }//fim do for

    printf("\nAluno nï¿½o encontrado.\n");
    return;

}

void onDestroy(Lista *lista){

    //lista nï¿½o criada
    if(lista == NULL) return;
    //nï¿½o hï¿½ nï¿½s
    if(lista -> begin == NULL) return;

    node_aluno *node;
    //se nï¿½o houver memï¿½ria
    if(node == NULL){

        printf("\nMemï¿½ria insuficiente!\n");
        exit(1); 

    }

    while(lista -> begin != NULL){

        //aux assume o valor do inicio da lista
        node = lista -> begin;

        //inicio da lista pega o prï¿½ximo valor (um dps do aux)
        lista -> begin = node -> next;

        //libera aux
        free(node);
    }

    //libera lista
    free(lista);

}
//fim das funï¿½ï¿½es do funcionamento da lista



//funï¿½ï¿½es logicas

int Check_Mat(Lista *lista, int mat){

    //lista nï¿½o criada
    if(lista == NULL){

        printf("\nLista nï¿½o criada!\n"); 
        return;

    }
    //nï¿½o hï¿½ alunos

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

        printf("\nLista nï¿½o criada!\n"); 
        return;

    }
    //nï¿½o hï¿½ alunos

    node_aluno *i;

    for(i = lista -> begin; i != NULL; i = i -> next){

        if(strcmp(nome, i -> name)==0){

            printf("\nMatr??cula: %d\n", i -> enrollment);
            printf("Nome: %s\n", i -> name);
            printf("Nota: %.2f\n", i -> note);
            printf("Frequ?ncia: %.2f\n", i -> frequency);
            printf("Turma: %c\n", i -> class);
            printf("\n");
            return;

        }

    }
    
    printf("\nAluno nï¿½o encontrado!\n");
    return;

}

void print_mat(Lista *lista, int mat){

    if(lista == NULL){

        printf("\nLista nï¿½o criada!\n"); 
        return;

    }
    //nï¿½o hï¿½ alunos

    node_aluno *i;

    for(i = lista -> begin; i != NULL; i = i -> next){

        if(i -> enrollment == mat){

            printf("\nMatr??cula: %d\n", i -> enrollment);
            printf("Nome: %s\n", i -> name);
            printf("Nota: %.2f\n", i -> note);
            printf("Frequ?ncia: %.2f\n", i -> frequency);
            printf("Turma: %c\n", i -> class);
            printf("\n");
            return;

        }

    }
    
    printf("\nAluno nï¿½o encontrado!\n");
    return;

}

void Name_Sort(Lista *lista){

    //lista nï¿½o criada
    if(lista == NULL){
         printf("\nLista nï¿½o criada.\n");
         return;
    }
    //nï¿½o hï¿½ nï¿½s
    if(lista -> begin == NULL){
        printf("\nNï¿½o hï¿½ alunos.\n");
        return;
    }

    if(lista -> begin == lista -> end){

        return;

    }

    node_aluno *j, *i;

    node_aluno *aux = (node_aluno*) malloc(sizeof(node_aluno));
    
    for(i = lista -> begin; i != NULL; i = i -> next ){

        for(j = i -> next; j != NULL; j = j -> next){
            
            if(strcmp(j -> name, i -> name) < 0){

                strcpy(aux -> name, i -> name);
                strcpy(i -> name, j -> name);
                strcpy(j -> name, aux -> name);

                aux -> enrollment = i -> enrollment;
                i -> enrollment = j -> enrollment;
                j -> enrollment = aux -> enrollment;

                aux -> note = i -> note;
                i -> note = j -> note;
                j -> note = aux -> note;

                aux -> frequency = i -> frequency;
                i -> frequency = j -> frequency;
                j -> frequency = aux -> frequency;
        
                aux -> class = i -> class;
                i -> class = j -> class;
                j -> class = aux -> class;
                

            }

        }

    }
    free(aux);

    return;

}

lista_print(Lista *lista){

    //lista nï¿½o criada
    if(lista == NULL){
         printf("\nLista nï¿½o criada.\n");
         return;
    }
    //nï¿½o hï¿½ nï¿½s
    if(lista -> begin == NULL){
        printf("\nNï¿½o hï¿½ alunos.\n");
        return;
    }

    for(node_aluno *i = lista -> begin; i != NULL; i = i-> next){

        printf("%s\n", i -> name);

    }
    return;

}

//fim das funï¿½ï¿½es lï¿½gicas

int main()
{
    setlocale(LC_ALL, "portuguese");
    int o=0;
    char nome[50], name[50], turma;
    int mat,m;
    float frequencia, nota;
    node_aluno *aux;
    int cont=0;

    Lista *lista = onCreate(); //criando lista

    do
    {
        
        printf("Escolha uma op??o:\n\n");
        printf("1. Cadastrar aluno no in??cio da lista;\n");
        printf("2. Remover aluno;\n");
        printf("3. Pesquisar aluno pelo nome;\n");
        printf("4. Pesquisar aluno por matr??cula;\n");
        printf("5. Mostrar todos os alunos de uma turma;\n");
        printf("6. Ordenar toda a lista de alunos por nome;\n");
        printf("7. Mostrar os alunos com a maior e menor nota;\n");
        printf("8. Sair.\n");
        printf("\nDigite sua op??o:");
        scanf("%d",&o);
        printf("\n");

        switch (o){

        case 1:
            
            printf("1 . Cadastrar aluno:\n\n");


            printf("Digite a matrï¿½cula do(a) aluno(a): ");
            scanf("%d",&mat);
            while(mat>99999||mat<0){
                printf("Matrï¿½cula invï¿½lida, sï¿½o aceitos nï¿½meros entre 0 e 99999\nInsira uma matrï¿½cula vï¿½lida: ");
                scanf("%d",&mat);
            }
            //checagem de matrï¿½cula
            while(Check_Mat(lista,mat)==1){
                printf("Matrï¿½cula jï¿½ cadastrada!\nInsira outro nï¿½mero de matricula:");
                scanf("%d",&mat);
            }
                    

            printf("Digite o nome do(a) aluno(a): ");
            setbuf(stdin,NULL);
            gets(nome);


            printf("Digite a nota do(a) aluno(a): ");
            scanf("%f",&nota);
            while(nota>10.0||nota<0.0){
                printf("Nota invï¿½lida, sï¿½o aceitos nï¿½meros entre 0,0 e 10,0\nInsira uma nota vï¿½lida: ");
                scanf("%f",&nota);
            }



            printf("Digite a frequï¿½ncia do(a) aluno(a): ");
            scanf("%f",&frequencia);
            while(frequencia>100.0||frequencia<0.0){
                printf("Frequï¿½ncia invï¿½lida, sï¿½o aceitos nï¿½meros entre 0,0 e 100,0\nInsira uma frequï¿½ncia vï¿½lida: ");
                scanf("%f",&frequencia);
            }
            setbuf(stdin,NULL);



            printf("Digite A para aluno(a) na turma A ou B para aluno(a) na turma B: ");
            scanf("%c",&turma);
            setbuf(stdin,NULL);
            while(turma!='A'&&turma!='B'){
                printf("Turma invï¿½lida, sï¿½o aceitos os caracteres 'A' e 'B'\nInsira uma turma vï¿½lida: ");
                scanf("%c",&turma);
                setbuf(stdin,NULL);
            }

            //inserindo dados na lista
            insert_aluno(lista,mat,nome,nota,frequencia,turma);
            
            break;
        

        case 2:

            printf("2 . Remover Aluno:\n\n");

            printf("Digite o nï¿½mero de matrï¿½cula do aluno que serï¿½ removido: ");
            scanf("%d",&m);
        
            remove_aluno(lista,m);
            
            break;
        

        case 3:

            printf("3 . Pesquisar aluno pelo nome:\n\n");

            printf("Digite o nome do aluno que serï¿½ pesquisado: ");
            setbuf(stdin,NULL);
            gets(name);

            print_name(lista,name);
            
            break;
        

        case 4:

            printf("3 . Pesquisar aluno pela matr?cula:\n\n");

            printf("Digite a matr?cula do aluno que serï¿½ pesquisado: ");
            scanf("%d", &mat);

            print_mat(lista,mat);
            
            break;
        

        case 5:

            printf("5 . Mostrar todos os alunos de uma turma:\n\n");

            setbuf(stdin,NULL);
            printf("Digite a turma: ");
            scanf("%c",&turma);
            setbuf(stdin,NULL);
            while(turma!='A'&&turma!='B'){
                printf("Turma invï¿½lida, sï¿½o aceitos os caracteres 'A' e 'B'\nInsira uma turma vï¿½lida: ");
                scanf("%c",&turma);
                setbuf(stdin,NULL);
            }

            printf("\n");

            for(aux = lista -> begin; aux != NULL; aux = aux -> next){

                if(aux -> class == turma){

                    cont++;
                    printf("%d. %s\n", cont, aux -> name);

                }

            }

            if(cont==0){

                printf("N?o existem alunos nessa turma!\n");

            }
            printf("\n");
            cont = 0;

            break;
        
        case 6:

            printf("6 . Ordenar toda a lista de alunos por nome;\n\n");

            Name_Sort(lista);
            
            node_aluno *i;
            cont = 1;
            for(i = lista -> begin; i != NULL ; i = i -> next){

                printf("%d. Nome: %s\n", cont, i -> name);
                printf("    Matrícula: %d\n", i -> enrollment);
                printf("    Nota: %.2f\n", i -> note);
                printf("    Frequência: %.2f\n", i -> frequency);
                printf("    Turma: %c\n\n", i -> class);

                cont++;
            }
            
            break;

        case 7:
            
            break;        
        
        default:

            break;
        }



    } while(o!=8);
    

    return 0;
}
