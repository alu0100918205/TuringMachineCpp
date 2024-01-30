// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologıa
// Grado en Ingenier ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 9: Implementacion de un simulador de Maquinas de Turing
// Autor: Sergio Mora González
// Correo: alu0100918205@ull.edu.es
// Fecha: Semana del 13 al 17 de noviembre de 2023

#include <fstream>
#include <iostream>

#include "Word.h"
#include "Alphabet.h"
#include "Language.h"
#include "TuringMachine.h"


void FaFormat();//Function that contains the format to build the FA
void Help();//Function that shows help and how the program works
void WrongInput();//Function to controll wrong inputs


int main(int argc, char* argv[]) {
  
  if (std::string(argv[1]) == "--help" && argc == 2) {
    Help(); 
    return 0;
  } 
  if (argc != 3) {
    WrongInput();
    return 1;
  }

  std::string tm_file = argv[1];
  TuringMachine TM(tm_file);
  TM.DisplayTuringMachineConfiguration();

  std::string word_file = argv[2];
  TM.LoadTape(word_file);
  TM.Simulate();

  return 0;
}


void WrongInput(){
  std::cout << 
  "**Wrong input, please execute the line \"./p09_TuringMachine --help\" to know how the program works**" 
  << std::endl;
}

void Help(){
  std::cout << "The program should be executed with the next line:" << std::endl;
  std::cout << "\"./p09_TuringMachine \'cyour_turing_machine_configuration.tm\' \'your_word_file.tape\' \" " << std::endl;
  std::cout << "Please, remember that in order to be properly executed, your_turing_machine_configuration.tm file must have the proper format." << std::endl;
  FaFormat();
  std::cout << "Please, remember that in order to be properly executed, your_word_file.tape file must have the following format:" << std::endl;
  std::cout << "yourwordwithoutspaces" << std::endl;
  std::cout << "..." << std::endl;
}

void FaFormat(){
  std::cout << "Turing Machine Configuration" << std::endl;
  std::cout << "============================" << std::endl;
  std::cout << "Line 1: Integer indicating the number of states in the machine." << std::endl;
  std::cout << "Line 2: Integer indicating the starting state." << std::endl;
  std::cout << "Line 3: Integers separated by spaces indicating the final or accepting states." << std::endl;
  std::cout << "Line 4: Integer indicating the number of tuples in the machine." << std::endl;
  std::cout << "Subsequent lines: One tuple per line. Elements of each tuple are separated by spaces (represented here graphically by the symbol space)." << std::endl;
  std::cout << "Tuple format:" << std::endl;
  std::cout << "• state: Integer (identifier) representing the current state." << std::endl;
  std::cout << "• input: Symbol from the tape alphabet being read from the tape." << std::endl;
  std::cout << "• write: Symbol from the tape alphabet to be written on the tape for the given state and input." << std::endl;
  std::cout << "• move: Movement to be performed by the tape read/write head:" << std::endl;
  std::cout << "  ◦ L: left" << std::endl;
  std::cout << "  ◦ R: right" << std::endl;
  std::cout << "  ◦ S: stop (do not move)" << std::endl;
  std::cout << "• nextstate: Integer (identifier) of the next state the machine transitions to." << std::endl;
  std::cout << "============================" << std::endl;
  std::cout << "5" << std::endl;
  std::cout << "0" << std::endl;
  std::cout << "3" << std::endl;
  std::cout << "11" << std::endl;
  std::cout << "0 $ $ S 3" << std::endl;
  std::cout << "0 Y Y R 4" << std::endl;
  std::cout << "0 a X R 1" << std::endl;
  std::cout << "1 Y Y R 1" << std::endl;
  std::cout << "1 a a R 1" << std::endl;
  std::cout << "1 b Y L 2" << std::endl;
  std::cout << "2 X X R 0" << std::endl;
  std::cout << "2 Y Y L 2" << std::endl;
  std::cout << "2 a a L 2" << std::endl;
  std::cout << "4 $ $ S 3" << std::endl;
  std::cout << "4 Y Y R 4" << std::endl;
}
