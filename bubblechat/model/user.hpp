///////////////////////////////////////////////////////////
///
///     file: user.hpp
///
///   author: Andy Scout <andyhuzhill@gmail.com>
///     date: 2019/6/3
///
///////////////////////////////////////////////////////////
#ifndef USER_HPP
#define USER_HPP

#include <iostream>

#include "common.hpp"

#include "Poco/Data/TypeHandler.h"
#include "Poco/DateTimeFormatter.h"

#include <string>

using Poco::DateTime;
using Poco::DateTimeFormatter;

struct User {
    std::uint32_t id;
    std::string nickName;
    std::string hashedSaltedPasswd;
    std::string passwdSalt;

    std::uint8_t sex;   ///< 0: secret 1: male 2: female
    DateTime birthday;
    std::uint8_t privacy; ///< 0: allow any one see infos 1: only friends can see infos 2: keep information secrect

    std::uint8_t avatar; ///< 0: default 255: user defined
    std::string signature;
    std::uint8_t addFriendAllowed; ///< 0: allow 1: disable

    DateTime registerDate;
    DateTime lastLoginDateTime;
};

namespace Poco
{
namespace Data
{

template<>
class TypeHandler<User>
{
public:
    static std::size_t size()
    {
        return 12;
    }

    static void bind(std::size_t pos, const User &user, AbstractBinder::Ptr pBinder, AbstractBinder::Direction dir)
    {
        std::cout << "bind " << std::endl;
        TypeHandler<std::uint32_t>::bind(pos++, user.id, pBinder, dir);
        TypeHandler<std::string>::bind(pos++, user.nickName, pBinder, dir);
        TypeHandler<std::string>::bind(pos++, user.hashedSaltedPasswd, pBinder, dir);
        TypeHandler<std::string>::bind(pos++, user.passwdSalt, pBinder, dir);
        
        TypeHandler<std::uint8_t>::bind(pos++, user.sex, pBinder, dir);
        TypeHandler<DateTime>::bind(pos++, user.birthday, pBinder, dir);
        TypeHandler<std::uint8_t>::bind(pos++, user.privacy, pBinder, dir);
        
        TypeHandler<std::uint8_t>::bind(pos++, user.avatar, pBinder, dir);
        TypeHandler<std::string>::bind(pos++, user.signature, pBinder, dir);
        TypeHandler<std::uint8_t>::bind(pos++, user.addFriendAllowed, pBinder, dir);
        
        TypeHandler<DateTime>::bind(pos++, user.registerDate, pBinder, dir);
        TypeHandler<DateTime>::bind(pos++, user.lastLoginDateTime, pBinder, dir);
    }

    static void extract(std::size_t pos, User &user, const User &deflt, AbstractExtractor::Ptr pExtr)
    {
        TypeHandler<std::uint32_t>::extract(pos++, user.id, deflt.id, pExtr);
        TypeHandler<std::string>::extract(pos++, user.nickName, deflt.nickName, pExtr);
        TypeHandler<std::string>::extract(pos++, user.hashedSaltedPasswd, deflt.hashedSaltedPasswd, pExtr);
        TypeHandler<std::string>::extract(pos++, user.passwdSalt, deflt.passwdSalt, pExtr);
        
        TypeHandler<std::uint8_t>::extract(pos++, user.sex, deflt.sex, pExtr);
        TypeHandler<DateTime>::extract(pos++, user.birthday, deflt.birthday, pExtr);
        TypeHandler<std::uint8_t>::extract(pos++, user.privacy, deflt.privacy, pExtr);
        
        TypeHandler<std::uint8_t>::extract(pos++, user.avatar, deflt.avatar, pExtr);
        TypeHandler<std::string>::extract(pos++, user.signature, deflt.signature, pExtr);
        TypeHandler<std::uint8_t>::extract(pos++, user.addFriendAllowed, deflt.addFriendAllowed, pExtr);
        
        TypeHandler<DateTime>::extract(pos++, user.registerDate, deflt.registerDate, pExtr);
        TypeHandler<DateTime>::extract(pos++, user.lastLoginDateTime, deflt.lastLoginDateTime, pExtr);
    }

    static void prepare(std::size_t pos, const User &user, AbstractPreparator::Ptr pPrep)
    {
        TypeHandler<std::uint32_t>::prepare(pos++, user.id, pPrep);
        TypeHandler<std::string>::prepare(pos++, user.nickName, pPrep);
        TypeHandler<std::string>::prepare(pos++, user.hashedSaltedPasswd, pPrep);
        TypeHandler<std::string>::prepare(pos++, user.passwdSalt, pPrep);
        
        TypeHandler<std::uint8_t>::prepare(pos++, user.sex, pPrep);
        TypeHandler<DateTime>::prepare(pos++, user.birthday, pPrep);
        TypeHandler<std::uint8_t>::prepare(pos++, user.privacy, pPrep);
        
        TypeHandler<std::uint8_t>::prepare(pos++, user.avatar, pPrep);
        TypeHandler<std::string>::prepare(pos++, user.signature, pPrep);
        TypeHandler<std::uint8_t>::prepare(pos++, user.addFriendAllowed, pPrep);
        
        TypeHandler<DateTime>::prepare(pos++, user.registerDate, pPrep);
        TypeHandler<DateTime>::prepare(pos++, user.lastLoginDateTime, pPrep);
    }
};

} // namespace Data
} // namespace Poco

#endif // USER_HPP
