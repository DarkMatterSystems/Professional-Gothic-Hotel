
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Room Door Simulator Display Entity */

void adm_sim_display_entity_room_door(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_room_door_typ * ent_room_door;

    adm_sim_width_room_door_typ width_room_door;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_room_door");
    #endif

    width_room_door.identity = strlen("Identity");
    width_room_door.status = strlen("Status");

    ent_room_door = adm_entity_system.ent_room_door.live_list_head;

    while (ent_room_door != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_room_door->identity);
        if (width > width_room_door.identity) width_room_door.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_sim_status_room_door[ent_room_door->status]);
        if (width > width_room_door.status) width_room_door.status = width;

        ent_room_door = ent_room_door->next;
    }

    printf(NEWLINE);
    printf("Room_Door:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_room_door.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_room_door.status, "Status");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_room_door.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_room_door.status);

    ent_room_door = adm_entity_system.ent_room_door.live_list_head;

    while (ent_room_door != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_room_door.identity, ent_room_door->identity);
        printf(ADM_SIM_COLUMN_GAP);

        switch (ent_room_door->status) {
            case ADM_STATUS_ROOM_DOOR_OPEN :
                printf("%-*s", width_room_door.status, "Open");
            break;
            case ADM_STATUS_ROOM_DOOR_CLOSED :
                printf("%-*s", width_room_door.status, "Closed");
            break;
            case ADM_STATUS_ROOM_DOOR_LOCKED :
                printf("%-*s", width_room_door.status, "Locked");
            break;
            case ADM_STATUS_ROOM_DOOR_UNLOCKED :
                printf("%-*s", width_room_door.status, "Unlocked");
            break;
            default :
                printf("%-*s", width_room_door.status, "ERROR");
            break;
        }


        ent_room_door = ent_room_door->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_room_door");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */