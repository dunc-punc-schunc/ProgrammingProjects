class Ship {
  // Member Variables
  int x, y, w, health, turret;
  boolean alive;
  boolean fireRight;
  PImage ship;
  PImage[] images;
  int imageCount;
  int frame;

  // Constructor
  Ship(String imagePrefix, int count) {
    imageCount = count;
    images = new PImage[imageCount];
    for (int i = 0; i < imageCount; i++) {
      // Use nf() to number format 'i' into four digits
      String filename = imagePrefix + nf(i, 2) + ".png";
      images[i] = loadImage(filename);
    }
    x = 0;
    y = 0;
    w = 50;
    fireRight = true;
    health = 100;
    turret = 1;
    alive = false;
    ship = loadImage("ship_0.png"); //Hoping to have this change to an animation using ship_0-3
  }

  // Member Methods

  void display(float xpos, float ypos) {
    x = int(xpos);
    y = int(ypos);
    imageMode(CENTER);
    frame = (frame + 1) % imageCount;
    image(images[frame], xpos, ypos);
  }

  int getWidth() {
    return images[0].width;
  }

  void move() {
  }

  void fire(Laser l) {
  }

  boolean intersect(Rock r) {
    return true;
  }
}
