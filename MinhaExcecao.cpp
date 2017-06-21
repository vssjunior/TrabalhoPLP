/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MinhaExcecao.cpp
 * Author: junior
 * 
 * Created on 19 de Junho de 2017, 23:37
 */

#include "MinhaExcecao.h"

int MinhaExcecao::ler_inteiro(){	
    char str[TAM_MAX_STRING];
    cin.getline(str, TAM_MAX_STRING);
    int num;
    if (sscanf(str, "%d", &num) != 1) {
        throw ARG_INVALIDO;
        cin.clear(); //Limpa a flag de erro quando há falha no parse do valor entrado
        cin.ignore(); //Limpa o buffer
    }
    return num;
        cin.clear(); //Limpa a flag de erro quando há falha no parse do valor entrado
        cin.ignore(); //Limpa o buffer		
}