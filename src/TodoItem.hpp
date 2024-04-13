#pragma once

#include <string>

class TodoItem {
public:
    TodoItem(const std::string& todo, bool completed = false);
    std::string get_todo() const;
    bool get_status() const;
    void set_status(bool completed);
private:
    std::string todo;
    bool completed;
};