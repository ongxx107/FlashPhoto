// Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
// Minnesota.

#include <math.h>
#include <iostream>
#include "gtest/gtest.h"
#include "imagetools/tool_pen.h"
#include "imagetools/float_matrix.h"

using image_tools::ToolPen;
using image_tools::FloatMatrix;

class ToolPenTest : public ::testing::Test {
  void SetUp() override {}

 protected:
  ToolPen pen_;
};

TEST_F(ToolPenTest, HasCorrectName) {
  EXPECT_EQ(pen_.name(), "Pen");
}

TEST_F(ToolPenTest, HasCorrectDimensionSize) {
  FloatMatrix* mat = pen_.CreateMask(2.0);
  EXPECT_EQ(mat->width(), 5);
  EXPECT_EQ(mat->height(), 5);
}
