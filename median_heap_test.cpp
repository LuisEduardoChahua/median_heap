#include <iostream>
#include <fstream>
#include "median_heap.cpp"

int main(int argc, char * argv[]){

  if (argc != 2) {
    std::cerr << "Bad number of parameters" << argc << std::endl;
    exit(1);
  }

  median_heap<int> h;
  std::ifstream input(argv[1]);
  unsigned long count = 0L;
  unsigned long aux;
  for (std::string line; std::getline(input, line); ) {
    aux = std::stoi(line);
    h.add(aux);
    std::cout << "read: " << line << "; median: " << h.get_median() << std::endl;
    count += h.get_median();
  }
  std::cout << count << std::endl;
  
  return 0;
}
