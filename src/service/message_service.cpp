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

#include "message_service.h"
#include <mutex>
#include <condition_variable>

int MessageService::send_msg(uint8_t msg_id, const message_t& msg) {
    std::unique_lock<std::mutex> lck(MSG_POOL[msg_id].my_locker);
    MSG_POOL[msg_id].msg_queue.push_front(msg);
    MSG_POOL[msg_id].my_cv.notify_all();
    return 0;
}

std::vector<message_t> MessageService::wait_msgs(uint8_t msg_id) {
    std::vector<message_t> msgs;
    std::unique_lock<std::mutex> lck(MSG_POOL[msg_id].my_locker);
    while (MSG_POOL[msg_id].msg_queue.empty()) {
        MSG_POOL[msg_id].my_cv.wait(lck);
    }

    while (MSG_POOL[msg_id].msg_queue.empty() == false) {
        msgs.push_back(MSG_POOL[msg_id].msg_queue.back());
        MSG_POOL[msg_id].msg_queue.pop_back();
    }      
    return msgs;
}