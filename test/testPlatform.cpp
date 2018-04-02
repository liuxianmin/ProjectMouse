#include <iostream>

int main()
{
  char message[256]="Hello World";
#ifdef _WIN32
  //define something for Windows (32-bit and 64-bit, this part is common)
  strcpy(message+11,"::WINDOWS");
  #ifdef _WIN64
    //define something for Windows (64-bit only)
    strcpy(message+20,"::WIN64");
  #else
    //define something for Windows (32-bit only)
    strcpy(message+20,"::WIN32");
  #endif
#elif __APPLE__
  strcpy(message+11,"::_APPLE_");
  #include "TargetConditionals.h"
  #if TARGET_IPHONE_SIMULATOR
    // iOS Simulator
    strcpy(message+20,"::IOS_SIMULATOR");
  #elif TARGET_OS_IPHONE
    // iOS device
    strcpy(message+20,"::IPHONE");
  #elif TARGET_OS_MAC
    // Other kinds of Mac OS
    strcpy(message+20,"::MAC");
  #else
    #error "Unknown Apple platform"
  #endif
#elif __ANDROID__
  // android
  strcpy(message+11,"::ANDROID");
#elif __linux__
  // linux
  strcpy(message+11,"::_LINUX_");
#elif __unix__ // all unices not caught above
  // Unix
  strcpy(message+11,"::_UINX__");
#elif defined(_POSIX_VERSION)
  // POSIX
  strcpy(message+11,"::_POSIX_");
#else
  #error "Unknown compiler"
#endif
    std::cout<<message<<std::endl;
	return 1;
}
