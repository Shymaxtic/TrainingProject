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
#ifndef BASE_MANAGER_H
#define BASE_MANAGER_H
#include "service/task_scheduler.h"
#include "service/message_receiver.h"
#include "service/message_sender.h"

class BaseManager {

    public:
        BaseManager(int msg_queue_id) : m_msg_receiver(msg_queue_id) {
            init_task_scheduler();
            init_msg_receiver();
        }
        virtual ~BaseManager() {}

        void execute();

        virtual void init_task_scheduler();
        virtual void init_msg_receiver();

    protected:
        TaskScheduler m_task_scheduler;
        MessageReceiver m_msg_receiver;
        MessageSender m_msg_sender;
};

#endif