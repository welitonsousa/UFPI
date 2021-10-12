#include <stdio.h>
#include <stdlib.h>

struct avr23
{
    int info1, info2, nInfos;
    struct avr23 *esq, *cen, *dir;
};
typedef struct avr23 Avr23;

int eFolha(Avr23 *raiz)
{
    int folha = 0;
    if (raiz->esq == NULL && raiz->cen == NULL && raiz->dir == null)
    {
        folha = 1;
    }
    return folha;
}

Avr23 *addNo(int info, Avr23 *filhoEsq, Avr23 *filhoCen)
{
    Avr23 *no;
    no = (Avr23 * malloc(sizeof(Avr23 *)));
    no->esq = filhoEsq;
    no->cen = filhoCen;
    no->dir = NULL;
    no->nInfos = 1;

    return no;
}

int add(Avr23 **pai, Avr23 **raiz, int valor)
{
    int inseriu = 0;
    if (*raiz == NULL)
    {
        *raiz = *addNo(valor, NULL, NULL, NULL);
    }
    else if (eFolha(*raiz))
    {
        if ((**raiz).nInfos == 1)
        {
            *raiz = addNo(*raiz, valor);
        }
        else
        {
            quebraNo(raiz, valor, no, sobe);
            if (pau == NULL)
            {
                Avr23 *novo;
                novo = addNo(sobe, *raiz, *no, NULL);
            }
            else if (**pai->nInfos == 1)
            {
                addNo(pai, sobe);
            }
        }
    }
    return valor;
}

Avr23 *addNo(Avr23 *no, int info, Avr23 *filho)
{
    if (info > no->info1)
    {
        no->info2 = info;
        no->dir = filho;
    }
    else
    {
        no->info2 = no->info1;
        no->info1 = info;
        no->dir = no->cen;
        no->cen = filho;
    }
    no->nInfos = 2;
    return no;
}

int main()
{
    printf("hello");
}