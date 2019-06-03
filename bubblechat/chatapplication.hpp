///////////////////////////////////////////////////////////
///
///     file: chatapplication.hpp
///
///   author: Andy Scout <andyhuzhill@gmail.com>
///     date: 2019/4/24
///
///////////////////////////////////////////////////////////
#ifndef CHATAPPLICATION_HPP
#define CHATAPPLICATION_HPP

#include <Poco/Util/ServerApplication.h>

using Poco::Util::ServerApplication;
using Poco::Util::OptionSet;

namespace Bubble {

class ChatApplication
        : public ServerApplication
{
public:
    ChatApplication() = default;

protected:
    void initialize(Application &self) final;

    void uninitialize() final;

    void reinitialize(Application &self) final;

    void defineOptions(OptionSet& options) final;

    void handleOption(const std::string& name, const std::string& value) final;

    int main(const std::vector<std::string>& args) final;
    
private:
    bool _helpRequested = false;
    
    void displayHelp();
};

} // Bubble namespace

#endif // BUBBLECHATAPPLICATION_HPP
