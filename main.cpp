#include "bib.h"

using namespace std;

void clear(){
    system("cls");
}
void pause(){
    system("pause");
}

void preencher(Pessoal dad) {
    cout<<"ID: ";
    cin>>dad.id;
    cout<<"\nCPF: ";
    cin>>dad.cpf;
    cout<<"\nNome: ";
    cin>>dad.nome;
    cout<<"\nCelular: ";
    cin>>dad.celular;
}
void preencher(Comercial dad) {
    cout<<"ID: ";
    cin>>dad.id;
    cout<<"\nCPF: ";
    cin>>dad.cnpj;
    cout<<"\nNome: ";
    cin>>dad.nomeEmpresa;
    cout<<"\nCelular: ";
    cin>>dad.celularComercial;
}

int selecionaPouC() {
    int escolha;
    while (escolha > 2 || escolha < 1) {
        cout<<"1 - Pessoal.\n2 - Comercial.";
        cin>>escolha;
        if (escolha > 2 || escolha < 1)
            cout<<"Valor inv�lido. Digite um valor de 1 a 2.";
    }
    return escolha;
}

template <int MAX>
int localizar(Agenda<Pessoal,MAX> &ag, string dado){
    while (true) {
        for (int i=0; i<ag.quantidade; i++) {
            if (ag.itens[i].id == dado || ag.itens[i].nome == dado) {
                return i;
            }
        }
        cout<<"Dado inv�lido. Reescreva um ID/Nome existente.\n";
        cin>>dado;
    }
}
template <int MAX>
int localizar(Agenda<Comercial,MAX> &ag, string dado){
    while (true) {
        cout<<"a";
        for (int i=0; i<ag.quantidade; i++) {
            cout<<"b";
            if (ag.itens[i].id == dado || ag.itens[i].nomeEmpresa == dado) {
                cout<<"c";
                return i;
            }
        }
        cout<<"Dado inv�lido. Reescreva um ID/Nome existente.\n";
        cin>>dado;
    }
}

int main() {
    pause();
    Pessoal contatinhos;
    Comercial work;
    Agenda <Pessoal,10> pes;
    Agenda <Comercial,10> com;
    int escolha;
    bool acabou = false;

    inicializaAgenda(pes);
    inicializaAgenda(com);

    while (!acabou) {
        cout<<"1 - Inserir um novo item na agenda.\n2 - Remover um item da agenda (pelo id ou nome).\n";
        cout<<"3 - Pesquisar um item na agenda (pelo id ou nome).\n4 - Ordenar a agenda por nome.\n";
        cout<<"5 - Mostrar todos os itens da agenda.\n6 - Encerrar o programa.\n";
        cin>>escolha;
        switch (escolha) {
        case 1: {
            int seleciona = selecionaPouC();
            if (seleciona == 1) {
                preencher(contatinhos);
                inserir(pes,contatinhos);
            }
            else if (seleciona == 2) {
                preencher(work);
                inserir(com,work);
            }

            break;
        }
        case 2: {
            int seleciona = selecionaPouC();
            string dado;
            cout<<"Digite o nome/ID de quem voce deseja remover\n";
            cin>>dado;
            if (seleciona == 1)
                remover(pes,localizar(pes,dado));
            else if (seleciona == 2)
                remover(com,localizar(com,dado));

            break;
        }
        case 3: {
            int seleciona = selecionaPouC();
            int auxPos;
            string dado;
            cout<<"Digite o nome/ID de quem voce deseja remover\n";
            cin>>dado;
            if (seleciona == 1) {
                auxPos = localizar(pes,dado);
                cout<<pes.itens[auxPos].id<<endl;
                cout<<pes.itens[auxPos].cpf<<endl;
                cout<<pes.itens[auxPos].nome<<endl;
                cout<<pes.itens[auxPos].celular<<endl;
            }
            else if (seleciona == 2) {
                auxPos = localizar(com,dado);
                cout<<com.itens[auxPos].id<<endl;
                cout<<com.itens[auxPos].cnpj<<endl;
                cout<<com.itens[auxPos].nomeEmpresa<<endl;
                cout<<com.itens[auxPos].celularComercial<<endl;
            }

            break;
        }
        case 4: {

        }
            break;
        case 5: {

        }
            break;
        case 6:
            cout<<"GG fml";
            acabou = true;
            break;
        default:
            cout<<"Valor inválido, escolha uma opção disponível.\n";
            break;
        }
    }
    return 0;
}
