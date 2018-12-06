// Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
// Minnesota.
#include <math.h>
#include <iostream>
#include "gtest/gtest.h"
#include "imagetools/image_editor.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/color_data.h"
#include "mia/command_line_processor.h"

using image_tools::ImageEditor;
using image_tools::PixelBuffer;
using image_tools::ColorData;
using image_tools::CommandLineProcessor;

class ToolsRegressionTest : public ::testing::Test {
  void SetUp() override {
    buffer_ = new PixelBuffer(400, 400, ColorData(1, 1, 1));
    png_ = new PixelBuffer("resources/flower.png");
  }

  void TearDown() override {
    delete buffer_;
    delete png_;
    buffer_ = NULL;
    png_ = NULL;
  }

 protected:
  PixelBuffer* buffer_;
  PixelBuffer* png_;
};

TEST_F(ToolsRegressionTest, test1) {
  ImageEditor* saveFile = new ImageEditor(buffer_);
  ColorData color(1.0, 0.0, 0.0);
  saveFile->StartStroke("Caligraphy Pen", color, 6.0, 0, 0);
  saveFile->AddToStroke(200, 300);
  saveFile->EndStroke(100, 100);
  saveFile->SaveToFile("resources/toolRegression1.png");

  ImageEditor* loadFile = new ImageEditor();
  loadFile->LoadFromFile("resources/toolRegression1.png");

  ImageEditor* expected = new ImageEditor(buffer_);
  expected->StartStroke("Caligraphy Pen", color, 6.0, 0, 0);
  expected->AddToStroke(200, 300);
  expected->EndStroke(100, 100);
  expected->SaveToFile("resources/expect.png");
  expected->LoadFromFile("resources/expect.png");

  EXPECT_EQ(*(loadFile->pixel_buffer()), *(expected->pixel_buffer()));

  delete saveFile;
  delete loadFile;
  delete expected;
  saveFile = NULL;
  loadFile = NULL;
  expected = NULL;
}

TEST_F(ToolsRegressionTest, test2) {
  ImageEditor* saveFile = new ImageEditor(png_);
  ColorData color(1.0, 0.0, 0.0);
  saveFile->StartStroke("Blur", color, 40.0, 0, 0);
  saveFile->AddToStroke(1000, 1000);
  saveFile->EndStroke(100, 100);
  saveFile->SaveToFile("resources/toolRegression2.png");

  ImageEditor* loadFile = new ImageEditor();
  loadFile->LoadFromFile("resources/toolRegression2.png");

  EXPECT_EQ(*(loadFile->pixel_buffer()), *(saveFile->pixel_buffer()));

  delete saveFile;
  delete loadFile;
  saveFile = NULL;
  loadFile = NULL;
}

TEST_F(ToolsRegressionTest, test3) {
  ImageEditor* saveFile = new ImageEditor(buffer_);
  ColorData color(1.0, 0.0, 0.0);
  saveFile->StartStroke("Chalk", color, 6.0, 0, 0);
  saveFile->AddToStroke(200, 300);
  saveFile->EndStroke(100, 100);
  saveFile->SaveToFile("resources/toolRegression3.png");

  ImageEditor* loadFile = new ImageEditor();
  loadFile->LoadFromFile("resources/toolRegression3.png");

  EXPECT_EQ(*(loadFile->pixel_buffer()), *(saveFile->pixel_buffer()));

  delete saveFile;
  delete loadFile;
  saveFile = NULL;
  loadFile = NULL;
}

TEST_F(ToolsRegressionTest, test4) {
  ImageEditor* saveFile = new ImageEditor(png_);
  ColorData color(1.0, 0.0, 0.0);
  saveFile->StartStroke("Eraser", color, 30.0, 0, 0);
  saveFile->AddToStroke(200, 300);
  saveFile->EndStroke(100, 100);
  saveFile->SaveToFile("resources/toolRegression4.png");

  ImageEditor* loadFile = new ImageEditor();
  loadFile->LoadFromFile("resources/toolRegression4.png");

  ImageEditor* expected = new ImageEditor(png_);
  expected->StartStroke("Eraser", color, 30.0, 0, 0);
  expected->AddToStroke(200, 300);
  expected->EndStroke(100, 100);
  expected->SaveToFile("resources/expect.png");
  expected->LoadFromFile("resources/expect.png");

  EXPECT_EQ(*(loadFile->pixel_buffer()), *(expected->pixel_buffer()));

  delete saveFile;
  delete loadFile;
  delete expected;
  saveFile = NULL;
  loadFile = NULL;
  expected = NULL;
}

TEST_F(ToolsRegressionTest, test5) {
  ImageEditor* saveFile = new ImageEditor(buffer_);
  ColorData color(1.0, 0.0, 0.0);
  saveFile->StartStroke("Highlighter", color, 6.0, 0, 0);
  saveFile->AddToStroke(200, 300);
  saveFile->EndStroke(100, 100);
  saveFile->SaveToFile("resources/toolRegression5.png");

  ImageEditor* loadFile = new ImageEditor();
  loadFile->LoadFromFile("resources/toolRegression5.png");

  EXPECT_EQ(*(loadFile->pixel_buffer()), *(saveFile->pixel_buffer()));

  delete saveFile;
  delete loadFile;
  saveFile = NULL;
  loadFile = NULL;
}

TEST_F(ToolsRegressionTest, test6) {
  ImageEditor* saveFile = new ImageEditor(buffer_);
  ColorData color(1.0, 0.0, 0.0);
  saveFile->StartStroke("Pen", color, 6.0, 0, 0);
  saveFile->AddToStroke(200, 300);
  saveFile->EndStroke(100, 100);
  saveFile->SaveToFile("resources/toolRegression6.png");

  ImageEditor* loadFile = new ImageEditor();
  loadFile->LoadFromFile("resources/toolRegression6.png");

  ImageEditor* expected = new ImageEditor(buffer_);
  expected->StartStroke("Pen", color, 6.0, 0, 0);
  expected->AddToStroke(200, 300);
  expected->EndStroke(100, 100);
  expected->SaveToFile("resources/expect.png");
  expected->LoadFromFile("resources/expect.png");

  EXPECT_EQ(*(loadFile->pixel_buffer()), *(expected->pixel_buffer()));

  delete saveFile;
  delete loadFile;
  delete expected;
  saveFile = NULL;
  loadFile = NULL;
  expected = NULL;
}

TEST_F(ToolsRegressionTest, test7) {
  ImageEditor* saveFile = new ImageEditor(buffer_);
  ColorData color(1.0, 0.0, 0.0);
  saveFile->StartStroke("Spray Can", color, 6.0, 0, 0);
  saveFile->AddToStroke(200, 300);
  saveFile->EndStroke(100, 100);
  saveFile->SaveToFile("resources/toolRegression7.png");

  ImageEditor* loadFile = new ImageEditor();
  loadFile->LoadFromFile("resources/toolRegression7.png");

  EXPECT_EQ(*(loadFile->pixel_buffer()), *(saveFile->pixel_buffer()));

  delete saveFile;
  delete loadFile;
  saveFile = NULL;
  loadFile = NULL;
}

TEST_F(ToolsRegressionTest, test8) {
  ImageEditor* saveFile = new ImageEditor(buffer_);
  ColorData color(1.0, 0.0, 0.0);
  saveFile->StartStroke("Stamp", color, 30.0, 0, 0);
  saveFile->AddToStroke(200, 300);
  saveFile->EndStroke(100, 100);
  saveFile->SaveToFile("resources/toolRegression8.png");

  ImageEditor* loadFile = new ImageEditor();
  loadFile->LoadFromFile("resources/toolRegression8.png");

  ImageEditor* expected = new ImageEditor(buffer_);
  expected->StartStroke("Stamp", color, 6.0, 0, 0);
  expected->AddToStroke(200, 300);
  expected->EndStroke(100, 100);
  expected->SaveToFile("resources/expect.png");
  expected->LoadFromFile("resources/expect.png");

  EXPECT_EQ(*(loadFile->pixel_buffer()), *(expected->pixel_buffer()));

  delete saveFile;
  delete loadFile;
  delete expected;
  saveFile = NULL;
  loadFile = NULL;
  expected = NULL;
}
