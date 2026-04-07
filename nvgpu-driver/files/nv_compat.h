/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Kernel API compatibility shims for OE4T/linux-nvgpu on vanilla kernels.
 * All real guards are #ifdef NV_* in the nvgpu source — this header
 * activates them so the module builds without L4T BSP headers.
 */
#ifndef _NV_COMPAT_H
#define _NV_COMPAT_H

/* vm_flags_set()/vm_flags_clear() — vm_flags became const in 6.3 */
#define NV_VM_AREA_STRUCT_HAS_CONST_VM_FLAGS

/* class_create() dropped THIS_MODULE arg in 6.4 */
#define NV_CLASS_CREATE_HAS_NO_OWNER_ARG

/* devnode() callback takes const struct device* since 6.2 */
#define NV_CLASS_STRUCT_DEVNODE_HAS_CONST_DEV_ARG

/* fd_file(fd) accessor added in 6.9 */
#define NV_FD_FILE_PRESENT

/* fd_empty(fd) accessor added in 6.12 */
#define NV_FD_EMPTY_PRESENT

/* hrtimer_setup() added in 6.14-rc1 */
#define NV_HRTIMER_SETUP_PRESENT

/* linux/iosys-map.h added in 5.18 */
#define NV_LINUX_IOSYS_MAP_H_PRESENT

/* platform_driver.remove returns void since 6.11 */
#define NV_PLATFORM_DRIVER_STRUCT_REMOVE_RETURNS_VOID

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

/* NOTE: do NOT define NV_MODULE_IMPORT_NS_CALLS_STRINGIFY —
 * kernel 6.18 uses string literal form, not the macro form. */

#endif /* _NV_COMPAT_H */
