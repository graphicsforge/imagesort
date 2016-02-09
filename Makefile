
CPP_FLAGS=-I./model-data/opencv/include/
LINK_FLAGS=-lopencv_core -lopencv_imgproc -lopencv_imgcodecs -lopencv_highgui -lopencv_video -lopencv_ml

default: rtree

rtree:
	g++ src/rtree.cpp -o build/rtree ${CPP_FLAGS} ${LINK_FLAGS}

