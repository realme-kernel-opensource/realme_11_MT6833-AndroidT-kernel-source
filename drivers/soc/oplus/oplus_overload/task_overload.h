/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2022 Oplus. All rights reserved.
 */


#ifndef _TASK_OVERLOAD_H
#define _TASK_OVERLOAD_H
#include <linux/kernel_stat.h>
#include <linux/cpufreq.h>
#include <linux/sched.h>

#define ABNORMAL_THRESHOLD (2500)
#define ABNORMAL_TIME (10)

struct abnormal_tsk_info {
	int   pid;
	int   uid;
	int   limit_flag;
	int   temp;
	int   freq;
	char  comm[TASK_COMM_LEN];
	long  date;
};

extern bool check_abnormal_freq(struct task_struct *p);
extern bool check_abnormal_task_util(struct task_struct *p);
extern bool check_abnormal_cpu_util(void);
extern void set_task_state(struct task_struct *p);
extern bool test_task_uid(struct task_struct *task);
extern bool test_task_overload(struct task_struct *task);
extern int sysctl_abnormal_enable;
#endif /* _TASK_OVERLOAD_H */
