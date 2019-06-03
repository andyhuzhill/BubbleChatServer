///////////////////////////////////////////////////////////
///
///     file: database.hpp
///
///   author: Andy Scout <andyhuzhill@gmail.com>
///     date: 2019/5/31
///
///////////////////////////////////////////////////////////
#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <memory>

#include "common.hpp"

#include "Poco/Data/Session.h"

using Poco::Data::Session;


namespace Bubble
{

class DataBase
{
    DISABLE_COPY(DataBase)
    
    DataBase();
public:
    static DataBase& Instance();
    
    static void initDatabase();
    
private:
    static std::shared_ptr<Session> session_;
};

} // Bubble namespace

#endif // DATABASE_HPP
