
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Secret Panel Simulator Display Entity */

void adm_sim_display_entity_secret_panel(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_secret_panel_typ * ent_secret_panel;

    adm_sim_width_secret_panel_typ width_secret_panel;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_secret_panel");
    #endif

    width_secret_panel.identity = strlen("Identity");
    width_secret_panel.status = strlen("Status");

    ent_secret_panel = adm_entity_system.ent_secret_panel.live_list_head;

    while (ent_secret_panel != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_secret_panel->identity);
        if (width > width_secret_panel.identity) width_secret_panel.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_sim_status_secret_panel[ent_secret_panel->status]);
        if (width > width_secret_panel.status) width_secret_panel.status = width;

        ent_secret_panel = ent_secret_panel->next;
    }

    printf(NEWLINE);
    printf("Secret_Panel:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_secret_panel.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_secret_panel.status, "Status");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_secret_panel.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_secret_panel.status);

    ent_secret_panel = adm_entity_system.ent_secret_panel.live_list_head;

    while (ent_secret_panel != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_secret_panel.identity, ent_secret_panel->identity);
        printf(ADM_SIM_COLUMN_GAP);

        switch (ent_secret_panel->status) {
            case ADM_STATUS_SECRET_PANEL_CLOSED :
                printf("%-*s", width_secret_panel.status, "Closed");
            break;
            case ADM_STATUS_SECRET_PANEL_OPENED :
                printf("%-*s", width_secret_panel.status, "Opened");
            break;
            default :
                printf("%-*s", width_secret_panel.status, "ERROR");
            break;
        }


        ent_secret_panel = ent_secret_panel->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_secret_panel");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */