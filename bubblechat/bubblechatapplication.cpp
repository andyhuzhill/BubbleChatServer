///////////////////////////////////////////////////////////
///
///     file: bubblechatapplication.cpp
///
///   author: andy
///     date: 2019/4/24
///
///////////////////////////////////////////////////////////
#include "bubblechatapplication.hpp"

#include <iostream>

BubbleChatApplication::BubbleChatApplication()
{

}

void BubbleChatApplication::initialize(Application &self)
{
    loadConfiguration();
    ServerApplication::initialize(self);
}

void BubbleChatApplication::uninitialize()
{
    ServerApplication::uninitialize();
}

void BubbleChatApplication::reinitialize(Poco::Util::Application &self)
{
    ServerApplication::reinitialize(self);
}

void BubbleChatApplication::defineOptions(OptionSet &options)
{
    ServerApplication::defineOptions(options);
}

void BubbleChatApplication::handleOption(const std::string &name, const std::string &value)
{
    ServerApplication::handleOption(name, value);
}

int BubbleChatApplication::main(const std::vector<std::string> &args)
{
    for (auto arg : args) {
        std::cout << "arg = " << arg << std::endl;
    }
    waitForTerminationRequest();
    return EXIT_OK;
}
