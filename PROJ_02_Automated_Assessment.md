### Assessment for Project Iteration 02 - Automated (Graded By: Dan Orban)

#### Total score: _67.47_ / _85_

Run on December 13, 08:20:03 AM.


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



+  _1_ / _1_ : Pass: Ensuring code follows style guide.



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
./build/bin/mia src/tests/inst_tests/input.png edgedetect output.png should return the help message.
iter2_test.cc:95: Failure
Value of: hasHelpMessage(getStdOutOrErr())
  Actual: false
Expected: true
./build/bin/mia src/tests/inst_tests/input.png -edgedetect 5 output.png should return the help message.</pre>




### Run Student Tests

+ Pass: Check that file "./build/test/gtests" exists.

+ Pass: Get all google tests.
    41 tests found.




#### Results

+ Pass: Check that a GoogleTest test passes.
    passes the test: FlashPhotoAppTest.GetToolTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: ConvolutionFilterEdgeTest.HasCorrectName.



+ Pass: Check that a GoogleTest test passes.
    passes the test: ConvolutionFilterEdgeTest.HasCorrectValue.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineProcessorTest.test1.



+ Fail: Check that a GoogleTest test passes.
    timeout occured: CommandLineProcessorTest.test2.
Running main() from gtest_main.cc
Note: Google Test filter = CommandLineProcessorTest.test2
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from CommandLineProcessorTest
[ RUN      ] CommandLineProcessorTest.test2




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



+ Fail: Check that a GoogleTest test passes.
    timeout occured: CommandLineProcessorTest.test8.
Running main() from gtest_main.cc
Note: Google Test filter = CommandLineProcessorTest.test8
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from CommandLineProcessorTest
[ RUN      ] CommandLineProcessorTest.test8




+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineProcessorTest.test9.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineProcessorTest.test10.



+ Fail: Check that a GoogleTest test passes.
    timeout occured: FiltersRegressionTest.test1.
Running main() from gtest_main.cc
Note: Google Test filter = FiltersRegressionTest.test1
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from FiltersRegressionTest
[ RUN      ] FiltersRegressionTest.test1




+ Fail: Check that a GoogleTest test passes.
    timeout occured: FiltersRegressionTest.test2.
Running main() from gtest_main.cc
Note: Google Test filter = FiltersRegressionTest.test2
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from FiltersRegressionTest
[ RUN      ] FiltersRegressionTest.test2




+ Fail: Check that a GoogleTest test passes.
    timeout occured: FiltersRegressionTest.test3.
Running main() from gtest_main.cc
Note: Google Test filter = FiltersRegressionTest.test3
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from FiltersRegressionTest
[ RUN      ] FiltersRegressionTest.test3




+ Pass: Check that a GoogleTest test passes.
    passes the test: FiltersRegressionTest.test4.



+ Pass: Check that a GoogleTest test passes.
    passes the test: FiltersRegressionTest.test5.



+ Pass: Check that a GoogleTest test passes.
    passes the test: FiltersRegressionTest.test6.



+ Pass: Check that a GoogleTest test passes.
    passes the test: FiltersRegressionTest.test7.



+ Fail: Check that a GoogleTest test passes.
    timeout occured: FiltersRegressionTest.test8.
Running main() from gtest_main.cc
Note: Google Test filter = FiltersRegressionTest.test8
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from FiltersRegressionTest
[ RUN      ] FiltersRegressionTest.test8




+ Pass: Check that a GoogleTest test passes.
    passes the test: FiltersRegressionTest.test9.



+ Fail: Check that a GoogleTest test passes.
    timeout occured: FiltersRegressionTest.test10.
Running main() from gtest_main.cc
Note: Google Test filter = FiltersRegressionTest.test10
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from FiltersRegressionTest
[ RUN      ] FiltersRegressionTest.test10




+ Fail: Check that a GoogleTest test passes.
    timeout occured: FiltersRegressionTest.test11.
Running main() from gtest_main.cc
Note: Google Test filter = FiltersRegressionTest.test11
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from FiltersRegressionTest
[ RUN      ] FiltersRegressionTest.test11




+ Fail: Check that a GoogleTest test passes.
    timeout occured: FiltersRegressionTest.test12.
Running main() from gtest_main.cc
Note: Google Test filter = FiltersRegressionTest.test12
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from FiltersRegressionTest
[ RUN      ] FiltersRegressionTest.test12




+ Fail: Check that a GoogleTest test passes.
    timeout occured: FiltersRegressionTest.test13.
Running main() from gtest_main.cc
Note: Google Test filter = FiltersRegressionTest.test13
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from FiltersRegressionTest
[ RUN      ] FiltersRegressionTest.test13




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



+  _11.34_ / _15_ : Fail: 75.61% of the tests passed, but the target is 100%.


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

#### Total score: _67.47_ / _85_

