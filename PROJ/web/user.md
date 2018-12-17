
##User 
- \subpage page1 \n \n
- \subpage page2 \n \n

\page page1 Getting Started with FlashPhoto

##Introduction: \n
FlashPhoto is an application that allows users to load any image, draw anything using a tool, filter the image, and eventually has the feature of saving final product of the image. For the Graphic User Interface(GUI), we used Mingfx as the base support of displaying user interface. FlashPhoto only supports PNG image which means it could only load and save one type of image file. \n
\n
In FlashPhoto application, there are 6 different tools and 8 different filters you could choose to use. \n \n
**Tools:** \n
    • Pen - This tool is designed to look like a pen. It makes an opaque, circular mark with constant intensity. This means that when the pen is applied to the canvas the digital ink from the pen completely covers any color that had previously been applied to the canvas at that position. The color of the pen can be set interactively using the GUI. \n
    ![](./pen.png) 
    \image html pen.png
    • Calligraphy Pen - This tool is designed to look like a calligraphy pen. It works almost the same way as the Pen tool. Like the Pen tool, it is completely opaque and it covers up any “paint” that was already applied to the canvas. However, the difference with the Calligraphy Pen is that the mask is an oval tilted at a 30-degree angle. The color of the highlighter can be set interactively using the GUI. \n

    • Chalk - This tool is designed to look like a piece of chalk dragged across a bumpy surface. It has a circular mask, but about 40% of the pixels within the circle are randomly chosen to be completely transparent. This creates the bumpy effect. The chalk color can be set interactively using the GUI. \n
    • Highlighter - This tool is designed to look like a highlighter marker. It uses an oval mask similar to the Calligraphy Pen, but the oval is oriented vertically, and the intensity of the mask is set to make the mark semi-transparent. The color applied to the canvas is approximately 40% the color of the highlighter and 60% whatever color is already on the canvas; however, a special color blending function is used for the highlighter so that dark colors show through more than light colors. The color of the highlighter’s ink can be set interactively using the GUI. \n
    • Spray Can - This tool is designed to mimic the look of paint from a spray can. It uses a special mask that is circular in shape but has a linear falloff to mimic the dispersion of color from the spray. The intensity is strongest at the center pixel and falls off linearly to zero intensity as it gets closer to the edge of the circle. The specific paint color can be set interactively using the GUI. \n
    • Blur - 
    
    • Eraser - This tool erases the digital canvas and returns it to its original background color. It has a circular mask, and eraser’s color cannot be changed through the GUI because there is currently no user interface for changing the canvas background color. \n
\n
(*Note: Each tool’s size could be set manually using the GUI.*) \n
\n \n
**Filters:** \n
    • Threshold - This filter is designed to make the image turning black and white (a.k.a.) binary image. It rounds up the color channels to the maximum value, 1.0 which is white or minimum value, 0.0 which is black. \n
    • Saturation - This filter is designed to change the colorfulness of the image. The image has either less color or more color filled with possible color channels. \n
    • Channels - This filter is designed to independently scale up or down the intensity of each color channel (red, green, and blue). \n
    • Quantize - This filter is designed to reduce the number of colors in the image by binning. For example, if the input is 4 bins, there will only be 4 possible intensity values for each color channel, spaced evenly: 0%, 33%, 66%, and 100%. Adjust each color channel value R, G, and B to put it into 6 the nearest bin. \n
    • Blur - This filter is designed to use a Gaussian Blur image convolution kernel to blur the image in proportion to the input amount specified in the GUI. \n
    • Motion Blur - This filter is designed to blur the image by convolving the image with an appropriate motion-blurring kernel. It has four possible blurring directions (North-to-South, East-to-West, Northeast-to-Southwest, and Northwest-to-Southeast) and blur according to the amount specified in the GUI. \n
    • Sharpen - This filter is designed to sharpen the image (increase the visibility of the edges of shapes) in proportion to the amount specified in the GUI by convolving the image with an appropriate sharpening kernel. \n
    • Edge Detection - This filter is designed to transform the image into one that only shows the edges of shapes by convolving 7 it with a 3x3 edge detection kernel. Thus, the pixels on the border of differently colored regions will be bright, while pixels in areas of low change will be dark. \n
\n
(*sourced from iteration1.pdf in handouts directory*) \n

\page page2 Getting Started with Mia

##Introduction: \n
Medical Imaging Assistant(MIA) is a very similar application to FlashPhoto but it is used for medical purpose. MIA does not have many features as FlashPhoto but it has most of the filters, a red pen tool and a marker tool for users. With these features, it is a good program for doing medical record. MIA provides GUI and Command Line Interface. GUI provides all filters and tools functionality whereas the Command Line Interface provides the user to edit their photos with filters only using specific command line. MIA only supports PNG image which means it could only load and save one type of image file. \n
\n
In MIA application, the features are almost the same as FlashPhoto. However, they have 2 tools and 5 filters only in GUI whereas there are all filters in Command Line interface. \n
\n
In GUI, 
    there is a new tool called:
        • Stamp - A tool that stamps a bullseye pattern, one circle inside another, that clinicians can use to mark important areas on the image. \n
    
    there are load and save feature.

In Command Line Interface, there would be a help message popping out from command terminal for the first time user. Generally, there are 1 input and 1 output filename required in front and back command line. Between the input and outfile line, user has the option to fill in any image processing commands to filter the input image file. There are 13 commands that user could manually enter the
        • 



        <!-- 
            cout << "usage: mia infile.png [image processing commands ...] outfile.png";
            cout << endl;
            cout << "infile.png:           input image file in png format" << endl;
            cout << "outfile.png:          filename to use for saving the result";
            cout << endl;
            cout << "image processing commands:" << endl;
            cout << "-blur r:              apply a gaussian blur of radius r ";
            cout << endl;
            cout << "-edgedetect:          apply an edge detection filter" << endl;
            cout << "-sharpen r:           apply a sharpening filter of radius r";
            cout << endl;
            cout << "-red s:               scale the red channel by factor s" << endl;
            cout << "-green s:             scale the green channel by factor s" << endl;
            cout << "-blue s:              scale the blue channel by factor s" << endl;
            cout << "-quantize n:          quantize each color channel into n bins";
            cout << endl;
            cout << "-saturate s:          saturate colors by scale factor s" << endl;
            cout << "-threshold c:         threshold using cutoff value c" << endl;
            cout << "-motionblur-n-s r:    north-south motion blur with kernel radius r";
            cout << endl;
            cout << "-motionblur-e-w r:    east-west motion blur with kernel radius r";
            cout << endl;
            cout << "-motionblur-ne-sw r:  ne-sw motion blur with kernel radius r";
            cout << endl;
            cout << "-motionblur-nw-se r:  nw-se motion blur with kernel radius r";
        
        • Pen – Similar to the one in FlashPhoto application. It works like a pen. It makes an opaque, circular mark with constant intensity. This means that when the pen is applied to the canvas the digital ink from the pen completely covers any color that had previously been applied to the canvas at that position. The color of the pen can be set interactively using the GUI. \n \n

    **Filters:** \n
        • Blur - Similar to the one in FlashPhoto application. This filter is designed to use a Gaussian Blur image convolution kernel to blur the image in proportion to the input amount specified in the GUI. \n
        • Sharpen - Similar to the one in FlashPhoto application. This filter is designed to sharpen the image (increase the visibility of the edges of shapes) in proportion to the amount specified in the GUI by convolving the image with an appropriate sharpening kernel. \n
        • Edge Detection - Similar to the one in FlashPhoto application. This filter is designed to transform the image into one that only shows the edges of shapes by convolving 7 it with a 3x3 edge detection kernel. Thus, the pixels on the border of differently colored regions will be bright, while pixels in areas of low change will be dark. \n
        • Threshold - Similar to the one in FlashPhoto application. This filter is designed to make the image turning black and white (a.k.a.) binary image. It rounds up the color channels to the maximum value, 1.0 which is white or minimum value, 0.0 which is black. \n
        • Quantize - Similar to the one in FlashPhoto application. This filter is designed to reduce the number of colors in the image by binning. For example, if the input is 4 bins, there will only be 4 possible intensity values for each color channel, spaced evenly: 0%, 33%, 66%, and 100%. Adjust each color channel value R, G, and B to put it into 6 the nearest bin. \n -->
\n
(*sourced from iteration1.pdf and iteration2.pdf in handouts directory*) \n