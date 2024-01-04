#ifndef LIVRO_H
#define LIVRO_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Livro {
public:
    // contrutor com parametros 
    Livro(string titulo, string autor, int anoPublicacao, float preco, int estoque, int numPaginas);

    // Destrutor
    ~Livro();

    // Métodos de acesso (getters)
    int getId() const;
    string getTitulo() const;
    string getAutor() const;
    int getAnoPublicacao() const;
    float getPreco() const;
    int getEstoque() const;
    int getnumPaginas() const;

    // Métodos de modificação (setters)
    void setTitulo(string titulo);
    void setAutor(string autor);
    void setAnoPublicacao(int anoPublicacao);
    void setPreco(float preco);
    void setEstoque(int estoque);
    void setnumPaginas(int numPaginas);
    void ordenaAno();
    void ordenaPagina();
    void ordenaEstoque();
    void ImprimeDados();
    void ImprimeLista();
    void ordenaPreco();
    int TamanhoLista(); 
    void adicionaLivro() {
        cout << "Insira o nome do Livro: " << endl;
        string title;
        cin >> title;

        cout << "Insira o Autor(a): " << endl;
        string author;
        cin >> author;

        cout << "Insira Ano de Publicacao: " << endl;
        int ano_publicacao;
        cin >> ano_publicacao;

        cout << "Insira o preco: " << endl;
        float price;
        cin >> price;

        cout << "Insira o estoque: " << endl;
        int estoque;
        cin >> estoque;

        cout << "Insira o numero de paginas: " << endl;
        int num_paginas;
        cin >> num_paginas;
        Livro LivroAdicionado(title, author, ano_publicacao, price, estoque, num_paginas);
}
    void removerLivro();
    void editarLivro();
    static const vector<Livro>& getLista();
    static vector<Livro> Lista;

private:
    // Atributos privados
    int id;
    string titulo;
    string autor;
    int anoPublicacao;
    float preco;
    int estoque;
    int numPaginas;

    
};

#endif // LIVRO_H
