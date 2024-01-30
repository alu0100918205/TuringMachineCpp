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

#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "Symbol.h"

/**
 * @class Alphabet
 * @brief Represents an alphabet of symbols.
 */
class Alphabet {
  private:
    std::set<Symbol> symbols_; ///< The set of symbols in the alphabet.

  public:
    /**
     * @brief Constructs an empty alphabet.
     */
    Alphabet();

    /**
     * @brief Destructor for Alphabet.
     */
    ~Alphabet();

    /**
     * @brief Adds a symbol to the alphabet.
     * @param symbol The symbol to add.
     */
    void AddSymbol(Symbol);

    /**
     * @brief Gets the set of symbols in the alphabet.
     * @return The set of symbols.
     */
    std::set<Symbol>& GetSymbols();

    /**
     * @brief Prints the symbols in the alphabet to an output stream.
     * @param output_stream The output stream to print to.
     * @return The output stream with the alphabet symbols.
     */
    std::ostream& PrintSymbols(std::ostream& output_stream);

    /**
    * @brief Checks if all symbols of another alphabet are contained.
    * @param other_alphabet The other alphabet to check.
    * @return True if all symbols are contained, false otherwise.
    *
    * This method checks whether all symbols of the specified @p other_alphabet are
    * contained in the current alphabet. It utilizes std::includes from the C++ Standard
    * Library, which determines if all elements of one range are present in another range.
    *
    * @note This method assumes that the Alphabet class contains a set of symbols.
    *
    * @param other_alphabet The alphabet to check for containment.
    * @return True if all symbols of the specified alphabet are contained, false otherwise.
    */
    bool ContainsAll(Alphabet& other_alphabet);

};
