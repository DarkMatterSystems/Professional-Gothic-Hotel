
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Room Device Simulator Display Entity */

void adm_sim_display_entity_room_device(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_room_device_typ * ent_room_device;

    adm_sim_width_room_device_typ width_room_device;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_room_device");
    #endif

    width_room_device.identity = strlen("Identity");
    width_room_device.status = strlen("Status");
    width_room_device.atb_name = strlen("Name");

    ent_room_device = adm_entity_system.ent_room_device.live_list_head;

    while (ent_room_device != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_room_device->identity);
        if (width > width_room_device.identity) width_room_device.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_sim_status_room_device[ent_room_device->status]);
        if (width > width_room_device.status) width_room_device.status = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_room_device->atb_name);
        if (width > width_room_device.atb_name) width_room_device.atb_name = width;

        ent_room_device = ent_room_device->next;
    }

    printf(NEWLINE);
    printf("Room_Device:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_room_device.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_room_device.status, "Status");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_room_device.atb_name, "Name");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_room_device.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_room_device.status);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_room_device.atb_name);

    ent_room_device = adm_entity_system.ent_room_device.live_list_head;

    while (ent_room_device != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_room_device.identity, ent_room_device->identity);
        printf(ADM_SIM_COLUMN_GAP);

        switch (ent_room_device->status) {
            case ADM_STATUS_ROOM_DEVICE_REDIRECT :
                printf("%-*s", width_room_device.status, "Redirect");
            break;
            default :
                printf("%-*s", width_room_device.status, "ERROR");
            break;
        }

        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_room_device->atb_name);
        printf("%-*s", width_room_device.atb_name, buffer);

        ent_room_device = ent_room_device->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_room_device");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */