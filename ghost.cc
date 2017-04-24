#include <iostream>
#include <string> 
#include <fstream>
#include <map>
#include "ghost.h"

// load a file into the buffert. 
void 
Ghost::load_file (std::string filename, Ghost::buffert_t &buffert) 
{
  std::ifstream ifs(filename);
  ifs.seekg(0, std::ios::end);
  buffert.content.reserve(ifs.tellg());
  ifs.seekg(0, std::ios::beg);
  buffert.content.assign((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
}

// count the words in the buffert. 
int
Ghost::words (Ghost::buffert_t &buffert) 
{ 
  int words = 0; 
  for (int i = 0; i < buffert.content.lenght(); ++i) 
  {
    if (buffert.content[i]==' ' && buffert.content[i+1] !=0) 
      ++words; 
  }
  return words; 
}


int 
main (int argc, char* argv[])
{
  if (argc < 2) 
  {
    std::cerr << "Usage: " << argv[0] << " filename " << std::endl; 
    return 1; 
  }
  Ghost ghost;
  Ghost::buffert_t buffert; 
  ghost.load_file(argv[1], buffert); 
  
  std::cout << buffert.content << std::endl; 
  
  return 0; 
}
