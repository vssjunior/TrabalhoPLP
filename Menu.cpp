/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.cpp
 * Author: junior
 * 
 * Created on 19 de Junho de 2017, 23:27
 */

#include "Menu.h"

//Classe que terá toda a interação com o usuário responsável
// responsavel pela exibição de menus, leitura e escrita de dados na tela.
// Nenhuma outra classe lê dados na entrada padrão ou escrever na saída padrão.
	
void Menu::interacaoUsuario(){
    //Variaveis locais
    int opcao = 0;
    int idade = 0;
    string nome, raca, dono, especie; 
    Cadastro cadastro;
    MinhaExcecao minhaexcecao;

    //Escopo do programa
    do {
    cout << "\n Bem Vindo ao software da Clinica Veterinaria \n";								
    cout << "\n 1 - Para cadastrar um novo animal \n";
    cout << "\n 2 - Para alterar dados de um animal cadastrado \n";
    cout << "\n 3 - Para remover um animal cadastrado \n";
    cout << "\n 4 - Buscar um animal no sistema \n";
    cout << "\n 5 - Exibir ficha tecnica de um animal cadastrado \n";
    cout << "\n 6 - Alterar a ficha tecnica de um animal cadastrado \n";				
    cout << "\n 7 - Exibir animais cadastrados \n";
    cout << "\n 8 - Sair \n";
    cout << "\n Para o bom desempenho do programa, utilize apenas os números \n";
    cout << " referentes as opções elencadas acima: \n";
    cout << "\n opcao: ";

        try{
            //Coleta de dados do usuario
            opcao = minhaexcecao.ler_inteiro();						
            if(opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4 || opcao == 5 || opcao == 6 || opcao == 7 || opcao == 8){

                //Funcionalidade das opcoes
                switch (opcao){
                    case 1:

                        cout << "\n Insira o dono do animal: \n";
                        cin >> dono;

                        cout << "\n Insira o nome do animal: \n";
                        cin >> nome;

                        cout << "\n Insira a raca do animal: \n";
                        cin >> raca;

                        cout << "\n Insira a especie(tipo_do_animal) do animal: \n";
                        cin >> especie;								

                        cout << "\n Insira a idade do animal: \n";
                        cin >> idade;// = minhaexcecao.ler_inteiro();

                        //Chama o metodo inserir da classe cadastro, para criar um novo animal
                        cadastro.inserirAnimal(nome, raca, dono, especie, idade);				

                        break;

                    case 2:

                        //Coleta de dados necessario para alterar os atribustos de um animal
                        cout << "\n Insira o antigo dono do animal: \n";
                        cin >> dono;

                        //Coleta de dados necessario para alterar os atributos de um animal				
                        cout << "\n Insira o nome do antigo animal: \n";
                        cin >> nome;

                        cadastro.alteraAnimal(nome,dono);

                        break;

                    case 3:

                        //Coleta de dados necessario para remocao
                        cout << "\n Insira o dono do animal: \n";
                        cin >> dono;

                        //Coleta de dados necessario para remocao
                        cout << "\n Insira o nome do animal: \n";
                        cin >> nome;

                        cadastro.removerAnimal(nome,dono);		

                        break;

                    case 4:
                        //Coleta de dados necessario para busca
                        cout << "\n Insira o dono do animal: \n";
                        cin >> dono;	

                        //Coleta de dados necessario para busca
                        cout << "\n Insira o nome do animal: \n";
                        cin >> nome;	

                        //Chamada do metodo buscar na classe cadastro
                        cadastro.buscarAnimal(nome,dono);					

                        break;

                    case 5:
                        //Coleta de dados necessario para exibir um historico
                        cout << "\n Insira o dono do animal: \n";
                        cin >> dono;	

                        //Coleta de dados necessario para exibir um historico
                        cout << "\n Insira o nome do animal: \n";
                        cin >> nome;	

                        //Chamada do metodo para exibir os atributos da classe Historico						
                        cadastro.imprimeHistorico(nome, dono);
                        break;

                    case 6:
                        //Coleta de dados necessario para editar um historico
                        cout << "\n Insira o dono do animal: \n";
                        cin >> dono;	

                        //Coleta de dados necessario para editar um historico
                        cout << "\n Insira o nome do animal: \n";
                        cin >> nome;	

                        //Chamada do metodo para editar os atributos da classe Historico					
                        cadastro.editarHistorico(nome, dono);

                        break;

                    case 7:	

                        //Chama o metodo que imprime o nome e o dono de todos os animais
                        cadastro.imprimeAnimaisCadastrados();

                        break;

                    default:

                        std::cout << "\033c"; // Limpa a tela.

                        cout << "\n Programa Finalizado Com sucesso! \n";
                        cout << "\n PRECIONE ENTER PARA FECHAR " << endl;								
                        break;
                }
            }else{

                std::cout << "\033c"; // Limpa a tela.

                cout << "\n Opcao invalida, tente novamente! " << endl;
                cout << "\n PRECIONE ENTER PARA CONTINUAR " << endl;
            }					
        }catch(int err) {
            if (err == ARG_INVALIDO){

                std::cout << "\033c"; // Limpa a tela.

                cout << "\n Argumento inválido! Somente Numeros Inteiros!" << endl;
                cout << "\n PRECIONE ENTER PARA CONTINUAR " << endl;

            }//Termino da condicional do bloco catch
        }//Termino do tratamento de exceção	

        cin.clear(); //Limpa a flag de erro quando há falha no parse do valor entrado
        cin.ignore(); //Limpa o buffer
    }while(opcao != 8);//Termino do while

}//Termino do metodo interacaoUsuario	
