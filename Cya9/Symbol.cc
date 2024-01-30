// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologıa
// Grado en Ingenier ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 9: Implementacion de un simulador de Maquinas de Turing
// Autor: Sergio Mora González
// Correo: alu0100918205@ull.edu.es
// Fecha: Semana del 13 al 17 de noviembre de 2023


#include "Symbol.h"

Symbol::Symbol(std::string new_symbol){
  symbol_ = new_symbol;
}

Symbol::Symbol(){
  symbol_ = "&";
}

Symbol::~Symbol(){

}

//Getter that returns the string attribute of the class
std::string Symbol::GetSymbol(){
  return symbol_;
}

std::string Symbol::GetSymbol() const{
  return symbol_;
}

//Setter to change the string attribute of the class
void Symbol::SetSymbol(std::string new_symbol){
  symbol_ = new_symbol;
}

//Method to print the symbol
std::ostream& Symbol::Write(std::ostream& output_stream){
  output_stream << GetSymbol();
  return output_stream;
}

std::ostream& Symbol::Write(std::ostream& output_stream) const {
  output_stream << GetSymbol();
  return output_stream;
}

//Overload of the < operator to compare symbols for the sets
bool Symbol::operator<(const Symbol& other) const {
  return symbol_ < other.symbol_;
}

//Overload of the != operator to compare diferent symbols
bool Symbol::operator!=(const Symbol& other) const {
  return symbol_ != other.symbol_;
}

//Overload of the != operator to compare a symbol and a string
bool Symbol::operator!=(const std::string& other) const {
  return symbol_ != other;
}

std::ostream& operator<<(std::ostream& os, const Symbol& symbol) {
  os << symbol.GetSymbol();  // Asumiendo que tienes un método GetSymbol()
  return os;
}