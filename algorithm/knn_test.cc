// Copyright (c) 2017, Pei Xingxin
// Filename:  knn_test.cc
// Description:
// Created:  11/08/2017 20:22:25
// Author:  michaelpei (Pei Xingxin), xingxinpei@gmail.com

#include "algorithm/knn.h"

#include <memory>

#include <gflags/gflags.h>
#include "gtest/gtest.h"

namespace algorithm {

// INPUT VALUE
// 100, 120, 140, 160, 180, 200, 220, 240, 260, 280
// INPUT SAMPLE DATA
// 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 10 (20500)
// 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 20 (14500)
// 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 30 (10500)
// 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 40 (8500)
// 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 50 (8500)
// 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 60 (10500)
// 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 70 (14500)
// 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 80 (20500)
// 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 90 (28500)
class KNNTest : public ::testing::Test {
 protected:
  virtual void SetUp() override {
    for (int i = 1; i < 10; ++i) {
      Vector t;
      t.Y = i * 10;
      for (int j = i * 10 + 100; j < i * 10 + 200; j += 10) {
        t.X.push_back(j);
      }
      sample_data_.push_back(std::move(t));
    }

    int j = 100;
    for (int i = 0; i < 10; ++i) {
      input_value_.X.push_back(j + i * 20);
    }
  }

  virtual void TearDown() override {
  }

 protected:
  KNN knn_;
  std::vector<Vector> sample_data_;
  Vector input_value_;
};

TEST_F(KNNTest, CalcDistanceTest) {
  knn_.input_value_ = &input_value_;
  knn_.sample_data_ = sample_data_;
  EXPECT_TRUE(knn_.distance_data_.empty());
  knn_.CalcDistance();
  EXPECT_FALSE(knn_.distance_data_.empty());
  for (auto it = knn_.distance_data_.begin(); it != knn_.distance_data_.end(); ++it) {
    printf("%f\n", it->first);
  }
}

TEST_F(KNNTest, FindNearestKNeighborsTest) {
  knn_.input_value_ = &input_value_;
  knn_.sample_data_ = sample_data_;
  EXPECT_TRUE(knn_.distance_data_.empty());
  knn_.CalcDistance();
  knn_.FindNearestKNeighbors(1, 1);
  EXPECT_EQ(40, input_value_.Y);
  knn_.FindNearestKNeighbors(1, 2);
  EXPECT_EQ(45, input_value_.Y);
  knn_.FindNearestKNeighbors(1, 3);
  EXPECT_EQ(40, input_value_.Y);
}
}

int main(int argc, char* argv[]) {
  ::google::InitGoogleLogging(argv[0]);
  ::google::ParseCommandLineFlags(&argc, &argv, true);
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
