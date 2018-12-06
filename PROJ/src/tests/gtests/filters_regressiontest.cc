// Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
// Minnesota.
#include <math.h>
#include <iostream>
#include "gtest/gtest.h"
#include "imagetools/image_editor.h"
#include "imagetools/pixel_buffer.h"
#include "mia/command_line_processor.h"

using image_tools::ImageEditor;
using image_tools::PixelBuffer;
using image_tools::CommandLineProcessor;

class FiltersRegressionTest : public ::testing::Test {
  void SetUp() override {
    buffer_ = new PixelBuffer("resources/flower.png");
  }

  void TearDown() override {
    delete buffer_;
    buffer_ = NULL;
  }

 protected:
  PixelBuffer* buffer_;
};

TEST_F(FiltersRegressionTest, test1) {
  ImageEditor* saveFile = new ImageEditor(buffer_);
  saveFile->ApplyBlurFilter(2.0);
  saveFile->SaveToFile("resources/filterRegression1.png");

  ImageEditor* loadFile = new ImageEditor();
  loadFile->LoadFromFile("resources/filterRegression1.png");

  CommandLineProcessor cmdLine;
  std::vector<std::string> input = {"", "resources/flower.png",
                        "-blur", "2.0", "resources/expect.png"};
  cmdLine.ProcessCommandLine(input.size(), input);
  ImageEditor* expected = new ImageEditor();
  expected->LoadFromFile("resources/expect.png");

  EXPECT_EQ(*(loadFile->pixel_buffer()), *(expected->pixel_buffer()));

  delete saveFile;
  delete loadFile;
  saveFile = NULL;
  loadFile = NULL;
}

TEST_F(FiltersRegressionTest, test2) {
  ImageEditor* saveFile = new ImageEditor(buffer_);
  saveFile->ApplyEdgeDetectFilter();
  saveFile->SaveToFile("resources/filterRegression2.png");

  ImageEditor* loadFile = new ImageEditor();
  loadFile->LoadFromFile("resources/filterRegression2.png");

  // ImageEditor* expected = new ImageEditor(buffer_);
  // expected->ApplyEdgeDetectFilter();
  // expected->SaveToFile("resources/expect.png");
  // expected->LoadFromFile("resources/expect.png");
  CommandLineProcessor cmdLine;
  std::vector<std::string> input = {"", "resources/flower.png",
                        "-edgedetect", "resources/expect.png"};
  cmdLine.ProcessCommandLine(input.size(), input);
  ImageEditor* expected = new ImageEditor();
  expected->LoadFromFile("resources/expect.png");

  EXPECT_EQ(*(loadFile->pixel_buffer()), *(expected->pixel_buffer()));

  delete saveFile;
  delete loadFile;
  saveFile = NULL;
  loadFile = NULL;
}

TEST_F(FiltersRegressionTest, test3) {
  ImageEditor* saveFile = new ImageEditor(buffer_);
  saveFile->ApplySharpenFilter(3.4);
  saveFile->SaveToFile("resources/filterRegression3.png");

  ImageEditor* loadFile = new ImageEditor();
  loadFile->LoadFromFile("resources/filterRegression3.png");

  CommandLineProcessor cmdLine;
  std::vector<std::string> input = {"", "resources/flower.png",
                      "-sharpen", "3.4", "resources/expect.png"};
  cmdLine.ProcessCommandLine(input.size(), input);
  ImageEditor* expected = new ImageEditor();
  expected->LoadFromFile("resources/expect.png");

  EXPECT_EQ(*(loadFile->pixel_buffer()), *(expected->pixel_buffer()));

  delete saveFile;
  delete loadFile;
  saveFile = NULL;
  loadFile = NULL;
}

TEST_F(FiltersRegressionTest, test4) {
  ImageEditor* saveFile = new ImageEditor(buffer_);
  saveFile->ApplyChannelsFilter(4.0, 1.0, 1.0);
  saveFile->SaveToFile("resources/filterRegression4.png");

  ImageEditor* loadFile = new ImageEditor();
  loadFile->LoadFromFile("resources/filterRegression4.png");

  CommandLineProcessor cmdLine;
  std::vector<std::string> input = {"", "resources/flower.png",
                          "-red", "4.0", "resources/expect.png"};
  cmdLine.ProcessCommandLine(input.size(), input);
  ImageEditor* expected = new ImageEditor();
  expected->LoadFromFile("resources/expect.png");

  EXPECT_EQ(*(loadFile->pixel_buffer()), *(expected->pixel_buffer()));

  delete saveFile;
  delete loadFile;
  saveFile = NULL;
  loadFile = NULL;
}

TEST_F(FiltersRegressionTest, test5) {
  ImageEditor* saveFile = new ImageEditor(buffer_);
  saveFile->ApplyChannelsFilter(1.0, 5.0, 1.0);
  saveFile->SaveToFile("resources/filterRegression5.png");

  ImageEditor* loadFile = new ImageEditor();
  loadFile->LoadFromFile("resources/filterRegression5.png");

  CommandLineProcessor cmdLine;
  std::vector<std::string> input = {"", "resources/flower.png",
                        "-green", "5.0", "resources/expect.png"};
  cmdLine.ProcessCommandLine(input.size(), input);
  ImageEditor* expected = new ImageEditor();
  expected->LoadFromFile("resources/expect.png");

  EXPECT_EQ(*(loadFile->pixel_buffer()), *(expected->pixel_buffer()));

  delete saveFile;
  delete loadFile;
  saveFile = NULL;
  loadFile = NULL;
}

TEST_F(FiltersRegressionTest, test6) {
  ImageEditor* saveFile = new ImageEditor(buffer_);
  saveFile->ApplyChannelsFilter(1.0, 1.0, 7.0);
  saveFile->SaveToFile("resources/filterRegression6.png");

  ImageEditor* loadFile = new ImageEditor();
  loadFile->LoadFromFile("resources/filterRegression6.png");

  CommandLineProcessor cmdLine;
  std::vector<std::string> input = {"", "resources/flower.png",
                        "-blue", "7.0", "resources/expect.png"};
  cmdLine.ProcessCommandLine(input.size(), input);
  ImageEditor* expected = new ImageEditor();
  expected->LoadFromFile("resources/expect.png");

  EXPECT_EQ(*(loadFile->pixel_buffer()), *(expected->pixel_buffer()));

  delete saveFile;
  delete loadFile;
  saveFile = NULL;
  loadFile = NULL;
}

TEST_F(FiltersRegressionTest, test7) {
  ImageEditor* saveFile = new ImageEditor(buffer_);
  saveFile->ApplyQuantizeFilter(3);
  saveFile->SaveToFile("resources/filterRegression7.png");

  ImageEditor* loadFile = new ImageEditor();
  loadFile->LoadFromFile("resources/filterRegression7.png");

  ImageEditor* expected = new ImageEditor(buffer_);
  expected->ApplyQuantizeFilter(3);

  EXPECT_EQ(*(loadFile->pixel_buffer()), *(expected->pixel_buffer()));

  delete saveFile;
  delete loadFile;
  saveFile = NULL;
  loadFile = NULL;
}

TEST_F(FiltersRegressionTest, test8) {
  ImageEditor* saveFile = new ImageEditor(buffer_);
  saveFile->ApplySaturateFilter(3.1);
  saveFile->SaveToFile("resources/filterRegression8.png");

  ImageEditor* loadFile = new ImageEditor();
  loadFile->LoadFromFile("resources/filterRegression8.png");

  CommandLineProcessor cmdLine;
  std::vector<std::string> input = {"", "resources/flower.png",
                    "-saturate", "3.1", "resources/expect.png"};
  cmdLine.ProcessCommandLine(input.size(), input);
  ImageEditor* expected = new ImageEditor();
  expected->LoadFromFile("resources/expect.png");

  EXPECT_EQ(*(loadFile->pixel_buffer()), *(expected->pixel_buffer()));

  delete saveFile;
  delete loadFile;
  saveFile = NULL;
  loadFile = NULL;
}

TEST_F(FiltersRegressionTest, test9) {
  ImageEditor* saveFile = new ImageEditor(buffer_);
  saveFile->ApplyThresholdFilter(0.6);
  saveFile->SaveToFile("resources/filterRegression9.png");

  ImageEditor* loadFile = new ImageEditor();
  loadFile->LoadFromFile("resources/filterRegression9.png");

  ImageEditor* expected = new ImageEditor(buffer_);
  expected->ApplyThresholdFilter(0.6);

  EXPECT_EQ(*(loadFile->pixel_buffer()), *(expected->pixel_buffer()));

  delete saveFile;
  delete loadFile;
  saveFile = NULL;
  loadFile = NULL;
}

TEST_F(FiltersRegressionTest, test10) {
  ImageEditor* saveFile = new ImageEditor(buffer_);
  saveFile->ApplyMotionBlurFilter(2.0, "North/South");
  saveFile->SaveToFile("resources/filterRegression10.png");

  ImageEditor* loadFile = new ImageEditor();
  loadFile->LoadFromFile("resources/filterRegression10.png");

  CommandLineProcessor cmdLine;
  std::vector<std::string> input = {"", "resources/flower.png",
                "-motionblur-n-s", "2.0", "resources/expect.png"};
  cmdLine.ProcessCommandLine(input.size(), input);
  ImageEditor* expected = new ImageEditor();
  expected->LoadFromFile("resources/expect.png");

  EXPECT_EQ(*(loadFile->pixel_buffer()), *(expected->pixel_buffer()));

  delete saveFile;
  delete loadFile;
  saveFile = NULL;
  loadFile = NULL;
}

TEST_F(FiltersRegressionTest, test11) {
  ImageEditor* saveFile = new ImageEditor(buffer_);
  saveFile->ApplyMotionBlurFilter(4.0, "East/West");
  saveFile->SaveToFile("resources/filterRegression11.png");

  ImageEditor* loadFile = new ImageEditor();
  loadFile->LoadFromFile("resources/filterRegression11.png");

  CommandLineProcessor cmdLine;
  std::vector<std::string> input = {"", "resources/flower.png",
                "-motionblur-e-w", "4.0", "resources/expect.png"};
  cmdLine.ProcessCommandLine(input.size(), input);
  ImageEditor* expected = new ImageEditor();
  expected->LoadFromFile("resources/expect.png");

  EXPECT_EQ(*(loadFile->pixel_buffer()), *(expected->pixel_buffer()));

  delete saveFile;
  delete loadFile;
  saveFile = NULL;
  loadFile = NULL;
}

TEST_F(FiltersRegressionTest, test12) {
  ImageEditor* saveFile = new ImageEditor(buffer_);
  saveFile->ApplyMotionBlurFilter(3.3, "Northeast/Southwest");
  saveFile->SaveToFile("resources/filterRegression12.png");

  ImageEditor* loadFile = new ImageEditor();
  loadFile->LoadFromFile("resources/filterRegression12.png");

  CommandLineProcessor cmdLine;
  std::vector<std::string> input = {"", "resources/flower.png",
            "-motionblur-ne-sw", "3.3", "resources/expect.png"};
  cmdLine.ProcessCommandLine(input.size(), input);
  ImageEditor* expected = new ImageEditor();
  expected->LoadFromFile("resources/expect.png");

  EXPECT_EQ(*(loadFile->pixel_buffer()), *(expected->pixel_buffer()));

  delete saveFile;
  delete loadFile;
  saveFile = NULL;
  loadFile = NULL;
}

TEST_F(FiltersRegressionTest, test13) {
  ImageEditor* saveFile = new ImageEditor(buffer_);
  saveFile->ApplyMotionBlurFilter(1.3, "Northwest/Southeast");
  saveFile->SaveToFile("resources/filterRegression13.png");

  ImageEditor* loadFile = new ImageEditor();
  loadFile->LoadFromFile("resources/filterRegression13.png");

  CommandLineProcessor cmdLine;
  std::vector<std::string> input = {"", "resources/flower.png",
                    "-motionblur-nw-se", "1.3", "resources/expect.png"};
  cmdLine.ProcessCommandLine(input.size(), input);
  ImageEditor* expected = new ImageEditor();
  expected->LoadFromFile("resources/expect.png");

  EXPECT_EQ(*(loadFile->pixel_buffer()), *(expected->pixel_buffer()));

  delete saveFile;
  delete loadFile;
  saveFile = NULL;
  loadFile = NULL;
}
