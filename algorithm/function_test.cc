// Copyright (c) 2017, Pei Xingxin
// Filename:  function_test.cc
// Description:
// Created:  11/30/2017 18:41:22
// Author:  michaelpei (Pei Xingxin), xingxinpei@gmail.com

#include <stdio.h>

#include <functional>

using DistanceFunction = float (*) (
    const float*,
    const float*,
    int32_t);

float Test(const float* a, const float* b, int32_t c) {
  return *a + *b + c;
}

int main() {
  float a = 1.0;
  float b = 2.0;
  DistanceFunction m = &Test;
  printf("%f\n", m(&a, &b, 3));
  std::function<float(const float*, const float*, int32_t)> n = &Test;
  printf("%f\n", n(&a, &b, 3));
  return 0;
}
