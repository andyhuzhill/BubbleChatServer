///////////////////////////////////////////////////////////
///
///     file: database.cpp
///
///   author: Andy Scout <andyhuzhill@gmail.com>
///     date: 2019/5/31
///
///////////////////////////////////////////////////////////
#include "database.hpp"

#include <Poco/Data/Session.h>
#include <Poco/Data/Statement.h>
#include <Poco/Data/Connector.h>

#include <Poco/Data/MySQL/Connector.h>
#include <Poco/Data/SQLite/Connector.h>

#include "user.hpp"

using namespace Poco::Data::Keywords;
using Poco::Data::Session;
using Poco::Data::Statement;

using namespace Bubble;

DataBase::DataBase()
{
    Poco::Data::MySQL::Connector::registerConnector();
    Poco::Data::SQLite::Connector::registerConnector();
}

DataBase &DataBase::Instance()
{
    static DataBase db;

    return db;
}

std::shared_ptr<Session> DataBase::session_;

void DataBase::initDatabase()
{
    session_ = std::make_shared<Session>("SQLite", "sample.db");

    *session_ << "DROP TABLE IF EXISTS User", now;

    *session_ << "CREATE TABLE users("
              "id INTEGER PRIMARY KEY NOT NULL,"
              "nickName TEXT NOT NULL,"
              "hashedSaltedPasswd TEXT NOT NULL,"
              "passwdSalt TEXT NOT NULL,"
              "sex INTEGER,"
              "birthday DATETIME,"
              "privacy INTEGER,"
              "avatar INTEGER,"
              "signature TEXT,"
              "addFriendAllowed INTEGER,"
              "registerDate DATETIME,"
              "lastLoginDateTime DATETIME"
              ")", now;
}
