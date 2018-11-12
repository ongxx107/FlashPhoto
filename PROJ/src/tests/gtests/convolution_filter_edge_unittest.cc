// Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
// Minnesota.

#include <math.h>
#include <iostream>
#include "gtest/gtest.h"
#include "flashphoto/filter.h"
#include "flashphoto/convolution_filter_edge.h"
#include "flashphoto/float_matrix.h"

using image_tools::ConvolutionFilterEdge;
using image_tools::FloatMatrix;

class ConvolutionFilterEdgeTest : public ::testing::Test {
  void SetUp() override {}

  void TearDown() override {
    delete edge_;
    delete mat;
  }

 protected:
  ConvolutionFilterEdge* edge_ = new ConvolutionFilterEdge();
  FloatMatrix* mat = edge_->CreateKernel();

};

TEST_F(ConvolutionFilterEdgeTest, HasCorrectName) {
  EXPECT_EQ(edge_->name(), "Convolution Filter Edge");
}

TEST_F(ConvolutionFilterEdgeTest, HasCorrectValue) {
  EXPECT_EQ(mat->value(0, 0), -1);
  EXPECT_EQ(mat->value(0, 1), -1);
  EXPECT_EQ(mat->value(0, 2), -1);
  EXPECT_EQ(mat->value(1, 0), -1);
  EXPECT_EQ(mat->value(1, 1), 8);
  EXPECT_EQ(mat->value(1, 2), -1);
  EXPECT_EQ(mat->value(2, 0), -1);
  EXPECT_EQ(mat->value(2, 1), -1);
  EXPECT_EQ(mat->value(2, 2), -1);
}
