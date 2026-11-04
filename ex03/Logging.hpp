#ifndef LOGGING_HPP
#define LOGGING_HPP

#ifdef DEBUG_MSG
    #include <iostream>
    #define LOG(msg) std::cout << msg << std::endl
#else
    #define LOG(msg) ((void)0)
#endif

#endif