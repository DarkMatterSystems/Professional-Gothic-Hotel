
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Simulator System Configuration */

/* Domain Map */

adm_sim_domain_typ adm_sim_domain[] = {
    {"Gothic_Security"},
    {SNULL}
};

/* Entity Map */

adm_sim_entity_typ adm_sim_entity[] = {
    {ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY, "Room_Device", TRUE, adm_sim_display_entity_room_device},
    {ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY, "Room_Door", TRUE, adm_sim_display_entity_room_door},
    {ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY, "Secret_Panel", TRUE, adm_sim_display_entity_secret_panel},
    {ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY, "Unlocking_Device", TRUE, adm_sim_display_entity_unlocking_device},
    {ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY, "Unlocking_Sequence", TRUE, adm_sim_display_entity_unlocking_sequence},
    {ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY, "Unlock_Step", TRUE, adm_sim_display_entity_unlock_step},
    {ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY, "Room", FALSE, adm_sim_display_entity_room},
    {null, SNULL, null, NULL}
};

/* Event Map */

adm_sim_event_typ adm_sim_event[] = {
    {
        ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY,
        ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_ROOM_DEVICE,
        "Device_update",
        FALSE,
        adm_sim_acquire_identity_event_room_device_device_update
    },
    {
        ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY,
        ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_ROOM_DOOR,
        "Door_closed",
        FALSE,
        adm_sim_acquire_identity_event_room_door_door_closed
    },
    {
        ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY,
        ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_ROOM_DOOR,
        "Door_opened",
        FALSE,
        adm_sim_acquire_identity_event_room_door_door_opened
    },
    {
        ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY,
        ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_ROOM_DOOR,
        "Lock_door",
        FALSE,
        adm_sim_acquire_identity_event_room_door_lock_door
    },
    {
        ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY,
        ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_ROOM_DOOR,
        "Unlock_door",
        FALSE,
        adm_sim_acquire_identity_event_room_door_unlock_door
    },
    {
        ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY,
        ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_SECRET_PANEL,
        "Unlock_panel",
        FALSE,
        adm_sim_acquire_identity_event_secret_panel_unlock_panel
    },
    {
        ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY,
        ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_SECRET_PANEL,
        "Panel_closed",
        FALSE,
        adm_sim_acquire_identity_event_secret_panel_panel_closed
    },
    {
        ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY,
        ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_UNLOCKING_DEVICE,
        "Device_update",
        FALSE,
        adm_sim_acquire_identity_event_unlocking_device_device_update
    },
    {
        ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY,
        ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_UNLOCKING_SEQUENCE,
        "Activate",
        FALSE,
        adm_sim_acquire_identity_event_unlocking_sequence_activate
    },
    {
        ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY,
        ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_UNLOCKING_SEQUENCE,
        "Reset",
        FALSE,
        adm_sim_acquire_identity_event_unlocking_sequence_reset
    },
    {
        ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY,
        ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_UNLOCKING_SEQUENCE,
        "Complete",
        FALSE,
        adm_sim_acquire_identity_event_unlocking_sequence_complete
    },
    {
        ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY,
        ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_UNLOCK_STEP,
        "Reset",
        FALSE,
        adm_sim_acquire_identity_event_unlock_step_reset
    },
    {
        ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY,
        ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_UNLOCK_STEP,
        "Advance",
        FALSE,
        adm_sim_acquire_identity_event_unlock_step_advance
    },
    {
        ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY,
        ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_UNLOCK_STEP,
        "Select",
        FALSE,
        adm_sim_acquire_identity_event_unlock_step_select
    },
    {
        ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY,
        ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_UNLOCK_STEP,
        "Prime",
        FALSE,
        adm_sim_acquire_identity_event_unlock_step_prime
    },
    {
        null,
        null,
        SNULL,
        null,
        NULL
    }
};

/* Identifier Map */

adm_sim_identifier_typ adm_sim_identifier[] = {
    {
        ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY,
        ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_ROOM_DEVICE,
        ADM_SIM_INDEX_EVENT_GOTHIC_SECURITY_ROOM_DEVICE_DEVICE_UPDATE,
        "Room_Device_Identifier",
        adm_sim_acquire_identifier_event_room_device_device_update_room_device_identifier
    },
    {
        ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY,
        ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_ROOM_DOOR,
        ADM_SIM_INDEX_EVENT_GOTHIC_SECURITY_ROOM_DOOR_DOOR_CLOSED,
        "Room_Door_Identifier",
        adm_sim_acquire_identifier_event_room_door_door_closed_room_door_identifier
    },
    {
        ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY,
        ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_ROOM_DOOR,
        ADM_SIM_INDEX_EVENT_GOTHIC_SECURITY_ROOM_DOOR_DOOR_OPENED,
        "Room_Door_Identifier",
        adm_sim_acquire_identifier_event_room_door_door_opened_room_door_identifier
    },
    {
        ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY,
        ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_ROOM_DOOR,
        ADM_SIM_INDEX_EVENT_GOTHIC_SECURITY_ROOM_DOOR_LOCK_DOOR,
        "Room_Door_Identifier",
        adm_sim_acquire_identifier_event_room_door_lock_door_room_door_identifier
    },
    {
        ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY,
        ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_ROOM_DOOR,
        ADM_SIM_INDEX_EVENT_GOTHIC_SECURITY_ROOM_DOOR_UNLOCK_DOOR,
        "Room_Door_Identifier",
        adm_sim_acquire_identifier_event_room_door_unlock_door_room_door_identifier
    },
    {
        null,
        null,
        null,
        SNULL,
        NULL
    }
};


/* Find Event Name From Event Index */

adm_base_string_typ * adm_sim_find_event_name(
    adm_base_integer_typ entity_index,
    adm_base_integer_typ entity_event_index)
{
    adm_base_integer_typ index;

    adm_base_boolean_typ event_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_find_event_name");
    #endif

    index = 0;

    event_not_found = TRUE;

    while (event_not_found) {

        if (adm_sim_event[index].entity == entity_index) {

            index += entity_event_index;

            event_not_found = FALSE;

        } else {

            ++index;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_find_event_name");
    #endif

    return (adm_sim_event[index].name);
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */