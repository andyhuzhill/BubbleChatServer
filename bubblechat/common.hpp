///////////////////////////////////////////////////////////
///
///     file: common.hpp
///
///   author: Andy Scout <andyhuzhill@gmail.com>
///     date: 2019/6/3
///
///////////////////////////////////////////////////////////
#ifndef COMMON_HPP
#define COMMON_HPP

#include <cstdint>


#define DISABLE_COPY(Class)                                                    \
    Class(const Class& other) = delete;                                        \
    Class operator=(const Class& other) = delete;


#endif // COMMON_HPP
