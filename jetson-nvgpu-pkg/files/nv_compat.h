/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Kernel API compatibility shims for OE4T/linux-nvgpu on vanilla kernels.
 * All real guards are #ifdef NV_* in the nvgpu source — this header
 * activates them so the module builds without L4T BSP headers.
 */
#ifndef _NV_COMPAT_H
#define _NV_COMPAT_H

/* hrtimer_setup() added in 6.14-rc1 (commit 5c2af[…]) */
#define NV_HRTIMER_SETUP_PRESENT

/* devm_clk_get_optional() present since 5.1 */
#define NV_DEVM_CLK_GET_OPTIONAL_PRESENT

/* dma_alloc_attrs() present since 4.8 */
#define NV_DMA_ALLOC_ATTRS_PRESENT

/* of_property_read_variable_u32_array() present since 4.10 */
#define NV_OF_PROPERTY_READ_VARIABLE_U32_ARRAY_PRESENT

/* drm_gem_object_put() (non-locked variant) present since 5.9 */
#define NV_DRM_GEM_OBJECT_PUT_PRESENT

/* drm_driver no .gem_prime_res_obj field since 5.4 */
#define NV_DRM_DRIVER_HAS_GEM_PRIME_RES_OBJ

/* pci_enable_atomic_ops_to_root() present since 4.16 */
#define NV_PCI_ENABLE_ATOMIC_OPS_TO_ROOT_PRESENT

/* nv_compat.h — 8 defines, no L4T BSP dependencies */

#endif /* _NV_COMPAT_H */
