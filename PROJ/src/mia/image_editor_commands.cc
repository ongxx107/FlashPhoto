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

#include "mia/image_editor_commands.h"

#include "imagetools/image_editor.h"

namespace image_tools {

ImageEditorCommand::ImageEditorCommand(ImageEditor *image_editor)
    : image_editor_(image_editor) {}

ImageEditorCommand::~ImageEditorCommand() {}

/*
BlurFilterCommand subclass takes ImageEditor pointer and any argument that needs
to iterate the buffer along with pixels. BlurFilterCommand subclass uses
ImageEditor pointer and execute the ApplyBlurFilter function. Also, the
BlurFilterCommand subclass has its own name for testing purposes.
*/
BlurFilterCommand::BlurFilterCommand(ImageEditor *image_editor, float radius)
    : ImageEditorCommand(image_editor), radius_(radius) {}

BlurFilterCommand::~BlurFilterCommand() {}

void BlurFilterCommand::Execute() { image_editor_->ApplyBlurFilter(radius_); }

std::string BlurFilterCommand::name() { return "Blur"; }

/*
EdgeFilterCommand subclass takes ImageEditor pointer and any argument that needs
to iterate the buffer along with pixels. EdgeFilterCommand subclass uses
ImageEditor pointer and execute the ApplyEdgeDetectFilter function. Also, the
EdgeFilterCommand subclass has its own name for testing purposes.
*/
EdgeFilterCommand::EdgeFilterCommand(ImageEditor *image_editor)
    : ImageEditorCommand(image_editor) {}

EdgeFilterCommand::~EdgeFilterCommand() {}

void EdgeFilterCommand::Execute() { image_editor_->ApplyEdgeDetectFilter(); }

std::string EdgeFilterCommand::name() { return "Edge"; }

/*
SharpenFilterCommand subclass takes ImageEditor pointer and any argument that
needs to iterate the buffer along with pixels. SharpenFilterCommand subclass
uses ImageEditor pointer and execute the ApplySharpenFilter function. Also, the
SharpenFilterCommand subclass has its own name for testing purposes.
*/
SharpenFilterCommand::SharpenFilterCommand(ImageEditor *image_editor,
                                           float radius)
    : ImageEditorCommand(image_editor), radius_(radius) {}

SharpenFilterCommand::~SharpenFilterCommand() {}

void SharpenFilterCommand::Execute() {
  image_editor_->ApplySharpenFilter(radius_);
}

std::string SharpenFilterCommand::name() { return "Sharpen"; }

/*
ChannelsFilterCommand subclass takes ImageEditor pointer and any argument that
needs to iterate the buffer along with pixels. ChannelsFilterCommand subclass
uses ImageEditor pointer and execute the ApplyChannelsFilter function. Also, the
ChannelsFilterCommand subclass has its own name for testing purposes.
*/
ChannelsFilterCommand::ChannelsFilterCommand(ImageEditor *image_editor,
                                             float red_scale, float green_scale,
                                             float blue_scale)
    : ImageEditorCommand(image_editor),
      r_(red_scale),
      g_(green_scale),
      b_(blue_scale) {}

ChannelsFilterCommand::~ChannelsFilterCommand() {}

void ChannelsFilterCommand::Execute() {
  image_editor_->ApplyChannelsFilter(r_, g_, b_);
}

std::string ChannelsFilterCommand::name() { return "Channels"; }

/*
QuantizeFilterCommand subclass takes ImageEditor pointer and any argument that
needs to iterate the buffer along with pixels. QuantizeFilterCommand subclass
uses ImageEditor pointer and execute the ApplyQuantizeFilter function. Also, the
QuantizeFilterCommand subclass has its own name for testing purposes.
*/
QuantizeFilterCommand::QuantizeFilterCommand(ImageEditor *image_editor,
                                             int bins)
    : ImageEditorCommand(image_editor), bins_(bins) {}

QuantizeFilterCommand::~QuantizeFilterCommand() {}

void QuantizeFilterCommand::Execute() {
  image_editor_->ApplyQuantizeFilter(bins_);
}

std::string QuantizeFilterCommand::name() { return "Quantize"; }

/*
SaturateFilterCommand subclass takes ImageEditor pointer and any argument that
needs to iterate the buffer along with pixels. SaturateFilterCommand subclass
uses ImageEditor pointer and execute the ApplySaturateFilter function. Also, the
SaturateFilterCommand subclass has its own name for testing purposes.
*/
SaturateFilterCommand::SaturateFilterCommand(ImageEditor *image_editor,
                                             float scale)
    : ImageEditorCommand(image_editor), scale_(scale) {}

SaturateFilterCommand::~SaturateFilterCommand() {}

void SaturateFilterCommand::Execute() {
  image_editor_->ApplySaturateFilter(scale_);
}

std::string SaturateFilterCommand::name() { return "Saturate"; }

/*
ThresholdFilterCommand subclass takes ImageEditor pointer and any argument that
needs to iterate the buffer along with pixels. ThresholdFilterCommand subclass
uses ImageEditor pointer and execute the ApplyThresholdFilter function. Also,
the ThresholdFilterCommand subclass has its own name for testing purposes.
*/
ThresholdFilterCommand::ThresholdFilterCommand(ImageEditor *image_editor,
                                               float cutoff)
    : ImageEditorCommand(image_editor), cutoff_(cutoff) {}

ThresholdFilterCommand::~ThresholdFilterCommand() {}

void ThresholdFilterCommand::Execute() {
  image_editor_->ApplyThresholdFilter(cutoff_);
}

std::string ThresholdFilterCommand::name() { return "Threshold"; }

/*
MotionBlurFilterCommand subclass takes ImageEditor pointer and any argument that
needs to iterate the buffer along with pixels. MotionBlurFilterCommand subclass
uses ImageEditor pointer and execute the ApplyMotionBlurFilter function. Also,
the MotionBlurFilterCommand subclass has its own name for testing purposes.
*/
MotionBlurFilterCommand::MotionBlurFilterCommand(
    ImageEditor *image_editor, float radius,
    std::string dir)
    : ImageEditorCommand(image_editor), radius_(radius), dir_(dir) {}

MotionBlurFilterCommand::~MotionBlurFilterCommand() {}

void MotionBlurFilterCommand::Execute() {
  image_editor_->ApplyMotionBlurFilter(radius_, dir_);
}

std::string MotionBlurFilterCommand::name() { return "MotionBlur"; }

/*
UndoCommand subclass takes ImageEditor pointer and any argument that
needs to iterate the buffer along with pixels. UndoCommand subclass
uses ImageEditor pointer and execute the Undo function. Also,
the UndoCommand subclass has its own name for testing purposes.
*/
UndoCommand::UndoCommand(ImageEditor *image_editor)
    : ImageEditorCommand(image_editor) {}

UndoCommand::~UndoCommand() {}

void UndoCommand::Execute() { image_editor_->Undo(); }

std::string UndoCommand::name() { return "Undo"; }

/*
RedoCommand subclass takes ImageEditor pointer and any argument that
needs to iterate the buffer along with pixels. RedoCommand subclass
uses ImageEditor pointer and execute the Redo function. Also,
the RedoCommand subclass has its own name for testing purposes.
*/
RedoCommand::RedoCommand(ImageEditor *image_editor)
    : ImageEditorCommand(image_editor) {}

RedoCommand::~RedoCommand() {}

void RedoCommand::Execute() { image_editor_->Redo(); }

std::string RedoCommand::name() { return "Redo"; }

/*
StartStrokeCommand subclass takes ImageEditor pointer and any argument that
needs to iterate the buffer along with pixels. StartStrokeCommand subclass
uses ImageEditor pointer and execute the StartStroke function. Also,
the StartStrokeCommand subclass has its own name for testing purposes.
*/
StartStrokeCommand::StartStrokeCommand(ImageEditor *image_editor,
                                       const std::string &tool_name,
                                       const ColorData &color, float radius,
                                       int x, int y)
    : ImageEditorCommand(image_editor),
      tool_name_(tool_name),
      color_(color),
      radius_(radius),
      x_(x),
      y_(y) {}

StartStrokeCommand::~StartStrokeCommand() {}

void StartStrokeCommand::Execute() {
  image_editor_->StartStroke(tool_name_, color_, radius_, x_, y_);
}

std::string StartStrokeCommand::name() { return "StartStroke"; }

/*
AddToStrokeCommand subclass takes ImageEditor pointer and any argument that
needs to iterate the buffer along with pixels. AddToStrokeCommand subclass
uses ImageEditor pointer and execute the AddToStroke function. Also,
the AddToStrokeCommand subclass has its own name for testing purposes.
*/
AddToStrokeCommand::AddToStrokeCommand(ImageEditor *image_editor, int x, int y)
    : ImageEditorCommand(image_editor), x_(x), y_(y) {}

AddToStrokeCommand::~AddToStrokeCommand() {}

void AddToStrokeCommand::Execute() { image_editor_->AddToStroke(x_, y_); }

std::string AddToStrokeCommand::name() { return "AddToStroke"; }

/*
EndStrokeCommand subclass takes ImageEditor pointer and any argument that
needs to iterate the buffer along with pixels. EndStrokeCommand subclass
uses ImageEditor pointer and execute the EndStroke function. Also,
the EndStrokeCommand subclass has its own name for testing purposes.
*/
EndStrokeCommand::EndStrokeCommand(ImageEditor *image_editor, int x, int y)
    : ImageEditorCommand(image_editor), x_(x), y_(y) {}

EndStrokeCommand::~EndStrokeCommand() {}

void EndStrokeCommand::Execute() { image_editor_->EndStroke(x_, y_); }

std::string EndStrokeCommand::name() { return "EndStroke"; }

/*
LoadCommand subclass takes ImageEditor pointer and any argument that
needs to iterate the buffer along with pixels. LoadCommand subclass
uses ImageEditor pointer and execute the LoadFromFile function. Also,
the LoadCommand subclass has its own name for testing purposes.
*/
LoadCommand::LoadCommand(ImageEditor *image_editor, const std::string &filename)
    : ImageEditorCommand(image_editor), filename_(filename) {}

LoadCommand::~LoadCommand() {}

void LoadCommand::Execute() { image_editor_->LoadFromFile(filename_); }

std::string LoadCommand::name() { return "Load"; }

/*
SaveCommand subclass takes ImageEditor pointer and any argument that
needs to iterate the buffer along with pixels. SaveCommand subclass
uses ImageEditor pointer and execute the SaveToFile function. Also, 
the SaveCommand subclass has its own name for testing purposes.
*/
SaveCommand::SaveCommand(ImageEditor *image_editor, const std::string &filename)
    : ImageEditorCommand(image_editor), filename_(filename) {}

SaveCommand::~SaveCommand() {}

void SaveCommand::Execute() { image_editor_->SaveToFile(filename_); }

std::string SaveCommand::name() { return "Save"; }

}  // namespace image_tools
