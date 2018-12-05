// Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
// Minnesota.

#include <math.h>
#include <iostream>
#include "gtest/gtest.h"
#include "imagetools/filter.h"
#include "imagetools/filter_channels.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/color_data.h"

using image_tools::FilterChannels;
using image_tools::PixelBuffer;
using image_tools::ColorData;

class FilterChannelsTest : public ::testing::Test {
  void SetUp() override {}

  void TearDown() override {
    delete chan1_;
    delete buf1_;
    delete chan2_;
    delete buf2_;
  }

 protected:
  FilterChannels* chan1_ = new FilterChannels(5.0, 6.0, 7.0);
  PixelBuffer* buf1_ = new PixelBuffer(11, 11, ColorData(1, 1, 2));

  FilterChannels* chan2_ = new FilterChannels(1.0, 2.0, 0.0);
  PixelBuffer* buf2_ = new PixelBuffer(11, 11, ColorData(1, 2, 1));

};

TEST_F(FilterChannelsTest, HasCorrectNames) {
  EXPECT_EQ(chan1_->name(), "Channels");
  EXPECT_EQ(chan2_->name(), "Channels");
}

TEST_F(FilterChannelsTest, HasCorrectValue1) {
  EXPECT_EQ(chan1_->CalculateFilteredPixel(buf1_, 0, 0).red(), 5.0);
  EXPECT_EQ(chan1_->CalculateFilteredPixel(buf1_, 0, 0).green(), 6.0);
  EXPECT_EQ(chan1_->CalculateFilteredPixel(buf1_, 0, 0).blue(), 14.0);
}

TEST_F(FilterChannelsTest, HasCorrectDimensionSize1) {
  EXPECT_EQ(buf1_->width(), 11);
  EXPECT_EQ(buf1_->height(), 11);
}

TEST_F(FilterChannelsTest, HasCorrectValue2) {
  EXPECT_EQ(chan2_->CalculateFilteredPixel(buf2_, 0, 0).red(), 1.0);
  EXPECT_EQ(chan2_->CalculateFilteredPixel(buf2_, 0, 0).green(), 4.0);
  EXPECT_EQ(chan2_->CalculateFilteredPixel(buf2_, 0, 0).blue(), 0.0);
}

TEST_F(FilterChannelsTest, HasCorrectDimensionSize2) {
  EXPECT_EQ(buf2_->width(), 11);
  EXPECT_EQ(buf2_->height(), 11);
}
