// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologıa
// Grado en Ingenier ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 9: Implementacion de un simulador de Maquinas de Turing
// Autor: Sergio Mora González
// Correo: alu0100918205@ull.edu.es
// Fecha: Semana del 13 al 17 de noviembre de 2023

#include "Alphabet.h"  
  
Alphabet::Alphabet(){
  /*for(int i = 0; i < word.size(); i++){
    if(word[i] != '&'){
      AddSymbol(word[i]);
    }
  }*/
}

Alphabet::~Alphabet(){

}

//Method that adds a new symbol to the alphabet
void Alphabet::AddSymbol(Symbol new_symbol){
  if(new_symbol != "&")
    GetSymbols().insert(new_symbol);
}

//Getter that returns the set<Symbol> attribute
std::set<Symbol>& Alphabet::GetSymbols(){
  return symbols_;
}

//Method to print the alphabet
std::ostream& Alphabet::PrintSymbols(std::ostream& output_stream) {
  output_stream << "{";
  bool first = true; // Para controlar si es el primer elemento
  for (const Symbol& symbol : GetSymbols()) {
    if (!first) {
      output_stream << ", ";
    }
    symbol.Write(output_stream);
    first = false;
  }
  output_stream << "}" << std::endl;
  return output_stream;
}

bool Alphabet::ContainsAll(Alphabet& other_alphabet) {
  return std::includes(GetSymbols().begin(), GetSymbols().end(), other_alphabet.GetSymbols().begin(), other_alphabet.GetSymbols().end());
}