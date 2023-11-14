#include <iostream>

struct LISTA
{
    int aresta[2];
    LISTA *proximo = NULL;
};

LISTA *criarLista();
void adicionarAresta(LISTA *&grafo, int v1, int v2);
void preencherGrafo(LISTA *&grafo, int vertices);
void imprimirGrafo(LISTA *grafo);
int contarLacos(LISTA *grafo);
bool verificarIsolado(LISTA *grafo);
int len(LISTA *grafo);
int contarVerticeFolha(LISTA *grafo, int vertices);

int main()
{
    LISTA *grafo = criarLista();
    int vertices = 0;
    std::cout << "Quantos vertices o grafo possui? ";
    std::cin >> vertices;
    preencherGrafo(grafo, vertices);
    imprimirGrafo(grafo);
    std::cout << "Quantidade de lacos: " << contarLacos(grafo) << '\n';
    std::cout << "Quantidade de vertices folha: " << contarVerticeFolha(grafo, vertices) << '\n';
    std::cout << "Existe isolados: " << (verificarIsolado(grafo) ? "Sim" : "Nao") << '\n';
    return 0;
}

LISTA *criarLista()
{
    return NULL;
}

void adicionarAresta(LISTA *&grafo, int v1, int v2)
{
    LISTA *novo = new LISTA;
    novo->aresta[0] = v1;
    novo->aresta[1] = v2;
    if (grafo == NULL)
    {
        grafo = novo;
    }
    else
    {
        LISTA *p = grafo;
        while (p->proximo != NULL)
        {
            p = p->proximo;
        }
        p->proximo = novo;
    }
}

void preencherGrafo(LISTA *&grafo, int vertices)
{
    int adj = 0;
    int aresta = 0;
    for (int i = 0; i < vertices; i++)
    {
        std::cout << "O vertice " << i + 1 << " possui quantas adjacencias? ";
        std::cin >> adj;
        if (adj == 0)
        {
            adicionarAresta(grafo, i + 1, adj);
        }
        for (int j = 0; j < adj; j++)
        {
            std::cout << "O vertice " << i + 1 << " se conecta a: ";
            std::cin >> aresta;
            if (aresta <= vertices && aresta > 0)
            {
                adicionarAresta(grafo, i + 1, aresta);
            }
        }
    }
}

void imprimirGrafo(LISTA *grafo)
{
    LISTA *p = grafo;
    while (p->proximo != NULL)
    {
        std::cout << "[" << p->aresta[0] << ", " << p->aresta[1] << "], ";
        p = p->proximo;
    }
    std::cout << "[" << p->aresta[0] << ", " << p->aresta[1] << "]. \n";
}

int contarLacos(LISTA *grafo)
{
    int lacos = 0;
    LISTA *p = grafo;
    while (p != NULL)
    {
        if (p->aresta[0] == p->aresta[1])
        {
            lacos++;
            p = p->proximo;
        }
        else
        {
            p = p->proximo;
        }
    }
    return lacos;
}

bool verificarIsolado(LISTA *grafo)
{
    LISTA *p = grafo;
    while (p != NULL)
    {
        if (p->aresta[1] == 0)
        {
            return true;
        }
        else
        {
            p = p->proximo;
        }
    }
    return false;
}

int len(LISTA *grafo)
{
    int tamanho = 0;
    LISTA *p = grafo;
    while (p != NULL)
    {
        tamanho++;
        p = p->proximo;
    }
    return tamanho;
}

int contarVerticeFolha(LISTA *grafo, int vertices)
{
    int quantidade = 0;
    int *grau = new int[vertices]{0};
    LISTA *p;

    for (int i = 1; i <= vertices; i++)
    {
        p = grafo;
        while (p != NULL)
        {
            if (p->aresta[0] == i)
            {
                grau[i - 1]++;
            }
            p = p->proximo;
        }
    }

    for (int i = 0; i < vertices; i++)
    {
        if (grau[i] == 1)
        {
            quantidade++;
        }
    }
    delete[] grau;
    return quantidade;
}