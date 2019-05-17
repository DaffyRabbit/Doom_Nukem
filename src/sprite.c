#include "wolf3d.h"

void        add_sprite(t_box *box, char n, int x, int y)
{
  box->sprites.spt[box->sprites.n_sprites].x = x+0.5;
  box->sprites.spt[box->sprites.n_sprites].y = y+0.5;
  if (n == '2')
    box->sprites.spt[box->sprites.n_sprites].n_text = 0;
  if (n == '3')
    box->sprites.spt[box->sprites.n_sprites].n_text = 1;
  if (n == '4')
    box->sprites.spt[box->sprites.n_sprites].n_text = 2;
  if (n == '5')
    box->sprites.spt[box->sprites.n_sprites].n_text = 3;
  if (n == '6')
    box->sprites.spt[box->sprites.n_sprites].n_text = 4;
  box->sprites.n_sprites++;
}

void		draw_sprites(t_box *box)
{
  box->dsprite.i = 0;
	sort_sprits(box);
  while(box->dsprite.i < box->sprites.n_sprites)
  {
    draw_sprites2(box);
    while(box->dsprite.drawStartX < box->dsprite.drawEndX)
    {
      box->dsprite.texX = (int)(256 * (box->dsprite.drawStartX - (-box->dsprite.spriteWidth / 2 + box->dsprite.spriteScreenX)) * 64 / box->dsprite.spriteWidth) / 256;
      box->dsprite.texX = abs(box->dsprite.texX) % 64;
      draw_sprites4(box);
      box->dsprite.drawStartX++;
    }
    box->dsprite.i++;
  }
}

void    draw_sprites2(t_box *box)
{
  box->dsprite.spriteX = box->sprites.spt[box->sprites.spriteOrder[box->dsprite.i]].x - box->cam.position.x;
  box->dsprite.spriteY = box->sprites.spt[box->sprites.spriteOrder[box->dsprite.i]].y - box->cam.position.y;
  box->dsprite.invDet = 1.0 / (box->cam.p.x * box->cam.d.y - box->cam.d.x * box->cam.p.y);
  box->dsprite.transformX = box->dsprite.invDet * (box->cam.d.y * box->dsprite.spriteX - box->cam.d.x * box->dsprite.spriteY);
  box->dsprite.transformY = box->dsprite.invDet * (-box->cam.p.y * box->dsprite.spriteX + box->cam.p.x * box->dsprite.spriteY);
  box->dsprite.spriteScreenX = (int)((WIND_W / 2) * (1 + box->dsprite.transformX / box->dsprite.transformY));
  box->dsprite.spriteHeight = abs((int)(WIND_H / (box->dsprite.transformY)));
  box->dsprite.drawStartY = -box->dsprite.spriteHeight / 2;
  box->dsprite.drawStartY -= box->dsprite.drawStartY * box->go.lop;
  box->dsprite.drawStartY += WIND_H / 2 + box->ogo.lop;
  draw_sprites3(box);
}

void    draw_sprites3(t_box *box)
{
  if(box->dsprite.drawStartY < 0)
  {
    box->dsprite.drawStartY = 0;
  }
  box->dsprite.drawEndY = box->dsprite.spriteHeight / 2;
  box->dsprite.drawEndY += box->dsprite.drawEndY * box->go.lop;
  box->dsprite.drawEndY += WIND_H / 2 + box->ogo.lop;
  if(box->dsprite.drawEndY >= WIND_H)
  {
    box->dsprite.drawEndY = WIND_H - 1;
  }
  box->dsprite.spriteWidth = abs( (int)(WIND_H / (box->dsprite.transformY)));
  box->dsprite.drawStartX = -box->dsprite.spriteWidth / 2 + box->dsprite.spriteScreenX;
  if(box->dsprite.drawStartX < 0)
  {
    box->dsprite.drawStartX = 0;
  }
  box->dsprite.drawEndX = box->dsprite.spriteWidth / 2 + box->dsprite.spriteScreenX;
  if(box->dsprite.drawEndX >= WIND_W)
  {
    box->dsprite.drawEndX = WIND_W - 1;
  }
}

void    draw_sprites4(t_box *box)
{
  Uint32    color;
  int d;
  int y;

  if(box->dsprite.transformY > 0 && box->dsprite.drawStartX > 0 && box->dsprite.drawStartX < WIND_W && box->dsprite.transformY < box->sprites.ZBuffer[box->dsprite.drawStartX])
  {
    y = box->dsprite.drawStartY;
    while(y < box->dsprite.drawEndY)
    {
      d = (y * 256 - WIND_H * 128 + box->dsprite.spriteHeight * 128 * ((-box->go.lop + 1))) - box->ogo.lop * 256;
      box->dsprite.texY = ((d * 64) / box->dsprite.spriteHeight) / 256;
      box->dsprite.texY = abs(box->dsprite.texY) % 64;
      color = get_pixel(box,box->sprites.tex_sprite[box->sprites.spt[box->sprites.spriteOrder[box->dsprite.i]].n_text],box->dsprite.texX,box->dsprite.texY);
      if((color & 0x00FFFFFF) != 0)
      {
        box->pixels[y * WIND_W + box->dsprite.drawStartX] = color;
      }
      y++;
    }
  }
}