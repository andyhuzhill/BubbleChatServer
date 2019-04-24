///////////////////////////////////////////////////////////
///
///     file: bubblechatapplication.hpp
///
///   author: andy
///     date: 2019/4/24
///
///////////////////////////////////////////////////////////
#ifndef BUBBLECHATAPPLICATION_HPP
#define BUBBLECHATAPPLICATION_HPP

#include <Poco/Util/ServerApplication.h>

using Poco::Util::ServerApplication;
using Poco::Util::OptionSet;

class BubbleChatApplication
        : public ServerApplication
{
public:
    explicit BubbleChatApplication();

protected:
    void initialize(Application &self) final;

    void uninitialize() final;

    void reinitialize(Application &self) final;

    void defineOptions(OptionSet& options) final;

    void handleOption(const std::string& name, const std::string& value) final;

    int main(const std::vector<std::string>& args) final;
};

#endif // BUBBLECHATAPPLICATION_HPP
