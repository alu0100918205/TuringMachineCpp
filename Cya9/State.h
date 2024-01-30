// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologıa
// Grado en Ingenier ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 9: Implementacion de un simulador de Maquinas de Turing
// Autor: Sergio Mora González
// Correo: alu0100918205@ull.edu.es
// Fecha: Semana del 13 al 17 de noviembre de 2023
#pragma once

#include <map>
#include <iostream>

#include "Symbol.h"
#include "Tuple.h"

class State {
  private:
    int state_id_;
    bool final_;
    std::map<Symbol, Tuple> transitions_;

  public:
    State(int id, bool is_final = false);

    void AddTransition(Symbol symbol, Tuple destination_state);

    int GetStateID();
    int GetStateID() const;

    void SetFinal(bool);

    bool IsFinalState();

    std::map<Symbol, Tuple>& GetTransitions();

    void DisplayTransitions();
    void DisplayFormatedTransitions();
    Tuple& GetTupleForSymbol(const Symbol& symbol);


    bool operator<(State& other);
    bool operator<(const State& other) const;

};
