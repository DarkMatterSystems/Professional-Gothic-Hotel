
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Simulator Room Device Acquire Identity Event */

void adm_sim_acquire_identity_event_room_device_device_update(
    void)
{
    adm_ent_room_device_typ * ent_room_device;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_room_device_device_update");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_room_device = adm_entity_system.ent_room_device.live_list_head;

    while (
        entity_not_found &&
        ent_room_device != NULL) {

        if (ent_room_device->identity == identity) {

            adm_send_event_room_device_device_update(
                NULL,
                ent_room_device,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_room_device = ent_room_device->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_room_device_device_update");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */