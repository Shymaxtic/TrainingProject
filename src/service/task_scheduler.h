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
#ifndef TASK_SCHEDULEER_H
#define TASK_SCHEDULEER_H
#include <functional>
#include <thread>

#define LOOP_INTERVAL_MS       100

typedef std::function<void(int)>        task_t;

#define TASK_1s         1

class TaskScheduler {
    public:
        TaskScheduler() {}
        virtual ~TaskScheduler() {}
        int register_task(const task_t& task, int type=TASK_1s);
        int unregister_task(const task_t& task);

        void run();
        void do_task();
    private:
            task_t m_task_1s[10];
            std::thread my_thread;
};

#endif