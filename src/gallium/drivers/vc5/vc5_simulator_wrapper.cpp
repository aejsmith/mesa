/*
 * Copyright © 2017 Broadcom
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

/** @file
 *
 * Wraps bits of the V3D simulator interface in a C interface for the
 * vc5_simulator.c code to use.
 */

#ifdef USE_VC5_SIMULATOR

#include "vc5_simulator_wrapper.h"

#define V3D_TECH_VERSION 3
#define V3D_REVISION 3
#define V3D_SUB_REV 0
#define V3D_HIDDEN_REV 0
#define V3D_COMPAT_REV 0
#include "v3d_hw_auto.h"

extern "C" {

struct v3d_hw *v3d_hw_auto_new(void *in_params)
{
        return v3d_hw_auto_make_unique().release();
}


uint32_t v3d_hw_get_mem(const struct v3d_hw *hw, size_t *size, void **p)
{
        return hw->get_mem(size, p);
}

bool v3d_hw_alloc_mem(struct v3d_hw *hw, size_t min_size)
{
        return hw->alloc_mem(min_size) == V3D_HW_ALLOC_SUCCESS;
}

bool v3d_hw_has_gca(struct v3d_hw *hw)
{
        return hw->has_gca();
}

uint32_t v3d_hw_read_reg(struct v3d_hw *hw, uint32_t reg)
{
        return hw->read_reg(reg);
}

void v3d_hw_write_reg(struct v3d_hw *hw, uint32_t reg, uint32_t val)
{
        hw->write_reg(reg, val);
}

void v3d_hw_tick(struct v3d_hw *hw)
{
        return hw->tick();
}

}

#endif /* USE_VC5_SIMULATOR */
