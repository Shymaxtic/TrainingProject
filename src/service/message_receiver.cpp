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
#include "message_receiver.h"
#include <unistd.h>
#include "message_service.h"

MessageReceiver::MessageReceiver(const int& msg_queue_id) : m_msg_queue_id(msg_queue_id)
{

}

MessageReceiver::~MessageReceiver()
{
}

int MessageReceiver::register_callback(cb_receiver_t call_back) {
    m_callback = call_back;
    return 0;
}

int MessageReceiver::listen_msg() {
    my_thread = std::thread([this]() {
        while (true)
        {
            printf("listening msg...\n");
            std::vector<message_t> msgs = MessageService::wait_msgs(m_msg_queue_id);
            printf("received new messages %d\n", msgs.size());
        }
        
    });
}