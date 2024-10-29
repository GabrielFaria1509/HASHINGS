#include <iostream>
using namespace std;
struct dado
{
    int k;
    int status; // 0-vazio, 1-ocupado, 2-removido
};
int h1(int k, int m) // início double hashing
{
    int h1 = k % m;

    if (h1 < 0)
    {
        h1 += m;
    }

    return h1;
}
int h2(int k, int m)
{
    int h2;

    h2 = 1 + (k % (m - 1));

    if (h2 < 0)
    {
        h2 += m;
    }

    return h2;
}
int dhash(int k, int m, int i) // fim double hashinh
{
    int h3;

    h3 = (h1(k, m) + i * h2(k, m)) % m;

    if (h3 < 0)
    {
        h3 = h3 + m;
    }

    return h3;
}
int hash_insert(dado t[], int m, int k) // hash de inserir a chave
{
    int j;
    int i = 0;

    do
    {
        j = dhash(k, m, i);
        if (t[j].status != 1)
        {
            t[j].k = k;
            t[j].status = 1;

            return j;
        }
        else
        {
            i = i + 1;
        }
    } while (i != m);

    return -1;
}
int hash_search(dado t[], int m, int k) // hash de prcurar valor
{
    int i = 0;
    int j;
    do
    {
        j = dhash(k, m, i);
        if (t[j].k == k)
        {
            return j;
        }
        i = i + 1;

    } while (t[j].status != 0 && i < m);

    return -1;
}
int hash_remove(dado t[], int m, int k)
{ // hash para remover o valor
    int j = hash_search(t, m, k);
    if (j != -1)
    {
        t[j].status = 2;
        t[j].k = -1;

        return 0; // consegui remover
    }
    else
    {
        return -1; // k não está na tabela
    }
}
int main() // principal
{
    int i = 0; // contador
    int k;     // chave
    int m;     // tamanho vetor
    int opcao = 0;
    int aux;

    cin >> m; // entrada tamanho da tabela

    dado t[m]; // struct que vai armazenas chaves

    for (i = 0; i < m; i++) // preciso desse for para inicializar o vetor do struct
    {
        t[i].k = -1;
        t[i].status = 0;
    }

    cin >> opcao; // entrada 2 , opção desejada

    do
    {
        // loop para rodar enquanto usuário quer usar // condição de parada é opção 5

        if (opcao == 1)
        { // caso opção 1

            cin >> k;
            aux = hash_insert(t, m, k); // insere elentos nas posições
        }

        if (opcao == 2)
        { // caso opção 2

            cin >> k; // chave a ser procurada
            int posicao = hash_search(t, m, k);

            cout << posicao << endl;
        }

        if (opcao == 3)
        { // caso opção 3

            cin >> k; // chave que quero remover

            aux = hash_remove(t, m, k);
        }

        if (opcao == 4)
        { // caso opção 4
            for (i = 0; i < m; i++)
            {
                if (i < m - 1)
                {
                    cout << t[i].k << " ";
                }
                else
                {
                    cout << t[i].k << endl;
                }
            }
        }

        cin >> opcao; // pergunta opção desejada novamente  // usuário pode querer usar de novo , evito de dar saída infinita de alguma opção

    } while (opcao != 5);

    return 0;
}
