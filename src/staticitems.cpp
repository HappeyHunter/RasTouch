#include "staticitems.h"

const QString StaticItems::CUSTOM_MESSAGE = "Custom Message";
const QString StaticItems::NAMES_FILE = "TargetNames";

const QMap<StaticItems::ButtonOption, QString> StaticItems::MESSAGES = {{StaticItems::ButtonOption::HangUpWashing, "Hang Up Washing"},
                                                                    {StaticItems::ButtonOption::PuttingOnWash, "Putting Wash On"},
                                                                    {StaticItems::ButtonOption::PickDinner, "Pick Dinner"},
                                                                    {StaticItems::ButtonOption::CookDinner, "Cook Dinner"},
                                                                    {StaticItems::ButtonOption::DinnerReady, "Dinner is ready!"}};

QString StaticItems::getMessage(ButtonOption option) {
    QMap<ButtonOption, QString>::const_iterator message = StaticItems::MESSAGES.find(option);
    if (message == StaticItems::MESSAGES.end()) {
        return CUSTOM_MESSAGE;
    }
    return message.value();
}
