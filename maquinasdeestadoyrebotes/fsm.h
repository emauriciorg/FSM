#ifndef FSM_H
#define FSM_H

typedef struct fsm_t fsm_t;//estructura de la maquina, no se mdifica

typedef int (*fsm_input_func_t) (fsm_t*);//guarda
typedef void (*fsm_output_func_t) (fsm_t*);//salida

typedef struct fsm_trans_t {//estructura de la tabla de //transiciones
  int orig_state;
  fsm_input_func_t in;
  int dest_state;
  fsm_output_func_t out;
} fsm_trans_t;

struct fsm_t {
  int current_state;
  fsm_trans_t* tt;//tabla de transiciones
};

fsm_t* fsm_new (fsm_trans_t* tt);
void fsm_init (fsm_t* this, fsm_trans_t* tt);//diseño orientado a objetos
void fsm_fire (fsm_t* this);//

#endif
