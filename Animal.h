/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Animal.h
 * Author: junior
 *
 * Created on 19 de Junho de 2017, 23:34
 */

#ifndef ANIMAL_H
#define ANIMAL_H

//#include "Historico.h"
#include <iostream>
#include <exception>
#include <cstdio>

using namespace std;

/**
 * Classe que representa os animais que são cadastrados pelo sistema.
 */
class Animal : public Historico {

    //Interacao com classe cadastro
    friend class Cadastro;

    //Interacao com classse menu
    friend class Menu;

    //Somente atributos
    public:
    string nome,raca,especie,dono;
    int idade;		
    Animal* proximo;
    Animal* anterior;
    Animal(string nome, string raca, string especie,string dono, int idade);
    virtual ~Animal();
};

#endif /* ANIMAL_H */

