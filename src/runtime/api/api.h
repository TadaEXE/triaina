#pragma once

extern "C" {

// NODE
void node_create();
void node_delete();
void node_set_evaluator();

void node_add_port();
void node_remove_port();

// EDGE
void edge_create();
void edge_find();
void edge_delete();

// EVALUATOR
void evaluator_create();
void evaluator_delete();
void evaluator_find();

// ACTIONS
void action_set_input();
void action_get_output();
}
