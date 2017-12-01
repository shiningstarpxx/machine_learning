// Copyright (c) 2017, Pei Xingxin
// Filename:  id3_test.cc
// Description:
// Created:  11/24/2017 14:33:36
// Author:  michaelpei (Pei Xingxin), xingxinpei@gmail.com

#include "algorithm/ID3.h"

#include <gflags/gflags.h>
#include "gtest/gtest.h"

namespace algorithm {
class ID3Test : public ::testing::Test {
 protected:
  virtual void SetUp() override {
    // 色泽 (青绿1, 乌黑2, 浅白3
    // 根蒂 (蜷缩1, 稍卷2, 硬挺3
    // 敲声 (浊响1, 沉闷2, 清脆3
    // 纹理 (清晰1，稍糊2，模糊3
    // 脐部 (凹陷1, 稍凹2, 平坦3
    // 触感 (硬滑1, 软粘2,

    // 好瓜1
    {  // 1
      ID3Node node;
      node.property = {1, 1, 1, 1, 1, 1};
      node.category = 1;
      rows_.push_back(node);
    }
    {  // 2
      ID3Node node;
      node.property = {2, 1, 2, 1, 1, 1};
      node.category = 1;
      rows_.push_back(node);
    }
    {  // 3
      ID3Node node;
      node.property = {2, 1, 1, 1, 1, 1};
      node.category = 1;
      rows_.push_back(node);
    }
    {  // 4
      ID3Node node;
      node.property = {1, 1, 2, 1, 1, 1};
      node.category = 1;
      rows_.push_back(node);
    }
    {  // 5
      ID3Node node;
      node.property = {3, 1, 1, 1, 1, 1};
      node.category = 1;
      rows_.push_back(node);
    }
    {  // 6
      ID3Node node;
      node.property = {1, 2, 1, 1, 2, 2};
      node.category = 1;
      rows_.push_back(node);
    }
    {  // 7
      ID3Node node;
      node.property = {2, 2, 1, 2, 2, 2};
      node.category = 1;
      rows_.push_back(node);
    }
    {  // 8
      ID3Node node;
      node.property = {2, 2, 1, 1, 2, 1};
      node.category = 1;
      rows_.push_back(node);
    }
    // 差瓜2
    {  // 9
      ID3Node node;
      node.property = {2, 2, 2, 2, 2, 1};
      node.category = 2;
      rows_.push_back(node);
    }
    {  // 10
      ID3Node node;
      node.property = {1, 3, 3, 1, 3, 2};
      node.category = 2;
      rows_.push_back(node);
    }
    {  // 11
      ID3Node node;
      node.property = {3, 3, 3, 3, 3, 1};
      node.category = 2;
      rows_.push_back(node);
    }
    {  // 12
      ID3Node node;
      node.property = {3, 1, 1, 3, 3, 2};
      node.category = 2;
      rows_.push_back(node);
    }
    {  // 13
      ID3Node node;
      node.property = {1, 2, 1, 2, 1, 1};
      node.category = 2;
      rows_.push_back(node);
    }
    {  // 14
      ID3Node node;
      node.property = {3, 2, 2, 2, 1, 1};
      node.category = 2;
      rows_.push_back(node);
    }
    {  // 15
      ID3Node node;
      node.property = {2, 2, 1, 1, 2, 2};
      node.category = 2;
      rows_.push_back(node);
    }
    {  // 16
      ID3Node node;
      node.property = {3, 1, 1, 3, 3, 1};
      node.category = 2;
      rows_.push_back(node);
    }
    {  // 17
      ID3Node node;
      node.property = {1, 1, 2, 2, 2, 1};
      node.category = 2;
      rows_.push_back(node);
    }
  }

  virtual void TearDown() override {
  }

 protected:
  ID3 id3_;
  std::vector<ID3Node> rows_;
};

TEST_F(ID3Test, CalcOriginEntropy) {
  std::vector<int> origin_category;
  for (const auto& d : rows_) {
    origin_category.push_back(d.category);
  }
  printf("%f\n", id3_.CalcOriginEntropy(origin_category));
}

TEST_F(ID3Test, CalcSubCategoryEntropy) {
  for (size_t i = 0; i < 6; ++i) {
    printf("%f\n", 0.998 - id3_.CalcSubCategoryEntropy(rows_, i));
  }
}
}
