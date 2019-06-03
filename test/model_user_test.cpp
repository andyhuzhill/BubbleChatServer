///////////////////////////////////////////////////////////
///
///     file: model_user_test.cpp
///
///   author: Andy Scout <andyhuzhill@gmail.com>
///     date: 2019/6/3
///
///////////////////////////////////////////////////////////

#include <gtest/gtest.h>

#include <iostream>
#include <memory>

#include "user.hpp"

#include "Poco/Data/Session.h"
#include "Poco/Data/Statement.h"
#include "Poco/Data/SQLite/Connector.h"

using namespace Poco::Data::Keywords;
using Poco::Data::Session;
using Poco::Data::Statement;

class UserTest: public testing::Test
{
protected:
    static void SetUpTestCase()
    {
        Poco::Data::SQLite::Connector::registerConnector();
        s = std::make_shared<Session>("SQLite", "sample.db");
    }

    static void TearDownTestCase()
    {
        s.reset();
    }

    static std::shared_ptr<Session> s;
};
std::shared_ptr<Session> UserTest::s;

TEST_F(UserTest, add_user)
{
    *s << "DROP TABLE IF EXISTS users", now;

    *s << "CREATE TABLE users("
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

    User u = {
        0,
        "Andy Scout",
        "12345",
        "67890",
        4,
        DateTime(2000, 1, 1),
        5,
        6,
        "Hello world",
        3,
        DateTime(2019, 6, 1),
        DateTime(2019, 6, 1)
    };

    Statement insertUser(*s);
    insertUser << "INSERT INTO users VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", use(u);
    auto affectedRows = insertUser.execute();

    EXPECT_NE(0, affectedRows);
}

TEST_F(UserTest, queryUser)
{
    User u;
    Statement selectUser(*s);
    selectUser << "SELECT * FROM users WHERE id = 0", into(u);
    auto affectedRows = selectUser.execute();

    EXPECT_EQ(1, affectedRows);

    EXPECT_EQ(0, u.id);
    EXPECT_STREQ("Andy Scout", u.nickName.c_str());
    EXPECT_STREQ("12345", u.hashedSaltedPasswd.c_str());
    EXPECT_STREQ("67890", u.passwdSalt.c_str());

    EXPECT_EQ(4, static_cast<int>(u.sex));
    EXPECT_EQ(2000, u.birthday.year());
    EXPECT_EQ(1, u.birthday.month());
    EXPECT_EQ(1, u.birthday.day());

    EXPECT_EQ(5, static_cast<int>(u.privacy));
    EXPECT_EQ(6, static_cast<int>(u.avatar));
    EXPECT_STREQ("Hello world", u.signature.c_str());
    EXPECT_EQ(3, static_cast<int>(u.addFriendAllowed));

    EXPECT_EQ(2019, u.registerDate.year());
    EXPECT_EQ(6, u.registerDate.month());
    EXPECT_EQ(1, u.registerDate.day());

    EXPECT_EQ(2019, u.lastLoginDateTime.year());
    EXPECT_EQ(6, u.lastLoginDateTime.month());
    EXPECT_EQ(1, u.lastLoginDateTime.day());
}

TEST_F(UserTest, deleteUser)
{
    Statement selectUser(*s);
    
    int count = 0;
    selectUser << "SELECT COUNT(*) FROM users WHERE id = 0", into(count);
    auto affectedRows = selectUser.execute();
    
    EXPECT_EQ(1, affectedRows);
    EXPECT_EQ(1, count);
    
    *s << "DELETE FROM users WHERE id = 0", now;
    
    Statement selectUser2(*s);
    selectUser2 << "SELECT COUNT(*) FROM users WHERE id = 0", into(count);
    affectedRows = selectUser2.execute();
    
    EXPECT_EQ(1, affectedRows);
    EXPECT_EQ(0, count);
}
