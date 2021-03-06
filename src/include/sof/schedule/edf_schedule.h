/* SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright(c) 2017 Intel Corporation. All rights reserved.
 *
 * Author: Liam Girdwood <liam.r.girdwood@linux.intel.com>
 */

#ifndef __SOF_SCHEDULE_EDF_SCHEDULE_H__
#define __SOF_SCHEDULE_EDF_SCHEDULE_H__

#include <sof/schedule/task.h>
#include <sof/trace/trace.h>
#include <user/trace.h>
#include <stdint.h>

/* schedule tracing */
#define trace_edf_sch(format, ...) \
	trace_event(TRACE_CLASS_EDF, format, ##__VA_ARGS__)

#define trace_edf_sch_error(format, ...) \
	trace_error(TRACE_CLASS_EDF, format, ##__VA_ARGS__)

#define tracev_edf_sch(format, ...) \
	tracev_event(TRACE_CLASS_EDF, format, ##__VA_ARGS__)

#define edf_sch_set_pdata(task, data) \
	(task->priv_data = data)

#define edf_sch_get_pdata(task) task->priv_data

struct edf_task_pdata {
	void *ctx;
};

int scheduler_init_edf(void);

int schedule_task_init_edf(struct task *task, uint32_t uid,
			   const struct task_ops *ops,
			   void *data, uint16_t core, uint32_t flags);

#endif /* __SOF_SCHEDULE_EDF_SCHEDULE_H__ */
