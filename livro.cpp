#include "livro.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

vector<Livro> Livro::Lista;

Livro::Livro(string titulo, string autor, int anoPublicacao, float preco, int estoque, int numPaginas) {
    this->id = Lista.size();
    this->titulo = titulo;
    this->autor = autor;
    this->anoPublicacao = anoPublicacao;
    this->preco = preco;
    this->estoque = estoque;
    this->numPaginas = numPaginas;
    if(titulo != " "){
        Lista.push_back(*this);
        cout << "Livro " << this->titulo << " foi adicionado com sucesso a Lista!" << endl;
    }    
}

Livro::~Livro() {
}
const std::vector<Livro>& Livro::getLista() {
    return Lista;
}

void Livro::ImprimeDados() {
    cout << "Dados do livro: " << endl;
    cout << "Titulo: " << getTitulo() << endl;
    cout << "Autor: " << getAutor() << endl;
    cout << "Ano de Publicacao: " << getAnoPublicacao() << endl;
    cout << "Preco: " << fixed << setprecision(2) << getPreco() << " R$" << endl;
    cout << "Estoque: " << getEstoque() << endl;
    cout << "Numero de Paginas: " << getnumPaginas() << endl;
}

// Metodos de acesso (getters)
string Livro::getTitulo() const {
    return this->titulo;
}
string Livro::getAutor() const {
    return this->autor;
}
int Livro::getAnoPublicacao() const {
    return this->anoPublicacao;
}
float Livro::getPreco() const {
    return this->preco;
}
int Livro::getEstoque() const {
    return this->estoque;
}
int Livro::getnumPaginas() const {
    return this->numPaginas;
}
int Livro::getId() const {
    return this->id;
}

// Metodos de modificacao (setters)
void Livro::setTitulo(string titulo) {
    this->titulo = titulo;
}
void Livro::setAutor(string autor) {
    this->autor = autor;
}
void Livro::setAnoPublicacao(int anoPublicacao) {
    this->anoPublicacao = anoPublicacao;
}
void Livro::setPreco(float preco) {
    this->preco = preco;
}
void Livro::setEstoque(int estoque) {
    this->estoque = estoque;
}
void Livro::setnumPaginas(int numPaginas) {
    this->numPaginas = numPaginas;
}
int Livro::TamanhoLista() {
    return Lista.size();
}

void Livro::ImprimeLista() {
    if(Lista.size() == 0){
        cout << "A lista está vazia!" << endl;
    }
    for (int i = 0; i < Lista.size(); i++) {
        cout << "Titulo: " << Lista[i].getTitulo() << endl;
    }
}

// Funcao auxiliar para particionar a lista
size_t partition(vector<Livro>& arr, size_t low, size_t high, int ordenacao) {
    if (ordenacao == 1) {
        float pivot = arr[high].getPreco();
        size_t i = low - 1;

        for (size_t j = low; j < high; j++) {
            if (arr[j].getPreco() <= pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }

        std::swap(arr[i + 1], arr[high]);
        return i + 1;
    } else if (ordenacao == 2) {
        int pivot = arr[high].getAnoPublicacao();
        size_t i = low - 1;

        for (size_t j = low; j < high; j++) {
            if (arr[j].getAnoPublicacao() <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);
        return i + 1;
    } else if (ordenacao == 3) {
        int pivot = arr[high].getEstoque();
        size_t i = low - 1;

        for (size_t j = low; j < high; j++) {
            if (arr[j].getEstoque() <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);
        return i + 1;
    } else if (ordenacao == 4) {
        int pivot = arr[high].getnumPaginas();
        size_t i = low - 1;

        for (size_t j = low; j < high; j++) {
            if (arr[j].getnumPaginas() <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    // Adicionando um retorno padrao para evitar warnings
    return 0;
}

// Funcao principal do Quicksort
void quicksort(vector<Livro>& arr, size_t low, size_t high, int ordenacao) {
    if (low < high) {
        size_t pivotIndex = partition(arr, low, high, ordenacao);

        if (pivotIndex > 0) {
            quicksort(arr, low, pivotIndex - 1, ordenacao);
        }

        quicksort(arr, pivotIndex + 1, high, ordenacao);
    }
}

void Livro::ordenaPreco() {
    vector<Livro> PriceOrdered = Lista;
    quicksort(PriceOrdered, 0, PriceOrdered.size() - 1, 1);

    cout << "Precos Ordenados: " << endl;
    for (const auto& livro : PriceOrdered) {
        cout << livro.getTitulo() << " custa: " << fixed << setprecision(2) << livro.getPreco() << " R$;" << endl;
    }
}

void Livro::ordenaAno() {
    vector<Livro> YearOrdered = Lista;
    quicksort(YearOrdered, 0, YearOrdered.size() - 1, 2);

    cout << "Anos Ordenados: " << endl;
    for (const auto& livro : YearOrdered) {
        cout << livro.getTitulo() << " e de " << livro.getAnoPublicacao() << "." << endl;
    }
}

void Livro::ordenaEstoque() {
    vector<Livro> EstoqueOrdered = Lista;
    quicksort(EstoqueOrdered, 0, EstoqueOrdered.size() - 1, 3);

    cout << "Estoques Ordenados: " << endl;
    for (const auto& livro : EstoqueOrdered) {
                cout << livro.getTitulo() << " tem " << livro.getEstoque() << " livros no estoque." << endl;
    }
}

void Livro::ordenaPagina() {
    vector<Livro> PageOrdered = Lista;
    quicksort(PageOrdered, 0, PageOrdered.size() - 1, 4);

    cout << "Paginas Ordenadas: " << endl;
    for (const auto& livro : PageOrdered) {
        cout << livro.getTitulo() << " tem " << livro.getnumPaginas() << " paginas." << endl;
    }
}


void Livro::removerLivro() {
    int id = this->getId();

    auto it = find_if(Lista.begin(), Lista.end(), [id](const Livro& livro) {
        return livro.getId() == id;
    });

    if (it != Lista.end()) {
        Lista.erase(it);
        cout << "Livro removido com sucesso." << endl;
    } else {
        cout << "Livro nao encontrado." << endl;
    }
}

void Livro::editarLivro() {
    int option;
    do {
        cout << "O que voce gostaria de editar no livro " << this->getTitulo() << "?" << endl;
        cout << "1. Titulo" << endl;
        cout << "2. Autor" << endl;
        cout << "3. Ano de publicacao" << endl;
        cout << "4. Preco" << endl;
        cout << "5. Estoque" << endl;
        cout << "6. Numero de paginas" << endl;
        cout << "0. Sair da edicao" << endl;

        cin >> option;

        switch (option) {
            case 1: {
                string novoTitulo;
                cout << "Insira o novo titulo: ";
                cin.ignore();  // Limpar o buffer antes de ler a string
                getline(cin, novoTitulo);
                this->setTitulo(novoTitulo);
                break;
            }
            case 2: {
                string novoAutor;
                cout << "Insira o novo autor: ";
                cin.ignore();  // Limpar o buffer antes de ler a string
                getline(cin, novoAutor);
                this->setAutor(novoAutor);
                break;
            }
            case 3: {
                int novoAno;
                cout << "Insira o novo ano de publicacao: ";
                cin >> novoAno;
                this->setAnoPublicacao(novoAno);
                break;
            }
            case 4: {
                float novoPreco;
                cout << "Insira o novo preco: ";
                cin >> novoPreco;
                this->setPreco(novoPreco);
                break;
            }
            case 5: {
                int novoEstoque;
                cout << "Insira o novo estoque: ";
                cin >> novoEstoque;
                this->setEstoque(novoEstoque);
                break;
            }
            case 6: {
                int novasPaginas;
                cout << "Insira o novo numero de paginas: ";
                cin >> novasPaginas;
                this->setnumPaginas(novasPaginas);
                break;
            }
            case 0:
                cout << "Saindo da edicao." << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (option != 0);
}

