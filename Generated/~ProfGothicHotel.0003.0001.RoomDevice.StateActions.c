
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Room Device State Actions */

void adm_state_action_room_device_redirect(
    adm_ent_room_device_typ * const ent_room_device)
{
    /* Entity Objects */
    adm_ent_room_door_typ * ent_room_door_0000000001;
    adm_ent_secret_panel_typ * ent_secret_panel_0000000002;
    adm_ent_unlocking_device_typ * ent_unlocking_device_0000000003;

    /* Relationship Relations */
    adm_rel_room_device_generalisation_room_door_typ * rel_room_device_generalisation_room_door_0000000001;
    adm_rel_room_device_generalisation_secret_panel_typ * rel_room_device_generalisation_secret_panel_0000000002;
    adm_rel_room_device_generalisation_unlocking_device_typ * rel_room_device_generalisation_unlocking_device_0000000003;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_room_device_redirect");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_room_device(
        ent_room_device,
        2, 27, 29);

    rel_room_device_generalisation_room_door_0000000001 = ent_room_device->rel_generalisation_room_door_head;

    if (rel_room_device_generalisation_room_door_0000000001 != NULL) {

        ent_room_door_0000000001 = rel_room_device_generalisation_room_door_0000000001->ent_room_door;

        /* GenerateEvent */

        adm_send_event_room_door_door_closed(
            ent_room_device,
            ent_room_door_0000000001,
            2, 30, 33);
    }

    /* Traverse - TraverseSelection */

    adm_object_existent_room_device(
        ent_room_device,
        2, 33, 29);

    rel_room_device_generalisation_secret_panel_0000000002 = ent_room_device->rel_generalisation_secret_panel_head;

    if (rel_room_device_generalisation_secret_panel_0000000002 != NULL) {

        ent_secret_panel_0000000002 = rel_room_device_generalisation_secret_panel_0000000002->ent_secret_panel;

        /* GenerateEvent */

        adm_send_event_secret_panel_panel_closed(
            ent_room_device,
            ent_secret_panel_0000000002,
            2, 36, 33);
    }

    /* Traverse - TraverseSelection */

    adm_object_existent_room_device(
        ent_room_device,
        2, 39, 29);

    rel_room_device_generalisation_unlocking_device_0000000003 = ent_room_device->rel_generalisation_unlocking_device_head;

    if (rel_room_device_generalisation_unlocking_device_0000000003 != NULL) {

        ent_unlocking_device_0000000003 = rel_room_device_generalisation_unlocking_device_0000000003->ent_unlocking_device;

        /* GenerateEvent */

        adm_send_event_unlocking_device_device_update(
            ent_room_device,
            ent_unlocking_device_0000000003,
            2, 42, 33);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_room_device_redirect");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */