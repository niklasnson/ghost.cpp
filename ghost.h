#ifndef GHOST_H
#define GHOST_H

class Ghost 
{
  public: 
    struct buffert_t {
      std::string content;
      std::string title; 
      std::map<std::string, int> keywords; 
      size_t words; 
    };

    Ghost(std::string filename, Ghost::buffert_t &buffert){
      load_file(filename, buffert);
      buffert.words = words(buffert);
    }; 

    void load_file(std::string filename, Ghost::buffert_t &buffert);

    size_t words (Ghost::buffert_t &buffert); 
  private: 
}; 

#endif
