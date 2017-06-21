/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cadastro.cpp
 * Author: junior
 * 
 * Created on 19 de Junho de 2017, 23:32
 */

#include "Cadastro.h"

//Implementacao do construtor
Cadastro::Cadastro(){
    //Inicializa a lista encadeada com 0
    this->tamanho = 0;
    //Faz o primeiro elemento apontar para nulo
    this->primeiro = NULL;
    this->ultimo = NULL;
};

//Metodo responsavel por inserir um animal na lista encadeada
void Cadastro::inserirAnimal(string nome, string raca, string dono, string especie, int idade){
        Animal* procurado = buscaInterna(nome,dono);
        if(procurado == NULL){

                Animal* novo = new Animal(nome,raca,especie,dono,idade);

                if(tamanho == 0){
                        primeiro = novo;
                        ultimo = novo;
                        novo->anterior = NULL;
                        novo->proximo = NULL;			
                        tamanho++;
                        std::cout << "\033c";  // Limpa a tela.
                        cout << "\n Animal inserido com sucesso \n ";
                }
                else{

                        //Insere o novo no final da lista
                        ultimo->proximo = novo;

                        //Guarda a referecia do ultimo
                        novo->anterior = ultimo;

                        //Reposicionando o ultimo
                        ultimo = novo;

                        //Inclemento do contador que controla o tamanho da lista
                        tamanho++;

                        std::cout << "\033c";  // Limpa a tela.
                        cout << "\n Animal inserido com sucesso \n ";
                }
        }
        else{

                std::cout << "\033c";  // Limpa a tela.
                cout << "\n Animal ja cadastrado \n ";
        }	
};

//Metodo responsavel por remover um animal na lista encadeada
void Cadastro::removerAnimal(string nome, string dono){

        Animal* procurado = buscaInterna(nome,dono);

        if(procurado == NULL){
                cout << "\n Animal nao encontrado " << endl;
        }
        else{
                //Removendo unico elemento da lista
                if(procurado->proximo == NULL and procurado->anterior == NULL){
                        //Tamanho da lista recebe 0
                        tamanho = 0;

                        //ultimo e proximo aponta para nulo
                        primeiro = NULL;
                        ultimo = NULL;

                        //Deleta arquivo procurado
                        delete procurado;

                        // Limpa a tela.
                        std::cout << "\033c";

                }

                //Removendo no meio da lista
                else if(procurado->proximo != NULL and procurado->anterior != NULL){
                        //remove um elemento do contador da lista
                        tamanho--;

                        //Redefine os ponteiros
                        procurado->proximo->anterior = procurado->anterior;
                        procurado->anterior->proximo = procurado->proximo;

                        //Deleta o animal procurado
                        delete procurado;

                        // Limpa a tela.
                        std::cout << "\033c";
                }	 

                //Removendo no fim da lista
                else if(procurado->proximo == NULL and procurado->anterior != NULL){
                        //remove um elemento do contador da lista
                        tamanho--;

                        //Redefine os ponteiros
                        procurado->anterior->proximo = NULL;

                        //Deleta o animal procurado
                        delete procurado;
                        // Limpa a tela.
                        std::cout << "\033c";

                }

                cout << "\n Animal removido com sucesso " << endl;
        }
};

//Metodo responsavel por buscar um animal na lista encadeada	
Animal* Cadastro::buscaInterna(string nome,string dono){
        Animal* aux = primeiro;
        bool achou = false;
        while(achou == false and aux!=NULL){
                if(aux->nome == nome and aux->dono == dono){
                        achou = true;
                        return aux;
                }
                else{
                        aux = aux->proximo;
                }
        }

        return NULL;
};

//Metodo responsavel por imprimir o nome do dono e do animal de todos animais cadastrado no sistema
void Cadastro::imprimeAnimaisCadastrados(){
        Animal* aux = primeiro;
        if (aux == NULL){
                // Limpa a tela.
                std::cout << "\033c";			
                cout << "\n Nao ha animais cadastrados \n";
                cout << "\n PRECIONE ENTER PARA CONTINUAR \n";
        }	
        else{
                // Limpa a tela.
                std::cout << "\033c";

                //Funcionalidade do metodo			
                cout << "\n Os seguintes animais estao cadastrados no sistema: \n";
                while(aux!=NULL){
                        cout << " \n Cachorro: " << aux->nome << "        Proprietario: " << aux->dono << " \n ";
                        aux = aux->proximo;
                }
                cout << " \n Total de animais cadastrados: " << tamanho << endl; 
        }	
};

//Metodo responsavel por imprimir a ficha do animal cadastrado no sistema
void Cadastro::imprimeHistorico(string nome, string dono){

        Animal* buscado = buscaInterna(nome,dono);

        if(buscado == NULL){
                // Limpa a tela.
                std::cout << "\033c";			
                cout << "\n Animal nao encontrado" << endl;
        }
        else{
                // Limpa a tela.
                std::cout << "\033c";

                // Funcioanlidade do metodo			
                cout << " \n Cachorro: " << buscado->nome << endl;
                cout << " \n Proprietario: " << buscado->dono << endl;
                cout << " \n Observacao: " << buscado->observacao << endl;
                cout << " \n Ultima visita: " << buscado->ultimaVisita << endl;
                cout << " \n Remedios: " << buscado->receita << endl;			

        }
};

//Metodo responsavel por buscar um unico animal com todos atributos
void Cadastro::buscarAnimal(string nome, string dono){

        Animal* buscado = buscaInterna(nome,dono);

        if(buscado == NULL){
                // Limpa a tela.
                std::cout << "\033c";			
                cout << "\n Animal nao encontrado" << endl;
                //cout << "\n PRECIONE ENTER PARA CONTINUAR" << endl;

        }
        else{
                // Limpa a tela.
                std::cout << "\033c";

                //Funcionalidade do metodo buscarAnimal
                cout << " \n Cachorro: " << buscado->nome << endl;
                cout << " \n Proprietario: " << buscado->dono << endl;
                cout << " \n Raca: " << buscado->raca << endl;
                cout << " \n Idade: " << buscado->idade << endl;
                cout << " \n Especie: " << buscado->especie << endl;										
        }
};

//Metodo responsavel por editar os atributos da classe Historico
void Cadastro::editarHistorico(string nome, string dono){
        Animal* alterado = buscaInterna(nome,dono);

        if(alterado == NULL){
                // Limpa a tela.
                std::cout << "\033c";

                //Mensagem de erro
                cout << "\n Animal nao encontrado" << endl;
        }
        else{
                // Limpa a tela.
                std::cout << "\033c";

                //Funcionalidade do metodo			
                cout << "\n Animal: " << nome << "  Proprietario: " << dono << endl;

                cout << "\n Obervacao: ";
                cin >> alterado->observacao;

                cout << "\n Ultima Visita: ";
                cin >> alterado->ultimaVisita;

                cout << "\n Remedios: ";
                cin >> alterado->receita;

                // Limpa a tela.
                std::cout << "\033c";

                cout << "\n Estorico editado com sucesso \n ";			
        }
};

//Metodo responsavel por editar as informacoes cadastradas de um determinado animal
void Cadastro::alteraAnimal(string nome, string dono){
    Animal* alterado = buscaInterna(nome,dono);

    if(alterado == NULL){
            // Limpa a tela.
            std::cout << "\033c";
            cout << "\n Animal nao encontrado" << endl;

    }

    //Coleta os dados do usuario e já altera na lista encadeada
    else{
        try {
                cout << "\n Insira o novo dono do animal: \n";
                cin >> alterado->dono;

                cout << "\n Insira o novo nome do animal: \n";
                cin >> alterado->nome;		

                cout << "\n Insira a nova raca do animal: \n";
                cin >> alterado->raca;

                cout << "\n Insira a nova especie do animal: \n";
                cin >> alterado->especie;

                cout << "\n Insira a nova idade do animal: \n";
                cin >> alterado->idade;// = ler_inteiro();

                // Limpa a tela.
                std::cout << "\033c";
                cout << "\n Dados alterado com sucesso " << endl;

        } catch(int err) {
                if (err == ARG_INVALIDO) 
                cout << "Idade inválida! Tente Novamente!" << endl;
                cout << "Somente Numeros Inteiros!" << endl;
        }		
    }
};
