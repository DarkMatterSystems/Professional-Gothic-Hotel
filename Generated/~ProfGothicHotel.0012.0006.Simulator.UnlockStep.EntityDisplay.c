
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Unlock Step Simulator Display Entity */

void adm_sim_display_entity_unlock_step(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_unlock_step_typ * ent_unlock_step;

    adm_sim_width_unlock_step_typ width_unlock_step;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_unlock_step");
    #endif

    width_unlock_step.identity = strlen("Identity");
    width_unlock_step.status = strlen("Status");

    ent_unlock_step = adm_entity_system.ent_unlock_step.live_list_head;

    while (ent_unlock_step != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_unlock_step->identity);
        if (width > width_unlock_step.identity) width_unlock_step.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_sim_status_unlock_step[ent_unlock_step->status]);
        if (width > width_unlock_step.status) width_unlock_step.status = width;

        ent_unlock_step = ent_unlock_step->next;
    }

    printf(NEWLINE);
    printf("Unlock_Step:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_unlock_step.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_unlock_step.status, "Status");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_unlock_step.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_unlock_step.status);

    ent_unlock_step = adm_entity_system.ent_unlock_step.live_list_head;

    while (ent_unlock_step != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_unlock_step.identity, ent_unlock_step->identity);
        printf(ADM_SIM_COLUMN_GAP);

        switch (ent_unlock_step->status) {
            case ADM_STATUS_UNLOCK_STEP_WRONG_STEP :
                printf("%-*s", width_unlock_step.status, "Wrong_Step");
            break;
            case ADM_STATUS_UNLOCK_STEP_LOCKED :
                printf("%-*s", width_unlock_step.status, "Locked");
            break;
            case ADM_STATUS_UNLOCK_STEP_SELECTED :
                printf("%-*s", width_unlock_step.status, "Selected");
            break;
            case ADM_STATUS_UNLOCK_STEP_PRIMED :
                printf("%-*s", width_unlock_step.status, "Primed");
            break;
            case ADM_STATUS_UNLOCK_STEP_UNLOCKED :
                printf("%-*s", width_unlock_step.status, "Unlocked");
            break;
            default :
                printf("%-*s", width_unlock_step.status, "ERROR");
            break;
        }


        ent_unlock_step = ent_unlock_step->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_unlock_step");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */