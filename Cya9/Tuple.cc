// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologıa
// Grado en Ingenier ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 9: Implementacion de un simulador de Maquinas de Turing
// Autor: Sergio Mora González
// Correo: alu0100918205@ull.edu.es
// Fecha: Semana del 13 al 17 de noviembre de 2023

#include "Tuple.h"

Tuple::Tuple(Symbol symbol, std::string toMove, int nextState)
  : to_write_(symbol), to_move_(toMove), next_state_(nextState) {}


Symbol Tuple::GetToWrite() {
  return to_write_;
}

std::string Tuple::GetToMove() {
  return to_move_;
}

int Tuple::GetNextState() {
  return next_state_;
}

void Tuple::DisplayTuple(){
  GetToWrite().Write(std::cout);
  std::cout << " ";
  std::cout << GetToMove();
  std::cout << " ";
  std::cout << GetNextState();
}
