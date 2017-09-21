
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Room Simulator Display Entity */

void adm_sim_display_entity_room(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_room_typ * ent_room;

    adm_sim_width_room_typ width_room;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_room");
    #endif

    width_room.identity = strlen("Identity");
    width_room.atb_number = strlen("Number");

    ent_room = adm_entity_system.ent_room.live_list_head;

    while (ent_room != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_room->identity);
        if (width > width_room.identity) width_room.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_room->atb_number);
        if (width > width_room.atb_number) width_room.atb_number = width;

        ent_room = ent_room->next;
    }

    printf(NEWLINE);
    printf("Room:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_room.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_room.atb_number, "Number");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_room.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_room.atb_number);

    ent_room = adm_entity_system.ent_room.live_list_head;

    while (ent_room != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_room.identity, ent_room->identity);
        printf(ADM_SIM_COLUMN_GAP);
        printf("%*d", width_room.atb_number, ent_room->atb_number);

        ent_room = ent_room->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_room");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */