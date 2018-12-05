/**
 This file is part of the CSCI-3081W Project Support Code, which was developed
 at the University of Minnesota.

 This code is to be used for student coursework.  It is not an open source
 project.
 Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
 Minnesota.

 Original Author(s) of this File:
 Daniel Keefe, 2018, University of Minnesota

 Author(s) of Significant Updates/Modifications to the File:
 ...
 */
#include <sys/stat.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdio.h>
#include <iomanip>
#include <sstream>
#include <utility>
#include <assert.h>
#include <mingfx.h>
#include <cmath>
#include "mia/command_line_processor.h"

#include "imagetools/image_editor.h"

using std::cout;
using std::endl;

namespace image_tools {

CommandLineProcessor::CommandLineProcessor() {
  // image_editor_ = new ImageEditor();
}

CommandLineProcessor::~CommandLineProcessor() {
  // delete image_editor_;
}

ImageEditorCommand CommandLineProcessor::commandList(){
  return cmd;
}

ImageEditor CommandLineProcessor::imageEditor(){
  return image_editor_;
}

void CommandLineProcessor::ProcessCommandLine(int argc, char* argv[]) {

  image_editor_ = new ImageEditor();
  std::vector<std::string> str;
  str.clear();

  for (int i = 1; i < argc; i++) {
    str.push_back(std::string(argv[i]));
  }

  std::string subIn = str[0];
  const std::string ext(".png");

  if (subIn != ext && subIn.size() > ext.size() && subIn.substr(subIn.size() - ext.size()) == ".png") {
  }
  else {
    std::cerr << "Input file is not .png type" << '\n';
    DefaultMsg();
    return;
  }

  std::string subOut = str[str.size()-1];

  if (subOut != ext && subOut.size() > ext.size() && subOut.substr(subOut.size() - ext.size()) == ".png") {
  }
  else {
    std::cerr << "Output file is not .png type" << '\n';
    DefaultMsg();
    return;
  }

  // check if the input filename exists or not
  struct stat buffer;
  if (stat (argv[1], &buffer) == 0) {
  }
  else {
    std::cerr << "Input filename does not exist" << '\n';
    DefaultMsg();
    return;
  }

  // start loading the existing file
  try {
    cmd.push_back(new LoadCommand(image_editor_, subIn));
  }
  catch(...) {
    DefaultMsg();
    return;
  }

  for (unsigned i = 1; i < str.size(); i++) {

    if (str[i] == "-blur") {
      float radius = 0.0;
      try {
        radius = stof(str[i+1]);
      }
      catch (const std::invalid_argument& ia) {
          std::cerr << "Invalid argument: " << ia.what() << '\n';
          DefaultMsg();
          return;
      }

      if (radius >= 1.0 && radius <= 10.0) {
        cmd.push_back(new BlurFilterCommand(image_editor_, radius));
      }
      else {
        std::cerr << "Out of Parameter Bound" << '\n';
        DefaultMsg();
        return;
      }
    }
    else if (str[i] == "-edgedetect") {
      cmd.push_back(new EdgeFilterCommand(image_editor_));
    }
    else if (str[i] == "-sharpen") {
      float radius = 0.0;
      try {
        radius = stof(str[i+1]);
      }
      catch (const std::invalid_argument& ia) {
          std::cerr << "Invalid argument: " << ia.what() << '\n';
          DefaultMsg();
          return;
      }

      if (radius >= 1.0 && radius <= 10.0) {
        cmd.push_back(new SharpenFilterCommand(image_editor_, radius));
      }
      else {
        std::cerr << "Out of Parameter Bound" << '\n';
        DefaultMsg();
        return;
      }
    }
    else if (str[i] == "-red") {
      float red = 0.0;
      try {
        red = stof(str[i+1]);
      }
      catch (const std::invalid_argument& ia) {
          std::cerr << "Invalid argument: " << ia.what() << '\n';
          DefaultMsg();
          return;
      }

      if (red > 0.0 && red <= 10.0) {
        cmd.push_back(new ChannelsFilterCommand(image_editor_, red, 1.0, 1.0));
      }
      else {
        std::cerr << "Out of Parameter Bound" << '\n';
        DefaultMsg();
        return;
      }
    }
    else if (str[i] == "-green") {
      float green = 0.0;
      try {
        green = stof(str[i+1]);
      }
      catch (const std::invalid_argument& ia) {
          std::cerr << "Invalid argument: " << ia.what() << '\n';
          DefaultMsg();
          return;
      }

      if (green > 0.0 && green <= 10.0) {
        cmd.push_back(new ChannelsFilterCommand(image_editor_, 1.0, green, 1.0));
      }
      else {
        std::cerr << "Out of Parameter Bound" << '\n';
        DefaultMsg();
        return;
      }
    }
    else if (str[i] == "-blue") {
      float blue = 0.0;
      // blue = strtof(argv[i+1], 0);
      try {
        blue = stof(str[i+1]);
      }
      catch (const std::invalid_argument& ia) {
          std::cerr << "Invalid argument: " << ia.what() << '\n';
          DefaultMsg();
          return;
      }

      if (blue > 0.0 && blue <= 10.0) {
        cmd.push_back(new ChannelsFilterCommand(image_editor_, 1.0, 1.0, blue));
      }
      else {
        std::cerr << "Out of Parameter Bound" << '\n';
        DefaultMsg();
        return;
      }
    }
    else if (str[i] == "-quantize") {
      int bin = 0;
      try {
        bin = stoi(str[i+1]);
      }
      catch (const std::invalid_argument& ia) {
          std::cerr << "Invalid argument: " << ia.what() << '\n';
          DefaultMsg();
          return;
      }

      if (bin > 0 && bin <= 256) {
        cmd.push_back(new QuantizeFilterCommand(image_editor_, bin));
      }
      else {
        std::cerr << "Out of Parameter Bound" << '\n';
        DefaultMsg();
        return;
      }
    }
    else if (str[i] == "-saturate") {
      float scale = 0.0;
      try {
        scale = stof(str[i+1]);
      }
      catch (const std::invalid_argument& ia) {
          std::cerr << "Invalid argument: " << ia.what() << '\n';
          DefaultMsg();
          return;
      }

      if (scale > 0.0 && scale <= 10.0) {
        cmd.push_back(new SaturateFilterCommand(image_editor_, scale));
      }
      else {
        std::cerr << "Out of Parameter Bound" << '\n';
        DefaultMsg();
        return;
      }
    }
    else if (str[i] == "-threshold") {
      float value = 0.0;
      try {
        value = stof(str[i+1]);
      }
      catch (const std::invalid_argument& ia) {
          std::cerr << "Invalid argument: " << ia.what() << '\n';
          DefaultMsg();
          return;
      }

      if (value > 0.0 && value <= 1.0) {
        cmd.push_back(new ThresholdFilterCommand(image_editor_, value));
      }
      else {
        std::cerr << "Out of Parameter Bound" << '\n';
        DefaultMsg();
        return;
      }
    }
    else if (str[i] == "-motionblur-n-s") {
      float radius = 0.0;
      try {
        radius = stof(str[i+1]);
      }
      catch (const std::invalid_argument& ia) {
          std::cerr << "Invalid argument: " << ia.what() << '\n';
          DefaultMsg();
          return;
      }

      if (radius >= 1.0 && radius <= 10.0) {
        cmd.push_back(new MotionBlurFilterCommand(image_editor_, radius, "North/South"));
      }
      else {
        std::cerr << "Out of Parameter Bound" << '\n';
        DefaultMsg();
        return;
      }
    }
    else if (str[i] == "-motionblur-e-w") {
      float radius = 0.0;
      try {
        radius = stof(str[i+1]);
      }
      catch (const std::invalid_argument& ia) {
          std::cerr << "Invalid argument: " << ia.what() << '\n';
          DefaultMsg();
          return;
      }

      if (radius >= 1.0 && radius <= 10.0) {
        cmd.push_back(new MotionBlurFilterCommand(image_editor_, radius, "East/West"));
      }
      else {
        std::cerr << "Out of Parameter Bound" << '\n';
        DefaultMsg();
        return;
      }
    }
    else if (str[i] == "-motionblur-ne-sw") {
      float radius = 0.0;
      try {
        radius = stof(str[i+1]);
      }
      catch (const std::invalid_argument& ia) {
          std::cerr << "Invalid argument: " << ia.what() << '\n';
          DefaultMsg();
          return;
      }

      if (radius >= 1.0 && radius <= 10.0) {
        cmd.push_back(new MotionBlurFilterCommand(image_editor_, radius, "Northeast/Southwest"));
      }
      else {
        std::cerr << "Out of Parameter Bound" << '\n';
        DefaultMsg();
        return;
      }
    }
    else if (str[i] == "-motionblur-nw-se") {
      float radius = 0.0;
      try {
        radius = stof(str[i+1]);
      }
      catch (const std::invalid_argument& ia) {
          std::cerr << "Invalid argument: " << ia.what() << '\n';
          DefaultMsg();
          return;
      }

      if (radius >= 1.0 && radius <= 10.0) {
        cmd.push_back(new MotionBlurFilterCommand(image_editor_, radius, "Northwest/Southeast"));
      }
      else {
        std::cerr << "Out of Parameter Bound" << '\n';
        DefaultMsg();
        return;
      }
    }
    else if (str[i] == "-h"){
      DefaultMsg();
      return;
    }
  }

//-------------------------------------------------------
 try{
    cmd.push_back(new SaveCommand(image_editor_, subOut));
  }
  catch(...){
    DefaultMsg();
    return;
  }

  for(unsigned i = 0; i < cmd.size(); i++) {
    cmd[i]->Execute();
  }

  delete image_editor_;
  image_editor_ = NULL;
  }

void CommandLineProcessor::DefaultMsg() {
  cout << "usage: mia infile.png [image processing commands ...] outfile.png" << endl;
  cout << "infile.png:           input image file in png format" << endl;
  cout << "outfile.png:          filename to use for saving the result" << endl;
  cout << "image processing comamnds:" << endl;
  cout << "-blur r:              apply a gaussian blur of radius r " << endl;
  cout << "-edgedetect:          apply an edge detection filter" << endl;
  cout << "-sharpen r:           apply a sharpening filter of radius r" << endl;
  cout << "-red s:               scale the red channel by factor s" << endl;
  cout << "-green s:             scale the green channel by factor s" << endl;
  cout << "-blue s:              scale the blue channel by factor s" << endl;
  cout << "-quantize n:          quantize each color channel into n bins" << endl;
  cout << "-saturate s:          saturate colors by scale factor s" << endl;
  cout << "-threshold c:         threshold using cutoff value c" << endl;
  cout << "-motionblur-n-s r:    north-south motion blur with kernel radius r" << endl;
  cout << "-motionblur-e-w r:    east-west motion blur with kernel radius r" << endl;
  cout << "-motionblur-ne-sw r:  ne-sw motion blur with kernel radius r" << endl;
  cout << "-motionblur-nw-se r:  nw-se motion blur with kernel radius r" << endl;
  }




}  // namespace image_tools
