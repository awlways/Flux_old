#ifndef __PREDICTOR__
#define __PREDICTOR__
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

union Entry {
  int missing;
  float fvalue;
};

float predict_margin(union Entry* data);

#endif