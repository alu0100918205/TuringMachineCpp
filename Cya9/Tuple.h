// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologıa
// Grado en Ingenier ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 9: Implementacion de un simulador de Maquinas de Turing
// Autor: Sergio Mora González
// Correo: alu0100918205@ull.edu.es
// Fecha: Semana del 13 al 17 de noviembre de 2023

/**
 * @file Tuple.h
 * @brief Defines the Tuple class for representing a transition tuple.
 *
 * This file contains the declaration of the Tuple class, which represents a
 * transition tuple in a Turing machine. It includes methods for accessing the
 * symbol to write, the movement direction, the next state, and displaying the tuple.
 */

#pragma once
#include "Symbol.h"

#include <iostream>
#include <string>

/**
 * @class Tuple
 * @brief Represents a transition tuple in a Turing machine.
 */
class Tuple {
  private:
    Symbol to_write_;    ///< The symbol to write on the tape.
    std::string to_move_; ///< The movement direction of the tape head.
    int next_state_;      ///< The next state in the Turing machine.

  public:
    /**
     * @brief Constructs a Tuple object with the provided information.
     * @param symbol The symbol to write.
     * @param toMove The movement direction.
     * @param nextState The next state.
     */
    Tuple(Symbol symbol, std::string toMove, int nextState);

    /**
     * @brief Gets the symbol to write on the tape.
     * @return The symbol to write.
     */
    Symbol GetToWrite();

    /**
     * @brief Gets the movement direction of the tape head.
     * @return The movement direction.
     */
    std::string GetToMove();

    /**
     * @brief Gets the next state in the Turing machine.
     * @return The next state.
     */
    int GetNextState();

    /**
     * @brief Displays the transition tuple to the standard output.
     */
    void DisplayTuple();
};
