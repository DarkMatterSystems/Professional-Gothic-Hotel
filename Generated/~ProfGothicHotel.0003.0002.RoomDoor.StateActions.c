
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Room Door State Actions */

void adm_state_action_room_door_open(
    adm_ent_room_door_typ * const ent_room_door)
{
    /* Entity Objects */
    adm_ent_room_device_typ * ent_room_device_0000000001;
    adm_ent_room_typ * ent_room_0000000001;
    adm_ent_room_device_typ * ent_room_device_0000000002;
    adm_ent_secret_panel_typ * ent_secret_panel_0000000002;
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence_0000000002;

    /* Relationship Relations */
    adm_rel_room_door_specialisation_room_device_typ * rel_room_door_specialisation_room_device_0000000001;
    adm_rel_room_device_contained_in_room_typ * rel_room_device_contained_in_room_0000000001;
    adm_rel_room_contains_room_device_typ * rel_room_contains_room_device_0000000002;
    adm_rel_room_device_generalisation_secret_panel_typ * rel_room_device_generalisation_secret_panel_0000000002;
    adm_rel_secret_panel_opened_by_unlocking_sequence_typ * rel_secret_panel_opened_by_unlocking_sequence_0000000002;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_room_door_open");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_room_door(
        ent_room_door,
        3, 23, 29);

    rel_room_door_specialisation_room_device_0000000001 = ent_room_door->rel_specialisation_room_device_head;

    if (rel_room_door_specialisation_room_device_0000000001 != NULL) {

        ent_room_device_0000000001 = rel_room_door_specialisation_room_device_0000000001->ent_room_device;

        rel_room_device_contained_in_room_0000000001 = ent_room_device_0000000001->rel_contained_in_room_head;

        if (rel_room_device_contained_in_room_0000000001 != NULL) {

            ent_room_0000000001 = rel_room_device_contained_in_room_0000000001->ent_room;

            /* Traverse - TraverseSelection */

            adm_object_existent_room(
                ent_room_0000000001,
                3, 28, 37);

            rel_room_contains_room_device_0000000002 = ent_room_0000000001->rel_contains_room_device_head;

            if (rel_room_contains_room_device_0000000002 != NULL) {

                while (rel_room_contains_room_device_0000000002 != NULL) {

                    ent_room_device_0000000002 = rel_room_contains_room_device_0000000002->ent_room_device;

                    rel_room_device_generalisation_secret_panel_0000000002 = ent_room_device_0000000002->rel_generalisation_secret_panel_head;

                    if (rel_room_device_generalisation_secret_panel_0000000002 != NULL) {

                        ent_secret_panel_0000000002 = rel_room_device_generalisation_secret_panel_0000000002->ent_secret_panel;

                        rel_secret_panel_opened_by_unlocking_sequence_0000000002 = ent_secret_panel_0000000002->rel_opened_by_unlocking_sequence_head;

                        if (rel_secret_panel_opened_by_unlocking_sequence_0000000002 != NULL) {

                            while (rel_secret_panel_opened_by_unlocking_sequence_0000000002 != NULL) {

                                ent_unlocking_sequence_0000000002 = rel_secret_panel_opened_by_unlocking_sequence_0000000002->ent_unlocking_sequence;

                                /* GenerateEvent */

                                adm_send_event_unlocking_sequence_reset(
                                    ent_room_door,
                                    ent_unlocking_sequence_0000000002,
                                    3, 33, 41);

                                rel_secret_panel_opened_by_unlocking_sequence_0000000002 = rel_secret_panel_opened_by_unlocking_sequence_0000000002->next;
                            }

                        } else {

                            adm_error_report(
                                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                                3, 30, 37,
                                "Secret_Panel",
                                ent_secret_panel_0000000002->identity,
                                "Opened_by",
                                "Unlocking_Sequence");
                        }
                    }

                    rel_room_contains_room_device_0000000002 = rel_room_contains_room_device_0000000002->next;
                }

            } else {

                adm_error_report(
                    ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                    3, 28, 37,
                    "Room",
                    ent_room_0000000001->identity,
                    "Contains",
                    "Room_Device");
            }

        } else {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                3, 24, 29,
                "Room_Device",
                ent_room_device_0000000001->identity,
                "Contained_in",
                "Room");
        }

    } else {

        adm_error_report(
            ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
            3, 23, 29,
            "Room_Door",
            ent_room_door->identity,
            "Specialisation",
            "Room_Device");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_room_door_open");
    #endif
}

void adm_state_action_room_door_closed(
    adm_ent_room_door_typ * const ent_room_door)
{
    /* Entity Objects */
    adm_ent_room_device_typ * ent_room_device_0000000001;
    adm_ent_room_typ * ent_room_0000000001;
    adm_ent_room_device_typ * ent_room_device_0000000002;
    adm_ent_secret_panel_typ * ent_secret_panel_0000000002;
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence_0000000002;

    /* Relationship Relations */
    adm_rel_room_door_specialisation_room_device_typ * rel_room_door_specialisation_room_device_0000000001;
    adm_rel_room_device_contained_in_room_typ * rel_room_device_contained_in_room_0000000001;
    adm_rel_room_contains_room_device_typ * rel_room_contains_room_device_0000000002;
    adm_rel_room_device_generalisation_secret_panel_typ * rel_room_device_generalisation_secret_panel_0000000002;
    adm_rel_secret_panel_opened_by_unlocking_sequence_typ * rel_secret_panel_opened_by_unlocking_sequence_0000000002;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_room_door_closed");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_room_door(
        ent_room_door,
        3, 51, 29);

    rel_room_door_specialisation_room_device_0000000001 = ent_room_door->rel_specialisation_room_device_head;

    if (rel_room_door_specialisation_room_device_0000000001 != NULL) {

        ent_room_device_0000000001 = rel_room_door_specialisation_room_device_0000000001->ent_room_device;

        rel_room_device_contained_in_room_0000000001 = ent_room_device_0000000001->rel_contained_in_room_head;

        if (rel_room_device_contained_in_room_0000000001 != NULL) {

            ent_room_0000000001 = rel_room_device_contained_in_room_0000000001->ent_room;

            /* Traverse - TraverseSelection */

            adm_object_existent_room(
                ent_room_0000000001,
                3, 56, 37);

            rel_room_contains_room_device_0000000002 = ent_room_0000000001->rel_contains_room_device_head;

            if (rel_room_contains_room_device_0000000002 != NULL) {

                while (rel_room_contains_room_device_0000000002 != NULL) {

                    ent_room_device_0000000002 = rel_room_contains_room_device_0000000002->ent_room_device;

                    rel_room_device_generalisation_secret_panel_0000000002 = ent_room_device_0000000002->rel_generalisation_secret_panel_head;

                    if (rel_room_device_generalisation_secret_panel_0000000002 != NULL) {

                        ent_secret_panel_0000000002 = rel_room_device_generalisation_secret_panel_0000000002->ent_secret_panel;

                        rel_secret_panel_opened_by_unlocking_sequence_0000000002 = ent_secret_panel_0000000002->rel_opened_by_unlocking_sequence_head;

                        if (rel_secret_panel_opened_by_unlocking_sequence_0000000002 != NULL) {

                            while (rel_secret_panel_opened_by_unlocking_sequence_0000000002 != NULL) {

                                ent_unlocking_sequence_0000000002 = rel_secret_panel_opened_by_unlocking_sequence_0000000002->ent_unlocking_sequence;

                                /* GenerateEvent */

                                adm_send_event_unlocking_sequence_activate(
                                    ent_room_door,
                                    ent_unlocking_sequence_0000000002,
                                    3, 61, 41);

                                rel_secret_panel_opened_by_unlocking_sequence_0000000002 = rel_secret_panel_opened_by_unlocking_sequence_0000000002->next;
                            }

                        } else {

                            adm_error_report(
                                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                                3, 58, 37,
                                "Secret_Panel",
                                ent_secret_panel_0000000002->identity,
                                "Opened_by",
                                "Unlocking_Sequence");
                        }
                    }

                    rel_room_contains_room_device_0000000002 = rel_room_contains_room_device_0000000002->next;
                }

            } else {

                adm_error_report(
                    ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                    3, 56, 37,
                    "Room",
                    ent_room_0000000001->identity,
                    "Contains",
                    "Room_Device");
            }

        } else {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                3, 52, 29,
                "Room_Device",
                ent_room_device_0000000001->identity,
                "Contained_in",
                "Room");
        }

    } else {

        adm_error_report(
            ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
            3, 51, 29,
            "Room_Door",
            ent_room_door->identity,
            "Specialisation",
            "Room_Device");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_room_door_closed");
    #endif
}

void adm_state_action_room_door_locked(
    adm_ent_room_door_typ * const ent_room_door)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_room_door_locked");
    #endif

    /* Template */

    adm_template_tab_in(3, 74, 21);
    adm_template_tab_in(3, 74, 21);
    adm_write_newline();
    adm_write_str("EVENT => Machinery::Actuator:Lock_door");
    adm_write_newline();
    adm_template_tab_out(3, 74, 21);
    adm_template_tab_out(3, 74, 21);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_room_door_locked");
    #endif
}

void adm_state_action_room_door_unlocked(
    adm_ent_room_door_typ * const ent_room_door)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_room_door_unlocked");
    #endif

    /* Template */

    adm_template_tab_in(3, 93, 21);
    adm_template_tab_in(3, 93, 21);
    adm_write_newline();
    adm_write_str("EVENT => Machinery::Actuator:Unlock_door");
    adm_write_newline();
    adm_template_tab_out(3, 93, 21);
    adm_template_tab_out(3, 93, 21);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_room_door_unlocked");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */