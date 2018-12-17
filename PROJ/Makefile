all: imagetools flashphoto mia tests doc

doc:
	doxygen docs/Doxyfile

check-style:
	cd src/flashphoto; make check-style
	cd src/imagetools; make check-style
	cd src/mia; make check-style
	cd src/tests; make check-style

check-style-cse:
	cd src/flashphoto; make check-style-cse
	cd src/imagetools; make check-style-cse
	cd src/mia; make check-style-cse
	cd src/tests; make check-style-cse

flashphoto:
	cd src/flashphoto; make -j

mia:
	cd src/mia; make -j

imagetools:
	cd src/imagetools; make -j

tests:
	cd src/tests; make -j

clean:
	rm -rf build
	rm -rf web/doxygen-html

clobber: clean
	cd src/external/MinGfx; make clobber
	cd src/external/googletest; make clean
