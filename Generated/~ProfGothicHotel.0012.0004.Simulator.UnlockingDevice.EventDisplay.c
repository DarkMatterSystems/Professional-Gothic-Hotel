
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Simulator Unlocking Device Display Event */

void adm_sim_display_event_unlocking_device_device_update(
    const adm_ent_unlocking_device_typ * const ent_unlocking_device,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_unlocking_device_device_update");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.events) {

        printf(NEWLINE);

        if (error_file != ADM_SIM_MATRIX_SCRIPT_EVENT) {

            printf(ADM_SIM_INDENT);
            printf(ADM_SIM_INDENT);
        }

        printf("EVENT (");
        printf("%d:%d:%d)", error_file, error_line, error_rank);
        printf(" - Unlocking_Device[");
        printf("%d", ent_unlocking_device->identity);
        printf("] Device_update (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_unlocking_device_device_update");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */