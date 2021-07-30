// Copyright (C) 2021 quynhpp
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

#include "task_scheduler.h"
#include <unistd.h>

void TaskScheduler::run() {
    my_thread = std::thread(&TaskScheduler::do_task, this);
}

void TaskScheduler::do_task() {
    while (true) {
        fprintf(stderr, "runing\n");
        usleep(100000);
    }
}
int TaskScheduler::register_task(const task_t& task, int type) {
    // TODO: thread-safe
    int result = -1;
    if (type == TASK_1s) {
        for (int i = 0; i < 10; ++i) {
            if (m_task_1s[i] == nullptr) {
                m_task_1s[i] = task;
                result = 0;
                break;
            }
        }
    }
    return result;
}

int TaskScheduler::unregister_task(const task_t& task) {
    
}
