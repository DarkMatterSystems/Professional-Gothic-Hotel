
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Unlocking Device Simulator Display Entity */

void adm_sim_display_entity_unlocking_device(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_unlocking_device_typ * ent_unlocking_device;

    adm_sim_width_unlocking_device_typ width_unlocking_device;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_unlocking_device");
    #endif

    width_unlocking_device.identity = strlen("Identity");
    width_unlocking_device.status = strlen("Status");

    ent_unlocking_device = adm_entity_system.ent_unlocking_device.live_list_head;

    while (ent_unlocking_device != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_unlocking_device->identity);
        if (width > width_unlocking_device.identity) width_unlocking_device.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_sim_status_unlocking_device[ent_unlocking_device->status]);
        if (width > width_unlocking_device.status) width_unlocking_device.status = width;

        ent_unlocking_device = ent_unlocking_device->next;
    }

    printf(NEWLINE);
    printf("Unlocking_Device:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_unlocking_device.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_unlocking_device.status, "Status");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_unlocking_device.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_unlocking_device.status);

    ent_unlocking_device = adm_entity_system.ent_unlocking_device.live_list_head;

    while (ent_unlocking_device != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_unlocking_device.identity, ent_unlocking_device->identity);
        printf(ADM_SIM_COLUMN_GAP);

        switch (ent_unlocking_device->status) {
            case ADM_STATUS_UNLOCKING_DEVICE_UPDATING :
                printf("%-*s", width_unlocking_device.status, "Updating");
            break;
            default :
                printf("%-*s", width_unlocking_device.status, "ERROR");
            break;
        }


        ent_unlocking_device = ent_unlocking_device->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_unlocking_device");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */