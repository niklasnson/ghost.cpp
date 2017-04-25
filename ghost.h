#ifndef GHOST_H
#define GHOST_H

class Ghost 
{
  public: 
    struct buffert_t {
      std::string                 raw;
      std::string                 title; 
      std::string                 body; 
      std::map<std::string, int>  map_keywords; 
      std::map<std::string, int>  map_words;
    };

    Ghost(std::string filename, Ghost::buffert_t &buffert){
      load_file(filename, buffert);
      make_words(buffert);  
    }; 

    void        load_file (std::string filename, Ghost::buffert_t &buffert);

    std::string title (Ghost::buffert_t &buffert); 

    void        make_words (Ghost::buffert_t &buffert); 


  private:
}; 

#endif
