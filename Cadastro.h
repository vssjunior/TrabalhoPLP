/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cadastro.h
 * Author: junior
 *
 * Created on 19 de Junho de 2017, 23:32
 */

#ifndef CADASTRO_H
#define CADASTRO_H

#include <iostream>
#include <exception>
#include <cstdio>

using namespace std;

/*
 * Classe responsável pela gestão de cadastro dos dados a serem tratados.
 */
class Cadastro {
    
    //Interacao com classe menu
    friend class Menu;
    
public:
    Animal* primeiro;
    Animal* ultimo;
    int tamanho;
    MinhaExcecao minhaexcecao;
    Cadastro();
    void inserirAnimal(string nome, string raca, string dono, string especie, int idade);
    void removerAnimal(string nome, string dono);
    Animal* buscaInterna(string nome,string dono);
    void imprimeAnimaisCadastrados();
    void imprimeHistorico(string nome, string dono);
    void buscarAnimal(string nome, string dono);
    void editarHistorico(string nome, string dono);
    void alteraAnimal(string nome, string dono);
    virtual ~Cadastro();
};

#endif /* CADASTRO_H */

