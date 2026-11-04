#ifndef LOGGING_HPP
#define LOGGING_HPP

#ifdef DBG
    #include <iostream>
    #define LOG(msg) std::cout << msg << std::endl
#else
    #define LOG(msg) ((void)0)
#endif

#endif