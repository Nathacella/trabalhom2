#include <iostream>
#include <stdlib.h> /// Clear e Pause

using namespace std;

struct Pessoal {
    string id, cpf, nome, celular;
};

struct Comercial {
    string id, cnpj, nomeEmpresa, celularComercial;
};

template <typename TIPO, int MAX>
struct Agenda {
    TIPO itens[MAX];
    int quantidade;
};

// Inicializa a agenda. Inicializações: Define que agenda está sem nenhum item.
template <typename TIPO, int MAX>
bool inicializaAgenda(Agenda <TIPO,MAX> &ag) {
    ag.quantidade = 0;
    return true;
};

// Inserir um contato:
template <typename TIPO, int MAX>
bool inserir(Agenda <TIPO,MAX> &ag, TIPO dado) {
    if (ag.quantidade >= MAX) {
        return false;
    }
    ag.itens[ag.quantidade] = dado;
    quantidade++;
    return true;
}

// Remover um contato (pelo id ou nome):
// Pessoal
template <typename TIPO, int MAX>
bool remover(Agenda <TIPO,MAX> &ag, int pos) {
    if (pos < 0 || pos >= ag.quantidade) {
        return false;
    }

    for(int i = pos; i<ag.quantidade; i++)
        ag.itens[i] = ag.itens[i+1];
    ag.quantidade--;
    return true;
}
