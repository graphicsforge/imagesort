#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <iostream>
#include <getopt.h> // getopt_long
#include <stdlib.h> // abs


using namespace cv;
using namespace std;

char* debug_filename_prepend = (char*)"";

// sum the diff between two mats of same dims
uint64_t diff( Mat a, Mat b )
{
  Mat diff;
  absdiff( a, b, diff );
  return sum( diff ).val[0];
}


void usage() {
  fprintf( stdout, "Usage: train [OPTIONS]\n");
  fprintf( stdout, "  --input [input image]\n" );
}

int main( int argc, char** argv )
{
  char* input_path;
  char* register_path;
  char* mask_path = (char*)"bottom_mask.png";

  // parse command line options
  int option_index = 0;
  int c;
  static struct option long_options[] = {
      {"input", required_argument, 0, 'i'},
      {"debug", required_argument, 0, 'd'},
      {"help", no_argument, 0, 'h'},
      {0, 0, 0, 0}
  };
  while (1) {
    c = getopt_long(argc, argv, "i:d:h", long_options, &option_index);
    if (c == -1)
      break;
    switch (c) {
      case 'i':
        input_path = optarg;
        break;
      case 'd':
        debug_filename_prepend = optarg;
        break;
      case 'h':
      case '?':
          usage();
          return 0;
        break;
    }
  }

  Mat input_image;
  Mat debug_image;

  Mat warp;

  Mat debug_output;
  char debug_path[128];

  input_image = imread(input_path, CV_LOAD_IMAGE_COLOR);
  if ( !input_image.data ) {
    fprintf(stderr, "could not open input image %s\n", input_path);
    return -1;
  }

  cvtColor(input_image, input_image, CV_BGR2GRAY);

  snprintf(debug_path, 128, "%s_input.jpg", debug_filename_prepend);
  imwrite(debug_path, input_image);

  vector<KeyPoint> keypoints;

  Ptr<FastFeatureDetector> fast = FastFeatureDetector::create();
  fast->detect(input_image, keypoints);

  drawKeypoints(input_image, keypoints, debug_image);

  snprintf(debug_path, 128, "%s_detectedfeatures.jpg", debug_filename_prepend);
  imwrite(debug_path, debug_image);

  return 0;
}

