// Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
// Minnesota.

#include <iostream>
#include <vector>
#include "gtest/gtest.h"
#include "mia/command_line_processor.h"
#include "mia/image_editor_commands.h"
#include "imagetools/image_editor.h"

using image_tools::CommandLineProcessor;
using image_tools::ImageEditorCommand;

class CommandLineProcessorTest : public ::testing::Test {
  void SetUp() override {
  }

  void TearDown() override {
  }

 protected:
  CommandLineProcessor cmdLine;
};

TEST_F(CommandLineProcessorTest, test1) {
  std::vector<std::string> input = {"", "resources/flower.png",
                  "edgedetect", "resources/outputUnitTest1.png"};
  cmdLine.ProcessCommandLine(input.size(), input);
  std::vector<ImageEditorCommand*> cmdList = cmdLine.CommandList();

  EXPECT_EQ(cmdList[0]->name(), "Load");
  EXPECT_TRUE(cmdList[1]->name() != "Edge");
  //EXPECT_EQ(cmdList[2]->name(), "Save");
}

TEST_F(CommandLineProcessorTest, test2) {
  std::vector<std::string> input = {"", "resources/flower.png",
    "-threshold", "0.4", "-sharpen", "4.6", "resources/outputUnitTest2.png"};
  cmdLine.ProcessCommandLine(input.size(), input);
  std::vector<ImageEditorCommand*> cmdList = cmdLine.CommandList();

  EXPECT_EQ(cmdList[0]->name(), "Load");
  EXPECT_EQ(cmdList[1]->name(), "Threshold");
  EXPECT_EQ(cmdList[2]->name(), "Sharpen");
  EXPECT_EQ(cmdList[3]->name(), "Save");
}

TEST_F(CommandLineProcessorTest, test3) {
  std::vector<std::string> input = {"", "resources/flower.png",
              "-saturate", "3.0", "resources/outputUnitTest3.png"};
  cmdLine.ProcessCommandLine(input.size(), input);
  std::vector<ImageEditorCommand*> cmdList = cmdLine.CommandList();

  EXPECT_EQ(cmdList[0]->name(), "Load");
  EXPECT_EQ(cmdList[1]->name(), "Saturate");
  EXPECT_EQ(cmdList[2]->name(), "Save");
}

TEST_F(CommandLineProcessorTest, test4) {
  std::vector<std::string> input = {"", "resources/flower.jpeg",
                    "-red", "3.0", "resources/outputUnitTest4.png"};
  cmdLine.ProcessCommandLine(input.size(), input);

  EXPECT_EQ(cmdLine.isSucess(), 1);
}

TEST_F(CommandLineProcessorTest, test5) {
  std::vector<std::string> input = {"", "resources/flower.png",
                  "-green", "4.0", "resources/outputUnitTest5.png"};
  cmdLine.ProcessCommandLine(input.size(), input);
  std::vector<ImageEditorCommand*> cmdList = cmdLine.CommandList();

  EXPECT_EQ(cmdList[0]->name(), "Load");
  EXPECT_EQ(cmdList[1]->name(), "Channels");
  EXPECT_EQ(cmdList[2]->name(), "Save");
}

TEST_F(CommandLineProcessorTest, test6) {
  std::vector<std::string> input = {"", "resources/flower.png",
                    "-blue", "6.0", "resources/outputUnitTest6.png"};
  cmdLine.ProcessCommandLine(input.size(), input);
  std::vector<ImageEditorCommand*> cmdList = cmdLine.CommandList();

  EXPECT_EQ(cmdList[0]->name(), "Load");
  EXPECT_EQ(cmdList[1]->name(), "Channels");
  EXPECT_EQ(cmdList[2]->name(), "Save");
}

TEST_F(CommandLineProcessorTest, test7) {
  std::vector<std::string> input = {"", "resources/flower.png",
                  "-quantize", "2", "resources/outputUnitTest7.png"};
  cmdLine.ProcessCommandLine(input.size(), input);
  std::vector<ImageEditorCommand*> cmdList = cmdLine.CommandList();

  EXPECT_EQ(cmdList[0]->name(), "Load");
  EXPECT_EQ(cmdList[1]->name(), "Quantize");
  EXPECT_EQ(cmdList[2]->name(), "Save");
}

TEST_F(CommandLineProcessorTest, test8) {
  std::vector<std::string> input = {"", "resources/flower.png",
          "-motionblur-n-s", "3.0", "resources/outputUnitTest8.png"};
  cmdLine.ProcessCommandLine(input.size(), input);
  std::vector<ImageEditorCommand*> cmdList = cmdLine.CommandList();

  EXPECT_EQ(cmdList[0]->name(), "Load");
  EXPECT_EQ(cmdList[1]->name(), "MotionBlur");
  EXPECT_EQ(cmdList[2]->name(), "Save");
}

TEST_F(CommandLineProcessorTest, test9) {
  std::vector<std::string> input = {"", "resources/flower.png",
        "-motionblur-n-s", "11.0", "resources/outputUnitTest9.png"};
  cmdLine.ProcessCommandLine(input.size(), input);

  EXPECT_EQ(cmdLine.isSucess(), 1);
}

TEST_F(CommandLineProcessorTest, test10) {
  std::vector<std::string> input = {"", "resources/flower.png",
        "-motionblur-e-w", "-1.0", "resources/outputUnitTest10.png"};
  cmdLine.ProcessCommandLine(input.size(), input);
  std::vector<ImageEditorCommand*> cmdList = cmdLine.CommandList();

  EXPECT_EQ(cmdLine.isSucess(), 1);
}

TEST_F(CommandLineProcessorTest, test11) {
  std::vector<std::string> input = {"", "resources/flower.png",
        "-edgedetect", "5", "resources/outputUnitTest11.png"};
  cmdLine.ProcessCommandLine(input.size(), input);
  std::vector<ImageEditorCommand*> cmdList = cmdLine.CommandList();

  EXPECT_EQ(cmdList[0]->name(), "Load");
  EXPECT_TRUE(cmdList[1]->name() == "Edge");
  EXPECT_EQ(cmdList[2]->name(), "Save");
}
