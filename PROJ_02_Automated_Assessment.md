### Assessment for Project Iteration 02 - Automated (Graded By: Dan Orban)

#### Total score: _70.13_ / _85_

Run on December 16, 01:22:01 AM.


#### System Files and PROJ Directory Structure

+ Pass: Check that directory "/classes/grades/Fall-2018/csci3081/dtorban/grading-scripts/_proj_materials" exists.

+ Pass: Setup grading environment.



+  _3_ / _3_ : Pass: Check that directory "PROJ" exists.

+  _2_ / _2_ : Pass: Check that directory "PROJ/src/imagetools" exists.

+  _2_ / _2_ : Pass: Check that file "PROJ/src/imagetools/color_data.h" exists.

+  _2_ / _2_ : Pass: Check that file "PROJ/src/imagetools/Makefile" exists.


#### Set up cpplint

+ Pass: Copy directory "cpplint".



+ Pass: Check that directory "cpplint" exists.


#### Set up Project

+ Pass: Change into directory "PROJ".

+ Pass: Setup grading environment.



+  _0_ / _1_ : Fail: Ensuring code follows style guide.

<pre>cd src/flashphoto; make check-style
make[1]: Entering directory '/classes/grades/Fall-2018/csci3081/dtorban/grading-scripts/grading/PROJ_02_Automated_Assessment/repo-ongxx107/PROJ/src/flashphoto'
==== Checking style is correct ====
/classes/grades/Fall-2018/csci3081/dtorban/grading-scripts/grading/PROJ_02_Automated_Assessment/repo-ongxx107/cpplint/cpplint.py --root=.. *.cc *.h
Done processing flashphoto_app.cc
Done processing main.cc
Done processing flashphoto_app.h
Total errors found: 0
make[1]: Leaving directory '/classes/grades/Fall-2018/csci3081/dtorban/grading-scripts/grading/PROJ_02_Automated_Assessment/repo-ongxx107/PROJ/src/flashphoto'
cd src/imagetools; make check-style
make[1]: Entering directory '/classes/grades/Fall-2018/csci3081/dtorban/grading-scripts/grading/PROJ_02_Automated_Assessment/repo-ongxx107/PROJ/src/imagetools'
==== Checking style is correct ====
/classes/grades/Fall-2018/csci3081/dtorban/grading-scripts/grading/PROJ_02_Automated_Assessment/repo-ongxx107/cpplint/cpplint.py --root=.. *.cc *.h
Done processing color_data.cc
Done processing convolution_filter_blur.cc
Done processing convolution_filter.cc
Done processing convolution_filter_edge.cc
Done processing convolution_filter_motion_blur.cc
Done processing convolution_filter_sharpen.cc
Done processing filter.cc
Done processing filter_channels.cc
Done processing filter_quantize.cc
Done processing filter_saturate.cc
Done processing filter_threshold.cc
Done processing float_matrix.cc
Done processing image_editor.cc
Done processing mask_factory.cc
Done processing pixel_buffer.cc
Done processing tool_blur.cc
Done processing tool_calligraphy_pen.cc
Done processing tool.cc
Done processing tool_chalk.cc
Done processing tool_eraser.cc
Done processing tool_highlighter.cc
Done processing tool_pen.cc
Done processing tool_spray_can.cc
Done processing tool_stamp.cc
Done processing color_data.h
Done processing convolution_filter_blur.h
Done processing convolution_filter_edge.h
Done processing convolution_filter.h
Done processing convolution_filter_motion_blur.h
Done processing convolution_filter_sharpen.h
Done processing filter_channels.h
Done processing filter.h
Done processing filter_quantize.h
Done processing filter_saturate.h
Done processing filter_threshold.h
Done processing float_matrix.h
Done processing image_editor.h
Done processing image_tools_math.h
Done processing mask_factory.h
Done processing pixel_buffer.h
Done processing tool_blur.h
Done processing tool_calligraphy_pen.h
Done processing tool_chalk.h
Done processing tool_eraser.h
Done processing tool.h
Done processing tool_highlighter.h
Done processing tool_pen.h
Done processing tool_spray_can.h
Done processing tool_stamp.h
Total errors found: 0
make[1]: Leaving directory '/classes/grades/Fall-2018/csci3081/dtorban/grading-scripts/grading/PROJ_02_Automated_Assessment/repo-ongxx107/PROJ/src/imagetools'
cd src/mia; make check-style
make[1]: Entering directory '/classes/grades/Fall-2018/csci3081/dtorban/grading-scripts/grading/PROJ_02_Automated_Assessment/repo-ongxx107/PROJ/src/mia'
==== Checking style is correct ====
/classes/grades/Fall-2018/csci3081/dtorban/grading-scripts/grading/PROJ_02_Automated_Assessment/repo-ongxx107/cpplint/cpplint.py --root=.. *.cc *.h
Done processing command_line_processor.cc
Done processing image_editor_commands.cc
Done processing main.cc
Done processing mia_app.cc
Done processing command_line_processor.h
Done processing image_editor_commands.h
Done processing mia_app.h
Total errors found: 0
make[1]: Leaving directory '/classes/grades/Fall-2018/csci3081/dtorban/grading-scripts/grading/PROJ_02_Automated_Assessment/repo-ongxx107/PROJ/src/mia'
cd src/tests; make check-style
make[1]: Entering directory '/classes/grades/Fall-2018/csci3081/dtorban/grading-scripts/grading/PROJ_02_Automated_Assessment/repo-ongxx107/PROJ/src/tests'
cd gtests; make check-style
make[2]: Entering directory '/classes/grades/Fall-2018/csci3081/dtorban/grading-scripts/grading/PROJ_02_Automated_Assessment/repo-ongxx107/PROJ/src/tests/gtests'
==== Checking style is correct ====
/classes/grades/Fall-2018/csci3081/dtorban/grading-scripts/grading/PROJ_02_Automated_Assessment/repo-ongxx107/cpplint/cpplint.py --root=.. *.cc *.h
command_line_processor_unittest.cc:32:  Consider using EXPECT_NE instead of EXPECT_TRUE(a != b)  [readability/check] [2]
command_line_processor_unittest.cc:33:  Should have a space between // and comment  [whitespace/comments] [4]
command_line_processor_unittest.cc:135:  Consider using EXPECT_EQ instead of EXPECT_TRUE(a == b)  [readability/check] [2]
Skipping input '*.h': Can't open for reading
Done processing command_line_processor_unittest.cc
Done processing convolution_filter_edge_unittest.cc
Done processing filter_channel_unittest.cc
Done processing filters_regressiontest.cc
Done processing flashphoto_app_test.cc
Done processing tool_pen_unittest.cc
Done processing tools_regressiontest.cc
Total errors found: 3
Makefile:179: recipe for target 'check-style' failed
make[2]: *** [check-style] Error 1
make[2]: Leaving directory '/classes/grades/Fall-2018/csci3081/dtorban/grading-scripts/grading/PROJ_02_Automated_Assessment/repo-ongxx107/PROJ/src/tests/gtests'
Makefile:6: recipe for target 'check-style' failed
make[1]: *** [check-style] Error 2
make[1]: Leaving directory '/classes/grades/Fall-2018/csci3081/dtorban/grading-scripts/grading/PROJ_02_Automated_Assessment/repo-ongxx107/PROJ/src/tests'
Makefile:7: recipe for target 'check-style' failed
make: *** [check-style] Error 2
</pre>



+  _25_ / _25_ : Pass: Check that make compiles.



+  _3_ / _3_ : Pass: Check that file "./build/lib/libimagetools.a" exists.

+  _3_ / _3_ : Pass: Check that file "./build/bin/flashphoto" exists.

+  _3_ / _3_ : Pass: Check that file "./build/bin/mia" exists.

+  _3_ / _3_ : Pass: Check that file "./build/test/gtests" exists.


### Instructor Tests

+ Pass: Change into directory "src/tests/inst_tests".

+ Pass: Check that make compiles.



+ Pass: Change into directory "../../..".

+ Pass: Check that file "./build/test/inst_tests" exists.


#### Testing ImageIO Implementation

+  _2_ / _2_ : Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.ImageLoadingAndSaving.




#### Testing MIA Application

+  _1_ / _1_ : Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.StampToolAdded.



+  _1_ / _1_ : Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.DisplayHelpMessage.



+  _2_ / _2_ : Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.MiaCommandLineCorrect.



+  _0_ / _2_ : Fail: Check that a GoogleTest test passes.
    fails the test: Iteration2Test.MiaCommandLineBadInput.
<pre>
[ RUN      ] Iteration2Test.MiaCommandLineBadInput
iter2_test.cc:95: Failure
Value of: hasHelpMessage(getStdOutOrErr())
  Actual: false
Expected: true
./build/bin/mia src/tests/inst_tests/input.png edgedetect output.png should return the help message.</pre>




### Run Student Tests

+ Pass: Check that file "./build/test/gtests" exists.

+ Pass: Get all google tests.
    42 tests found.




#### Results

+ Pass: Check that a GoogleTest test passes.
    passes the test: FlashPhotoAppTest.GetToolTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: ConvolutionFilterEdgeTest.HasCorrectName.



+ Pass: Check that a GoogleTest test passes.
    passes the test: ConvolutionFilterEdgeTest.HasCorrectValue.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineProcessorTest.test1.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineProcessorTest.test2.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineProcessorTest.test3.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineProcessorTest.test4.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineProcessorTest.test5.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineProcessorTest.test6.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineProcessorTest.test7.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineProcessorTest.test8.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineProcessorTest.test9.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineProcessorTest.test10.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineProcessorTest.test11.



+ Pass: Check that a GoogleTest test passes.
    passes the test: FiltersRegressionTest.test1.



+ Pass: Check that a GoogleTest test passes.
    passes the test: FiltersRegressionTest.test2.



+ Pass: Check that a GoogleTest test passes.
    passes the test: FiltersRegressionTest.test3.



+ Pass: Check that a GoogleTest test passes.
    passes the test: FiltersRegressionTest.test4.



+ Pass: Check that a GoogleTest test passes.
    passes the test: FiltersRegressionTest.test5.



+ Pass: Check that a GoogleTest test passes.
    passes the test: FiltersRegressionTest.test6.



+ Pass: Check that a GoogleTest test passes.
    passes the test: FiltersRegressionTest.test7.



+ Pass: Check that a GoogleTest test passes.
    passes the test: FiltersRegressionTest.test8.



+ Pass: Check that a GoogleTest test passes.
    passes the test: FiltersRegressionTest.test9.



+ Pass: Check that a GoogleTest test passes.
    passes the test: FiltersRegressionTest.test10.



+ Pass: Check that a GoogleTest test passes.
    passes the test: FiltersRegressionTest.test11.



+ Pass: Check that a GoogleTest test passes.
    passes the test: FiltersRegressionTest.test12.



+ Pass: Check that a GoogleTest test passes.
    passes the test: FiltersRegressionTest.test13.



+ Pass: Check that a GoogleTest test passes.
    passes the test: ToolsRegressionTest.test1.



+ Pass: Check that a GoogleTest test passes.
    passes the test: ToolsRegressionTest.test2.



+ Pass: Check that a GoogleTest test passes.
    passes the test: ToolsRegressionTest.test3.



+ Pass: Check that a GoogleTest test passes.
    passes the test: ToolsRegressionTest.test4.



+ Pass: Check that a GoogleTest test passes.
    passes the test: ToolsRegressionTest.test5.



+ Pass: Check that a GoogleTest test passes.
    passes the test: ToolsRegressionTest.test6.



+ Pass: Check that a GoogleTest test passes.
    passes the test: ToolsRegressionTest.test7.



+ Pass: Check that a GoogleTest test passes.
    passes the test: ToolsRegressionTest.test8.



+ Pass: Check that a GoogleTest test passes.
    passes the test: ToolPenTest.HasCorrectName.



+ Pass: Check that a GoogleTest test passes.
    passes the test: ToolPenTest.HasCorrectDimensionSize.



+ Pass: Check that a GoogleTest test passes.
    passes the test: FilterChannelsTest.HasCorrectNames.



+ Pass: Check that a GoogleTest test passes.
    passes the test: FilterChannelsTest.HasCorrectValue1.



+ Pass: Check that a GoogleTest test passes.
    passes the test: FilterChannelsTest.HasCorrectDimensionSize1.



+ Pass: Check that a GoogleTest test passes.
    passes the test: FilterChannelsTest.HasCorrectValue2.



+ Pass: Check that a GoogleTest test passes.
    passes the test: FilterChannelsTest.HasCorrectDimensionSize2.



+  _15_ / _15_ : Pass: 100% of the tests passed.


### Testing Mutants


#### Testing Pen Tool for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - There is no regression test.


#### Testing Eraser Tool for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - There is no regression test.


#### Testing Stamp Tool for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - The stamp tool does not stamp, it slides.


#### Testing Blur Filter for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - In Mutant: The radius is 2 less than it is supposed to be.


#### Testing Edge Detector Filter for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - In Mutant: Edge detect is not implemented.


#### Testing Image IO Implementaiton for failure

+ Pass: At least one test failed for Image IO Implementaiton


#### Results

+  _3.13_ / _15_ : Fail: 16.67% of the tests passed, but the target is 80.0%.

#### Total score: _70.13_ / _85_

