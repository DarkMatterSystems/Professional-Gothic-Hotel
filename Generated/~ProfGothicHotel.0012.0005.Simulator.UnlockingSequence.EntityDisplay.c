
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Unlocking Sequence Simulator Display Entity */

void adm_sim_display_entity_unlocking_sequence(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence;

    adm_sim_width_unlocking_sequence_typ width_unlocking_sequence;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_unlocking_sequence");
    #endif

    width_unlocking_sequence.identity = strlen("Identity");
    width_unlocking_sequence.status = strlen("Status");

    ent_unlocking_sequence = adm_entity_system.ent_unlocking_sequence.live_list_head;

    while (ent_unlocking_sequence != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_unlocking_sequence->identity);
        if (width > width_unlocking_sequence.identity) width_unlocking_sequence.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_sim_status_unlocking_sequence[ent_unlocking_sequence->status]);
        if (width > width_unlocking_sequence.status) width_unlocking_sequence.status = width;

        ent_unlocking_sequence = ent_unlocking_sequence->next;
    }

    printf(NEWLINE);
    printf("Unlocking_Sequence:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_unlocking_sequence.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_unlocking_sequence.status, "Status");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_unlocking_sequence.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_unlocking_sequence.status);

    ent_unlocking_sequence = adm_entity_system.ent_unlocking_sequence.live_list_head;

    while (ent_unlocking_sequence != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_unlocking_sequence.identity, ent_unlocking_sequence->identity);
        printf(ADM_SIM_COLUMN_GAP);

        switch (ent_unlocking_sequence->status) {
            case ADM_STATUS_UNLOCKING_SEQUENCE_IDLE :
                printf("%-*s", width_unlocking_sequence.status, "Idle");
            break;
            case ADM_STATUS_UNLOCKING_SEQUENCE_ACTIVE :
                printf("%-*s", width_unlocking_sequence.status, "Active");
            break;
            case ADM_STATUS_UNLOCKING_SEQUENCE_COMPLETE :
                printf("%-*s", width_unlocking_sequence.status, "Complete");
            break;
            default :
                printf("%-*s", width_unlocking_sequence.status, "ERROR");
            break;
        }


        ent_unlocking_sequence = ent_unlocking_sequence->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_unlocking_sequence");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */