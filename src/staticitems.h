#ifndef STATICITEMS_H_
#define STATICITEMS_H_

#include <QString>
#include <QMap>

class StaticItems {

public:
    enum ButtonOption {
        Close,
        Cancel,
        Washing,
        Dinner,
        PuttingOnWash,
        HangUpWashing,
        PickDinner,
        CookDinner,
        DinnerReady
    };

    static QString const CUSTOM_MESSAGE;
    static QString const NAMES_FILE;

    static QMap<ButtonOption, QString> const MESSAGES;

    static QString getMessage(ButtonOption);
};


#endif /* STATICITEMS_H_ */
