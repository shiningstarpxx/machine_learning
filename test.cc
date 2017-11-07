// Copyright (c) 2017, Pei Xingxin
// Filename:  test.cc
// Description:
// Created:  11/07/2017 18:42:13
// Author:  michaelpei (Pei Xingxin), xingxinpei@gmail.com

#include <stdio.h>

#include <string>

#include <gflags/gflags.h>

DEFINE_string(test_file, "test_file", "");

int main() {
  printf("%s\n", FLAGS_test_file.c_str());
  return 0;
}

