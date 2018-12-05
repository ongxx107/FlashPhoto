/**
This file is part of the CSCI-3081W Project Support Code, which was developed
at the University of Minnesota.

This code is to be used for student coursework.  It is not an open source
project.
Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
Minnesota.

Original Author(s) of this File:
  Seth Johnson, 2/15/15, University of Minnesota

Author(s) of Significant Updates/Modifications to the File:
  Daniel Keefe, 2018, UMN -- ported to MinGfx
  ...
*/

#include "imagetools/image_editor.h"
#include </classes/csel-f18c3081/include/imageio/image.h>
#include </classes/csel-f18c3081/include/imageio/image_manager.h>

namespace image_tools {

ImageEditor::ImageEditor(PixelBuffer *buffer){
  current_buffer_ = buffer;
  //max_undos_ = 50;
}

/** Creates an editor with a NULL pixel buffer.  You will need to set the
 pixel buffer before performing any editing operations. */
ImageEditor::ImageEditor(){
  current_buffer_ = NULL;
}

ImageEditor::~ImageEditor(){}

Tool *ImageEditor::GetToolByName(const std::string &name) {
  if (name == t_blur_.name()) {
    return &t_blur_;
  } else if (name == t_calligraphy_pen_.name()) {
    return &t_calligraphy_pen_;
  } else if (name == t_chalk_.name()) {
    return &t_chalk_;
  } else if (name == t_eraser_.name()) {
    return &t_eraser_;
  } else if (name == t_highlighter_.name()) {
    return &t_highlighter_;
  } else if (name == t_pen_.name()) {
    return &t_pen_;
  } else if (name == t_spray_can_.name()) {
    return &t_spray_can_;
  } else if (name == t_stamp_.name()) {
    return &t_stamp_;
  } else {
    return NULL;
  }
}

void ImageEditor::StartStroke(const std::string &tool_name,
                                const ColorData &color, float radius, int x,
                                int y) {
  current_tool_ = GetToolByName(tool_name);
  tool_color_ = color;
  tool_radius_ = radius;
  if ((current_tool_) && (current_buffer_)) {
    SaveStateForPossibleUndo();
    current_tool_->StartStroke(current_buffer_, x, y, tool_color_,
                               tool_radius_);
  }
}

void ImageEditor::AddToStroke(int x, int y) {
  if ((current_tool_) && (current_buffer_)) {
    current_tool_->AddToStroke(x, y);
  }
}

void ImageEditor::EndStroke(int x, int y) {
  if ((current_tool_) && (current_buffer_)) {
    current_tool_->EndStroke(x, y);
  }
}

void ImageEditor::LoadFromFile(const std::string &filename) {
  if (current_buffer_ != NULL) {
    SaveStateForPossibleUndo();
    current_buffer_->LoadFromFile(filename);
  } else {
    current_buffer_ = new PixelBuffer(filename);
  }
}

void ImageEditor::SaveToFile(const std::string &filename) {
  current_buffer_->SaveToFile(filename);
}

void ImageEditor::ApplyBlurFilter(float radius) {
  SaveStateForPossibleUndo();
  f_blur_ = new ConvolutionFilterBlur(radius);
  f_blur_->ApplyToBuffer(pixel_buffer());
  delete f_blur_;
  // f_blur_->CleanupFilter();
  f_blur_ = NULL;
}

void ImageEditor::ApplyMotionBlurFilter(float rad, std::string dirName) {
  SaveStateForPossibleUndo();
  // std::string DirName = MotionBlurDirectionName(dir);
  f_motion_blur_ = new ConvolutionFilterMotionBlur(rad, dirName);
  f_motion_blur_->ApplyToBuffer(pixel_buffer());
  delete f_motion_blur_;
  //f_motion_blur_->CleanupFilter();
  f_motion_blur_ = NULL;
}

void ImageEditor::ApplySharpenFilter(float rad) {
  SaveStateForPossibleUndo();
  f_sharpen_ = new ConvolutionFilterSharpen(rad);
  f_sharpen_->ApplyToBuffer(pixel_buffer());
  delete f_sharpen_;
  //f_sharpen_->CleanupFilter();
  f_sharpen_ = NULL;
}

void ImageEditor::ApplyEdgeDetectFilter() {
  SaveStateForPossibleUndo();
  f_edge_ = new ConvolutionFilterEdge();
  f_edge_->ApplyToBuffer(pixel_buffer());
  delete f_edge_;
  //f_edge_->CleanupFilter();
  f_edge_ = NULL;
}

void ImageEditor::ApplyThresholdFilter(float value) {
  SaveStateForPossibleUndo();
  f_threshold_ = new FilterThreshold(value);
  f_threshold_->ApplyToBuffer(pixel_buffer());
  delete f_threshold_;
  //f_threshold_->CleanupFilter();
  f_threshold_ = NULL;
}

void ImageEditor::ApplySaturateFilter(float scale) {
  SaveStateForPossibleUndo();
  f_saturate_ = new FilterSaturate(scale);
  f_saturate_->ApplyToBuffer(pixel_buffer());
  delete f_saturate_;
  //f_saturate_->CleanupFilter();
  f_saturate_ = NULL;
}

void ImageEditor::ApplyChannelsFilter(float red, float green, float blue) {
  SaveStateForPossibleUndo();
  f_channels_ = new FilterChannels(red, green, blue);
  f_channels_->ApplyToBuffer(pixel_buffer());
  delete f_channels_;
  //f_channels_->CleanupFilter();
  f_channels_ = NULL;
}

void ImageEditor::ApplyQuantizeFilter(int num) {
  SaveStateForPossibleUndo();
  f_quantize_ = new FilterQuantize(num);
  f_quantize_->ApplyToBuffer(pixel_buffer());
  delete f_quantize_;
  //f_quantize_->CleanupFilter();
  f_quantize_ = NULL;
}

bool ImageEditor::can_undo() { return saved_states_.size(); }

bool ImageEditor::can_redo() { return undone_states_.size(); }

void ImageEditor::Undo() {
  if (can_undo()) {
    // save state for a possilbe redo
    undone_states_.push_front(current_buffer_);

    // make the top state on the undo stack the current one
    current_buffer_ = saved_states_.front();
    saved_states_.pop_front();
  }
}

void ImageEditor::Redo() {
  if (can_redo()) {
    // save state for a possible undo
    saved_states_.push_front(current_buffer_);

    // make the top state on the redo stack the current one
    current_buffer_ = undone_states_.front();
    undone_states_.pop_front();
  }
}

void ImageEditor::SaveStateForPossibleUndo() {
  PixelBuffer *buffer_copy = new PixelBuffer(*current_buffer_);
  saved_states_.push_front(buffer_copy);

  // remove the oldest undos if we've over our limit
  while (saved_states_.size() > max_undos_) {
    delete saved_states_.back();
    saved_states_.pop_back();
  }

  // committing a new state invalidates the states saved in the redo stack,
  // so, we simply clear out this stack.
  while (!undone_states_.empty()) {
    delete undone_states_.back();
    undone_states_.pop_back();
  }
}

PixelBuffer *ImageEditor::pixel_buffer() { return current_buffer_; }

void ImageEditor::set_pixel_buffer(PixelBuffer *buffer) {
  current_buffer_ = buffer;
}

} /* namespace image_tools */
