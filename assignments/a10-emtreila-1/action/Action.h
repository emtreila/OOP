#ifndef ACTION_H
#define ACTION_H


class Action {
public:
    Action() = default;
    virtual ~Action() = default;
    virtual void executeUndo() = 0;
    virtual void executeRedo() = 0;
};


#endif //ACTION_H
