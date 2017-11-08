// Copyright (c) 2017, Pei Xingxin
// Filename:  knn.cc
// Description:
// Created:  11/06/2017 15:22:15
// Author:  michaelpei (Pei Xingxin), xingxinpei@gmail.com

#include "algorithm/knn.h"

#include <stdio.h>

#include <complex>

#include <gflags/gflags.h>
// #include "glog/logging.h"

namespace advanced_algorithm {

void KNN::CalcDistance() {
  if (input_value_ == nullptr) {
    printf("no input value\n");
    return;
  }

  for (const auto& data : sample_data_) {
    if (input_value_->X.size() != data.X.size()) {
      printf("invalid data format, X dimesion is not equal\n");
      return;
    }

    double sum = 0;
    for (int i = 0; i < input_value_->X.size(); ++i) {
      sum += std::pow(input_value_->X.at(i) - data.X.at(i), 2);
    }
    distance_data_.insert(std::make_pair(sum, data));
  }
}

void KNN::FindNearestKNeighbors(int process_type, int number_of_neighbors) {
  // TODO(michael): check not null of input_value_, better use glog
  // k-mean
  if (process_type == 1) {
    double sum = 0;
    int count = 0;
    for (auto it = distance_data_.begin();
         it != distance_data_.end() && count < number_of_neighbors;
         ++it, ++count) {
      sum += it->second.Y;
    }
    input_value_->Y = sum / number_of_neighbors;
  } else if (process_type == 2) { // classification
    std::map<double, int> classification;
    int count = 0;
    for (auto it = distance_data_.begin();
         it != distance_data_.end() && count < number_of_neighbors;
         ++it, ++count) {
      if (classification.find(it->second.Y) == classification.end()) {
        classification.insert(std::make_pair(it->second.Y, 1));
      } else {
        classification[it->second.Y]++;
      }
    }
    int max = 0;
    for (auto it = classification.begin(); it != classification.end(); ++it) {
      if (it->second > max) {
        input_value_->Y = it->first;
        max = it->second;
      }
    }
  }
}

double KNN::Calc(
    const std::string& file_name,
    int process_type,
    int number_of_neighbors,
    Vector* input_value) {
  // TODO(michael): check input_value
  ParseFile(file_name);
  CalcDistance();
  FindNearestKNeighbors(process_type, number_of_neighbors);
  return input_value_->Y;
}

}
