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
  return -sum;
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

double ID3::CalcSubCategoryEntropy(
    const std::vector<ID3Node>& rows, int index) {
  // 第一层，先确定有几个分类
  std::map<int, int> classfication;
  for (const auto& d : rows) {
    if (index < d.property.size()) {
      int tmp = d.property[index];
      if (classfication.find(tmp) == classfication.end()) {
        classfication.insert(std::make_pair(tmp, 1));
      } else {
        classfication[tmp]++;
      }
    }
  }

  double sum = 0.0;
  for (auto it = classfication.begin(); it != classfication.end(); ++it) {
    std::map<int, int> category;
    for (const auto& d: rows) {

    }
  }
  return CalcClassfiEntropy(classfication, rows.size());
}

}  // namespace algorithm

