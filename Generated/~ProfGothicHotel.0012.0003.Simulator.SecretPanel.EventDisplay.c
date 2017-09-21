
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Simulator Secret Panel Display Event */

void adm_sim_display_event_secret_panel_unlock_panel(
    const adm_ent_secret_panel_typ * const ent_secret_panel,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_secret_panel_unlock_panel");
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
        printf(" - Secret_Panel[");
        printf("%d", ent_secret_panel->identity);
        printf("] Unlock_panel (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_secret_panel_unlock_panel");
    #endif
}

void adm_sim_display_event_secret_panel_panel_closed(
    const adm_ent_secret_panel_typ * const ent_secret_panel,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_secret_panel_panel_closed");
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
        printf(" - Secret_Panel[");
        printf("%d", ent_secret_panel->identity);
        printf("] Panel_closed (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_secret_panel_panel_closed");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */