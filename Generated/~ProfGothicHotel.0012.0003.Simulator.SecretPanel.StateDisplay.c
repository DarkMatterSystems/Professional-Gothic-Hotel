
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Simulator Secret Panel Display State */

void adm_sim_display_state_secret_panel_closed(
    adm_pool_target_secret_panel_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_secret_panel_closed");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (4:14:26) - Secret_Panel[");
        printf("%d", (pool_target->ent_secret_panel)->identity);
        printf("] ");
        printf("Closed");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_SECRET_PANEL, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_secret_panel[(pool_target->ent_secret_panel)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_secret_panel_closed");
    #endif
}

void adm_sim_display_state_secret_panel_opened(
    adm_pool_target_secret_panel_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_secret_panel_opened");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (4:49:26) - Secret_Panel[");
        printf("%d", (pool_target->ent_secret_panel)->identity);
        printf("] ");
        printf("Opened");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_SECRET_PANEL, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_secret_panel[(pool_target->ent_secret_panel)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_secret_panel_opened");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */