/*
 * Copyright 2009, Lloyd Hilaiel.
 *
 * License
 * 
 * All the cruft you find here is public domain.  You don't have to credit
 * anyone to use this code, but my personal request is that you mention
 * Igor Pavlov for his hard, high quality work.
 *
 * easylzma/decompress.h - The API for LZMA decompression using easylzma
 */

#ifndef __EASYLZMADECOMPRESS_H__ 
#define __EASYLZMADECOMPRESS_H__ 

#include "easylzma/common.h"

/** an opaque handle to an lzma decompressor */
typedef struct _elzma_decompress_handle * elzma_decompress_handle;

/**
 * Allocate a handle to an LZMA decompressor object.
 */ 
elzma_decompress_handle elzma_decompress_alloc();

/**
 * set allocation routines (optional, if not called malloc & free will
 * be used) 
 */ 
void elzma_decompress_set_allocation_callbacks(
    elzma_decompress_handle hand,
    elzma_malloc mallocFunc, void * mallocFuncContext,
    elzma_free freeFunc, void * freeFuncContext);

/**
 * Free all data associated with an LZMA decompressor object.
 */ 
void elzma_decompress_free(elzma_decompress_handle * hand);

/**
 * Perform decompression
 */ 
int elzma_decompress_run(
    elzma_decompress_handle hand,
    elzma_read_callback inputStream, void * inputContext,
    elzma_write_callback outputStream, void * outputContext);

#endif