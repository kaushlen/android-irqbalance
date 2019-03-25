#ifndef _IRQBALANCE_H
#define _IRQBALANCE_H

#include <stdbool.h>

typedef unsigned char u8;
typedef unsigned long long u64;

typedef struct cpudata {
    // general
    u8 core;
    bool online;

    // cputimes read from /proc/stat
    u64 cputime_user;
    u64 cputime_nice;
    u64 cputime_system;
    u64 cputime_idle;
    u64 cputime_iowait;
    u64 cputime_irq;
    u64 cputime_softirq;
    u64 cputime_steal;
    u64 cputime_guest;
    u64 cputime_guest_nice;

    // utilization
    u64 cpu_util;

} cpudata_t;

/* Assume all CPUs are IRQ CPUs */
static int OFFS_CPUS = 0;

static int *cpus_with_prio;
static int num_cpus_with_prio = -1;

static int *ignored_irqs;
static int num_ignored_irqs;

static u64 THREAD_DELAY = 1000000;

static int *irqs;
static int irqs_num;

static int *irq_blacklist;
static int irq_blacklist_num;

static cpudata_t *__cpudata;

// Functions
int read_irq_conf();

#endif  // _IRQBALANCE_H