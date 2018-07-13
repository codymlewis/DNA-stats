/**
 * Strand.h - DNA_sim
 * Author: Cody Lewis
 * Date: 2018-07-13
 * Description:
 *  A class for a strand of DNA (A collection of codons)
 */
#ifndef STRAND_h
#define STRAND_h
#include <vector>
#include <iostream>
#include "Codon.h"
namespace DNA_sim {
  class Strand {
    private:
      std::vector<Codon> codons; // The Codon collection
    public:
      Strand();
      Strand(std::string input); // input constructor
      ~Strand(); // Destructor

      // Queries
      std::string stats() const;
      std::string get_strand() const;

      // Mutators
      bool set_strand(std::string input);
  };
  std::istream& operator>>(std::istream& in, Strand& str);
  std::ostream& operator<<(std::ostream& out, const Strand& str);
}
#endif /* ifndef STRANG_h */
