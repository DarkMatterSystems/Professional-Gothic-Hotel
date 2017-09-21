
/* Simulator System Prototype Internals Header */

/* Display Entity Prototypes */

void adm_sim_display_entity_room_device(
    void);

void adm_sim_display_entity_room_door(
    void);

void adm_sim_display_entity_secret_panel(
    void);

void adm_sim_display_entity_unlocking_device(
    void);

void adm_sim_display_entity_unlocking_sequence(
    void);

void adm_sim_display_entity_unlock_step(
    void);

void adm_sim_display_entity_room(
    void);


/* Acquire Identity Event Prototypes */

void adm_sim_acquire_identity_event_room_device_device_update(
    void);

void adm_sim_acquire_identity_event_room_door_door_closed(
    void);

void adm_sim_acquire_identity_event_room_door_door_opened(
    void);

void adm_sim_acquire_identity_event_room_door_lock_door(
    void);

void adm_sim_acquire_identity_event_room_door_unlock_door(
    void);

void adm_sim_acquire_identity_event_secret_panel_unlock_panel(
    void);

void adm_sim_acquire_identity_event_secret_panel_panel_closed(
    void);

void adm_sim_acquire_identity_event_unlocking_device_device_update(
    void);

void adm_sim_acquire_identity_event_unlocking_sequence_activate(
    void);

void adm_sim_acquire_identity_event_unlocking_sequence_reset(
    void);

void adm_sim_acquire_identity_event_unlocking_sequence_complete(
    void);

void adm_sim_acquire_identity_event_unlock_step_reset(
    void);

void adm_sim_acquire_identity_event_unlock_step_advance(
    void);

void adm_sim_acquire_identity_event_unlock_step_select(
    void);

void adm_sim_acquire_identity_event_unlock_step_prime(
    void);


/* Acquire Identifier Event Prototypes */

void adm_sim_acquire_identifier_event_room_device_device_update_room_device_identifier(
    void);

void adm_sim_acquire_identifier_event_room_door_door_closed_room_door_identifier(
    void);

void adm_sim_acquire_identifier_event_room_door_door_opened_room_door_identifier(
    void);

void adm_sim_acquire_identifier_event_room_door_lock_door_room_door_identifier(
    void);

void adm_sim_acquire_identifier_event_room_door_unlock_door_room_door_identifier(
    void);


/* Display Event Prototypes */

void adm_sim_display_event_room_device_device_update(
    const adm_ent_room_device_typ * const ent_room_device,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_room_door_door_closed(
    const adm_ent_room_door_typ * const ent_room_door,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_room_door_door_opened(
    const adm_ent_room_door_typ * const ent_room_door,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_room_door_lock_door(
    const adm_ent_room_door_typ * const ent_room_door,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_room_door_unlock_door(
    const adm_ent_room_door_typ * const ent_room_door,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_secret_panel_unlock_panel(
    const adm_ent_secret_panel_typ * const ent_secret_panel,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_secret_panel_panel_closed(
    const adm_ent_secret_panel_typ * const ent_secret_panel,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_unlocking_device_device_update(
    const adm_ent_unlocking_device_typ * const ent_unlocking_device,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_unlocking_sequence_activate(
    const adm_ent_unlocking_sequence_typ * const ent_unlocking_sequence,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_unlocking_sequence_reset(
    const adm_ent_unlocking_sequence_typ * const ent_unlocking_sequence,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_unlocking_sequence_complete(
    const adm_ent_unlocking_sequence_typ * const ent_unlocking_sequence,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_unlock_step_reset(
    const adm_ent_unlock_step_typ * const ent_unlock_step,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_unlock_step_advance(
    const adm_ent_unlock_step_typ * const ent_unlock_step,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_unlock_step_select(
    const adm_ent_unlock_step_typ * const ent_unlock_step,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_sim_display_event_unlock_step_prime(
    const adm_ent_unlock_step_typ * const ent_unlock_step,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);


/* Display State Prototypes */

void adm_sim_display_state_room_device_redirect(
    adm_pool_target_room_device_typ * pool_target);

void adm_sim_display_state_room_door_open(
    adm_pool_target_room_door_typ * pool_target);

void adm_sim_display_state_room_door_closed(
    adm_pool_target_room_door_typ * pool_target);

void adm_sim_display_state_room_door_locked(
    adm_pool_target_room_door_typ * pool_target);

void adm_sim_display_state_room_door_unlocked(
    adm_pool_target_room_door_typ * pool_target);

void adm_sim_display_state_secret_panel_closed(
    adm_pool_target_secret_panel_typ * pool_target);

void adm_sim_display_state_secret_panel_opened(
    adm_pool_target_secret_panel_typ * pool_target);

void adm_sim_display_state_unlocking_device_updating(
    adm_pool_target_unlocking_device_typ * pool_target);

void adm_sim_display_state_unlocking_sequence_idle(
    adm_pool_target_unlocking_sequence_typ * pool_target);

void adm_sim_display_state_unlocking_sequence_active(
    adm_pool_target_unlocking_sequence_typ * pool_target);

void adm_sim_display_state_unlocking_sequence_complete(
    adm_pool_target_unlocking_sequence_typ * pool_target);

void adm_sim_display_state_unlock_step_wrong_step(
    adm_pool_target_unlock_step_typ * pool_target);

void adm_sim_display_state_unlock_step_locked(
    adm_pool_target_unlock_step_typ * pool_target);

void adm_sim_display_state_unlock_step_selected(
    adm_pool_target_unlock_step_typ * pool_target);

void adm_sim_display_state_unlock_step_primed(
    adm_pool_target_unlock_step_typ * pool_target);

void adm_sim_display_state_unlock_step_unlocked(
    adm_pool_target_unlock_step_typ * pool_target);


/* Find Event Name Prototype */

adm_base_string_typ * adm_sim_find_event_name(
    adm_base_integer_typ entity_index,
    adm_base_integer_typ entity_event_index);

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */