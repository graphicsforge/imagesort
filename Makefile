
CPP_FLAGS=-I./model-data/opencv/include/
LINK_FLAGS=-lopencv_core -lopencv_imgproc -lopencv_imgcodecs -lopencv_highgui -lopencv_video -lopencv_ml -lopencv_features2d

default: train

train:
	g++ src/train.cpp -o build/train ${CPP_FLAGS} ${LINK_FLAGS}

rtree:
	g++ src/rtree.cpp -o build/rtree ${CPP_FLAGS} ${LINK_FLAGS}

