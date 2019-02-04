# Fract'ol
This project is meant to create graphically beautiful fractals | UNIT Factory
-----------------------------------------------------------------------------
The main goal of this project was to create a small fractal exploration program, to discover the mathematical notion of complex numbers and the basic concept of optimization in computer graphics.

- The program offers 8 different types of fractals: Mandelbrot, Julia, Burning_ship, flower(selfmade, variation of Julia), beetle, celtic, iricorn, heart.
- It is possible to make the parameter of the Julia set vary only with the mouse (without clicking).
- The mouse wheel zooms in and out.
- You can set up different colors pallete by changing RGB channels (pressing the appropriate 'R', 'G', 'B' keys, 'C' - grayscale mode).
- The parameter is passed on the command line to define what type of fractal will be viewed.
- Graphic library miniLibX was used. This library was developed internally and includes the minimum necessary to open a window, light a pixel and deal with events linked to this window: keyboard and mouse.

usage: ./fractol [mandelbrot/julia/burning_ship/flower/beetle/celtic/iricorn/heart]

BONUS PART:
- additional fractals;
- moveng with arrows;
- color range shift;
- multi-threading implementation.

<table style="width:100%">
  <tr>
    <td><img src="https://github.com/nkuchyna/Fractol/blob/master/screenshots/mandelbrot.png" data-canonical-src="mandelbrot" width="400"/></td>
    <td><img src="https://github.com/nkuchyna/Fractol/blob/master/screenshots/julia.png" data-canonical-src="julia" width="400"/></td> 
  </tr>
  <tr>
    <td><img src="https://github.com/nkuchyna/Fractol/blob/master/screenshots/burning_ship.png" data-canonical-src="burning_ship" width="400"/></td>
    <td><img src="https://github.com/nkuchyna/Fractol/blob/master/screenshots/flower.png" data-canonical-src="flower" width="400"/></td> 
  </tr>
    <tr>
    <td><img src="https://github.com/nkuchyna/Fractol/blob/master/screenshots/beetle.png" data-canonical-src="beetle" width="400"/></td>
     <td><img src="https://github.com/nkuchyna/Fractol/blob/master/screenshots/celtic.png" data-canonical-src="celtic" width="400"/></td> 
  </tr>
  <tr>
    <td><img src="https://github.com/nkuchyna/Fractol/blob/master/screenshots/iricorn.png" data-canonical-src="iricorn" width="400"/></td>
    <td><img src="https://github.com/nkuchyna/Fractol/blob/master/screenshots/heart.png" data-canonical-src="heart" width="400"/></td>
  </tr>
</table>
