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

#include <string>
#include <fstream>
#include <iostream>

/**
 * @class Symbol
 * @brief Represents a symbol used in finite automata.
 */
class Symbol {
  private:
    std::string symbol_; ///< The symbol's value.

  public:
    /**
     * @brief Constructs a symbol with the given value.
     * @param value The value of the symbol.
     */
    Symbol(std::string value);

    /**
     * @brief Default constructor for Symbol.
     */
    Symbol();

    /**
     * @brief Destructor for Symbol.
     */
    ~Symbol();

    /**
     * @brief Gets the symbol's value.
     * @return The symbol's value.
     */
    std::string GetSymbol();

    /**
     * @brief Gets the symbol's value (const version).
     * @return The symbol's value.
     */
    std::string GetSymbol() const;

    /**
     * @brief Sets the symbol's value.
     * @param value The value to set.
     */
    void SetSymbol(std::string value);

    /**
     * @brief Writes the symbol's value to an output stream.
     * @param output_stream The output stream to write to.
     * @return The output stream with the symbol's value.
     */
    std::ostream& Write(std::ostream& output_stream);

    /**
     * @brief Writes the symbol's value to an output stream (const version).
     * @param output_stream The output stream to write to.
     * @return The output stream with the symbol's value.
     */
    std::ostream& Write(std::ostream& output_stream) const;

    /**
     * @brief Compares two symbols based on their values for sorting.
     * @param other The symbol to compare with.
     * @return True if the current symbol's value is less than the other symbol's value.
     */
    bool operator<(const Symbol& other) const;

    /**
     * @brief Compares two symbols based on their values for inequality.
     * @param other The symbol to compare with.
     * @return True if the current symbol's value is not equal to the other symbol's value.
     */
    bool operator!=(const Symbol& other) const;

    /**
     * @brief Compares a symbol to a string based on their values for inequality.
     * @param value The string to compare with the symbol's value.
     * @return True if the symbol's value is not equal to the provided string.
     */
    bool operator!=(const std::string& value) const;

    friend std::ostream& operator<<(std::ostream& os, const Symbol& symbol);
  
};
