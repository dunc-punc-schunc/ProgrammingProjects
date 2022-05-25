class Laser {
  // Member Variables
  int x, y, w, h, speed;

  // Constructor
  Laser(int x, int y) {
    this.x = x;
    this.y = y;
    w = 3;
    h = 16;
    speed = 12;
  }
  // Member Methods
  void display() {
    rectMode(CENTER);
    fill(255);
    noStroke();
    rect(x, y, w, h);
  }

  void move() {
    y -= speed;
  }

  boolean reachedTop() {
    if (y < -50) {
      return true;
    } else {
      return false;
    }
  }

  boolean intersect(Rock r) {
    float distance = dist(x, y, r.x, r.y);
    if (distance < 30) {
      return true;
    } else {
      return false;
    }
  }
}
