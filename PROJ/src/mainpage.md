My Main Page  {#mainpage}
===========

For users: \n
\subpage page1 \n
\subpage page2 \n

\n
For developer: \n
\subpage page3 \n
\subpage page4 \n
\subpage page5 \n
\subpage page6 \n

\page page1 - Getting Started with FlashPhoto

Introduction: \n
FlashPhoto is an application that allows users to load any image, draw anything using a tool, filter the image, and eventually has the feature of saving final product of the image. For the Graphic User Interface(GUI), we used Mingfx as the base support of displaying user interface. FlashPhoto only supports PNG image which means it could only load and save one type of image file. \n

In FlashPhoto application, there are 6 different tools and 8 different filters you could choose to use. \n
Tools: \n
    • Pen - This tool is designed to look like a pen. It makes an opaque, circular mark with constant intensity. This means that when the pen is applied to the canvas the digital ink from the pen completely covers any color that had previously been applied to the canvas at that position. The color of the pen can be set interactively using the GUI. \n
    • Calligraphy Pen - This tool is designed to look like a calligraphy pen. It works almost the same way as the Pen tool. Like the Pen tool, it is completely opaque and it covers up any “paint” that was already applied to the canvas. However, the difference with the Calligraphy Pen is that the mask is an oval tilted at a 30-degree angle. The color of the highlighter can be set interactively using the GUI. \n
    • Chalk - This tool is designed to look like a piece of chalk dragged across a bumpy surface. It has a circular mask, but about 40% of the pixels within the circle are randomly chosen to be completely transparent. This creates the bumpy effect. The chalk color can be set interactively using the GUI. \n
    • Highlighter - This tool is designed to look like a highlighter marker. It uses an oval mask similar to the Calligraphy Pen, but the oval is oriented vertically, and the intensity of the mask is set to make the mark semi-transparent. The color applied to the canvas is approximately 40% the color of the highlighter and 60% whatever color is already on the canvas; however, a special color blending function is used for the highlighter so that dark colors show through more than light colors. The color of the highlighter’s ink can be set interactively using the GUI. \n
    • Spray Can - This tool is designed to mimic the look of paint from a spray can. It uses a special mask that is circular in shape but has a linear falloff to mimic the dispersion of color from the spray. The intensity is strongest at the center pixel and falls off linearly to zero intensity as it gets closer to the edge of the circle. The specific paint color can be set interactively using the GUI. \n
    • Eraser - This tool erases the digital canvas and returns it to its original background color. It has a circular mask, and eraser’s color cannot be changed through the GUI because there is currently no user interface for changing the canvas background color. \n
\n
Note: Each tool’s size could be set manually using the GUI. \n
\n
Filters: \n
    • Threshold - This filter is designed to make the image turning black and white (a.k.a.) binary image. It rounds up the color channels to the maximum value, 1.0 which is white or minimum value, 0.0 which is black. \n
    • Saturation - This filter is designed to change the colorfulness of the image. The image has either less color or more color filled with possible color channels. \n
    • Channels - This filter is designed to independently scale up or down the intensity of each color channel (red, green, and blue). \n
    • Quantize - This filter is designed to reduce the number of colors in the image by binning. For example, if the input is 4 bins, there will only be 4 possible intensity values for each color channel, spaced evenly: 0%, 33%, 66%, and 100%. Adjust each color channel value R, G, and B to put it into 6 the nearest bin. \n
    • Blur - This filter is designed to use a Gaussian Blur image convolution kernel to blur the image in proportion to the input amount specified in the GUI. \n
    • Motion Blur - This filter is designed to blur the image by convolving the image with an appropriate motion-blurring kernel. It has four possible blurring directions (North-to-South, East-to-West, Northeast-to-Southwest, and Northwest-to-Southeast) and blur according to the amount specified in the GUI. \n
    • Sharpen - This filter is designed to sharpen the image (increase the visibility of the edges of shapes) in proportion to the amount specified in the GUI by convolving the image with an appropriate sharpening kernel. \n
    • Edge Detection - This filter is designed to transform the image into one that only shows the edges of shapes by convolving 7 it with a 3x3 edge detection kernel. Thus, the pixels on the border of differently colored regions will be bright, while pixels in areas of low change will be dark. \n
\n
(sourced from iteration1.pdf in handouts directory) \n

\page page2 - Getting Started with Mia

Introduction: \n
Medical Imaging Assistant(MIA) is a very similar application to FlashPhoto but it is used for medical purpose. MIA does not have many features as FlashPhoto but it has most of the filters, a red pen tool and a marker tool for users. With these features, it is a good program for doing medical record. MIA provides GUI and Command Line Interface. GUI provides all filters and tools functionality whereas the Command Line Interface provides the user to edit their photos with filters only using specific command line. MIA only supports PNG image which means it could only load and save one type of image file. \n
\n
In MIA application, the features are almost the same as FlashPhoto. However, they have 2 tools and 5 filters only in GUI whereas there are all filters in Command Line interface. \n
\n
In GUI, there are: \n
	Tools: \n
    • Stamp - A tool that stamps a bullseye pattern, one circle inside another, that clinicians can use to mark important areas on the image. \n
    • Pen – Similar to the one in FlashPhoto application. It works like a pen. It makes an opaque, circular mark with constant intensity. This means that when the pen is applied to the canvas the digital ink from the pen completely covers any color that had previously been applied to the canvas at that position. The color of the pen can be set interactively using the GUI. \n

Filters: \n
    • Blur - Similar to the one in FlashPhoto application. This filter is designed to use a Gaussian Blur image convolution kernel to blur the image in proportion to the input amount specified in the GUI. \n
    • Sharpen - Similar to the one in FlashPhoto application. This filter is designed to sharpen the image (increase the visibility of the edges of shapes) in proportion to the amount specified in the GUI by convolving the image with an appropriate sharpening kernel. \n
    • Edge Detection - Similar to the one in FlashPhoto application. This filter is designed to transform the image into one that only shows the edges of shapes by convolving 7 it with a 3x3 edge detection kernel. Thus, the pixels on the border of differently colored regions will be bright, while pixels in areas of low change will be dark. \n
    • Threshold - Similar to the one in FlashPhoto application. This filter is designed to make the image turning black and white (a.k.a.) binary image. It rounds up the color channels to the maximum value, 1.0 which is white or minimum value, 0.0 which is black. \n
    • Quantize - Similar to the one in FlashPhoto application. This filter is designed to reduce the number of colors in the image by binning. For example, if the input is 4 bins, there will only be 4 possible intensity values for each color channel, spaced evenly: 0%, 33%, 66%, and 100%. Adjust each color channel value R, G, and B to put it into 6 the nearest bin. \n
\n
 (sourced from iteration1.pdf and iteration2.pdf in handouts directory) \n


\page page3 - Programming Reference
- #image_tools
- #image_tools::MiaApp
- #image_tools::FlashPhotoApp

\page page4 - High-Level Design
##UML
![](../ongxx107_iteration1_UML.pdf)

\page page5 - Coding Style
Page 2 Getting Started with Mia

\page page6 - Common Tasks

How to Add a New Filter: \n
\n
Instructions: \n
 \n
    1. To add a new filter, for example, threshold, first, you have to implement a subclass of Filter called FilterThreshold. The respective files are filter_threshold.h and filter_threshold.cc. Here's the brief implementation of these two source files. \n

PROJ/src/imagetools/filter_threshold.h

	#ifndef IMAGETOOLS_FILTER_THRESHOLD_H_
#define IMAGETOOLS_FILTER_THRESHOLD_H_

#include "imagetools/filter.h"

namespace image_tools {

class FilterThreshold : public Filter {
public:
FilterThreshold(float value);
ColorData CalculateFilteredPixel(PixelBuffer* buffer, int x, int y) override; };
} // namespace image_tools
#endif // IMAGETOOLS_FILTER_THRESHOLD_H_


PROJ/src/imagetools/filter_threshold.cc

	#include "imagetools/filter_threshold.h"
#include "imagetools/color_data.h"
#include "imagetools/pixel_buffer.h"

namespace image_tools {

FilterThreshold::FilterThreshold(float value) { value_ = value; }
ColorData FilterThreshold::CalculateFilteredPixel(PixelBuffer* buffer, int x, int y) {
// Implementation for filter threshold
}

 } /* namespace image_tools */

    2. Next, we have to add the creation of the filter threshold into ImageEditor class. In ImageEditor.cc, we have to build ApplyThresholdFilter() to make it fully functional for the applications. We just need to assign the input value into Threshold class and eventually call ApplyToBuffer() in ImageEditor.cc. Don't forget to include the header file filter_threshold.h in ImageEditor.h.

PROJ/src/imagetools/image_editor.h
…
#include "imagetools/filter_threshold.h"

namespace image_tools {

class ImageEditor {
public:
 void ApplyThresholdFilter(float cutoff_value);
};
	} /* namespace image_tools */

PROJ/src/imagetools/image_editor.cc

namespace image_tools {
…
void ImageEditor::ApplyThresholdFilter(float value) {
SaveStateForPossibleUndo();
FilterThreshold* f_threshold_ = new FilterThreshold(value);
f_threshold_->ApplyToBuffer(pixel_buffer());
delete f_threshold_;
f_threshold_ = NULL;
}
} /* namespace image_tools */

    3. Finally, you have to add Threshold Button on GUI and build a setCallBack() function for the button in flahphoto_app.cc. You have to add the declaration for ApplyThresholdFilter() using ImageEditor pointer and the caller itself in flashphoto_app.cc.

PROJ/src/flashphoto/flashphoto_app.cc

namespace image_tools {
…
// THRESHOLD
nanogui::PopupButton *thresh = new nanogui::PopupButton(filters, "Threshold");
thresh->setFixedSize({150, 20});
nanogui::Popup *thresh_win = thresh->popup();
thresh_win->setLayout(new nanogui::GroupLayout(4, 4, 8, 8));
nanogui::Widget *thresh_params = new nanogui::Widget(thresh_win);
thresh_params->setLayout(params_layout);
new nanogui::Label(thresh_params, "Cutoff Value:", "sans-bold");
nanogui::Widget *thresh_param1 = new nanogui::Widget(thresh_params);
thresh_param1->setLayout(new nanogui::BoxLayout( nanogui::Orientation::Horizontal, nanogui::Alignment::Middle, 0, 6));
nanogui::Slider *th_slider = new nanogui::Slider(thresh_param1);
th_slider->setRange(std::make_pair(0, 1));
th_slider->setValue(thresh_cutoff_);
th_slider->setFixedWidth(150);
nanogui::TextBox *th_text = new nanogui::TextBox(thresh_param1);
th_text->setFixedSize({60, 20});
th_text->setFontSize(18); th_text->setAlignment(nanogui::TextBox::Alignment::Right);
std::stringstream stream;
stream << std::fixed << std::setprecision(2) << thresh_cutoff_; th_text->setValue(stream.str());
th_slider->setCallback([this, th_text](float value) { std::stringstream innerStream; innerStream << std::fixed << std::setprecision(2) << value;
th_text->setValue(innerStream.str());
thresh_cutoff_ = value; });
b = new nanogui::Button(thresh_win, "Apply");
b->setFixedSize({150, 30}); b->setCallback([this] { ApplyThresholdFilter(thresh_cutoff_); });

…

void FlashPhotoApp::ApplyThresholdFilter(float value) {
image_editor_->ApplyThresholdFilter(value);
}

} /* namespace image_tools */

    4. Congratulations! You made a new filter!
