
#ifndef MIA_COMMAND_LINE_PROCESSOR_H_
#define MIA_COMMAND_LINE_PROCESSOR_H_

#include <string>
#include <utility>
#include <vector>
#include <mingfx.h>

#include "imagetools/color_data.h"
#include "imagetools/image_editor.h"
#include "imagetools/pixel_buffer.h"

#include "mia/image_editor_commands.h"

namespace image_tools {

/** @brief The Mia GUI. This class creates a graphics window to display
 the current PixelBuffer and a graphical user interface to interact with it
 using
 Tools and Filters. */
class CommandLineProcessor {
 public:
  CommandLineProcessor();
  virtual ~CommandLineProcessor();

  ImageEditor imageEditor();

  std::vector<ImageEditorCommand*> commandList();

  void ProcessCommandLine(int argc, char* argv[]);

  void DefaultMsg();

 private:
   std::vector<ImageEditorCommand*> cmd;
   ImageEditor* image_editor_;

};

}  // namespace image_tools

#endif  // MIA_COMMAND_LINE_PROCESSOR_H_
