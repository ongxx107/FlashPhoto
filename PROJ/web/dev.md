

##Developer 
- \subpage page3 \n \n
- \subpage page4 \n \n
- \subpage page5 \n \n
- \subpage page6 \n \n


\page page3 Programming Reference
- #image_tools
- #image_tools::MiaApp
- #image_tools::FlashPhotoApp

\page page4 High-Level Design
##Introduction:
In this section, there are some keypoints that make applications beneficial.

## Libraries
![Diagram above shows the relationship between 2 applications and 3 libraries.](./library.png)
\n
- We use 3 libraries to run the applications. **The reason why we cluster them into libraries rather than making them altogether into one is we could fix the bug error easily and also it has better optimization due to reusability by other application.** Thus, the other application could reuse the library. There are 1 internal library, libimagetools, and 2 external libraries which are MinGfx and imageio made by UMN CSE faculties. 
- Internal library:
    - libimagetools
        - Has features of tools and filters for applications.

\n
- External libraries: 
    - MinGfx 
        - This library has the GUI implementation for applications. \n
    - imageio 
        - This private library has the save to file and load from file functionalities for both Flashphoto and MIA applications to work. \n
        - It support .png filetype only. 

## Tool Diagram Class
![Diagram above shows Tool class and its subclasses.](./toolClass.png)
\n
- The [Tool](classimage__tools_1_1Tool.html) class is an abstract class since it can't be used and instantiated. Thus, its functionality is called through inheritance.
- All subclasses of [Tool](classimage__tools_1_1Tool.html) need [FloatMatrix](classimage__tools_1_1FloatMatrix.html) to iterate the canvas in GUI. Thus, the subclasses of [Tool](classimage__tools_1_1Tool.html) need factory class which is [MaskFactory](classimage__tools_1_1MaskFactory.html) to build a mask/matrix through factory method called CreateMask(). 
- Therefore, each tool has its certain mask since it has specific CreateMask() defined in each subclass.

## Filter Diagram Class
![Diagram above shows Filter class and its subclasses.](./filterClass.png)
\n
- The [Filter](classimage__tools_1_1Filter.html) class is an abstract class since it can't be used and instantiated. Thus, its functionality is overriden through inheritance.
    - There are 2 types of filter, basic, and convolution filter.
        - basic filter:
            - Does not require a kernel to check around its neighboring pixel.
            - Can calculate each pixel in place.
            - Calculates each pixel based on specified filters.
            - Is inherited from [Filter](classimage__tools_1_1Filter.html) parent class
        - convolution filter:
            - Requires a kernel to check around its neighboring pixel. 
            - Needs a factory method CreateKernel() for specific convolution filter.
            - Cannot calculate each pixel in place.
            - Is inherited from [ConvolutionFilter](classimage__tools_1_1ConvolutionFilter.html) parent class
\n
- Once the buffer is setup by specific filter, ApplyToBuffer() as template method from [Filter](classimage__tools_1_1Filter.html) is required in order to make the pixel display in GUI.

## Command Design Pattern
- "Encapsulate a request as an object, thereby letting you parametrize clients with different requests, queue or log requests, and support undoable operations." (*sourced from https://sourcemaking.com/design_patterns/command*)
- Implementation of the command pattern in MIA application is used to filter input image using filters from libimagetools.
- It takes a list of command filters in a vector standard type. Eventually, it executes and produces an output png image.
- Command pattern handles all invalid arguments/errors by using try/catch exception.
    - Error Handling:
        - File does not exist
        - Input file type is invalid
        - Parameter for filter is invalid
        - Command filter name is invalid
        - Invalid input name
    - Example from [commmand_line_processor](classimage__tools_1_1CommandLineProcessor.html):

            try {
                radius = stof(str[i+1]);
            }
            catch (const std::invalid_argument& ia) {
                std::cerr << "Invalid argument: " << ia.what() << '\n';
                DefaultMsg();
                success_ = 1;
                return;
            }

##Model-View-Controller (MVC)
![MVC structure (sourced from 20_IntroToIteration2AndMVC.pdf)](./MVC.png)
- MVC is a design pattern in this project such that MVC is a paradigm used to organize applications that work together.
- The Model - represents current pixel buffer which is utilized/changed by tools or filters. In others word, the application would try to manipulate the pixel buffer
- The View - 
    - "Implements a visual display of the model" (*sourced from 20_IntroToIteration2AndMVC.pdf*)
    - In applications, it represents GUI which is compiled from MinGfx external library. The intterface changes constantly whenever the model has any changes.
    - In MIA command line, it represents the terminal with a list of command lines that are about to execute.
- The Controller -
    - Receives all input events from the user (*sourced from 20_IntroToIteration2AndMVC.pdf*)
    - In applications, it represents mouse that drags and click around the interface.
    - In MIA command line, it represents keyboard which inputs all the keywords.

\page page5 Coding Style
##Note: All styles checking are based on Google style guide
##Naming conventions

Member variables - In this project, we use Google style naming conventions. One of the example would be initializing a member variable and ends with "_". One of my examples is "mat_" in convolution_filter.cc.

    void ConvolutionFilter::SetupFilter() {
        mat_ = CreateKernel();
    }

Routine(Function) name - In this project, I named my function with routine name style. For example, in command_line_processor.cc, one of the function I named is:

    void CommandLineProcessor::DefaultMsg() {
        ...
    }

Pascal type - Every name that starts with first capital letter is followed with pascal naming convention. In other word, within the name, if there exists another word, that word must start with a new first capital letter. For example, in command_line_processor.cc,

    CommandLineProcessor::CommandLineProcessor() {
        ...
    }

##File names 
- All C++ and header files are ended with .cc or .h type.
- The name of the files is set in lowercase form and separated with underscore '_'. 
- Names are clear and easy to understand with specific description to the given files. Most of the files are named with classes.
- Example from [ConvolutionFilter](classimage__tools_1_1ConvolutionFilter.html), its name "convolution_filter.cc" is pretty straight forward and its .cc file is named with lowercase and separated with underscore.

##Directory layout
- The directory layout is designed for better reconnectivity between 2 applications and the imagetools library.
- In general, PROJ is the main directory of this project.
- Handouts directory contains all the descriptive files for all projects throughout this semester.
- cmake directory contains the necessaity of maintaining the build structure of applications for this project.
- resources directory has all the .png files for testing purposes.
- docs and web directories have the documentations that runs on web browser.

##Use of whitespace, indentation and placement of braces
- All open braces must have a whitespace before them, then the content is put after them. For example, in command_line_processor.cc,

        CommandLineProcessor::CommandLineProcessor() {
            ...
        }

- 1 space is being used before the start of "public, protected, or private" and 2 spaces are added for each following member variable instead of using tabs. For example, in tool.h, 

        namespace image_tools {

        class Tool {
         ...
         protected:
          ColorData paint_color_;
         ...
        };
        } // namespace image_tools

- Indentation or \t is used to show nested conditions so that user has better readibility. No space is added in the beginning or the end of the condition statements. 1 space is added after the semicolon within the for loop. For example, in filter.cc,

        namespace image_tools {
            ...
            for (int i = 0; i < buffer->height(); i++) {
                for (int j = 0; j < buffer->width(); j++) {
                    ...
                }
            }
            ...
        }

- Blank new line is minimized unless it is used to separate between the functions.

##Line length
- In this project, the maximum number of characters for each line is 80.

\page page6 Common Tasks

##How to Add a New Filter: \n

###Instructions: \n
 
1. To add a new filter, for example, threshold, first, you have to implement a subclass of Filter called FilterThreshold. The respective files are filter_threshold.h and filter_threshold.cc. Here's the brief implementation of these two source files. \n \n

    - PROJ/src/imagetools/filter_threshold.h

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

    - PROJ/src/imagetools/filter_threshold.cc

            #include "imagetools/filter_threshold.h"
            #include "imagetools/color_data.h"
            #include "imagetools/pixel_buffer.h"

            namespace image_tools {

            FilterThreshold::FilterThreshold(float value) { value_ = value; }
            ColorData FilterThreshold::CalculateFilteredPixel(PixelBuffer* buffer, int x, int y) {
            // Implementation for filter threshold
            }

            } /* namespace image_tools */
\n
\n
2. Next, we have to add the creation of the filter threshold into ImageEditor class. In ImageEditor.cc, we have to build ApplyThresholdFilter() to make it fully functional for the applications. We just need to assign the input value into Threshold class and eventually call ApplyToBuffer() in ImageEditor.cc. Don't forget to include the header file filter_threshold.h in ImageEditor.h. \n \n

    - PROJ/src/imagetools/image_editor.h

            …
            #include "imagetools/filter_threshold.h"

            namespace image_tools {

            class ImageEditor {
            public:
            void ApplyThresholdFilter(float cutoff_value);
            };
                } /* namespace image_tools */

    - PROJ/src/imagetools/image_editor.cc

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
\n
\n
3. Finally, you have to add Threshold Button on GUI and build a setCallBack() function for the button in one of application .cc file. This will utilize nanogui. You have to add the declaration for ApplyThresholdFilter() using ImageEditor pointer and the caller itself in application .cc file. \n \n

    - PROJ/src/flashphoto/flashphoto_app.cc

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
\n
\n
4. Finally, you have to add your new filter into your mia application command. In order to do that, you must add the some functions in ImageEditorCommands and CommandLineProcessor classes.

    - PROJ/src/mia/command_line_processor.cc

            namespace image_tools {
                ...
                void CommandLineProcessor::ProcessCommandLine(int argc, std::vector<std::string> argumentv) {

                ...
                // for loop to iterate command list
                    ...
                    else if (str[i] == "-threshold") {
                        float value = 0.0;
                        try {
                            // parse the argument to float
                        }
                        catch (const std::invalid_argument& ia) {
                            // print invalid argument and print help message
                            return;
                        }

                        if (value >= 0.0 && value <= 1.0) {
                            // add the command to the vector list
                        } else {
                            // print out error
                        }
                    }
                    ...
                }
            }  // namespace image_tools

    - PROJ/src/mia/image_editor_commands.cc

            namespace image_tools {
                ...  
                // Constructor to set the cutoff value

                ThresholdFilterCommand::~ThresholdFilterCommand() {}

                void ThresholdFilterCommand::Execute() {
                    // Implements applyThresholdFilter from ImageEditor
                }

                std::string ThresholdFilterCommand::name() { return "Threshold"; }
                ...
            }  // namespace image_tools
    
    - PROJ/src/mia/image_editor_commands.h

            namespace image_tools {
                ...
                class ThresholdFilterCommand : public ImageEditorCommand {
                public:
                ThresholdFilterCommand(ImageEditor *image_editor, float cutoff);
                virtual ~ThresholdFilterCommand();

                void Execute() override;

                std::string name() override;

                private:
                float cutoff_;
                };
                ...
            }  // namespace image_tools
\n
\n
5. Run 'make clean' and 'make' again to check any errors from compiling.
\n
\n
6. Last, make sure to check the format with Google style guide using 'make check-style'
\n
\n
7. Congratulations! You made a new filter! \n
