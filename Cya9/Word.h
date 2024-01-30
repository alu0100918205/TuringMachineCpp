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
#include <iostream>
#include <fstream>
#include <vector>
#include <set>

#include "Alphabet.h"
#include "Symbol.h"

class Language;

/**
 * @class Word
 * @brief Represents a word composed of symbols from an alphabet.
 */
class Word{
  private:
    std::string original_word_; ///< The original word string.
    mutable std::vector<Symbol> word_by_symbols_; ///< Vector of symbols composing the word.
    Alphabet alphabet_; ///< The alphabet to which the word belongs.
    int word_size_; ///< The size of the word.

  public:
    /**
     * @brief Constructs a word from a given string.
     * @param new_word The string to construct the word from (default is an empty word).
     */
    Word(std::string new_word = "&");

    /**
     * @brief Destructor for Word.
     */
    ~Word();

    /**
     * @brief Gets the original word string.
     * @return The original word string.
     */
    std::string GetOriginalWord();

    /**
     * @brief Gets the original word string (const version).
     * @return The original word string.
     */
    std::string GetOriginalWord() const;

    /**
     * @brief Gets the vector of symbols composing the word.
     * @return The vector of symbols.
     */
    std::vector<Symbol>& GetWordSymbols();

    /**
     * @brief Gets the vector of symbols composing the word (const version).
     * @return The vector of symbols.
     */
    std::vector<Symbol>& GetWordSymbols() const;

    /**
     * @brief Gets the alphabet to which the word belongs.
     * @return The alphabet.
     */
    Alphabet& GetAlphabet();//opcodoe 1

    /**
     * @brief Gets the size of the word.
     * @return The size of the word.
     */
    int GetWordSize();//opcodoe 2

    /**
     * @brief Gets the size of the word (const version).
     * @return The size of the word.
     */
    int GetWordSize() const;

    /**
     * @brief Creates and returns the reverse of the word.
     * @return The reversed word.
     */
    Word WordReverse();//opcodoe 3

    /**
     * @brief Gets the set of prefixes for the word.
     * @return The set of prefixes.
     */
    Language GetPrefixes();//opcodoe 4

    /**
     * @brief Gets the set of suffixes for the word.
     * @return The set of suffixes.
     */
    Language GetSufixes();//opcodoe 5

    /**
     * @brief Writes the word to an output stream.
     * @param output_stream The output stream to write to.
     * @return The output stream with the word.
     */
    std::ostream& Write(std::ostream&);

    /**
     * @brief Writes the word to an output stream (const version).
     * @param output_stream The output stream to write to.
     * @return The output stream with the word.
     */
    std::ostream& Write(std::ostream&) const;

    /**
     * @brief Compares two words based on their sizes for sorting.
     * @param other The word to compare with.
     * @return True if the current word's size is less than the other word's size.
     */
    bool operator<(const Word& other) const;

  private:
    /**
     * @brief Builds the word by breaking down the input string into symbols.
     * @param word The input string to build the word from.
     */
    void BuildWord(std::string);

    /**
     * @brief Builds the alphabet for the word based on its symbols.
     */
    void BuildAlphabet();
};
