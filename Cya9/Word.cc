// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologıa
// Grado en Ingenier ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 9: Implementacion de un simulador de Maquinas de Turing
// Autor: Sergio Mora González
// Correo: alu0100918205@ull.edu.es
// Fecha: Semana del 13 al 17 de noviembre de 2023


#include "Word.h"
#include "Language.h"

//COnstructor that initializes all class attributes
Word::Word(std::string new_word) : original_word_(new_word) {
  BuildWord(new_word);
  BuildAlphabet();
  word_size_ = (new_word == "&" ? 0 : GetWordSymbols().size());
}

Word::~Word(){

}

//Method called in the constructor to build the vector<Symbol> attribute
void Word::BuildWord(std::string word){
  for (char c : word) {
    std::string charAsString(1, c); 
    GetWordSymbols().push_back(Symbol(charAsString));
  }
}

//Method to build a new alphabet based on the symbols of the word
void Word::BuildAlphabet(){
  for (const Symbol& symbol : GetWordSymbols()) {
    GetAlphabet().AddSymbol(symbol);
  }
}

//Getter for the original input string in constructor
std::string Word::GetOriginalWord(){
  return original_word_;
}

std::string Word::GetOriginalWord() const{
  return original_word_;
}

//Getter that returns the alphabet attribute
Alphabet& Word::GetAlphabet(){
  return alphabet_;
}

//Getter that returns the vector<Symbol> attribute
std::vector<Symbol>& Word::GetWordSymbols(){
  return word_by_symbols_;
}

std::vector<Symbol>& Word::GetWordSymbols() const{
  return word_by_symbols_;
}

//Getter that returns the word_size_ attribute
int Word::GetWordSize(){
  return word_size_;
}
  
int Word::GetWordSize() const{
  return word_size_;
}

//Method to get the reverse word of a word by getting the symbols of the vector backwards
Word Word::WordReverse(){
  std::string reverse_word = "";
  for (int i = GetWordSymbols().size() - 1; i >= 0; --i) {
    reverse_word += GetWordSymbols()[i].GetSymbol();
  }
  return Word(reverse_word);
}

//Method that returns a set<Word> that will be the prefixes of a word to use it on a Language constructor
Language Word::GetPrefixes(){
  std::set<Word> prefixes_set;
  prefixes_set.insert(Word("&"));
  for (int i = 0; i < GetWordSize(); ++i) {
    std::string new_prefix = "";
    for (int j = 0; j <= i; ++j) {
      new_prefix += GetWordSymbols()[j].GetSymbol();
    }
    prefixes_set.insert(Word(new_prefix));
  }
  return Language(prefixes_set);
}

//Method that returns a set<Word> that will be the sufixes of a word to use it on a Language constructor
Language Word::GetSufixes(){
  std::set<Word> sufixes_set;
  sufixes_set.insert(Word("&"));
  for (int i = 0; i < GetWordSize(); ++i) {
    std::string new_sufix = "";
    for (int j = i; j < GetWordSize(); ++j) {
      new_sufix += GetWordSymbols()[j].GetSymbol();
    }
    sufixes_set.insert(Word(new_sufix));
  }
  return Language(sufixes_set);
}

//Method to print a word by symbols
std::ostream& Word::Write(std::ostream& output_stream){
  for (const Symbol& symbol : word_by_symbols_) {
    output_stream << symbol.GetSymbol();
  }
  output_stream << std::endl;
  return output_stream;
}

std::ostream& Word::Write(std::ostream& output_stream) const{
  for (const Symbol& symbol : word_by_symbols_) {
    output_stream << symbol.GetSymbol();
  }
  return output_stream;
}

//Overload of < operator to compare words by size so the Language can sort the words
bool Word::operator<(const Word& other) const {
    return GetWordSize() < other.GetWordSize();
}
