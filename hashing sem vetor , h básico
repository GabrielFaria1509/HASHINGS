#include <iostream>
using namespace std;
int hash_aux(int k, int m)
{
    int aux;
    aux = k % m;

    if (aux >= 0)
    {
        return aux;
    }
    else
        return aux + m;
}
int main()
{
    int k;
    int m;
    int aux;

    cin >> k;
    cin >> m;

    while (k != 0 && m != 0)
    {
        aux = hash_aux(k, m);
        cout << aux << endl;
        cin >> k;
        cin >> m;
    }
    return 0;
}
