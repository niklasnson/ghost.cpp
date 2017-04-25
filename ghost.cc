#include <iostream>
#include <sstream>
#include <string> 
#include <fstream>
#include <map>
#include <vector>
#include "ghost.h"

// load a file into the buffert. 
void 
Ghost::load_file (std::string filename, Ghost::buffert_t &buffert) 
{
  std::ifstream ifs(filename);
  ifs.seekg(0, std::ios::end);
  buffert.raw.reserve(ifs.tellg());
  ifs.seekg(0, std::ios::beg);
  buffert.raw.assign((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
}

// count the words in the buffert. 
void
Ghost::make_words (Ghost::buffert_t &buffert) 
{ 
  // go over string, find substring, add substring to map_words 
  std::istringstream iss(buffert.raw); 
  std::string word; 
  while (iss >> word) {
    std::cout << word << std::endl; 
    //++buffert.map_words(word);
  }
}

std::string 
Ghost::title (Ghost::buffert_t &buffert) 
{
  std::cout << buffert.raw << std::endl;
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
  
  std::cout << buffert.raw << std::endl; 
  //std::cout << buffert.words << std::endl;  
  return 0; 
}
