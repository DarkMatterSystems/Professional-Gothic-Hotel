
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Secret Panel State Actions */

void adm_state_action_secret_panel_closed(
    adm_ent_secret_panel_typ * const ent_secret_panel)
{
    /* Entity Objects */
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence_0000000001;
    adm_ent_room_device_typ * ent_room_device_0000000002;
    adm_ent_room_typ * ent_room_0000000002;
    adm_ent_room_device_typ * ent_room_device_0000000003;
    adm_ent_room_door_typ * ent_room_door_0000000003;

    /* Relationship Relations */
    adm_rel_secret_panel_opened_by_unlocking_sequence_typ * rel_secret_panel_opened_by_unlocking_sequence_0000000001;
    adm_rel_secret_panel_specialisation_room_device_typ * rel_secret_panel_specialisation_room_device_0000000002;
    adm_rel_room_device_contained_in_room_typ * rel_room_device_contained_in_room_0000000002;
    adm_rel_room_contains_room_device_typ * rel_room_contains_room_device_0000000003;
    adm_rel_room_device_generalisation_room_door_typ * rel_room_device_generalisation_room_door_0000000003;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_secret_panel_closed");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_secret_panel(
        ent_secret_panel,
        4, 18, 29);

    rel_secret_panel_opened_by_unlocking_sequence_0000000001 = ent_secret_panel->rel_opened_by_unlocking_sequence_head;

    if (rel_secret_panel_opened_by_unlocking_sequence_0000000001 != NULL) {

        while (rel_secret_panel_opened_by_unlocking_sequence_0000000001 != NULL) {

            ent_unlocking_sequence_0000000001 = rel_secret_panel_opened_by_unlocking_sequence_0000000001->ent_unlocking_sequence;

            /* GenerateEvent */

            adm_send_event_unlocking_sequence_reset(
                ent_secret_panel,
                ent_unlocking_sequence_0000000001,
                4, 21, 33);

            rel_secret_panel_opened_by_unlocking_sequence_0000000001 = rel_secret_panel_opened_by_unlocking_sequence_0000000001->next;
        }

    } else {

        adm_error_report(
            ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
            4, 18, 29,
            "Secret_Panel",
            ent_secret_panel->identity,
            "Opened_by",
            "Unlocking_Sequence");
    }

    /* Traverse - TraverseSelection */

    adm_object_existent_secret_panel(
        ent_secret_panel,
        4, 24, 29);

    rel_secret_panel_specialisation_room_device_0000000002 = ent_secret_panel->rel_specialisation_room_device_head;

    if (rel_secret_panel_specialisation_room_device_0000000002 != NULL) {

        ent_room_device_0000000002 = rel_secret_panel_specialisation_room_device_0000000002->ent_room_device;

        rel_room_device_contained_in_room_0000000002 = ent_room_device_0000000002->rel_contained_in_room_head;

        if (rel_room_device_contained_in_room_0000000002 != NULL) {

            ent_room_0000000002 = rel_room_device_contained_in_room_0000000002->ent_room;

            /* Traverse - TraverseSelection */

            adm_object_existent_room(
                ent_room_0000000002,
                4, 29, 37);

            rel_room_contains_room_device_0000000003 = ent_room_0000000002->rel_contains_room_device_head;

            if (rel_room_contains_room_device_0000000003 != NULL) {

                while (rel_room_contains_room_device_0000000003 != NULL) {

                    ent_room_device_0000000003 = rel_room_contains_room_device_0000000003->ent_room_device;

                    rel_room_device_generalisation_room_door_0000000003 = ent_room_device_0000000003->rel_generalisation_room_door_head;

                    if (rel_room_device_generalisation_room_door_0000000003 != NULL) {

                        ent_room_door_0000000003 = rel_room_device_generalisation_room_door_0000000003->ent_room_door;

                        /* GenerateEvent */

                        adm_send_event_room_door_unlock_door(
                            ent_secret_panel,
                            ent_room_door_0000000003,
                            4, 33, 41);
                    }

                    rel_room_contains_room_device_0000000003 = rel_room_contains_room_device_0000000003->next;
                }

            } else {

                adm_error_report(
                    ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                    4, 29, 37,
                    "Room",
                    ent_room_0000000002->identity,
                    "Contains",
                    "Room_Device");
            }

        } else {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                4, 25, 29,
                "Room_Device",
                ent_room_device_0000000002->identity,
                "Contained_in",
                "Room");
        }

    } else {

        adm_error_report(
            ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
            4, 24, 29,
            "Secret_Panel",
            ent_secret_panel->identity,
            "Specialisation",
            "Room_Device");
    }

    /* Template */

    adm_template_tab_in(4, 34, 21);
    adm_template_tab_in(4, 34, 21);
    adm_write_newline();
    adm_write_str("EVENT => Machinery::Actuator:Lock_panel");
    adm_write_newline();
    adm_template_tab_out(4, 34, 21);
    adm_template_tab_out(4, 34, 21);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_secret_panel_closed");
    #endif
}

void adm_state_action_secret_panel_opened(
    adm_ent_secret_panel_typ * const ent_secret_panel)
{
    /* Entity Objects */
    adm_ent_room_device_typ * ent_room_device_0000000001;
    adm_ent_room_typ * ent_room_0000000001;
    adm_ent_room_device_typ * ent_room_device_0000000002;
    adm_ent_room_door_typ * ent_room_door_0000000002;

    /* Relationship Relations */
    adm_rel_secret_panel_specialisation_room_device_typ * rel_secret_panel_specialisation_room_device_0000000001;
    adm_rel_room_device_contained_in_room_typ * rel_room_device_contained_in_room_0000000001;
    adm_rel_room_contains_room_device_typ * rel_room_contains_room_device_0000000002;
    adm_rel_room_device_generalisation_room_door_typ * rel_room_device_generalisation_room_door_0000000002;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_secret_panel_opened");
    #endif

    /* Template */

    adm_template_tab_in(4, 51, 21);
    adm_template_tab_in(4, 51, 21);
    adm_write_newline();
    adm_write_str("EVENT => Machinery::Actuator:Unlock_panel");
    adm_write_newline();
    adm_template_tab_out(4, 51, 21);
    adm_template_tab_out(4, 51, 21);

    /* Traverse - TraverseSelection */

    adm_object_existent_secret_panel(
        ent_secret_panel,
        4, 60, 29);

    rel_secret_panel_specialisation_room_device_0000000001 = ent_secret_panel->rel_specialisation_room_device_head;

    if (rel_secret_panel_specialisation_room_device_0000000001 != NULL) {

        ent_room_device_0000000001 = rel_secret_panel_specialisation_room_device_0000000001->ent_room_device;

        rel_room_device_contained_in_room_0000000001 = ent_room_device_0000000001->rel_contained_in_room_head;

        if (rel_room_device_contained_in_room_0000000001 != NULL) {

            ent_room_0000000001 = rel_room_device_contained_in_room_0000000001->ent_room;

            /* Traverse - TraverseSelection */

            adm_object_existent_room(
                ent_room_0000000001,
                4, 65, 37);

            rel_room_contains_room_device_0000000002 = ent_room_0000000001->rel_contains_room_device_head;

            if (rel_room_contains_room_device_0000000002 != NULL) {

                while (rel_room_contains_room_device_0000000002 != NULL) {

                    ent_room_device_0000000002 = rel_room_contains_room_device_0000000002->ent_room_device;

                    rel_room_device_generalisation_room_door_0000000002 = ent_room_device_0000000002->rel_generalisation_room_door_head;

                    if (rel_room_device_generalisation_room_door_0000000002 != NULL) {

                        ent_room_door_0000000002 = rel_room_device_generalisation_room_door_0000000002->ent_room_door;

                        /* GenerateEvent */

                        adm_send_event_room_door_lock_door(
                            ent_secret_panel,
                            ent_room_door_0000000002,
                            4, 69, 41);
                    }

                    rel_room_contains_room_device_0000000002 = rel_room_contains_room_device_0000000002->next;
                }

            } else {

                adm_error_report(
                    ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                    4, 65, 37,
                    "Room",
                    ent_room_0000000001->identity,
                    "Contains",
                    "Room_Device");
            }

        } else {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                4, 61, 29,
                "Room_Device",
                ent_room_device_0000000001->identity,
                "Contained_in",
                "Room");
        }

    } else {

        adm_error_report(
            ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
            4, 60, 29,
            "Secret_Panel",
            ent_secret_panel->identity,
            "Specialisation",
            "Room_Device");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_secret_panel_opened");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */