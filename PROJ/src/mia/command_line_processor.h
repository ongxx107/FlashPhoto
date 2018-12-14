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
#ifndef MIA_COMMAND_LINE_PROCESSOR_H_
#define MIA_COMMAND_LINE_PROCESSOR_H_

#include <mingfx.h>
#include <utility>
#include <vector>
#include <string>
#include "imagetools/color_data.h"
#include "imagetools/image_editor.h"
#include "imagetools/pixel_buffer.h"
#include "mia/image_editor_commands.h"

namespace image_tools {

/** @brief The MIA CommandLineProcessor. This class takes the arguments from
    terminal and runs the functions from image_editor_commands class. Then,
    the functions from the image_editor_commands call the functions from
    image_editor class.
*/
class CommandLineProcessor {
 public:
  CommandLineProcessor();
  virtual ~CommandLineProcessor();

  ImageEditor* imageEditor();

  std::vector<ImageEditorCommand*> CommandList();

  int isSucess();

  void ProcessCommandLine(int argc, std::vector<std::string> argumentv);

  void DefaultMsg();

 private:
  std::vector<ImageEditorCommand*> cmd;
  ImageEditor* image_editor_;
  int success_;
};

}  // namespace image_tools

#endif  // MIA_COMMAND_LINE_PROCESSOR_H_
