#include <stdlib.h>
#include "fsm.h"

fsm_t*
fsm_new (fsm_trans_t* tt)
{
	fsm_t* this = (fsm_t*) malloc (sizeof (fsm_t));
	fsm_init (this, tt);
	return this;
}

void
fsm_init (fsm_t* this, fsm_trans_t* tt)
{
	this->current_state = tt[0].orig_state;
	this->tt = tt;
}


/*comprueba el estado de la guarda*/
void
fsm_fire (fsm_t* this)
{
	fsm_trans_t* t;
	for (t = this->tt; t->orig_state >= 0; ++t) {/*recorre la tabla de transicion */
		if ((this->current_state == t->orig_state) && t->in(this)) {//verifica si estoy en el estado actual y si la guarda es 1
			this->current_state = t->dest_state;
			if (t->out)
			t->out(this);
			break;
		}
	}
}
