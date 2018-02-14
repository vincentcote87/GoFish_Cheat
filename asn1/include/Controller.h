#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

class Controller
{
public:
    virtual ~Controller() {}

    virtual void play() = 0;
};

#endif // CONTROLLER_H_INCLUDED
