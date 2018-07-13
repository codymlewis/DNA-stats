/**
 * Codon.cpp - DNA_sim
 * Author: Cody Lewis
 * Date: 2018-07-07
 * Last Modified: 2018-07-07
 * Description:
 *  A Class for A codon (a collection of three mRNA bases)
 */
#include <cstdlib>
#include "Codon.h"
namespace DNA_sim {
  // Constructors
  Codon::Codon() {
    bases.resize(3);
  }
  Codon::Codon(std::string input) {
    Codon();
    set_bases(input);
  }
  // Destructor
  Codon::~Codon() {}
  // Queries
  std::string Codon::get_bases() const {
    return bases;
  }
  // Mutators
  bool Codon::set_bases(std::string input) {
    bases = input;
    return true;
  }
  // Operator overloads
  std::istream& operator>>(std::istream& in, Codon& cod) {
    std::string input;
    in >> input;
    cod.set_bases(input);
    return in;
  }
  std::ostream& operator<<(std::ostream& out, const Codon& cod) {
    out << cod.get_bases();
    return out;
  }
  bool operator<(const Codon& lhs, const Codon& rhs) {
    return lhs.get_bases() < rhs.get_bases();
  }
}
