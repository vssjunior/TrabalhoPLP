/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MinhaExcecao.h
 * Author: junior
 *
 * Created on 19 de Junho de 2017, 23:37
 */

#ifndef MINHAEXCECAO_H
#define MINHAEXCECAO_H

#define ARG_INVALIDO 1
#define TAM_MAX_STRING 80

#include <iostream>
#include <exception>
#include <cstdio>

using namespace std;

//Classe de tratamento de exceção com inteiros.
class MinhaExcecao{
	
    //Interacao com classe Menu e Cadastro
    friend class Menu;
    friend class Cadastro;

    int ler_inteiro();		
};

#endif /* MINHAEXCECAO_H */

