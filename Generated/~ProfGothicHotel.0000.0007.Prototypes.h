
/* System Prototypes Header */

/* Main Prototype */

int main(
    int,
    char * []);


/* System Library */

void * adm_allocate_memory(
    adm_base_integer_typ amount);

void adm_deallocate_memory(
    const void * memory);

void adm_open_stream_file(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_close_stream_file(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_write_int(
    adm_base_integer_typ number);

void adm_write_bln(
    adm_base_boolean_typ value);

void adm_write_fxd(
    adm_base_fixed_typ number);

void adm_write_flt(
    adm_base_float_typ number);

void adm_write_str(
    const adm_base_string_typ * const string);

void adm_write_newline(void);

void adm_template_tab_in(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_template_tab_out(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_display_tab_in(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_display_tab_out(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_convert_string_upper_case(
    const adm_base_string_typ * const source_string,
    adm_base_string_typ * const target_string);

void adm_convert_string_lower_case(
    const adm_base_string_typ * const source_string,
    adm_base_string_typ * const target_string);

void adm_convert_string_sentence_case(
    const adm_base_string_typ * const source_string,
    adm_base_string_typ * const target_string);

void adm_convert_string_capital_case(
    const adm_base_string_typ * const source_string,
    adm_base_string_typ * const target_string);

void adm_convert_string_remove_spaces(
    const adm_base_string_typ * const source_string,
    adm_base_string_typ * const target_string);

void adm_convert_string_convert_underlines(
    const adm_base_string_typ * const source_string,
    adm_base_string_typ * const target_string);

void adm_integrity_check(void);


#if ADM_PROBE

void adm_probe_enter(
    adm_probe_group_typ   group,
    adm_base_string_typ * procedure_name);

void adm_probe_leave(
    adm_probe_group_typ   group,
    adm_base_string_typ * procedure_name);

void adm_add_spaces(
    adm_base_string_typ  * space_string,
    adm_base_integer_typ   space_number);

#endif


/* System Error Handler */

void adm_error_report(
    adm_err_number_typ          error,
    adm_err_file_typ            file,
    adm_err_line_typ            line,
    adm_err_rank_typ            rank,
    adm_err_problem_typ       * source,
    adm_base_integer_typ        identity,
    adm_err_problem_typ       * relation,
    const adm_err_problem_typ * target);


/* Initialisation Prototype */

void adm_initialisation(void);


/* Domain Initialisation Prototypes */

void adm_initialisation_gothic_security(void);


/* System Scheduler Prototypes */

void adm_scheduler(void);

void adm_scheduler_dom_gothic_security(void);


/* System Initialisation Scheduler Prototypes */

void adm_scheduler_initialisation(void);

void adm_scheduler_initialisation_gothic_security(void);


/* System Determine Termination Scheduler Prototypes */

adm_base_boolean_typ adm_scheduler_determine_termination(void);

adm_base_boolean_typ adm_scheduler_determine_termination_dom_gothic_security(void);


/* Data Access Prototypes */

adm_ent_room_device_typ * adm_make_object_room_device(
    adm_sta_room_device_typ status);

adm_ent_room_door_typ * adm_make_object_room_door(
    adm_sta_room_door_typ status);

adm_ent_secret_panel_typ * adm_make_object_secret_panel(
    adm_sta_secret_panel_typ status);

adm_ent_unlocking_device_typ * adm_make_object_unlocking_device(
    adm_sta_unlocking_device_typ status);

adm_ent_unlocking_sequence_typ * adm_make_object_unlocking_sequence(
    adm_sta_unlocking_sequence_typ status);

adm_ent_unlock_step_typ * adm_make_object_unlock_step(
    adm_sta_unlock_step_typ status);

adm_ent_room_typ * adm_make_object_room(void);

void adm_bind_object_room_device(
    adm_ent_room_device_typ * ent_room_device,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_room_door(
    adm_ent_room_door_typ * ent_room_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_secret_panel(
    adm_ent_secret_panel_typ * ent_secret_panel,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_unlocking_device(
    adm_ent_unlocking_device_typ * ent_unlocking_device,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_unlocking_sequence(
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_unlock_step(
    adm_ent_unlock_step_typ * ent_unlock_step,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_room(
    adm_ent_room_typ * ent_room,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_room_device(
    void * source_object,
    adm_ent_room_device_typ * ent_room_device,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_room_door(
    void * source_object,
    adm_ent_room_door_typ * ent_room_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_secret_panel(
    void * source_object,
    adm_ent_secret_panel_typ * ent_secret_panel,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_unlocking_device(
    void * source_object,
    adm_ent_unlocking_device_typ * ent_unlocking_device,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_unlocking_sequence(
    void * source_object,
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_unlock_step(
    void * source_object,
    adm_ent_unlock_step_typ * ent_unlock_step,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_room(
    void * source_object,
    adm_ent_room_typ * ent_room,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_room_device_contained_in_room(
    adm_ent_room_device_typ * ent_source_room_device,
    adm_ent_room_typ * ent_target_room,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_room_device_generalisation_room_door(
    adm_ent_room_device_typ * ent_source_room_device,
    adm_ent_room_door_typ * ent_target_room_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_room_device_generalisation_secret_panel(
    adm_ent_room_device_typ * ent_source_room_device,
    adm_ent_secret_panel_typ * ent_target_secret_panel,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_room_device_generalisation_unlocking_device(
    adm_ent_room_device_typ * ent_source_room_device,
    adm_ent_unlocking_device_typ * ent_target_unlocking_device,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_room_door_specialisation_room_device(
    adm_ent_room_door_typ * ent_source_room_door,
    adm_ent_room_device_typ * ent_target_room_device,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_secret_panel_opened_by_unlocking_sequence(
    adm_ent_secret_panel_typ * ent_source_secret_panel,
    adm_ent_unlocking_sequence_typ * ent_target_unlocking_sequence,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_secret_panel_specialisation_room_device(
    adm_ent_secret_panel_typ * ent_source_secret_panel,
    adm_ent_room_device_typ * ent_target_room_device,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_unlocking_device_sets_unlock_step(
    adm_ent_unlocking_device_typ * ent_source_unlocking_device,
    adm_ent_unlock_step_typ * ent_target_unlock_step,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_unlocking_sequence_opens_secret_panel(
    adm_ent_unlocking_sequence_typ * ent_source_unlocking_sequence,
    adm_ent_secret_panel_typ * ent_target_secret_panel,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_unlocking_sequence_starts_at_unlock_step(
    adm_ent_unlocking_sequence_typ * ent_source_unlocking_sequence,
    adm_ent_unlock_step_typ * ent_target_unlock_step,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_unlock_step_followed_by_unlock_step(
    adm_ent_unlock_step_typ * ent_source_unlock_step,
    adm_ent_unlock_step_typ * ent_target_unlock_step,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_unlock_step_part_of_unlocking_sequence(
    adm_ent_unlock_step_typ * ent_source_unlock_step,
    adm_ent_unlocking_sequence_typ * ent_target_unlocking_sequence,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_room_contains_room_device(
    adm_ent_room_typ * ent_source_room,
    adm_ent_room_device_typ * ent_target_room_device,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_room_device_contained_in_room(
    adm_ent_room_device_typ * ent_room_device,
    adm_rel_room_device_contained_in_room_typ * rel_room_device_contained_in_room,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_room_device_generalisation_room_door(
    adm_ent_room_device_typ * ent_room_device,
    adm_rel_room_device_generalisation_room_door_typ * rel_room_device_generalisation_room_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_room_device_generalisation_secret_panel(
    adm_ent_room_device_typ * ent_room_device,
    adm_rel_room_device_generalisation_secret_panel_typ * rel_room_device_generalisation_secret_panel,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_room_device_generalisation_unlocking_device(
    adm_ent_room_device_typ * ent_room_device,
    adm_rel_room_device_generalisation_unlocking_device_typ * rel_room_device_generalisation_unlocking_device,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_room_door_specialisation_room_device(
    adm_ent_room_door_typ * ent_room_door,
    adm_rel_room_door_specialisation_room_device_typ * rel_room_door_specialisation_room_device,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_secret_panel_opened_by_unlocking_sequence(
    adm_ent_secret_panel_typ * ent_secret_panel,
    adm_rel_secret_panel_opened_by_unlocking_sequence_typ * rel_secret_panel_opened_by_unlocking_sequence,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_secret_panel_specialisation_room_device(
    adm_ent_secret_panel_typ * ent_secret_panel,
    adm_rel_secret_panel_specialisation_room_device_typ * rel_secret_panel_specialisation_room_device,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_unlocking_device_sets_unlock_step(
    adm_ent_unlocking_device_typ * ent_unlocking_device,
    adm_rel_unlocking_device_sets_unlock_step_typ * rel_unlocking_device_sets_unlock_step,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_unlocking_sequence_opens_secret_panel(
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence,
    adm_rel_unlocking_sequence_opens_secret_panel_typ * rel_unlocking_sequence_opens_secret_panel,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_unlocking_sequence_starts_at_unlock_step(
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence,
    adm_rel_unlocking_sequence_starts_at_unlock_step_typ * rel_unlocking_sequence_starts_at_unlock_step,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_unlock_step_followed_by_unlock_step(
    adm_ent_unlock_step_typ * ent_unlock_step,
    adm_rel_unlock_step_followed_by_unlock_step_typ * rel_unlock_step_followed_by_unlock_step,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_unlock_step_part_of_unlocking_sequence(
    adm_ent_unlock_step_typ * ent_unlock_step,
    adm_rel_unlock_step_part_of_unlocking_sequence_typ * rel_unlock_step_part_of_unlocking_sequence,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_room_contains_room_device(
    adm_ent_room_typ * ent_room,
    adm_rel_room_contains_room_device_typ * rel_room_contains_room_device,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_room_device(
    const adm_ent_room_device_typ * const ent_room_device,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_object_existent_room_door(
    const adm_ent_room_door_typ * const ent_room_door,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_object_existent_secret_panel(
    const adm_ent_secret_panel_typ * const ent_secret_panel,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_object_existent_unlocking_device(
    const adm_ent_unlocking_device_typ * const ent_unlocking_device,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_object_existent_unlocking_sequence(
    const adm_ent_unlocking_sequence_typ * const ent_unlocking_sequence,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_object_existent_unlock_step(
    const adm_ent_unlock_step_typ * const ent_unlock_step,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_object_existent_room(
    const adm_ent_room_typ * const ent_room,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);


/* Event Sender Prototypes */

void adm_send_event_room_device_device_update(
    const void * const source_object,
    const adm_ent_room_device_typ * const ent_room_device,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_room_door_door_closed(
    const void * const source_object,
    const adm_ent_room_door_typ * const ent_room_door,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_room_door_door_opened(
    const void * const source_object,
    const adm_ent_room_door_typ * const ent_room_door,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_room_door_lock_door(
    const void * const source_object,
    const adm_ent_room_door_typ * const ent_room_door,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_room_door_unlock_door(
    const void * const source_object,
    const adm_ent_room_door_typ * const ent_room_door,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_secret_panel_unlock_panel(
    const void * const source_object,
    const adm_ent_secret_panel_typ * const ent_secret_panel,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_secret_panel_panel_closed(
    const void * const source_object,
    const adm_ent_secret_panel_typ * const ent_secret_panel,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_unlocking_device_device_update(
    const void * const source_object,
    const adm_ent_unlocking_device_typ * const ent_unlocking_device,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_unlocking_sequence_activate(
    const void * const source_object,
    const adm_ent_unlocking_sequence_typ * const ent_unlocking_sequence,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_unlocking_sequence_reset(
    const void * const source_object,
    const adm_ent_unlocking_sequence_typ * const ent_unlocking_sequence,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_unlocking_sequence_complete(
    const void * const source_object,
    const adm_ent_unlocking_sequence_typ * const ent_unlocking_sequence,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_unlock_step_reset(
    const void * const source_object,
    const adm_ent_unlock_step_typ * const ent_unlock_step,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_unlock_step_advance(
    const void * const source_object,
    const adm_ent_unlock_step_typ * const ent_unlock_step,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_unlock_step_select(
    const void * const source_object,
    const adm_ent_unlock_step_typ * const ent_unlock_step,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);

void adm_send_event_unlock_step_prime(
    const void * const source_object,
    const adm_ent_unlock_step_typ * const ent_unlock_step,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank);


/* Dispatcher Prototypes */

void adm_dispatcher_room_device         (void);
void adm_dispatch_home_pool_room_device (void);

adm_pool_target_room_device_typ * adm_find_home_target_event_room_device (void);
adm_pool_target_room_device_typ * adm_find_away_target_event_room_device (void);

void adm_dispatch_state_action_room_device(
    adm_pool_target_room_device_typ * pool_target_room_device);

void adm_dispatcher_room_door         (void);
void adm_dispatch_home_pool_room_door (void);

adm_pool_target_room_door_typ * adm_find_home_target_event_room_door (void);
adm_pool_target_room_door_typ * adm_find_away_target_event_room_door (void);

void adm_dispatch_state_action_room_door(
    adm_pool_target_room_door_typ * pool_target_room_door);

void adm_dispatcher_secret_panel         (void);
void adm_dispatch_home_pool_secret_panel (void);

adm_pool_target_secret_panel_typ * adm_find_home_target_event_secret_panel (void);
adm_pool_target_secret_panel_typ * adm_find_away_target_event_secret_panel (void);

void adm_dispatch_state_action_secret_panel(
    adm_pool_target_secret_panel_typ * pool_target_secret_panel);

void adm_dispatcher_unlocking_device         (void);
void adm_dispatch_home_pool_unlocking_device (void);

adm_pool_target_unlocking_device_typ * adm_find_home_target_event_unlocking_device (void);
adm_pool_target_unlocking_device_typ * adm_find_away_target_event_unlocking_device (void);

void adm_dispatch_state_action_unlocking_device(
    adm_pool_target_unlocking_device_typ * pool_target_unlocking_device);

void adm_dispatcher_unlocking_sequence         (void);
void adm_dispatch_home_pool_unlocking_sequence (void);

adm_pool_target_unlocking_sequence_typ * adm_find_home_target_event_unlocking_sequence (void);
adm_pool_target_unlocking_sequence_typ * adm_find_away_target_event_unlocking_sequence (void);

void adm_dispatch_state_action_unlocking_sequence(
    adm_pool_target_unlocking_sequence_typ * pool_target_unlocking_sequence);

void adm_dispatcher_unlock_step         (void);
void adm_dispatch_home_pool_unlock_step (void);

adm_pool_target_unlock_step_typ * adm_find_home_target_event_unlock_step (void);
adm_pool_target_unlock_step_typ * adm_find_away_target_event_unlock_step (void);

void adm_dispatch_state_action_unlock_step(
    adm_pool_target_unlock_step_typ * pool_target_unlock_step);


/* State Action Prototypes */

void adm_state_action_room_device_redirect(
    adm_ent_room_device_typ * const ent_room_device);

void adm_state_action_room_door_open(
    adm_ent_room_door_typ * const ent_room_door);

void adm_state_action_room_door_closed(
    adm_ent_room_door_typ * const ent_room_door);

void adm_state_action_room_door_locked(
    adm_ent_room_door_typ * const ent_room_door);

void adm_state_action_room_door_unlocked(
    adm_ent_room_door_typ * const ent_room_door);

void adm_state_action_secret_panel_closed(
    adm_ent_secret_panel_typ * const ent_secret_panel);

void adm_state_action_secret_panel_opened(
    adm_ent_secret_panel_typ * const ent_secret_panel);

void adm_state_action_unlocking_device_updating(
    adm_ent_unlocking_device_typ * const ent_unlocking_device);

void adm_state_action_unlocking_sequence_idle(
    adm_ent_unlocking_sequence_typ * const ent_unlocking_sequence);

void adm_state_action_unlocking_sequence_active(
    adm_ent_unlocking_sequence_typ * const ent_unlocking_sequence);

void adm_state_action_unlocking_sequence_complete(
    adm_ent_unlocking_sequence_typ * const ent_unlocking_sequence);

void adm_state_action_unlock_step_wrong_step(
    adm_ent_unlock_step_typ * const ent_unlock_step);

void adm_state_action_unlock_step_unlocked(
    adm_ent_unlock_step_typ * const ent_unlock_step);


/* Identifier Prototypes */

void adm_check_identifiers_unique_room_device(
    adm_ent_room_device_typ * ent_source_room_device,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_check_identifiers_unique_room_door(
    adm_ent_room_door_typ * ent_source_room_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_check_identifiers_unique_room(
    adm_ent_room_typ * ent_source_room,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);


/* Process Include Entity Prototypes */

void adm_ent_pro_unlocking_sequence_0106_process_reset_unlock_steps(
    adm_ent_unlock_step_typ * ent_unlock_step_0000000001,
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence);

void adm_ent_pro_unlocking_sequence_0106_process_select_unlock_steps(
    adm_ent_unlock_step_typ * ent_unlock_step_0000000001,
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence);

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */