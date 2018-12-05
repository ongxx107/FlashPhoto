// Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
// Minnesota.

#include <iostream>
#include "gtest/gtest.h"
#include "mia/command_line_processor.h"

using image_tools::CommandLineProcessor;

class CommandLineProcessorTest : public ::testing::Test {
  void SetUp() override {
    cmdLine = new ProcessCommandLine(3, "mia -sharpen 5.0 -edgedetect");
  }

  void TearDown() override {
    delete cmdLine;
  }

 protected:
  CommandLineProcessor *cmdLine;
};

TEST_F(CommandLineProcessorTest, test1) {

  image_tools::Tool* unknownTool = app_->GetToolByName("Unknown");
  EXPECT_FALSE(unknownTool);
}
