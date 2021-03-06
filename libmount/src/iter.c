/*
 * Copyright (C) 2009 Karel Zak <kzak@redhat.com>
 *
 * This file may be redistributed under the terms of the
 * GNU Lesser General Public License.
 */

/**
 * SECTION: iter
 * @title: Iterator
 * @short_description: unified iterator
 *
 * The iterator keeps direction and last position for access to the internal
 * library tables/lists.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "mountP.h"

/**
 * mnt_new_iter:
 * @direction: MNT_INTER_{FOR,BACK}WARD direction
 *
 * Returns: newly allocated generic libmount iterator.
 */
struct libmnt_iter *mnt_new_iter(int direction)
{
	struct libmnt_iter *itr = calloc(1, sizeof(*itr));
	if (!itr)
		return NULL;
	itr->direction = direction;
	return itr;
}

/**
 * mnt_free_iter:
 * @itr: iterator pointer
 *
 * Deallocates iterator.
 */
void mnt_free_iter(struct libmnt_iter *itr)
{
	free(itr);
}

/**
 * mnt_reset_iter:
 * @itr: iterator pointer
 * @direction: MNT_INTER_{FOR,BACK}WARD or -1 to keep the derection unchanged
 *
 * Resets iterator.
 */
void mnt_reset_iter(struct libmnt_iter *itr, int direction)
{
	if (direction == -1)
		direction = itr->direction;

	memset(itr, 0, sizeof(*itr));
	itr->direction = direction;
}

/**
 * mnt_iter_get_direction:
 * @itr: iterator pointer
 *
 * Returns: MNT_INTER_{FOR,BACK}WARD
 */
int mnt_iter_get_direction(struct libmnt_iter *itr)
{
	return itr->direction;
}
