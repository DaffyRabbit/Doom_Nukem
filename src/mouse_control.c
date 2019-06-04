
#include "wolf3d.h"

int			mouse_control(int x, int y, t_box *box)
{	
		box->mouse.old_px = box->cam.p.x;
		box->cam.p.x = box->cam.p.x * cos((x) * box->mouse.rot_spd) -
			box->cam.p.y * sin((x) * box->mouse.rot_spd);
		box->cam.p.y = box->mouse.old_px * sin((x) * box->mouse.rot_spd) +
			box->cam.p.y * cos((x) * box->mouse.rot_spd);
			box->mouse.od_x = box->cam.d.x;
		box->cam.d.x = box->cam.d.x * cos((x) * box->mouse.rot_spd) -
			box->cam.d.y * sin((x) * box->mouse.rot_spd);
		box->cam.d.y = box->mouse.od_x * sin((x) * box->mouse.rot_spd) +
			box->cam.d.y * cos((x) * box->mouse.rot_spd);
	if (box->ogo.lop <= WIND_H / 2 && box->ogo.lop >= -WIND_H / 2)
		box->ogo.lop += -y * 1.2;
	if (box->ogo.lop > WIND_H / 2)
		box->ogo.lop = WIND_H / 2;
	if (box->ogo.lop < -WIND_H / 2)
		box->ogo.lop = -WIND_H / 2;
	return(0);
}

