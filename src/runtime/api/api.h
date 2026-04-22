#pragma once

extern "C" {
void node_create();
void node_delete();
void node_set_evaluator();
void node_add_port();
void node_remove_port();

void vertex_create();
void vertex_delete();

void evaluator_create();
void evaluator_delete();
void evaluator_find();
}
