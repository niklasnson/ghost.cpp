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
size_t
Ghost::words (Ghost::buffert_t &buffert) 
{ 
  size_t words = 0; 
  for (size_t i = 0; i < buffert.content.length(); ++i) 
  {
    if (buffert.content[i]==' ' && buffert.content[i+1] !=0) 
      ++words; 
  }
  return words; 
}

std::string 
Ghost::title (Ghost::buffert_t &buffert) 
{
  return "hello"; 
}

int 
main (int argc, char* argv[])
{
  if (argc < 2) 
  {
    std::cerr << "Usage: " << argv[0] << " filename " << std::endl; 
    return 1; 
  }
  Ghost::buffert_t buffert; 
  Ghost ghost(argv[1], buffert);
  
  std::cout << buffert.content << std::endl; 
  std::cout << buffert.words << std::endl;  
  return 0; 
}
