/**
 * Codon.h - DNA_sim
 * Author: Cody Lewis
 * Date: 2018-07-07
 * Last Modified: 2018-07-07
 * Description:
 *  A Class for A codon (a collection of three mRNA bases)
 */
#ifndef CODON_h
#define CODON_h
#include <string>
#include <vector>
#include <iostream>
namespace DNA_sim {
  class Codon {
    private:
      /* enum Base
       *  The invidual bases of mRNA
       */
      std::string bases; // 3 bases per codon
    public:
      Codon(); // Default constructor
      Codon(std::string input); // Input constructor
      ~Codon(); // Destructor

      // Queries
      std::string get_bases() const;

      // Mutators
      bool set_bases(std::string input);
  };
  // Operator Overloads
  std::istream& operator>>(std::istream& in, Codon& cod); // input
  std::ostream& operator<<(std::ostream& out, const Codon& cod); // output
  bool operator<(const Codon& lhs, const Codon& rhs);
}
#endif /* ifndef CODON_h */
