class Star {
  // Member Variables
  int x, y, w, speed;

  // Constructor
  Star() {
    x = int(random(width));
    y = -10;
    w = int(random(1, 5));
    speed = int(random(1, 5));
  }
  // Member Methods
  void display() {
    fill(150);
    rectMode(CENTER);
    rect(x, y, w, w);
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
}
