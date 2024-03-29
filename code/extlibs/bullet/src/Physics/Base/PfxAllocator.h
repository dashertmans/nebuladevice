/* [SCE CONFIDENTIAL DOCUMENT]
 * $PSLibId$
 *                Copyright (C) 2008 Sony Computer Entertainment Inc.
 *                                                All Rights Reserved.
 */

#ifndef __PFX_ALLOCATOR_H__
#define __PFX_ALLOCATOR_H__

class PfxAllocator {
public:
	PfxAllocator(size_t preAllocatedBytes=0) {}

	virtual ~PfxAllocator() {}

	virtual void *allocate(size_t size) = 0;

	virtual void *reallocate(void* ptr,size_t size) = 0;

	virtual void *allocateAlign(size_t boundary,size_t size) = 0;

	virtual void deallocate(void *ptr) = 0;
	
	virtual size_t allocatedBytes() = 0;
};

#endif /* __PFX_ALLOCATOR_H__ */
