// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologıa
// Grado en Ingenier ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 9: Implementacion de un simulador de Maquinas de Turing
// Autor: Sergio Mora González
// Correo: alu0100918205@ull.edu.es
// Fecha: Semana del 13 al 17 de noviembre de 2023


#include "Language.h"

Language::Language(std::set<Word> words) : words_(words){

}

Language::~Language(){

}

//Getter that returns the set<Word> attribute of the class
std::set<Word>& Language::GetWords(){
    return words_;
}

//Method to print the language
std::ostream& Language::PrintLanguage(std::ostream& output_stream){
    output_stream << "{";
    bool first = true; // Para controlar si es el primer elemento
    for (const Word& word : GetWords()) {
        if (!first) {
            output_stream << ", ";
        }
        word.Write(output_stream);
        first = false;
    }
    output_stream << "}" << std::endl;
    return output_stream;
}


