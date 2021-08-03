// Copyright (C) 2021 Shymaxtic
// 
// This file is part of TrainingProject.
// 
// TrainingProject is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// TrainingProject is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with TrainingProject.  If not, see <http://www.gnu.org/licenses/>.
#ifndef MESSAGE_RECEIVER_H
#define MESSAGE_RECEIVER_H
#include <functional>
#include <thread>

typedef std::function<void(void*)>        cb_receiver_t;

class MessageReceiver
{
public:
    MessageReceiver(const int& msg_queue_id);
    ~MessageReceiver();
    int register_callback(cb_receiver_t);
    int listen_msg();
    
private:
    int m_msg_queue_id;
    cb_receiver_t m_callback;
    std::thread my_thread;
};

#endif