#include <cstdlib>
#include <map>
#include <sstream>
#include "Strand.h"
namespace DNA_sim {
  Strand::Strand() {}
  Strand::Strand(std::string input) {
    set_strand(input);
  }
  Strand::~Strand() {}
  std::string Strand::stats() const {
    std::map<Codon, int> codon_count;
    for(std::size_t i = 0; i < codons.size(); ++i) {
      if(codon_count.find(codons[i]) == codon_count.end()) {
        codon_count[codons[i]] = 1;
      } else {
        codon_count[codons[i]]++;
      }
    }
    std::string result_stats = "Codon:\tCount:\n";
    for(std::map<Codon, int>::iterator it = codon_count.begin(); it != codon_count.end(); ++it) {
      std::stringstream ss;
      ss << it->second;
      ss >> result_stats;
      result_stats = it->first.get_bases() + "\t" + result_stats;
      result_stats += "\n";
    }
    return result_stats;
  }
  std::string Strand::get_strand() const {
    std::string strand_str = "";
    for(std::size_t i = 0; i < codons.size(); ++i) {
      strand_str += codons[i].get_bases();
    }
    return strand_str;
  }
  bool Strand::set_strand(std::string input) {
    for(std::size_t i = 0; i < input.length(); i += 3) {
      codons.push_back(Codon(input.substr(i, 3)));
    }
    return true;
  }
  std::istream& operator>>(std::istream& in, Strand& str) {
    std::string input;
    in >> input;
    str.set_strand(input);
    return in;
  }
  std::ostream& operator<<(std::ostream& out, const Strand& str) {
    out << str.get_strand();
    return out;
  }
}
