/* SPDX-License-Identifier: MIT */
/*
 * nvmap kernel compatibility header for Linux 6.18
 *
 * The nvmap out-of-tree driver uses <nvidia/conftest.h> to detect kernel API
 * changes via compile-time probes. In the Talos pkgs build environment the
 * conftest.sh probe system does not work (probe programs silently fail due to
 * missing include paths), causing all NV_* macros to be left undefined and
 * selecting stale API code paths that do not compile against kernel 6.18.
 *
 * This file replaces the conftest-generated headers with static definitions
 * for the kernel 6.18 API. It is installed as /conftest/nvidia/conftest.h so
 * that '#include <nvidia/conftest.h>' resolves correctly when KCPPFLAGS
 * contains '-I/conftest'.
 */

#ifndef _NVMAP_COMPAT_H
#define _NVMAP_COMPAT_H

/*
 * Linux v6.10+: __assign_str() takes only the destination name argument;
 * the source argument was removed.
 */
#define NV___ASSIGN_STR_HAS_NO_SRC_ARG

/*
 * Linux v6.5+: get_user_pages() dropped the trailing NULL 'locked' argument,
 * leaving a 4-argument signature: (start, nr_pages, gup_flags, pages).
 */
#define NV_GET_USER_PAGES_HAS_ARGS_FLAGS

/*
 * Linux v6.2+: mm->rss_stat changed from a struct with a count[] array to a
 * percpu_counter[] array.  Access via percpu_counter_add(&mm->rss_stat[i], v).
 */
#define NV_MM_STRUCT_STRUCT_HAS_PERCPU_COUNTER_RSS_STAT

/*
 * Linux v6.15+: ioremap_prot() argument 3 changed type from unsigned long
 * (pgprot value) to pgprot_t.
 */
#define NV_IOREMAP_PROT_HAS_PGPROT_T_ARG

/*
 * Linux v6.10+: __alloc_pages_bulk() dropped the page_list (struct list_head)
 * argument, leaving 5 arguments: (gfp, nid, zonelist, nr_pages, page_array).
 */
#define NV__ALLOC_PAGES_BULK_HAS_NO_PAGE_LIST_ARG

/*
 * Linux v6.7+: shrinker_alloc() / shrinker_free() API replaces the embedded
 * struct shrinker registration pattern.
 */
#define NV_SHRINKER_ALLOC_PRESENT

/*
 * Linux v6.0+: register_shrinker() accepts a printf-style format string as
 * its second argument for naming the shrinker.
 */
#define NV_REGISTER_SHRINKER_HAS_FMT_ARG

/*
 * Linux v5.18+: folio_entire_mapcount() is present.
 */
#define NV_FOLIO_ENTIRE_MAPCOUNT_PRESENT

/*
 * Linux v6.11+: platform_driver.remove callback returns void instead of int.
 */
#define NV_PLATFORM_DRIVER_STRUCT_REMOVE_RETURNS_VOID

/*
 * Linux v6.3+: vma->vm_flags is declared const; modifications must go through
 * vm_flags_set() / vm_flags_clear() helpers.
 */
#define NV_VM_AREA_STRUCT_HAS_CONST_VM_FLAGS

/*
 * Linux v6.13+: struct file has an f_ref refcount field replacing the old
 * f_count atomic.
 */
#define NV_FILE_STRUCT_HAS_F_REF

/*
 * Linux v6.7+: get_file_rcu() takes struct file ** (double pointer) to allow
 * RCU-safe file reference acquisition.
 */
#define NV_GET_FILE_RCU_HAS_DOUBLE_PTR_FILE_ARG

/*
 * linux/iosys-map.h is present (added in Linux 5.15, replaces dma_buf_map).
 * dma_buf vmap/vunmap callbacks use struct iosys_map.
 */
#define NV_LINUX_IOSYS_MAP_H_PRESENT

/*
 * NV_DMA_BUF_OPS_HAS_CACHE_SGT_MAPPING: intentionally NOT defined.
 *
 * dma_buf_ops.cache_sgt_mapping was added in Linux 5.15 but removed again
 * before 6.18 — the field no longer exists in the struct.
 */

/*
 * NV_MODULE_IMPORT_NS_CALLS_STRINGIFY: intentionally NOT defined.
 *
 * Linux 6.18 uses MODULE_IMPORT_NS("DMA_BUF") with a string literal directly.
 * Defining this macro would select the old STRINGIFY-based form which does not
 * compile on 6.18.
 */

#endif /* _NVMAP_COMPAT_H */
