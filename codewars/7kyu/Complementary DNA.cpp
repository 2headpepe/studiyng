#include <string>

std::string DNAStrand(const std::string& dna)
{
  std::string dna_new=dna;
  for(int i =0;i<dna.length();++i)
  {
    if(dna[i]=='A') dna_new[i]='T';
    if(dna[i]=='T') dna_new[i]='A';
    if(dna[i]=='C') dna_new[i]='G';
    if(dna[i]=='G') dna_new[i]='C';
  }
  return dna_new;
}
