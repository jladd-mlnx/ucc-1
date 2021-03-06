/**
 * Copyright (C) Mellanox Technologies Ltd. 2020.  ALL RIGHTS RESERVED.
 *
 * See file LICENSE for terms.
 */

#include "tl_ucp.h"
#include "utils/ucc_malloc.h"

/* NOLINTNEXTLINE  params is not used*/
UCC_CLASS_INIT_FUNC(ucc_tl_ucp_lib_t, const ucc_base_lib_params_t *params,
                    const ucc_base_config_t *config)
{
    const ucc_tl_ucp_lib_config_t *tl_ucp_config =
        ucc_derived_of(config, ucc_tl_ucp_lib_config_t);
    UCC_CLASS_CALL_SUPER_INIT(ucc_tl_lib_t, &ucc_tl_ucp.super,
                              &tl_ucp_config->super);
    memcpy(&self->cfg, tl_ucp_config, sizeof(*tl_ucp_config));
    tl_info(&self->super, "initialized lib object: %p", self);
    return UCC_OK;
}

UCC_CLASS_CLEANUP_FUNC(ucc_tl_ucp_lib_t)
{
    tl_info(&self->super, "finalizing lib object: %p", self);
}

UCC_CLASS_DEFINE(ucc_tl_ucp_lib_t, ucc_tl_lib_t);

ucc_status_t ucc_tl_ucp_get_lib_attr(const ucc_base_lib_t *lib, /* NOLINT */
                                     ucc_base_attr_t *attr)     /* NOLINT */
{
    //TODO
    return UCC_ERR_NOT_IMPLEMENTED;
}
