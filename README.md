# Mini_RT

# Description
miniRT is an introductory project to the fascinating world of Ray Tracing. Once completed, you'll be able to generate simple Computer-Generated Images and won't be afraid of applying mathematical formulas anymore. In this project, you take your first steps with miniLibX, a Ray Tracer written in the C language. The primary goal of miniRT is to demonstrate your ability to apply mathematical or physics formulas. Here, we'll only implement the most basic ray tracing features.


### Requirements
Before running this program on your computer, make sure you have installed those dependencies :
```
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev
```



### Objects

* Ambient lightning: `A 0.2 255,255,255`
    * identifier: A
    * ambient lighting ratio in range [0.0,1.0]: 0.2
    * R,G,B colors in range [0-255]: 255, 255, 255

* Camera: `C  -50.0,0,200,0,1   70`
    * identifier: C
    * x,y,z coordinates of the view point: 0.0,0.0,20.6
    * 3d normalized orientation vector. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
    * FOV : Horizontal field of view in degrees in range [0,180]

* Light: `L   -40.0,50.0,0.0  0.6 10,0,255`
    * identifier: L
    * x,y,z coordinates of the light point: 0.0,0.0,20.6
    * the light brightness ratio in range [0.0,1.0]: 0.6
    * (unused in mandatory part)R,G,B colors in range [0-255]: 10, 0, 255

* Sphere: `sp  0.0,0.0,20.6  12.6  10,0,255`
    * identifier: sp
    * x,y,z coordinates of the sphere center: 0.0,0.0,20.6
    * the sphere diameter:12.6
    * R,G,B colors in range [0-255]: 255, 0, 255

* Triangle: `tr 10.0,20.0,10.0 10.0,10.0,20.0  20.0,10.0,10.0  0,0,255`
    * identifier: tr
    * x,y,z coordinates of the first point: 10.0,20.0,10.0
    * x,y,z coordinates of the first point: 10.0,10.0,20.0
    * x,y,z coordinates of the first point: 20.0,10.0,10.0
    * R,G,B colors in range [0-255]: 0, 255, 255

* Square: `sq  0.0,0.0,20.6   1.0,0.0,0.0  12.6  255,0,255`
    * identifier: pl
    * y,z coordinates of the square center: 0.0,0.0,20.6
    * 3d normalized orientation vector. In range [-1,1] for each x,y,z axis: 1.0,0.0,0.0
    * side size: 12.6
    * R,G,B colors in range [0-255]: 255, 0, 255

* Plane: `pl  0.0,0.0,-10.0 0.0,1.0,0.0  0,0,225`
    * identifier: pl
    * x,y,z coordinates: 0.0,0.0,-10.0
    * 3d normalized orientation vector. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
    * R,G,B colors in range [0-255]: 0, 255, 255

* Cylinder: `cy  50.0,0.0,20.6   0.0,0.0,1.0  14.2 21.42   10,0,255`
    * identifier: cy
    * x,y,z coordinates: 50.0,0.0,20.6
    * 3d normalized orientation vector. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
    * R,G,B colors in range [0-255]: 255, 255, 255
## Usage

Clone project

```bash
  git clone https://github.com/tatataha/miniRT.git
```

Go to project directory

```bash
  cd miniRT
```

Make it

```bash
  make
```

Start game

```bash
  ./miniRT ./maps/"map name"
```

  
