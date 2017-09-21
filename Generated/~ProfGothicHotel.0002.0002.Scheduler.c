
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Domain Scheduler */

void adm_scheduler_dom_gothic_security(
    void)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SCHEDULER, "adm_scheduler_dom_gothic_security");
    #endif

    if (adm_entity_system.ent_room_device.away_pool_head != NULL) adm_dispatcher_room_device();
    if (adm_entity_system.ent_room_door.away_pool_head != NULL) adm_dispatcher_room_door();
    if (adm_entity_system.ent_secret_panel.away_pool_head != NULL) adm_dispatcher_secret_panel();
    if (adm_entity_system.ent_unlocking_device.away_pool_head != NULL) adm_dispatcher_unlocking_device();
    if (adm_entity_system.ent_unlocking_sequence.away_pool_head != NULL) adm_dispatcher_unlocking_sequence();
    if (adm_entity_system.ent_unlock_step.away_pool_head != NULL) adm_dispatcher_unlock_step();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SCHEDULER, "adm_scheduler_dom_gothic_security");
    #endif
}

adm_base_boolean_typ adm_scheduler_determine_termination_dom_gothic_security(
    void)
{
    adm_base_boolean_typ event_pending;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SCHEDULER, "adm_scheduler_determine_termination_dom_gothic_security");
    #endif

    event_pending =
        (adm_entity_system.ent_room_device.away_pool_head != NULL) ||
        (adm_entity_system.ent_room_door.away_pool_head != NULL) ||
        (adm_entity_system.ent_secret_panel.away_pool_head != NULL) ||
        (adm_entity_system.ent_unlocking_device.away_pool_head != NULL) ||
        (adm_entity_system.ent_unlocking_sequence.away_pool_head != NULL) ||
        (adm_entity_system.ent_unlock_step.away_pool_head != NULL);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SCHEDULER, "adm_scheduler_determine_termination_dom_gothic_security");
    #endif

    return (event_pending);
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */