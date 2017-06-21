/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Historico.h
 * Author: junior
 *
 * Created on 19 de Junho de 2017, 23:35
 */

#ifndef HISTORICO_H
#define HISTORICO_H

#include <iostream>
#include <exception>
#include <cstdio>

using namespace std;

/**
 * Classe cujos objetos representam um dos atributos do objeto cadastrado.
 */
class Historico{
    //Interacao com classse Animal
    friend class Animal;

    //Interacao com classse Cadastro
    friend class Cadastro;			

    private:
        //Atributos
        string observacao;
        string ultimaVisita;
        string receita;
        
        //Metodos
        string getObservacao();
        string getUlitmaVisita();
        string getReceita();
    
    public:
        void setObservacao(string observacao);
        void setUlitmaVisita(string ulitmaVisita);
        void setReceita(string receita);
};

#endif /* HISTORICO_H */

