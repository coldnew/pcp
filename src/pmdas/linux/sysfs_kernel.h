/*
 * Linux sysfs_kernel cluster
 *
 * Copyright (c) 2009, Red Hat, Inc.  All Rights Reserved.
 * 
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 */

#ifndef _SYSFS_KERNEL_H
#define _SYSFS_KERNEL_H

#include "pmapi.h"
#include "impl.h"
#include "pmda.h"
#include <ctype.h>

typedef struct {
	int		valid_uevent_seqnum;
	uint64_t	uevent_seqnum; /* /sys/kernel/uevent_seqnum */
	/* TODO queue length, event type counters and other metrics */
} sysfs_kernel_t;

/* refresh sysfs_kernel */
extern int refresh_sysfs_kernel(sysfs_kernel_t *);

#endif /* _SYSFS_KERNEL_H */