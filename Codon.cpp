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
    std::string base_string;
    for(std::size_t i = 0; i < bases.size(); ++i) {
      switch (bases[i]) {
        case Base::adenine:
          base_string += 'A';
          break;
        case Base::uracil:
          base_string += 'U';
          break;
        case Base::cytosine:
          base_string += 'C';
          break;
        case Base::guanine:
          base_string += 'G';
          break;
        default:
          base_string += '_';
      }
    }
    return base_string;
  }
  // Mutators
  bool Codon::set_bases(std::string input) {
    int j = 0;
    for(std::string::iterator it = input.begin(); it != input.end(); ++it) {
      switch (*it) {
        case 'A':
          bases[j] = Base::adenine;
          break;
        case 'U':
          bases[j] = Base::uracil;
          break;
        case 'C':
          bases[j] = Base::cytosine;
          break;
        case 'G':
          bases[j] = Base::guanine;
          break;
        default:
          bases[j] = Base::adenine;
      }
      j++;
    }
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
}
