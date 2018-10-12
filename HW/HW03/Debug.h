//  Copyright (c) 2018 CCSI3081. All rights reserved.

#ifndef HW03_DEBUG_H_
#define HW03_DEBUG_H_

#include <cstdlib>

#define DEBUG 0

#define assert(e) if (!(e)) {             \
     cout << "Invariant \"" << #e         \
          << "\" on line "                \
          << __LINE__ << " fails.\n"  ;   \
     exit(1) ;}

#endif  // HW03_DEBUG_H_
