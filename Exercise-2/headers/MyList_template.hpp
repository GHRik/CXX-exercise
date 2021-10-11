#include "MyList.hpp"
#include "../src/MyList.cpp"  // it is included because templates
                             // must be in same file. Templates
                            // can NOT be separate on two files.
                            // Separate provides to compilation
                            // error with "reference not found".
