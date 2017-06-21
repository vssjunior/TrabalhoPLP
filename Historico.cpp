/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Historico.cpp
 * Author: junior
 * 
 * Created on 19 de Junho de 2017, 23:
 */

#include "Historico.h"

Historico::setObservacao(string observacao){
    this->observacao = observacao;
}

Historico::setReceita(string receita){
    this->receita = receita;
}

Historico::setUlitmaVisita(string ulitmaVisita){
    this->ultimaVisita = ultimaVisita;
}

Historico::getObservacao(){
    return Historico::observacao;
}

Historico::getReceita(){
    return Historico::receita;
}

Historico::getUlitmaVisita(){
    return Historico::ultimaVisita;
}