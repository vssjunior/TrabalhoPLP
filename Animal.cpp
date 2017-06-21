/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Animal.cpp
 * Author: junior
 * 
 * Created on 19 de Junho de 2017, 23:34
 */
#include "Animal.h"

Animal::Animal(string nome, string raca, string especie, string dono, int idade){
    this->nome = nome;
    this->raca = raca;
    this->especie = especie;
    this->dono = dono;
    this->idade = idade;
    proximo = NULL;
    anterior = NULL;
    //Super
    observacao = "Nao ha observacoes";
    ultimaVisita = "Nao foi cadastrada a ultima visita";
    receita = "Nao foi cadastrado medicamentos para este animal";
}
