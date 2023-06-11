#pragma once

#include <deque>

class ActionEvent;

class ActionQueue {
  private:
    std::deque<ActionEvent, std::allocator<ActionEvent> > mQueue;

  public:
    ActionQueue(void);
    void pushBackActionEvent(ActionEvent);
    bool getNextActionEvent(ActionEvent &);
    void clearQueue(void);
    bool isEmpty(void) const;
};