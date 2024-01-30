// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologıa
// Grado en Ingenier ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 9: Implementacion de un simulador de Maquinas de Turing
// Autor: Sergio Mora González
// Correo: alu0100918205@ull.edu.es
// Fecha: Semana del 13 al 17 de noviembre de 2023
#include "State.h"

State::State(int id, bool is_final) : state_id_(id), final_(is_final){}

void State::AddTransition(Symbol input, Tuple next_state_id) {
  transitions_.insert(std::make_pair(input, next_state_id));
}


int State::GetStateID() {
  return state_id_;
}

int State::GetStateID() const {
  return state_id_;
}

void State::SetFinal(bool boolean){
  final_ = boolean;
}


bool State::IsFinalState() {
  return final_;
}


std::map<Symbol, Tuple>& State::GetTransitions() {
  return transitions_;
}

void State::DisplayTransitions() {
  for ( auto transition : transitions_) {
    std::cout << GetStateID();
    std::cout << " ";

    Symbol input = transition.first;
    Tuple tuple = transition.second;

    input.Write(std::cout);
    std::cout << " ";
    tuple.DisplayTuple();
    std::cout << "\n";
  }
}

void State::DisplayFormatedTransitions() {
  std::cout << "Transitions for State " << GetStateID();
  std::cout << ":\n";
  for ( auto transition : transitions_) {
    Symbol input = transition.first;
    Tuple tuple = transition.second;

    std::cout << "  Input: ";
    input.Write(std::cout);
    std::cout << ", Tuple: ";
    tuple.DisplayTuple();
    std::cout << "\n";
  }
  std::cout << "\n";
}

Tuple& State::GetTupleForSymbol(const Symbol& symbol) {
  auto it = transitions_.find(symbol);
  if (it != transitions_.end()) {
    return it->second;
  }
}


bool State::operator<(State& other) {
  return GetStateID() < other.GetStateID();
}

bool State::operator<(const State& other) const {
  return GetStateID() < other.GetStateID();
}