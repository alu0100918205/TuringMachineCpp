// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologıa
// Grado en Ingenier ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 9: Implementacion de un simulador de Maquinas de Turing
// Autor: Sergio Mora González
// Correo: alu0100918205@ull.edu.es
// Fecha: Semana del 13 al 17 de noviembre de 2023
#include "TuringMachine.h"

TuringMachine::TuringMachine(const std::string& file_path) {
  std::ifstream file(file_path);
  if (!file.is_open()) {
    throw std::runtime_error("Could not open the file");
  }

  //first line
  file >> number_of_states_;

  //second line
  file >> s_;
  current_state_ = GetStartState();
  
  //creates all the states
  for (int i = 0; i < number_of_states_; ++i) {
    State state(i);
    states_.insert(state);
  }

  //third line
  std::string final_states_line;
  std::getline(file, final_states_line);
  std::getline(file, final_states_line);
  std::istringstream final_states_stream(final_states_line);
  
  int final_state_id;
  while (final_states_stream >> final_state_id) {
    GetStateByID(final_state_id).SetFinal(true);
  }
    
  //fourth line
  file >> number_of_tuples_;

  GetTapeAlphabet().AddSymbol(Symbol("$"));
  //rest of lines for transitions
  std::string tuple_line;
  std::getline(file, tuple_line);
  int counter_of_tuples = 0;
  while(!file.eof()){
    std::getline(file, tuple_line);

    std::istringstream tuple_line_stream(tuple_line);
    int state_to_add;
    tuple_line_stream >> state_to_add;
    std::string symbol_to_read;
    tuple_line_stream >> symbol_to_read;
    std::string symbol_to_write;
    tuple_line_stream >> symbol_to_write;
    std::string movement;
    tuple_line_stream >> movement;
    if(movement != "L" && movement != "R" && movement != "S"){
      throw std::runtime_error("That is not a valid move for the tape");
    }
    int next_state;
    tuple_line_stream >> next_state;

    Tuple my_tuple(Symbol(symbol_to_write), movement, next_state);
    GetStateByID(state_to_add).AddTransition(Symbol(symbol_to_read), my_tuple);
    
    //Adding tape symbols to alphabet
    GetTapeAlphabet().AddSymbol(Symbol(symbol_to_write));
    GetTapeAlphabet().AddSymbol(Symbol(symbol_to_read));

    counter_of_tuples++;
  }
  std::cout << counter_of_tuples << std::endl;
  std::cout << number_of_tuples_ << std::endl;
  if(counter_of_tuples != number_of_tuples_){
    throw std::runtime_error("The number of tuples specified " + std::to_string(number_of_tuples_) + " does not match the actual number of tuples in the file " + std::to_string(counter_of_tuples));
  }
}

TuringMachine::~TuringMachine() {
}

Alphabet& TuringMachine::GetTapeAlphabet(){
  return tape_alphabet_;
}

int TuringMachine::GetNumberOfStates(){
  return number_of_states_;
}

int TuringMachine::GetStartState(){
  return s_;
}

std::set<State>& TuringMachine::GetTuringMachineStates(){
  return states_;
}


State& TuringMachine::GetStateByID(int state_id) {
  for (auto& state : states_) {
    if (state.GetStateID() == state_id) {
      return const_cast<State&>(state);
    }
  }
  throw std::runtime_error("State not found with ID: " + std::to_string(state_id));
}

void TuringMachine::DisplayStatesWithFinalStatus() {
  std::cout << "{";
  bool first = true;

  for (State state : states_) {
    if (!first) {
      std::cout << ", ";
    }
    std::cout << state.GetStateID();
    
    if (state.IsFinalState()) {
      std::cout << "(final)";
    }

    first = false;
  }

  std::cout << "}" << std::endl;
}


void TuringMachine::DisplayTuringMachineConfiguration(){
  std::cout << GetNumberOfStates() << std::endl;
  std::cout << GetStartState() << std::endl;

  for (State state : states_) {
    if(state.IsFinalState()){
      std::cout << state.GetStateID() << " ";
    }
  }
  std::cout << std::endl;

  std::cout << number_of_tuples_ << std::endl;

  for (State state : states_) {
    state.DisplayTransitions();
  }
}


void TuringMachine::WriteInfoToFile(const std::string& file_path) {
    // Abre el archivo para escritura.
    std::ofstream file(file_path);
    if (!file.is_open()) {
        std::cerr << "No se pudo abrir el archivo" << std::endl;
        return;
    }

    
    file.close();
}


void TuringMachine::MoveHeader(const std::string& direction) {
  switch (direction[0]) {
    case 'L':
      if (header_ == tape_.begin()) {
        tape_.push_front(Symbol("$"));
      }
      --header_;
      break;
    case 'R':
      if (std::next(header_) == tape_.end()) {
        tape_.push_back(Symbol("$"));
      }
      ++header_;
      break;
    case 'S':
      break;
    default:
      std::cout << "Unknown movement" << std::endl;
  }
  //std::cout << "header simbol is  " << header_->GetSymbol() << std::endl;

}


void TuringMachine::LoadTape(const std::string& file_path){
  std::ifstream file(file_path);
  if (!file.is_open()) {
    throw std::runtime_error("Could not open the file");
  }

  std::string word_to_load;
  file >> word_to_load;
  
  Word word_symbols(word_to_load);

  if(GetTapeAlphabet().ContainsAll(word_symbols.GetAlphabet())){
    for (Symbol symbol : word_symbols.GetWordSymbols()) {
      tape_.push_back(symbol);
    }

    header_ = tape_.begin();
  }
  else{
    throw std::runtime_error("there are input word symbols that are not content in the tape alphabet");
  }
}


void TuringMachine::DisplayTuringMachineStatus() {
  std::cout << "$";

  for (auto it = tape_.begin(); it != header_; ++it) {
    std::cout << *it;
  }

  std::cout << " q" << GetCurrentState() << " ";

  for (auto it = header_; it != tape_.end(); ++it) {
    std::cout << *it;
  }

  std::cout << "$" << std::endl;
}


int& TuringMachine::GetCurrentState(){
  return current_state_;
}

void TuringMachine::PerformStep() {
  Tuple tuple_to_process = GetStateByID(GetCurrentState()).GetTupleForSymbol(*header_);
  *header_ = tuple_to_process.GetToWrite();
  MoveHeader(tuple_to_process.GetToMove());
  GetCurrentState() = tuple_to_process.GetNextState();
}

void TuringMachine::Simulate() {
  DisplayTuringMachineStatus();
  while (GetStateByID(GetCurrentState()).GetTransitions().find(*header_) !=
         GetStateByID(GetCurrentState()).GetTransitions().end()) {
    PerformStep();
    DisplayTuringMachineStatus();
  }
  std::cout << std::endl << "String " << (GetStateByID(GetCurrentState()).IsFinalState()? "accepted" : "rejected") << std::endl;
}
