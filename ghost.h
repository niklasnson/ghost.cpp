#ifndef GHOST_H
#define GHOST_H

class Ghost 
{
  public: 
    struct buffert_t {
      std::string content;
      std::string title; 
      std::map<std::string, int> keywords; 
      int size; 
    };
    Ghost(){}; 
    void load_file(std::string filename, Ghost::buffert_t &buffert);

  private: 
}; 

#endif
