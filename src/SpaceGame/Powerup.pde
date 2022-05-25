class Powerup {
  // Member Variables
  int x, y, diam, speed, rand;
  PImage powerup;
  char type;

  // Constructor
  Powerup(int x, int y) {
    this.x = x;
    this.y = y;
    speed = 3;
    rand = int(random(2));
    if (rand == 0) {
      powerup = loadImage("powerup_0.png");
    } else if (rand == 1) {
      powerup = loadImage("powerup_1.png");
    } else if (rand == 2){
      powerup = loadImage("powerup_2.png");
    }
    if (rand == 0) {
      type = 't';
    } else if (rand == 1) {
      type = 'h';
    } else if (rand == 2){
      type = 's';
    }
  }
  // Member Methods
  void display() {
    //if (type == 't') {
    //} else if (type == 'h') {
    //} else if (type == 's') {
    //}
    image(powerup, x, y);
  }

  void move() {
    y += speed;
  }

  boolean reachedBottom() {
    if (y > height+50) {
      return true;
    } else {
      return false;
    }
  }

  boolean intersect(Ship s) {
    float distance = dist(x, y, s.x, s.y);
    if (distance < 20) {
      return true;
    } else {
      return false;
    }
  }
}
