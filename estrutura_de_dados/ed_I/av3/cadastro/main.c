#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct pessoa Pessoa;
typedef struct docente Docente;
typedef struct discente Discente;

//struts...
struct pessoa
{
    char *nome;
    int idade, ID; //identificador
    int matricula; //deve ser gerada automaticamente
};

struct docente
{
    Pessoa info_docente;
    int qtd_orientacoes_graduacao, qtd_orientacoes_pos_graduacao;
};

struct discente
{
    Pessoa info_discente;
    int nivel; // 1- graduacao ou 2 - posgraduacao
    char *nome_curso;
    int senha, ID_orientador, ID_coorientador;
};



//funcoes: 

int menu(){
		int opcao;
		do{
			printf("\n\t\t\t\tMenu\n");
	        printf("\t\t\t(1) - cadastrar docente\n");
	        printf("\t\t\t(2) - cadastrar discente\n");
	        printf("\t\t\t(3) - mostrar docentes\n");
	        printf("\t\t\t(4) - mostrar discentes\n");
	        printf("\t\t\t(5) - adicionar orientador ao discente\n");
	        printf("\t\t\t(6) - adicionar coorientador ao discente\n");
	        printf("\t\t\t(7) - mostrar alunos do docente\n");
	        printf("\t\t\t(8) - mostrar alunos sem orientadores\n");
	        printf("\t\t\t(9) - remover discente\n");
	        printf("\t\t\t(10) - buscar docente\n");
	        printf("\t\t\t(11) - buscar discente\n");
	        printf("\t\t\t(0) - remover docente\n");
	        printf("\nOpcao: ");
        	scanf("%d", &opcao);
		}while(opcao < 0);
		printf("\n");
		return opcao;
}

Docente *cadastrarDocente(Docente *docentes, int *quantDocentes){
    if (*quantDocentes == 0)
    {
        docentes = (Docente *)calloc(1, sizeof(Docente));
    }
    else
    {
        docentes = realloc(docentes, sizeof(Docente) * (*quantDocentes + 1));//transforma em uma matrix de docentes
    }
    printf("Digite o nome: ");
    char nome[50];
    scanf("%s", nome);
    setbuf(stdin, NULL);
    docentes[*quantDocentes].info_docente.nome = (char *)malloc(sizeof(nome));//reserva o espaco na memoria para a variavelnome
    strcpy(docentes[*quantDocentes].info_docente.nome, nome);

    printf("Digite a idade: ");
    scanf("%d", &docentes[*quantDocentes].info_docente.idade);

    printf("Digite o ID: ");
    scanf("%d", &docentes[*quantDocentes].info_docente.ID);

    docentes[*quantDocentes].info_docente.matricula = rand() % 1000;
    docentes[*quantDocentes].qtd_orientacoes_graduacao = 0;
    docentes[*quantDocentes].qtd_orientacoes_pos_graduacao = 0;

    (*quantDocentes)++;
    printf("Docente adicionado\n");
    return docentes;
}

Discente *cadastrarDiscente(Discente *discentes, int *quantDiscentes)
{
    if (*quantDiscentes == 0)
    {
        discentes = (Discente *)calloc(1, sizeof(Discente));
    }
    else
    {
        discentes = (Discente *)realloc(discentes, sizeof(Discente) * (*quantDiscentes + 1));
    }

    printf("Digite o nome: ");
    char string[50];
    scanf("%s", string);
    setbuf(stdin, NULL);

    discentes[*quantDiscentes].info_discente.nome = (char *)malloc(sizeof(string));
    strcpy(discentes[*quantDiscentes].info_discente.nome, string);
    printf("Digite a idade: ");
    scanf("%d", &discentes[*quantDiscentes].info_discente.idade);

    printf("Digite o ID: ");
    scanf("%d", &discentes[*quantDiscentes].info_discente.ID);
    discentes[*quantDiscentes].info_discente.matricula = rand() % 9000 + 1000;

    printf("Digite nÃ­vel (1- graduando, 2 - pos-graduando): ");
    scanf("%d", &discentes[*quantDiscentes].nivel);

    printf("Digite o nome do curso: ");
    scanf("%s", string);
    setbuf(stdin, NULL);
    discentes[*quantDiscentes].nome_curso = (char *)malloc(sizeof(string));
    strcpy(discentes[*quantDiscentes].nome_curso, string);
    printf("digite a senha: ");
    scanf("%d", &discentes[*quantDiscentes].senha);
    discentes[*quantDiscentes].info_discente.matricula = rand() % 1000;
    discentes[*quantDiscentes].ID_orientador = 0;
    discentes[*quantDiscentes].ID_coorientador = 0;
    (*quantDiscentes)++;
    return discentes;
}

void mostrarDiscentes(Discente *discentes, int quantDiscentes)
{
	int i;
    for (i = 0; i < quantDiscentes; i++)
    {
        printf("nome: %s\n", discentes[i].info_discente.nome);
        printf("idade: %d\n", discentes[i].info_discente.idade);
        printf("ID: %d\n", discentes[i].info_discente.ID);
        printf("matricula: %d\n", discentes[i].info_discente.matricula);
        printf("nivel: %d\n", discentes[i].nivel);
        printf("curso: %s\n", discentes[i].nome_curso);
        if (discentes->ID_orientador != 0)
        {
            printf("id orientador: %d\n", discentes[i].ID_orientador);
        }
        if (discentes->ID_coorientador != 0)
        {
            printf("id coorientador: %d\n", discentes[i].ID_coorientador);
        }
        printf("-----------------\n");
    }
    if(quantDiscentes == 0){
		printf("\nNao possuem Discentes cadastrados!\n");
	}
}

int buscarDocente(Docente *docentes, int quantidadeDocentes, int idDocente)
{
	int i;
    for (i = 0; i < quantidadeDocentes; i++)
    {
        if (idDocente == docentes[i].info_docente.ID)
        {
            return i;
        }
    }
    printf("docente nao encontrado\n");
    return -1;
}

int buscarDiscente(Discente *discentes, int quantidadeDiscentes, int idDiscente)
{
	int i;
    for (i = 0; i < quantidadeDiscentes; i++)
    {
        if (idDiscente == discentes[i].info_discente.ID)
        {
            return i;
        }
    }
    printf("discente nao encontrado\n");
    return -1;
}

void mostrarDocentes(Docente *docentes, int quantidadeDocentes)
{
	int i;
    for (i = 0; i < quantidadeDocentes; i++)
    {
        printf("nome: %s\n", docentes[i].info_docente.nome);
        printf("idade: %d\n", docentes[i].info_docente.idade);
        printf("ID: %d\n", docentes[i].info_docente.ID);
        printf("matricula: %d\n", docentes[i].info_docente.matricula);
        printf("-----------------\n");
    }
    if(quantidadeDocentes == 0){
		printf("Nao possuem Docentes Cadastrados!\n");
	}
}

void addOrientadorParaDiscente(Discente *discentes, int quantidadeDiscentes, Docente *docentes, int quantidadeDocentes)
{
    int idDocente, idDiscente;
    printf("Id do docente: ");
    scanf("%d", &idDocente);
    int indexDocente = buscarDocente(docentes, quantidadeDocentes, idDocente);
    if (indexDocente != -1)
    {
        printf("Id do discente: ");
        scanf("%d", &idDiscente);
        int indexDiscente = buscarDiscente(discentes, quantidadeDiscentes, idDiscente);
        if (indexDiscente != -1)
        {
        	if( discentes[indexDiscente].ID_orientador != idDocente){
                if (discentes[indexDiscente].nivel == 1 && docentes[indexDocente].qtd_orientacoes_graduacao <= 4)
                {
                    docentes[indexDocente].qtd_orientacoes_graduacao += 1;
                    discentes[indexDiscente].ID_orientador = idDocente;
                    printf("operacao concluida\n");
                }
                else if (discentes[indexDiscente].nivel == 2 && docentes[indexDocente].qtd_orientacoes_pos_graduacao <= 6)
                {
                    docentes[indexDocente].qtd_orientacoes_pos_graduacao += 1;
                    discentes[indexDiscente].ID_orientador = idDocente;
                    printf("operacao concluida\n");
                }
            }
        }
    }
}

void addCoorientadorParaDiscente(Discente *discentes, int quantidadeDiscentes, Docente *docentes, int quantidadeDocentes)
{
    int idDocente, idDiscente;
    printf("Id do docente: ");
    scanf("%d", &idDocente);
    int indexDocente = buscarDocente(docentes, quantidadeDocentes, idDocente);
    if (indexDocente != -1)
    {
        printf("Id do discente: ");
        scanf("%d", &idDiscente);
        int indexDiscente = buscarDiscente(discentes, quantidadeDiscentes, idDiscente);
        if (indexDiscente != -1)
        {
            if (idDocente != discentes[indexDiscente].ID_orientador)
            {
                if (discentes[indexDiscente].nivel == 1 && docentes[indexDocente].qtd_orientacoes_graduacao <= 4)
                {
                    docentes[indexDocente].qtd_orientacoes_graduacao += 1;
                    discentes[indexDiscente].ID_coorientador = idDocente;
                    printf("operacao concluida\n");
                }
                else if (discentes[indexDiscente].nivel == 2 && docentes[indexDocente].qtd_orientacoes_pos_graduacao <= 6)
                {
                    discentes[indexDiscente].ID_coorientador = idDocente;
                    docentes[indexDocente].qtd_orientacoes_pos_graduacao += 1;
                    printf("operacao concluida\n");
                }
            }
        }
    }
}


void mostrarAlunosDocente(Docente *docentes, int quantidadeDocentes, Discente *discentes, int quantidadeDiscente)
{
    printf("Digite o id do Docente: ");
    int idDocente;
    scanf("%d", &idDocente);
    int indexDocente = buscarDocente(docentes, quantidadeDocentes, idDocente);
    if (indexDocente != -1)
    {
    	int i;
        for (i = 0; i < quantidadeDiscente; i++)
        {
            if (discentes[i].ID_orientador == idDocente || discentes[i].ID_coorientador == idDocente)
            {
                printf("Nome: %s\n", discentes[i].info_discente.nome);
            }
        }
    }
}


void mostrarAlunosSemOrientador(Discente *discentes, int quantidadeDiscentes)
{
	int i;
    for (i = 0; i < quantidadeDiscentes; i++)
    {
        if (discentes[i].ID_orientador == 0)
        {
            printf("Nome: %s\n", discentes[i].info_discente.nome);
            printf("Idade: %d\n", discentes[i].info_discente.idade);
            printf("ID: %d\n", discentes[i].info_discente.ID);
            printf("Matricula: %d\n", discentes[i].info_discente.matricula);
            printf("------------------\n");
        }
    }
}


Discente *removerDiscente(Discente *discentes, int *quantidadeDiscentes, Docente *docentes, int quantidadeDocentes)
{
    int idDiscente, indexDiscente;
    printf("\nId do discente: ");
    scanf("%d", &idDiscente);
    indexDiscente = buscarDiscente(discentes, *quantidadeDiscentes, idDiscente);
    if (idDiscente != -1)
    {

        int indexOrientador = buscarDocente(docentes, quantidadeDocentes, discentes[indexDiscente].ID_orientador);
        int indexCoorientador = buscarDocente(docentes, quantidadeDocentes, discentes[indexDiscente].ID_coorientador);

        if (discentes[indexDiscente].nivel == 1)
        {
            if (indexOrientador != -1)
            {
                docentes[indexOrientador].qtd_orientacoes_graduacao -= 1;
            }
            if (indexCoorientador != -1)
            {
                docentes[indexCoorientador].qtd_orientacoes_graduacao -= 1;
            }
        }
        else if (discentes[indexDiscente].nivel == 2)
        {
            if (indexOrientador != -1)
            {
                docentes[indexOrientador].qtd_orientacoes_pos_graduacao -= 1;
            }
            if (indexCoorientador != -1)
            {
                docentes[indexCoorientador].qtd_orientacoes_pos_graduacao -= 1;
            }
        }
		
		int i;
        for (i = indexDiscente; i < *quantidadeDiscentes; i++)
        {
            if (i < *quantidadeDiscentes - 1)
            {
                discentes[i] = discentes[i + 1];
            }
        }
        discentes = realloc(discentes, sizeof(Discente) * (*quantidadeDiscentes - 1));
        *quantidadeDiscentes -= 1;
        printf("Discente removido\n");
    }
    return discentes;
}

Docente *removerDocente(Docente *docentes, int *quantidadeDocentes)
{
    int idDocente, indexDocente;
    printf("\nId do docente: ");
    scanf("%d", &idDocente);
    indexDocente = buscarDocente(docentes, *quantidadeDocentes, idDocente);
    if (indexDocente != -1)
    {

        if (docentes[indexDocente].qtd_orientacoes_graduacao + docentes[indexDocente].qtd_orientacoes_pos_graduacao == 0)
        {
			int i;
            for (i = indexDocente; i < *quantidadeDocentes; i++)
            {
                if (i < *quantidadeDocentes - 1)
                {
                    docentes[i] = docentes[i + 1];
                }
            }
            docentes = realloc(docentes, sizeof(Discente) * (*quantidadeDocentes - 1));
            *quantidadeDocentes -= 1;
            printf("Docente removido\n");
        }else{
            printf("Este docente nao pode ser removido, pois esta orientando alguem\n");
        }
    }
    return docentes;
}


int main(){
    srand(time(NULL));
    Docente *docentes;
    int quantDocentes = 0;
    Discente *discentes;
    int quantDiscentes = 0;
    int idDocente;
    int indexDocente;
    int idDiscente;
    int indexDiscente;


    while(1)
		{
        	switch(menu())
			{
			case 1:
				docentes = cadastrarDocente(docentes, &quantDocentes);
				break;
			case 2:
				discentes = cadastrarDiscente(discentes, &quantDiscentes);
				break;
			case 3:
				 mostrarDocentes(docentes, quantDocentes);
				break;
			case 4:
				mostrarDiscentes(discentes, quantDiscentes);
				break;
			case 5:
				addOrientadorParaDiscente(discentes, quantDiscentes, docentes, quantDocentes);
				break;
			case 6:
                addCoorientadorParaDiscente(discentes, quantDiscentes, docentes, quantDocentes);
				break;
			case 7: 
				 mostrarAlunosDocente(docentes, quantDocentes, discentes, quantDiscentes);
				break;
			case 8:
				mostrarAlunosSemOrientador(discentes, quantDiscentes);
				break;
			case 9:
				removerDiscente(discentes, &quantDiscentes, docentes, quantDocentes);
				break;
			
			case 10:
				
            	printf("Id do Docente: ");
            	scanf("%d", &idDocente);
            	indexDocente = buscarDocente(docentes, quantDocentes, idDocente);
            	if (indexDocente != -1) {
                	printf("nome: %s\n", docentes[indexDocente].info_docente.nome);
                	printf("Idade: %d\n", docentes[indexDocente].info_docente.idade);
                	printf("matricula: %d\n", docentes[indexDocente].info_docente.matricula);
            		printf("ID: %d\n", docentes[indexDocente].info_docente.ID);
				}
        	   	break;
            
			case 11:
				printf("Id do Discente: ");
				scanf("%d", &idDiscente);
            	indexDiscente = buscarDiscente(discentes, quantDiscentes, idDiscente);
            	if (indexDiscente != -1) {
 	 	  	    	printf("nome: %s\n", discentes[indexDiscente].info_discente.nome);
                	printf("Idade: %d\n", discentes[indexDiscente].info_discente.idade);
                	printf("matricula: %d\n", discentes[indexDiscente].info_discente.matricula);
                	printf("ID: %d\n", discentes[indexDiscente].info_discente.ID);
 	 	        }
 	 	        break;
			case 0:
				   removerDocente(docentes, &quantDocentes);
				break;
			default:
				break;
			}
    }
    return 0;
}