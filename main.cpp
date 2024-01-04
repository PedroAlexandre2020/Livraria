#include "livro.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>  

using namespace std;

int main() {
    int saida = -1;  

    while (saida != 0) {
        cout << "Ola, seja bem-vindo a livraria! Insira qual das operacoes voce deseja executar. Lembrando que se quiser sair, insira 0." << endl;
        cout << "Adicionar um Livro(1) / " << "Editar um livro(2) / " << "Listar todos os livros(3) / " << "Apagar um livro(4) / " << endl;
        cout << "Ordenar por Preco(5) / " << "Ordenar por Ano de Publicacao(6) / " << "Ordenar por estoque(7) / " << "Ordenar por numero de paginas(8) / "<< endl;
        cout << "Sair(0)" << endl;

        cin >> saida;

        if (saida >= 0 && saida <= 8) {
            string title;
            string author;
            int publi;
            float price;
            int storage;
            int pages;
            Livro inicial(" ", "xuxa", 2000, 39.99, 9, 0);

            switch (saida) {
                case 1: {
                    cout << "Digite os detalhes do livro:" << endl;
                    cout << "Titulo: "; cin >> title;
                    cout << "Autor: "; cin >> author;
                    cout << "Ano de Publicacao: "; cin >> publi;
                    cout << "Preco: "; cin >> price;
                    cout << "Estoque: "; cin >> storage;
                    cout << "Numero de Paginas: "; cin >> pages;

                    Livro livroNovo(title, author, publi, price, storage, pages);
                    break;
                }
                case 2: {
                    cout << "Digite o titulo do livro que deseja editar: ";
                    string tituloParaEditar;
                    cin >> tituloParaEditar;

                    auto it = find_if(Livro::Lista.begin(), Livro::Lista.end(), [tituloParaEditar](const Livro& livro) {
                        return livro.getTitulo() == tituloParaEditar;
                    });

                    if (it != Livro::Lista.end()) {
                        it->editarLivro();
                    } else {
                        cout << "Livro nao encontrado." << endl;
                    }
                    break;
                }
                case 3:
                    inicial.ImprimeLista();
                    break;
                case 4: {
                    cout << "Digite o titulo do livro que deseja apagar: ";
                    string tituloParaApagar;
                    cin >> tituloParaApagar;

                    auto it = find_if(Livro::Lista.begin(), Livro::Lista.end(), [tituloParaApagar](const Livro& livro) {
                        return livro.getTitulo() == tituloParaApagar;
                    });

                    if (it != Livro::Lista.end()) {
                        it->removerLivro();
                    } else {
                        cout << "Livro nao encontrado." << endl;
                    }
                    break;
                }
                case 5:
                    inicial.ordenaPreco();
                    break;
                case 6:
                    inicial.ordenaAno();
                    break;
                case 7:
                    inicial.ordenaEstoque();
                    break;
                case 8:
                    inicial.ordenaPagina();
                    break;
                case 0:
                    cout << "Saindo do programa." << endl;
                    break;
            }
        } else {
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    }

    return 0;
}
