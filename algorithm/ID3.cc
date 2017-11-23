// Copyright (c) 2017, Pei Xingxin
// Filename:  ID3.cc
// Description:  
// Created:  11/23/2017 19:37:27
// Author:  michaelpei (Pei Xingxin), xingxinpei@gmail.com

#include "algorithm/ID3.h"

#include <math.h>

#include <map>
#include <utility>

namespace algorithm {

static double CalcClassfiEntropy(
    const std::map<int, int> classfi, double size) {
  double sum = 0.0;
  for (auto it = classfi.begin(); it != classfi.end(); ++it) {
    sum += it->second / size * log2(it->second / size);
  }
  return sum;
}

double ID3::CalcOriginEntropy(const std::vector<int>& result) {
  std::map<int, int> classfication;
  for (int d : result) {
    if (classfication.find(d) == classfication.end()) {
      classfication.insert(std::make_pair(d, 1));
    } else {
      classfication[d]++;
    }
  }
  return CalcClassfiEntropy(classfication, result.size());
}

}
