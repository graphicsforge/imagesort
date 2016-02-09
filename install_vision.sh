
sudo apt-get update

# install potrace
sudo apt-get install -y potrace

# install imagemagick
sudo apt-get install -y git imagemagick

# install blender
sudo apt-get install -y blender

# install opencv
sudo apt-get install -y git make cmake g++
if [ ! -d "./opencv" ]; then
  git clone --depth 1 https://github.com/Itseez/opencv.git
  mkdir -p ./opencv/build
  cd opencv/build
  cmake ../
  make -j 2
  sudo make install
  cd ../..
fi

# install caffe
sudo apt-get install -y libprotobuf-dev protobuf-compiler protobuf-c-compiler libboost-all-dev libhdf5-dev liblmdb-dev libleveldb-dev libsnappy-dev libatlas-base-dev
if [ ! -d "./caffe" ]; then
  git clone --depth 1 https://github.com/BVLC/caffe.git
  mkdir -p ./caffe/build
  cd caffe/build
  cmake ../
  make -j 2
  sudo make install
  cd ../..
fi

# update dynamic linker
sudo ldconfig

mkdir -p ./build

