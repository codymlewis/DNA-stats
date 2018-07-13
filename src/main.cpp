/**
 * main.cpp - DNA_sim
 * Author: Cody Lewis
 * Description:
 *  The UI for the DNA_sim
 */
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "Strand.h"
void add_strand(std::vector<DNA_sim::Strand>& strands);
void view_stats(std::vector<DNA_sim::Strand>& strands);
void view_strands(std::vector<DNA_sim::Strand>& strands);
int main() {
  int input;
  std::vector<DNA_sim::Strand> strands;
  bool exit = false;
  while(!exit) {
    std::cout << "Add Strand(1), View strand stats(2), View strands(3), Exit(9)" << std::endl;
    std::cin >> input;
    switch(input) {
      case 1:
        add_strand(strands);
        break;
      case 2:
        view_stats(strands);
        break;
      case 3:
        view_strands(strands);
        break;
      case 9:
        exit = true;
        break;
      default:
        std::cout << "Invalid input, please try again." << std::endl;
    }
  }
  return 0;
}
void add_strand(std::vector<DNA_sim::Strand>& strands) {
  std::string input;
  std::cout << "Do you want to use a file (y/N) ";
  std::cin >> input;
  if(input == "y" || input == "Y") {
    std::cout << "Specify a file name: ";
    input.clear();
    std::cin >> input;
    std::ifstream in_data;
    in_data.open(input.c_str());
    input.clear();
    in_data >> input; // takes a single line
    strands.push_back(DNA_sim::Strand(input));
  } else {
    std::cout << "Input your strand: ";
    input.clear();
    std::cin >> input;
  }
  strands.push_back(DNA_sim::Strand(input));
}
void view_stats(std::vector<DNA_sim::Strand>& strands) {
  for(std::size_t i = 0; i < strands.size(); ++i) {
    std::cout << "Strand " << i << ":" << std::endl;
    std::cout << strands[i].stats() << std::endl;
  }
}
void view_strands(std::vector<DNA_sim::Strand>& strands) {
  for(std::size_t i = 0; i < strands.size(); ++i) {
    std::cout << "Strand " << i << ":" << std::endl;
    std::cout << strands[i] << std::endl;
  }
}
