#include <iostream>
using namespace std;
int hash_aux(int k, int m) // hashaux==h
{                          // função //k é o valor que vai entrar no vetor //m é o tamanho do vetor
    int h = k % m;
    if (h < 0)
        h += m;

    return h;
}
int hash1(int k, int i, int m) // hash1==h'
{
    int h = (hash_aux(k, m) + i) % m;

    return h;
}
int main()
{ // função principal
    int k;
    int m;
    int aux; // recebe função
    int vet[50];

    cin >> k >> m; // entraada de dados

    for (int i = 0; i < m; i++)
    { // coloca os elemntos do vetor na posição possível
        vet[i] = hash1(k, i, m);
    }

    for (int i = 0; i < m; i++)
    {
        cout << vet[i] << " ";
    }

    return 0;
}
