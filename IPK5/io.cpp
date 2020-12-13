#include "io.h"

#include <iostream>
#include <random>
#include <string>

std::vector<double> read_vector() {
  std::vector<double> result;
  try {
    for (std::string line; std::getline(std::cin, line);)
      result.push_back(std::stod(line));
  } catch (std::invalid_argument&) {
  }
  return result;
}

std::vector<double> uniform_distribution(int seed, int N, double min,
                                         double max) {
  std::mt19937_64 rng(seed);
  std::uniform_real_distribution<> dist(min, max);
  std::vector<double> result(N);
  for (double& x : result) x = dist(rng);
  return result;
}

std::vector<double> normal_distribution(int seed, int N, double avg,
                                        double std_dev) {
  std::mt19937_64 rng(seed);
  std::normal_distribution<> dist(avg, std_dev);
  std::vector<double> result(N);
  for (double& x : result) x = dist(rng);
  return result;
}

int random_seed() {
  std::random_device rng;
  return rng();
}

void print_vector(std::vector<double> printvector){
  std::string str;
  for (unsigned long int i=0; i<printvector.size(); i++){
    str+=std::to_string(printvector[i]) + ", ";
  }
  if (str.size()>0)
    str.resize(str.size()-3);
  std::cout << "Printing vector: [" << str << "]" << std::endl;
}
