// Copyright (c) 2017, Pei Xingxin
// Filename:  knn.h
// Description:
// Created:  11/06/2017 14:37:33
// Author:  michaelpei (Pei Xingxin), xingxinpei@gmail.com

#ifndef ALGORITHM_KNN_H_
#define ALGORITHM_KNN_H_

#include <map>
#include <vector>

namespace advanced_algorithm {

// input: file, process type (classfication, evaluation), k, to-value vector
// file content:  x1, x2, ... xn, y1
// output: output file or output vector
struct Vector {
  std::vector<double> X;
  double Y;
};

class KNN {
 public:
  double Calc(
      const std::string& file_name,
      int process_type,
      int number_of_neighbors,
      Vector* input_value);

 private:
  void ParseFile(const std::string& file_name);
  void CalcDistance();
  void FindNearestKNeighbors(int process_type, int number_of_neighbors);

  std::vector<Vector> sample_data_;
  std::multimap<double, Vector> distance_data_;
  Vector* input_value_;
};
}
#endif  // ALGORITHM_KNN_H_
