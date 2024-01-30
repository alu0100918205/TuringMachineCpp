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
 * @file Language.h
 * @brief Defines the Language class for representing a language.
 *
 * This file contains the declaration of the Language class, which represents a set
 * of words and includes methods for adding words, retrieving the set of words,
 * and printing the language to an output stream.
 */

#pragma once 

#include <set>
#include <string>
#include <iostream>

#include "Symbol.h"
#include "Word.h"

/**
 * @class Language
 * @brief Represents a language as a set of words.
 */
class Language {
  private:
    std::set<Word> words_; ///< The set of words in the language.

  public:
    /**
     * @brief Constructs a Language object with an initial set of words.
     * @param words The set of words to initialize the language.
     */
    Language(std::set<Word> words);

    /**
     * @brief Destructor for the Language class.
     */
    ~Language();

    /**
     * @brief Adds a word to the language.
     * @param word The word to add.
     */
    void AddWord(Word word);

    /**
     * @brief Gets the set of words in the language.
     * @return Reference to the set of words.
     */
    std::set<Word>& GetWords();

    /**
     * @brief Prints the language to an output stream.
     * @param output_stream The output stream to print to.
     * @return The output stream with the language words.
     */
    std::ostream& PrintLanguage(std::ostream& output_stream);
};

