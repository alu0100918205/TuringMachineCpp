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
 * @file TuringMachine.h
 * @brief Defines the TuringMachine class for simulating Turing machines.
 *
 * This file contains the declaration of the TuringMachine class, which represents a
 * Turing machine capable of simulating computations on input words. It includes methods
 * for loading configurations, displaying machine status, performing simulation steps,
 * and simulating the machine until a halting state is reached.
 */

#pragma once

#include <list>
#include <fstream>
#include <sstream>
#include <set>
#include <iostream>

#include "Word.h"
#include "Alphabet.h"
#include "State.h"

/**
 * @class TuringMachine
 * @brief Represents a Turing machine for simulating computations on input words.
 */
class TuringMachine {
  private:
    Alphabet tape_alphabet_;          ///< The alphabet of symbols on the tape.
    int number_of_states_;            ///< The total number of states in the machine.
    int number_of_tuples_;            ///< The total number of transition tuples in the machine.
    int s_;                            ///< The start state of the machine.
    std::set<State> states_;           ///< Set of all states in the machine.
    std::list<Symbol> tape_;           ///< List representing the tape of symbols.
    std::list<Symbol>::iterator header_; ///< Iterator pointing to the current tape position.
    int current_state_;               ///< The current state of the machine.

  public:
    /**
     * @brief Constructs a Turing machine by loading configurations from a file.
     * @param file_path The path to the file containing machine configurations.
     * @throw std::runtime_error if the file cannot be opened or if there are errors
     *        in the configuration format.
     */
    TuringMachine(const std::string& file_path);

    /**
     * @brief Destructor for the TuringMachine class.
     */
    ~TuringMachine();

    /**
     * @brief Gets the tape alphabet of the Turing machine.
     * @return Reference to the tape alphabet.
     */
    Alphabet& GetTapeAlphabet();

    /**
     * @brief Gets the total number of states in the Turing machine.
     * @return The number of states.
     */
    int GetNumberOfStates();

    /**
     * @brief Gets the start state of the Turing machine.
     * @return The start state.
     */
    int GetStartState();

    /**
     * @brief Gets the set of all states in the Turing machine.
     * @return Reference to the set of states.
     */
    std::set<State>& GetTuringMachineStates();

    /**
     * @brief Displays the configuration of the Turing machine.
     */
    void DisplayTuringMachineConfiguration();

    /**
     * @brief Displays the states along with their final status.
     */
    void DisplayStatesWithFinalStatus();

    /**
     * @brief Displays the current status of the Turing machine.
     */
    void DisplayTuringMachineStatus();

    /**
     * @brief Gets the state with the specified ID.
     * @param state_id The ID of the state to retrieve.
     * @return Reference to the State object.
     * @throw std::runtime_error if the state with the given ID is not found.
     */
    State& GetStateByID(int state_id);

    /**
     * @brief Loads an input word onto the tape.
     * @param file_path The path to the file containing the input word.
     * @throw std::runtime_error if the file cannot be opened or if there are input word
     *        symbols not present in the tape alphabet.
     */
    void LoadTape(const std::string& file_path);

    /**
     * @brief Writes information about the Turing machine to a file.
     * @param file_path The path to the file to write information to.
     */
    void WriteInfoToFile(const std::string& file_path);

    /**
     * @brief Gets the current state of the Turing machine.
     * @return Reference to the current state.
     */
    int& GetCurrentState();

    /**
     * @brief Performs a single step in the simulation of the Turing machine.
     */
    void PerformStep();

    /**
     * @brief Simulates the Turing machine until a halting state is reached.
     */
    void Simulate();

  private:
    /**
     * @brief Moves the tape head in the specified direction.
     * @param direction The direction to move the tape head ('L', 'R', or 'S').
     */
    void MoveHeader(const std::string& direction);
};
